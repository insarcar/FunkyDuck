#pragma once
#include <JuceHeader.h>
#include "PluginParameters.h"

class EnvelopeFollower
{
public:
	
	EnvelopeFollower(){}
	~EnvelopeFollower(){}
	void prepareToPlay(dsp::ProcessSpec& processSpec) {}
	void releaseResources() {}
	void processBlock(AudioBuffer<float>& side){}
};

class RMSFollower : EnvelopeFollower 
{
public:
	RMSFollower(){}
	~RMSFollower(){}

	void prepareToPlay(dsp::ProcessSpec& processSpec) 
	{
		sampleRate = processSpec.sampleRate;
		initHistory();
	}

	void releaseResources()
	{
		history.setSize(0, 0);
	}

	void processBlock(AudioBuffer<float>& side, int numSamples)
	{	
		float* data = side.getWritePointer(0);
		float* historyData = history.getWritePointer(0);

		FloatVectorOperations::multiply(data, data, numSamples);
		FloatVectorOperations::multiply(data, 1.0f / windowSize, numSamples);

		for (int sample = 0; sample < numSamples; ++sample)
		{
			sum += data[sample] - historyData[historyIndex];
			historyData[historyIndex] = data[sample];
			data[sample] = sqrt(sum);
			++historyIndex %= windowSize;
		}
	}

private:
	void initHistory()
	{
		windowSize = (int)(RESOLUTION * MS2SEC * sampleRate);
		history.setSize(1, windowSize);
		history.clear();
		historyIndex = 0;
		sum = 0.0f;
	}

	AudioBuffer<float> history;
	int historyIndex = 0;
	float sum = 0.0f;
	double sampleRate = 1.0;
	int windowSize = 1;
};

class PeakFollower : EnvelopeFollower
{
public:
	PeakFollower(){}
	~PeakFollower(){}

	void prepareToPlay(dsp::ProcessSpec& processSpec) 
	{
		prev = 0.0f;
		alpha = exp(-1.0f / (RESOLUTION * MS2SEC * processSpec.sampleRate));
	}
	void releaseResources() {}

	void processBlock(AudioBuffer<float>& side, int numSamples) 
	{
		float* sideData = side.getWritePointer(0);
		FloatVectorOperations::abs(sideData, sideData, numSamples);
		for (int smp = 0; smp < numSamples; ++smp)
		{
			sideData[smp] = jmax(prev * alpha, sideData[smp]);
			prev = sideData[smp];
		}
	}
private:
	float prev = 0.0f;
	float alpha = 0.0f;
};
