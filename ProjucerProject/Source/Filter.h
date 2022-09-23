#pragma once
#include <JuceHeader.h>
#include "PluginParameters.h"

class Butter
{
public:
	Butter(){};
	~Butter() {};

	void prepareToPlay(dsp::ProcessSpec& processSpec)
	{
		sampleRate = processSpec.sampleRate;
		iirFilter.reset();

		updateCoefficients();
	};

	void releaseResources() {}

	void processBlock(AudioBuffer<float>& buffer, const int numSamples)
	{
		//processing del filtro
		iirFilter.processSamples(buffer.getWritePointer(0), numSamples);
	};

	void setFreq(double newValue)
	{
		//il chiamante setta la frequenza di taglio
		frequency = newValue;
		updateCoefficients();
	};


private:

	void updateCoefficients()
	{	
		IIRCoefficients coefficients;

			coefficients = IIRCoefficients::makeHighPass(sampleRate, frequency, quality);

		iirFilter.setCoefficients(coefficients);
	};

	IIRFilter iirFilter;
	double sampleRate = 44100.0;
	double frequency = DEFAULT_FREQ;
	const float quality = QUALITY;
};

class FirstOrderHPF
{
public:
	FirstOrderHPF() {};
	~FirstOrderHPF() {};

	void prepareToPlay(dsp::ProcessSpec& processSpec)
	{
		prev = 0.0f;
	};

	void releaseResources() {}

	void processBlock(AudioBuffer<float>& buffer, const int numSamples)
	{
		//processing del filtro
		float** data = buffer.getArrayOfWritePointers();
		for (int smp = 0; smp < numSamples; ++smp) 
		{
			const auto temp = data[0][smp];
			data[0][smp] = 0.5f * data[0][smp] - 0.5f * prev;
			prev = temp;
		}
	};
private:
	double sampleRate = 44100.0;
	float prev = 0.0f;
};
