#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
FunkyDuckAudioProcessor::FunkyDuckAudioProcessor() :
    parameters(*this, nullptr, Identifier("FunkyDuckParameters"), createParameterLayout())
{
    parameters.addParameterListener(NAME_ACTIVE, &compressor);
    parameters.addParameterListener(NAME_COMPRESSION, &compressor);
    parameters.addParameterListener(NAME_FACTORSWITCH, &compressor);
    parameters.addParameterListener(NAME_INSTRUMENT, &compressor);
    parameters.addParameterListener(NAME_KNEE, &compressor);
    parameters.addParameterListener(NAME_LEVEL, &compressor);
    parameters.addParameterListener(NAME_TIMESCALE, &compressor);
}
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif


FunkyDuckAudioProcessor::~FunkyDuckAudioProcessor()
{
}

//==============================================================================
const juce::String FunkyDuckAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool FunkyDuckAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool FunkyDuckAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool FunkyDuckAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double FunkyDuckAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int FunkyDuckAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int FunkyDuckAudioProcessor::getCurrentProgram()
{
    return 0;
}

void FunkyDuckAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String FunkyDuckAudioProcessor::getProgramName (int index)
{
    return {};
}

void FunkyDuckAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void FunkyDuckAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    ps.sampleRate = sampleRate;
    ps.maximumBlockSize = samplesPerBlock;
    auxSignal.setSize(1, samplesPerBlock);
    compressor.prepareToPlay(ps);
}

void FunkyDuckAudioProcessor::releaseResources()
{
    auxSignal.setSize(0, 0);
    compressor.releaseResources();
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool FunkyDuckAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void FunkyDuckAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auxSignal.clear();
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    auto numSamples = buffer.getNumSamples();

    {
        const AudioBuffer<float>* source = &buffer;
        const int numCh = source->getNumChannels();
        for (int ch = numCh; --ch >= 0;)
            auxSignal.addFrom(0, 0, *source, ch, 0, numSamples, 1.0f / numCh);
    }

    compressor.processBlock(buffer, auxSignal);
    envelope = jmax(envelope.get(), compressor.getEnvelope());
}

//==============================================================================
bool FunkyDuckAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* FunkyDuckAudioProcessor::createEditor()
{
   return new PluginEditor (*this, parameters);
}

//==============================================================================
void FunkyDuckAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    auto state = parameters.copyState();
    std::unique_ptr<XmlElement> xml(state.createXml());
    copyXmlToBinary(*xml, destData);
}

void FunkyDuckAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    std::unique_ptr<XmlElement> xmlState(getXmlFromBinary(data, sizeInBytes));

    if (xmlState.get() != nullptr) //se ho caricato dei dati
    {

        if (xmlState->hasTagName(parameters.state.getType())) //se il tipo nel valuetreestate corrisponde allora posso caricare lo stato nel tree
        {

            parameters.replaceState(ValueTree::fromXml(*xmlState));

        }

    }
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new FunkyDuckAudioProcessor();
}
