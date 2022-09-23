#pragma once
#include <JuceHeader.h>
#include "PluginParameters.h"

class AutoARFilter
{
public:

	AutoARFilter()
	{
		//init smoothed values
		timeScale.setCurrentAndTargetValue(DEFAULT_TIMESCALE);
		minAtk.setCurrentAndTargetValue(GUITAR_MIN_ATK);
		minRel.setCurrentAndTargetValue(GUITAR_MIN_REL);
		maxAtk.setCurrentAndTargetValue(GUITAR_MAX_ATK);
		maxRel.setCurrentAndTargetValue(GUITAR_MAX_REL);
	}
	~AutoARFilter(){}

	void prepareToPlay(dsp::ProcessSpec& processSpec) 
	{
		sampleRate = processSpec.sampleRate;

		//reset smoothed values
		timeScale.reset(sampleRate, SMOOTHING_RAMP);
		minAtk.reset(sampleRate, SMOOTHING_RAMP);
		minRel.reset(sampleRate, SMOOTHING_RAMP);
		maxAtk.reset(sampleRate, SMOOTHING_RAMP);
		maxRel.reset(sampleRate, SMOOTHING_RAMP);

		//init variabile di retroattività
		prev = 1.0f;
	}
	void releaseResources() {}

	void processBlock(AudioBuffer<float>& side, AudioBuffer<float>& factor, int numSamples)
	{
		applyBallistics(side, factor, numSamples);
	}

	void setTimeScale(float newValue)
	{
		//il chiamante che è observer del parametro utente setta il parametro interno
		timeScale.setTargetValue(newValue);
	}

	void setInstrument(int newValue) 
	{
		//il chiamante che è observer del parametro utente setta i tempi di attacco e di rilascio di base
		switch (newValue) 
		{
		case 0:
			minAtk.setTargetValue(GUITAR_MIN_ATK);
			minRel.setTargetValue(GUITAR_MIN_REL);
			maxAtk.setTargetValue(GUITAR_MAX_ATK);
			maxRel.setTargetValue(GUITAR_MAX_REL);
			break;
		case 1:
			minAtk.setTargetValue(BASS_MIN_ATK);
			minRel.setTargetValue(BASS_MIN_REL);
			maxAtk.setTargetValue(BASS_MAX_ATK);
			maxRel.setTargetValue(BASS_MAX_REL);
			break;
		}
	}

private:

	void applyBallistics(AudioBuffer<float>& side, AudioBuffer<float>& factor, int numSamples)
	{
		float** sideData = side.getArrayOfWritePointers();
		const float** factorData = factor.getArrayOfReadPointers();

		for (int smp = 0; smp < numSamples; ++smp)
		{
			sideData[0][smp] = continousTS(sideData[0][smp], factorData[0][smp]);
			prev = sideData[0][smp];
		}
	}
	float continousTS(float sample, float factor)
	{
		const float w = jmax(timeScale.getNextValue(), 0.0f) * 2.0f;
		const float ts = jmax(pow(fabs(timeScale.getCurrentValue()), 1.5f) * 10.0f, 1.0f);
		const float ex = pow(factor, 2.0f * -timeScale.getCurrentValue());

		const float tmpAtk = maxAtk.getNextValue() * w + minAtk.getNextValue() * (1.0f - w);
		const float tmpRel = maxRel.getNextValue() * w + minRel.getNextValue() * (1.0f - w);

		const float atk = exp(-1.0f / (((tmpAtk / ts) * ex) * MS2SEC * sampleRate));
		const float rel = exp(-1.0f / (((tmpRel / ts) * ex) * MS2SEC * sampleRate));

		const float gr = (sample < prev) ? atk * prev + (1 - atk) * sample : rel * prev + (1 - rel) * sample;
		return gr;
	}
	

	SmoothedValue <float, ValueSmoothingTypes::Linear> timeScale, minAtk, minRel, maxAtk, maxRel;
	float prev = 1.0f;
	double sampleRate = 1.0;
};
