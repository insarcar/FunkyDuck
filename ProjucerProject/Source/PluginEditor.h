/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 7.0.2

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "PluginParameters.h"
#include "MyLookAndFeel.h"
#include "Meter.h"

typedef AudioProcessorValueTreeState::SliderAttachment SliderAttachment;
typedef AudioProcessorValueTreeState::ButtonAttachment ButtonAttachment;
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class PluginEditor  : public AudioProcessorEditor,
                      public juce::Slider::Listener,
                      public juce::Button::Listener
{
public:
    //==============================================================================
    PluginEditor (FunkyDuckAudioProcessor& p,  AudioProcessorValueTreeState& vts);
    ~PluginEditor() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void sliderValueChanged (juce::Slider* sliderThatWasMoved) override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;

    // Binary resources:
    static const char* _160_jpg2;
    static const int _160_jpg2Size;
    static const char* kneeBianco_png;
    static const int kneeBianco_pngSize;
    static const char* kobe_cattivoBianco_png;
    static const int kobe_cattivoBianco_pngSize;
    static const char* kobe_softBianco_png;
    static const int kobe_softBianco_pngSize;
    static const char* bassWhiteLulu_png;
    static const int bassWhiteLulu_pngSize;
    static const char* guitarBianca_png;
    static const int guitarBianca_pngSize;
    static const char* crestBianco_png;
    static const int crestBianco_pngSize;
    static const char* v_png;
    static const int v_pngSize;
    static const char* u_png;
    static const int u_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    FunkyDuckAudioProcessor& processor;
    AudioProcessorValueTreeState& valueTreeState;
    MyLookAndFeel myTheme;

    std::unique_ptr<SliderAttachment> compressionAttachment;
    std::unique_ptr<SliderAttachment> levelAttachment;
    std::unique_ptr<SliderAttachment> timeScaleAttachment;
    std::unique_ptr<ButtonAttachment> bypassAttachment;
    std::unique_ptr<SliderAttachment> kneeAttachment;
    std::unique_ptr<SliderAttachment> factorAttachment;
    std::unique_ptr<SliderAttachment> instrumentAttachment;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::Slider> compressionSlider;
    std::unique_ptr<juce::Slider> levelSlider;
    std::unique_ptr<juce::Slider> timeScaleSlider;
    std::unique_ptr<Meter> vuMeter;
    std::unique_ptr<juce::ToggleButton> bypassButton;
    std::unique_ptr<juce::Slider> kneeSlider;
    std::unique_ptr<juce::Slider> factorSlider;
    std::unique_ptr<juce::Slider> instrumentSlider;
    juce::Path internalPath1;
    juce::Image cachedImage__160_jpg2_2;
    juce::Image cachedImage_kneeBianco_png_3;
    juce::Image cachedImage_kobe_cattivoBianco_png_4;
    juce::Image cachedImage_kobe_softBianco_png_5;
    juce::Image cachedImage_crestBianco_png_6;
    juce::Image cachedImage_bassWhiteLulu_png_7;
    juce::Image cachedImage_guitarBianca_png_8;
    juce::Image cachedImage_v_png_9;
    juce::Image cachedImage_u_png_10;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

