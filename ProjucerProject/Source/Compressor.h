#pragma once
#include <JuceHeader.h>
#include "TransientDetector.h"
#include "AutoARFilter.h"

class Compressor : public AudioProcessorValueTreeState::Listener
{
public:

	Compressor()
	{
		//init smoothed values
		threshold.setCurrentAndTargetValue(Decibels::gainToDecibels(DEFAULT_THRESHOLD));
		slope.setCurrentAndTargetValue(DEFAULT_COMPRESSION);
		level.setCurrentAndTargetValue(Decibels::decibelsToGain(DEFAULT_LEVEL));
		knee.setCurrentAndTargetValue(SOFT_KNEE);
	}
	~Compressor() {}

	void prepareToPlay(dsp::ProcessSpec& processSpec)
	{
		//chiamata delle varie prepareToPlay
		crest.prepareToPlay(processSpec);
		cobe.prepareToPlay(processSpec);
		ballistics.prepareToPlay(processSpec);

		//reset smoothed values
		threshold.reset(processSpec.sampleRate, SMOOTHING_RAMP);
		slope.reset(processSpec.sampleRate, SMOOTHING_RAMP);
		level.reset(processSpec.sampleRate, SMOOTHING_RAMP);
		knee.reset(processSpec.sampleRate, SMOOTHING_RAMP);

		//init  buffer ausiliari
		factor.setSize(1, processSpec.maximumBlockSize);
		auxEnvelope.setSize(1, processSpec.maximumBlockSize);

		sampleRate = processSpec.sampleRate;

	}

	void releaseResources() 
	{
		//chiamata delle varie release resources
		crest.releaseResources();
		cobe.releaseResources();
		ballistics.releaseResources();

		//deallocazione dei buffer ausiliari, uno per i fattori di transiente, uno per l'inviluppo ausiliario utilizzato nel calcolo del fattore stesso
		factor.setSize(0, 0);
		auxEnvelope.setSize(0, 0);
	}

	void processBlock(AudioBuffer<float>& main, AudioBuffer<float>& side) 
	{
		//buffer clear
		auxEnvelope.clear();
		factor.clear();

		//bypass
		if (active)
		{	
			//setup del buffer ausiliario
			const auto numSamples = main.getNumSamples();
			const float* sideData = side.getReadPointer(0);
			auxEnvelope.copyFrom(0, 0, sideData, numSamples);

			//switch on factorSwitch
			switch (factorSwitch)
			{
			case 0:
				crest.processBlock(side, factor, auxEnvelope, numSamples);
				break;
			case 1:
				cobe.setMode(0);
				cobe.processBlock(side, factor, auxEnvelope, numSamples);
				break;
			case 2:
				cobe.setMode(1);
				cobe.processBlock(side, factor, auxEnvelope, numSamples);
				break;
			}

			//gain computer
			gainComputer(side, numSamples);

			//auto ar filter
			ballistics.processBlock(side, factor, numSamples);

			//gain stage
			applyGain(main, side, numSamples);

			//salvo il massimo valore del main per il vu meter pre softclip
			envelope = main.getMagnitude(0, numSamples);

			//soft clip
			softClip(main, LENGTH, HARDNESS, numSamples);

		}
		else
			envelope = 0.0f;
	}

	float getEnvelope()
	{
		//ritrona l'attuale massimo per il vu meter
		return envelope;
	}

private:

	void applyGain(AudioBuffer<float>& main, AudioBuffer<float>& side, int numSamples) 
	{
		float** mainData = main.getArrayOfWritePointers();
		const float* sideData = side.getReadPointer(0);


		for (int ch = main.getNumChannels(); --ch >= 0; )
		{
			FloatVectorOperations::multiply(mainData[ch], sideData, numSamples);
		}
		level.applyGain(main, numSamples);
	}

	void gainComputer(AudioBuffer<float>& side, int numSamples) 
	{
		/*gain computer ------ il calcolo per i valori dell'auto knee avviene ad ogni ciclo
		in quanto retroattivo*/
		float** sideData = side.getArrayOfWritePointers();
		const auto alpha = exp(-1.0f / (ALPHA_TIME * sampleRate));
		for (int smp = 0; smp < numSamples; ++smp)
		{
			//calcolo variabili auto knee
			const auto estimate = threshold.getNextValue() * slope.getNextValue() / 2.0f;
			const auto mag2db = Decibels::gainToDecibels(sideData[0][smp]);
			
			const auto pseudoVC = mag2db * slope.getNextValue() / 2.0f;
			kneeDeviation = (smp) ? alpha * kneeDeviation + (1 - alpha) * (pseudoVC - estimate) : (1 - alpha) * (pseudoVC - estimate);
			knee.setTargetValue((kneeDeviation + estimate) / 2);

			//calcolo overshoot
			const auto overshoot = mag2db - threshold.getNextValue();

			//switch on kneeMode -- calcolo della gain reduction in base alla modalità indicata
			//softKnee e autoKnee sono in parte ridondanti, tuttavia questa modalita evita un controllo in più
			switch(kneeMode)
			{
			case 0:
				sideData[0][smp] = hardKnee(overshoot);
				break;
			case 1:
				sideData[0][smp] = softKnee(overshoot);
				break;
			case 2:
				sideData[0][smp] = autoKnee(overshoot);
				break;
			}
		}

	}

	float hardKnee(float overshoot) 
	{
		//hard knee
		const float gr = (overshoot > 0) ? Decibels::decibelsToGain(overshoot * slope.getNextValue()) : 1.0f;
		return gr;
	}

	float softKnee(float overshoot) 
	{
		//soft knee con ampiezza 12 dB fissa

		const float kneeHalf = SOFT_KNEE / 2.0f;
		float gr = 1.0f;

		if (overshoot > kneeHalf)
			gr = Decibels::decibelsToGain(overshoot * slope.getNextValue());
		if (overshoot > -kneeHalf && overshoot < kneeHalf)
			gr = Decibels::decibelsToGain(0.5 * slope.getNextValue() * ((overshoot + kneeHalf) * (overshoot + kneeHalf) / SOFT_KNEE));

		return gr;
	}

	float autoKnee(float overshoot) 
	{
		//auto knee con ampiezza calcolata in gainComputer

		const float kneeHalf = knee.getNextValue() / 2.0f;
		float gr = 1.0f;

		if (overshoot > kneeHalf)
			gr = Decibels::decibelsToGain(overshoot * slope.getNextValue());
		if (overshoot > -kneeHalf && overshoot < kneeHalf)
			gr = Decibels::decibelsToGain(0.5 * slope.getNextValue() * ((overshoot + kneeHalf) * (overshoot + kneeHalf) / knee.getNextValue()));

		return gr;
	}

	void softClip(AudioBuffer<float>& main, int length, int hardness, int numSamples) 
	{
		//soft clip
		const int ord = hardness * 2 + 1;
		const int cmp = ord - 1;
		float r = cmp / (ord * length);
		r = (r != 0.0f) ? r : 0.000001f;

		float** mainData = main.getArrayOfWritePointers();

		for(int ch = main.getNumChannels(); --ch >= 0; )
		{
			FloatVectorOperations::multiply(mainData[ch], r, numSamples);
			for(int smp = 0; smp < numSamples; ++smp)
			{

				mainData[ch][smp] -= pow(mainData[ch][smp], ord) / ord;
				if (mainData[ch][smp] < -1.0f)
					mainData[ch][smp] = -cmp / ord;
				if (mainData[ch][smp] > 1.0f)
					mainData[ch][smp] = cmp / ord;
			
			}
			FloatVectorOperations::multiply(mainData[ch], 1 / r, numSamples);
		}
	}

	void parameterChanged(const String& paramID, float newValue)override 
	{
		if (paramID == NAME_ACTIVE)
			active = newValue;

		if (paramID == NAME_COMPRESSION)
		{
			setThreshold(newValue * PARAM_SCALE);
			setSlope(newValue * PARAM_SCALE);
		}

		if (paramID == NAME_LEVEL)
			level.setTargetValue(Decibels::decibelsToGain(newValue * PARAM_SCALE));

		if (paramID == NAME_FACTORSWITCH)
			factorSwitch = roundToInt(newValue);

		if (paramID == NAME_KNEE)
			kneeMode = roundToInt(newValue);

		if (paramID == NAME_TIMESCALE)
			ballistics.setTimeScale(newValue);
		
		if (paramID == NAME_INSTRUMENT)
			ballistics.setInstrument(roundToInt(newValue));

	}

	//threshold e slope sono smoothed values che vengono cambiati in base alla variazione del parametro utente Compression
	void setThreshold(float newValue) 
	{
		/*funzione con decrescita lenta a partire da 1, asintotica a 0.0000001
		trasforma il parametro utente nel range delle ampiezze e lo converte poi nel range logaritmico */
		const auto a = COEFF_A;
		const auto b = COEFF_B;
		const auto c = COEFF_C;
		
		const auto target = 1.0f + a * exp(b * exp(c * newValue));

		threshold.setTargetValue(Decibels::gainToDecibels(target));
	}

	void setSlope(float newValue) 
	{
		//mappa lineare per la coversione del parametro utente in ratio
		const auto ratio = newValue * RATIO_CONVERSION + 1.0f;
		const auto target = 1.0f / ratio - 1.0f;
		slope.setTargetValue(target);
	}

	bool active = DEFAULT_ACTIVE;
	SmoothedValue <float, ValueSmoothingTypes::Linear> threshold, slope, level, knee;
	int kneeMode = DEFAULT_KNEE;
	int factorSwitch = DEFAULT_FACTORSWITCH;

	AudioBuffer<float> factor, auxEnvelope;

	float envelope = 0.0f;
	float kneeDeviation = 0.0f;
	double sampleRate = 1.0;

	CrestFactor crest;
	CoBE cobe;
	AutoARFilter ballistics;
};