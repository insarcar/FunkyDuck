#pragma once
#include <JuceHeader.h>
#include "EnvelopeFollower.h"
#include "Filter.h"

class TransientDetector
{
public:
	TransientDetector(){}
	~TransientDetector(){}
	void prepareToPlay(dsp::ProcessSpec& processSpec) {}
	void releaseResources() {}

	void processBlock(AudioBuffer<float>& side, AudioBuffer<float>& factor, AudioBuffer<float>& auxEnv, int numSamples) {}

private:
	void factorCalculation(AudioBuffer<float>& factor, AudioBuffer<float>& env, AudioBuffer<float>& auxEnv, int numSamples) {}
};

class CrestFactor : TransientDetector
{
public:
	CrestFactor(){}
	~CrestFactor(){}

	void prepareToPlay(dsp::ProcessSpec& processSpec) 
	{
		//prepareToPlay degli envelope follower
		rms.prepareToPlay(processSpec);
		peak.prepareToPlay(processSpec);
	}
	void releaseResources() 
	{
		//releaseResources degli envelope follower
		rms.releaseResources();
		peak.releaseResources();
	}

	void processBlock(AudioBuffer<float>& side, AudioBuffer<float>& factor, AudioBuffer<float>& auxEnv, int numSamples)
	{
		//envelope follower
		rms.processBlock(side, numSamples);
		peak.processBlock(auxEnv, numSamples);
		//calcolo crest factor
		factorCalculation(factor, side, auxEnv, numSamples);
	}

private:

	void factorCalculation(AudioBuffer<float>& factor, AudioBuffer<float>& env, AudioBuffer<float>& auxEnv, int numSamples) 
	{	
		//calcolo del crest factor e scalatura

		const float** envData = env.getArrayOfReadPointers();
		const float** auxData = auxEnv.getArrayOfReadPointers();
		float** factorData = factor.getArrayOfWritePointers();
		
		for (int smp = 0; smp < numSamples; ++smp)
		{
			factorData[0][smp] = auxData[0][smp] / envData[0][smp] + 1;
			factorData[0][smp] = log10(factorData[0][smp]) * CREST_SCALE;
		}

		FloatVectorOperations::multiply(factorData[0], factorData[0], numSamples);
		FloatVectorOperations::max(factorData[0], factorData[0], 1.0f, numSamples);
		FloatVectorOperations::min(factorData[0], factorData[0], 6.0f, numSamples);
	}
	PeakFollower peak;
	RMSFollower rms;
};

class CoBE : TransientDetector
{
public:
	CoBE(){}
	~CoBE(){}

	void prepareToPlay(dsp::ProcessSpec& processSpec)
	{
		//prepareToPlay degli envelope follower e dei filtri
		rmsA.prepareToPlay(processSpec);
		rmsB.prepareToPlay(processSpec);
		peakA.prepareToPlay(processSpec);
		peakB.prepareToPlay(processSpec);
		hpf.prepareToPlay(processSpec);
		butter.prepareToPlay(processSpec);
	}
	void releaseResources()
	{
		//releaseResources degli envelope follower e dei filtri
		rmsA.releaseResources();
		rmsB.releaseResources();
		peakA.releaseResources();
		peakB.releaseResources();
		hpf.releaseResources();
		butter.releaseResources();
	}


	void processBlock(AudioBuffer<float>& side, AudioBuffer<float>& factor, AudioBuffer<float>& auxEnv, int numSamples) 
	{
		//HPF first order dell'inviluppo ausiliario
		hpf.processBlock(auxEnv, numSamples);

		//peak cobe o rms cobe
		if(mode)
		{
			peakA.processBlock(side, numSamples);
			peakB.processBlock(auxEnv, numSamples);
		}
		else
		{
			rmsA.processBlock(side, numSamples);
			rmsB.processBlock(auxEnv, numSamples);
		}
		//calcolo del fattore
		factorCalculation(factor, side, auxEnv, numSamples);
	}

	void setMode(bool newValue) 
	{
		//permette al chiamante di settare la modalità peak o cobe
		mode = newValue;
	}

private:
	void factorCalculation(AudioBuffer<float>& factor, AudioBuffer<float>& env, AudioBuffer<float>& auxEnv, int numSamples)
	{
	
		const float** envData = env.getArrayOfReadPointers();
		const float** auxData = auxEnv.getArrayOfReadPointers();
		float** factorData = factor.getArrayOfWritePointers();

		float scale = (!mode) ? COBE_RMS_SCALE : COBE_PEAK_SCALE;

		//cobe factor
		for (int smp = 0; smp < numSamples; ++smp)
		{
			factorData[0][smp] = auxData[0][smp] / envData[0][smp];
		}


		//hpf butter a 25 hZ
		butter.setFreq(DEFAULT_FREQ);
		butter.processBlock(factor, numSamples);

		//scaling
		FloatVectorOperations::max(factorData[0], factorData[0], 0.0f, numSamples);
		FloatVectorOperations::multiply(factorData[0], scale, numSamples);
		FloatVectorOperations::add(factorData[0], 1.0f, numSamples);
		FloatVectorOperations::min(factorData[0], factorData[0], 6.0f, numSamples);

	}

	bool mode = 0;
	Butter butter;
	FirstOrderHPF hpf;
	PeakFollower peakA, peakB;
	RMSFollower rmsA, rmsB;
};