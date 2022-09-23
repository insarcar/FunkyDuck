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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
PluginEditor::PluginEditor (FunkyDuckAudioProcessor& p,  AudioProcessorValueTreeState& vts)
    : AudioProcessorEditor(&p), processor(p), valueTreeState(vts)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    compressionSlider.reset (new juce::Slider ("Compression"));
    addAndMakeVisible (compressionSlider.get());
    compressionSlider->setRange (0, 1, 0.001);
    compressionSlider->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    compressionSlider->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    compressionSlider->addListener (this);
    compressionSlider->setSkewFactor (0.9);

    compressionSlider->setBounds (56, 56, 128, 120);

    levelSlider.reset (new juce::Slider ("Level"));
    addAndMakeVisible (levelSlider.get());
    levelSlider->setRange (0, 1, 0.001);
    levelSlider->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    levelSlider->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    levelSlider->addListener (this);

    levelSlider->setBounds (448, 56, 128, 120);

    timeScaleSlider.reset (new juce::Slider ("Time Scale"));
    addAndMakeVisible (timeScaleSlider.get());
    timeScaleSlider->setRange (-0.5, 0.5, 0.1);
    timeScaleSlider->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    timeScaleSlider->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    timeScaleSlider->addListener (this);

    timeScaleSlider->setBounds (267, 80, 112, 97);

    vuMeter.reset (new Meter());
    addAndMakeVisible (vuMeter.get());
    vuMeter->setName ("Vu Meter");

    vuMeter->setBounds (586, 63, 16, 96);

    bypassButton.reset (new juce::ToggleButton ("Bypass"));
    addAndMakeVisible (bypassButton.get());
    bypassButton->setButtonText (juce::String());
    bypassButton->addListener (this);
    bypassButton->setToggleState (true, juce::dontSendNotification);

    bypassButton->setBounds (240, 299, 168, 56);

    kneeSlider.reset (new juce::Slider ("Knee"));
    addAndMakeVisible (kneeSlider.get());
    kneeSlider->setRange (0, 2, 1);
    kneeSlider->setSliderStyle (juce::Slider::LinearHorizontal);
    kneeSlider->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    kneeSlider->setColour (juce::Slider::backgroundColourId, juce::Colour (0xffceb3af));
    kneeSlider->setColour (juce::Slider::thumbColourId, juce::Colour (0xffdcc38c));
    kneeSlider->setColour (juce::Slider::trackColourId, juce::Colour (0xffceb3af));
    kneeSlider->addListener (this);

    kneeSlider->setBounds (67, 186, 115, 40);

    factorSlider.reset (new juce::Slider ("Factor Mode"));
    addAndMakeVisible (factorSlider.get());
    factorSlider->setRange (0, 2, 1);
    factorSlider->setSliderStyle (juce::Slider::LinearHorizontal);
    factorSlider->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    factorSlider->setColour (juce::Slider::backgroundColourId, juce::Colour (0xffceb3af));
    factorSlider->setColour (juce::Slider::thumbColourId, juce::Colour (0xffdcc38c));
    factorSlider->setColour (juce::Slider::trackColourId, juce::Colour (0xffceb3af));
    factorSlider->addListener (this);

    factorSlider->setBounds (265, 186, 115, 40);

    instrumentSlider.reset (new juce::Slider ("Instrument"));
    addAndMakeVisible (instrumentSlider.get());
    instrumentSlider->setRange (0, 1, 1);
    instrumentSlider->setSliderStyle (juce::Slider::LinearHorizontal);
    instrumentSlider->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    instrumentSlider->setColour (juce::Slider::backgroundColourId, juce::Colour (0xffceb3af));
    instrumentSlider->setColour (juce::Slider::thumbColourId, juce::Colour (0xffdcc38c));
    instrumentSlider->setColour (juce::Slider::trackColourId, juce::Colour (0xffceb3af));
    instrumentSlider->setColour (juce::Slider::rotarySliderFillColourId, juce::Colour (0xff96b5c3));
    instrumentSlider->addListener (this);

    instrumentSlider->setBounds (468, 186, 90, 40);

    internalPath1.startNewSubPath (20.0f, 380.0f);
    internalPath1.lineTo (20.0f, 24.0f);
    internalPath1.lineTo (624.0f, 24.0f);
    internalPath1.lineTo (624.0f, 380.0f);
    internalPath1.closeSubPath();

    cachedImage__160_jpg2_2 = juce::ImageCache::getFromMemory (_160_jpg2, _160_jpg2Size);
    cachedImage_kneeBianco_png_3 = juce::ImageCache::getFromMemory (kneeBianco_png, kneeBianco_pngSize);
    cachedImage_kobe_cattivoBianco_png_4 = juce::ImageCache::getFromMemory (kobe_cattivoBianco_png, kobe_cattivoBianco_pngSize);
    cachedImage_kobe_softBianco_png_5 = juce::ImageCache::getFromMemory (kobe_softBianco_png, kobe_softBianco_pngSize);
    cachedImage_crestBianco_png_6 = juce::ImageCache::getFromMemory (crestBianco_png, crestBianco_pngSize);
    cachedImage_bassWhiteLulu_png_7 = juce::ImageCache::getFromMemory (bassWhiteLulu_png, bassWhiteLulu_pngSize);
    cachedImage_guitarBianca_png_8 = juce::ImageCache::getFromMemory (guitarBianca_png, guitarBianca_pngSize);
    cachedImage_v_png_9 = juce::ImageCache::getFromMemory (v_png, v_pngSize);
    cachedImage_u_png_10 = juce::ImageCache::getFromMemory (u_png, u_pngSize);

    //[UserPreSize]
    vuMeter->connectTo(processor.envelope);

    compressionAttachment.reset(new SliderAttachment(vts, NAME_COMPRESSION, *compressionSlider));
    levelAttachment.reset(new SliderAttachment(vts, NAME_LEVEL, *levelSlider));
    timeScaleAttachment.reset(new SliderAttachment(vts, NAME_TIMESCALE, *timeScaleSlider));
    kneeAttachment.reset(new SliderAttachment(vts, NAME_KNEE, *kneeSlider));
    factorAttachment.reset(new SliderAttachment(vts, NAME_FACTORSWITCH, *factorSlider));
    instrumentAttachment.reset(new SliderAttachment(vts, NAME_INSTRUMENT, *instrumentSlider));
    bypassAttachment.reset(new ButtonAttachment(vts, NAME_ACTIVE, *bypassButton));

    this->setLookAndFeel(&myTheme);
    //[/UserPreSize]

    setSize (650, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

PluginEditor::~PluginEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    this->setLookAndFeel(nullptr);
    compressionAttachment.reset();
    levelAttachment.reset();
    timeScaleAttachment.reset();
    bypassAttachment.reset();
    kneeAttachment.reset();
    factorAttachment.reset();
    instrumentAttachment.reset();
    //[/Destructor_pre]

    compressionSlider = nullptr;
    levelSlider = nullptr;
    timeScaleSlider = nullptr;
    vuMeter = nullptr;
    bypassButton = nullptr;
    kneeSlider = nullptr;
    factorSlider = nullptr;
    instrumentSlider = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void PluginEditor::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff323e44));

    {
        float x = 0, y = 0;
        juce::Colour fillColour = juce::Colour (0xfff1d4d4);
        juce::Colour strokeColour1 = juce::Colour (0xffedd3da), strokeColour2 = juce::Colour (0xfff0dbea);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillPath (internalPath1, juce::AffineTransform::translation(x, y));
        g.setGradientFill (juce::ColourGradient (strokeColour1,
                                             16.0f - 0.0f + x,
                                             424.0f - 0.0f + y,
                                             strokeColour2,
                                             112.0f - 0.0f + x,
                                             160.0f - 0.0f + y,
                                             false));
        g.strokePath (internalPath1, juce::PathStrokeType (14.700f, juce::PathStrokeType::curved, juce::PathStrokeType::rounded), juce::AffineTransform::translation(x, y));
    }

    {
        int x = 444, y = 228, width = 124, height = 136;
            //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setTiledImageFill (cachedImage__160_jpg2_2,
                         430 - 444 + x,
                         180 - 228 + y,
                         1.0000f);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 36, y = 28, width = 170, height = 44;
        juce::String text (TRANS("COMPRESSION"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font ("Bell MT", 25.70f, juce::Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 436, y = 28, width = 152, height = 44;
        juce::String text (TRANS("LEVEL"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font ("Bell MT", 25.70f, juce::Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 247, y = 28, width = 152, height = 44;
        juce::String text (TRANS("SENSITIVITY"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font ("Bell MT", 25.70f, juce::Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = -36, y = 192, width = 220, height = 68;
        juce::String text (TRANS("HARD"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font ("Bell MT", 15.00f, juce::Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 18, y = 192, width = 220, height = 68;
        juce::String text (TRANS("SOFT"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font ("Bell MT", 15.00f, juce::Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 71, y = 192, width = 220, height = 68;
        juce::String text (TRANS("AUTO"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font ("Bell MT", 15.00f, juce::Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 108, y = 248, width = 52, height = 60;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (juce::Colours::black);
        g.drawImage (cachedImage_kneeBianco_png_3,
                     x, y, width, height,
                     0, 0, cachedImage_kneeBianco_png_3.getWidth(), cachedImage_kneeBianco_png_3.getHeight());
    }

    {
        int x = 353, y = 216, width = 44, height = 44;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (juce::Colours::black);
        g.drawImage (cachedImage_kobe_cattivoBianco_png_4,
                     x, y, width, height,
                     0, 0, cachedImage_kobe_cattivoBianco_png_4.getWidth(), cachedImage_kobe_cattivoBianco_png_4.getHeight());
    }

    {
        int x = 301, y = 216, width = 44, height = 44;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (juce::Colours::black);
        g.drawImage (cachedImage_kobe_softBianco_png_5,
                     x, y, width, height,
                     0, 0, cachedImage_kobe_softBianco_png_5.getWidth(), cachedImage_kobe_softBianco_png_5.getHeight());
    }

    {
        int x = 253, y = 216, width = 44, height = 44;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (juce::Colours::black);
        g.drawImage (cachedImage_crestBianco_png_6,
                     x, y, width, height,
                     0, 0, cachedImage_crestBianco_png_6.getWidth(), cachedImage_crestBianco_png_6.getHeight());
    }

    {
        int x = 528, y = 184, width = 68, height = 60;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (juce::Colours::black);
        g.drawImage (cachedImage_bassWhiteLulu_png_7,
                     x, y, width, height,
                     0, 0, cachedImage_bassWhiteLulu_png_7.getWidth(), cachedImage_bassWhiteLulu_png_7.getHeight());
    }

    {
        int x = 435, y = 192, width = 44, height = 44;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (juce::Colours::black);
        g.drawImage (cachedImage_guitarBianca_png_8,
                     x, y, width, height,
                     0, 0, cachedImage_guitarBianca_png_8.getWidth(), cachedImage_guitarBianca_png_8.getHeight());
    }

    {
        int x = 218, y = 237, width = 220, height = 68;
        juce::String text (TRANS("DETECTION"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font ("Bell MT", 18.10f, juce::Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 215, y = 250, width = 220, height = 68;
        juce::String text (TRANS("MODE"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font ("Bell MT", 18.10f, juce::Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 260, y = 156, width = 20, height = 30;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (juce::Colours::black);
        g.drawImage (cachedImage_v_png_9,
                     x, y, width, height,
                     0, 0, cachedImage_v_png_9.getWidth(), cachedImage_v_png_9.getHeight());
    }

    {
        int x = 364, y = 156, width = 20, height = 30;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (juce::Colours::black);
        g.drawImage (cachedImage_u_png_10,
                     x, y, width, height,
                     0, 0, cachedImage_u_png_10.getWidth(), cachedImage_u_png_10.getHeight());
    }

    {
        int x = -39, y = 370, width = 452, height = 18;
        juce::String text (TRANS("Coded at Laboratorio di Informatica Musicale by Matteo Insarauto"));
        juce::Colour fillColour = juce::Colours::aliceblue;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font ("Bell MT", 13.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 560, y = 18, width = 68, height = 18;
        juce::String text (TRANS("Ver. 1.0.0"));
        juce::Colour fillColour = juce::Colours::aliceblue;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font ("Bell MT", 13.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 63, y = 156, width = 28, height = 31;
        juce::String text (TRANS("0"));
        juce::Colour fillColour = juce::Colours::aliceblue;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font ("Bell MT", 32.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 150, y = 156, width = 28, height = 31;
        juce::String text (TRANS("12"));
        juce::Colour fillColour = juce::Colours::aliceblue;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font ("Bell MT", 32.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 454, y = 156, width = 28, height = 31;
        juce::String text (TRANS("0"));
        juce::Colour fillColour = juce::Colours::aliceblue;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font ("Bell MT", 32.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 543, y = 156, width = 28, height = 31;
        juce::String text (TRANS("12"));
        juce::Colour fillColour = juce::Colours::aliceblue;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font ("Bell MT", 32.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 313, y = 60, width = 20, height = 20;
        juce::String text (TRANS("0"));
        juce::Colour fillColour = juce::Colours::aliceblue;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font ("Bell MT", 32.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void PluginEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void PluginEditor::sliderValueChanged (juce::Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == compressionSlider.get())
    {
        //[UserSliderCode_compressionSlider] -- add your slider handling code here..
        //[/UserSliderCode_compressionSlider]
    }
    else if (sliderThatWasMoved == levelSlider.get())
    {
        //[UserSliderCode_levelSlider] -- add your slider handling code here..
        //[/UserSliderCode_levelSlider]
    }
    else if (sliderThatWasMoved == timeScaleSlider.get())
    {
        //[UserSliderCode_timeScaleSlider] -- add your slider handling code here..
        //[/UserSliderCode_timeScaleSlider]
    }
    else if (sliderThatWasMoved == kneeSlider.get())
    {
        //[UserSliderCode_kneeSlider] -- add your slider handling code here..
        //[/UserSliderCode_kneeSlider]
    }
    else if (sliderThatWasMoved == factorSlider.get())
    {
        //[UserSliderCode_factorSlider] -- add your slider handling code here..
        //[/UserSliderCode_factorSlider]
    }
    else if (sliderThatWasMoved == instrumentSlider.get())
    {
        //[UserSliderCode_instrumentSlider] -- add your slider handling code here..
        //[/UserSliderCode_instrumentSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void PluginEditor::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == bypassButton.get())
    {
        //[UserButtonCode_bypassButton] -- add your button handler code here..
        //[/UserButtonCode_bypassButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="PluginEditor" componentName=""
                 parentClasses="public AudioProcessorEditor" constructorParams="FunkyDuckAudioProcessor&amp; p,  AudioProcessorValueTreeState&amp; vts"
                 variableInitialisers="AudioProcessorEditor(&amp;p), processor(p), valueTreeState(vts)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="650" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44">
    <PATH pos="0 0 100 100" fill="solid: fff1d4d4" hasStroke="1" stroke="14.7, curved, rounded"
          strokeColour="linear: 16 424, 112 160, 0=ffedd3da, 1=fff0dbea"
          nonZeroWinding="1">s 20 380 l 20 24 l 624 24 l 624 380 x</PATH>
    <RECT pos="444 228 124 136" fill="image: _160_jpg2, 1, 430 180" hasStroke="0"/>
    <TEXT pos="36 28 170 44" fill="solid: ffffffff" hasStroke="0" text="COMPRESSION"
          fontname="Bell MT" fontsize="25.7" kerning="0.0" bold="1" italic="0"
          justification="36" typefaceStyle="Bold"/>
    <TEXT pos="436 28 152 44" fill="solid: ffffffff" hasStroke="0" text="LEVEL"
          fontname="Bell MT" fontsize="25.7" kerning="0.0" bold="1" italic="0"
          justification="36" typefaceStyle="Bold"/>
    <TEXT pos="247 28 152 44" fill="solid: ffffffff" hasStroke="0" text="SENSITIVITY"
          fontname="Bell MT" fontsize="25.7" kerning="0.0" bold="1" italic="0"
          justification="36" typefaceStyle="Bold"/>
    <TEXT pos="-36 192 220 68" fill="solid: ffffffff" hasStroke="0" text="HARD"
          fontname="Bell MT" fontsize="15.0" kerning="0.0" bold="1" italic="0"
          justification="36" typefaceStyle="Bold"/>
    <TEXT pos="18 192 220 68" fill="solid: ffffffff" hasStroke="0" text="SOFT"
          fontname="Bell MT" fontsize="15.0" kerning="0.0" bold="1" italic="0"
          justification="36" typefaceStyle="Bold"/>
    <TEXT pos="71 192 220 68" fill="solid: ffffffff" hasStroke="0" text="AUTO"
          fontname="Bell MT" fontsize="15.0" kerning="0.0" bold="1" italic="0"
          justification="36" typefaceStyle="Bold"/>
    <IMAGE pos="108 248 52 60" resource="kneeBianco_png" opacity="1.0" mode="0"/>
    <IMAGE pos="353 216 44 44" resource="kobe_cattivoBianco_png" opacity="1.0"
           mode="0"/>
    <IMAGE pos="301 216 44 44" resource="kobe_softBianco_png" opacity="1.0"
           mode="0"/>
    <IMAGE pos="253 216 44 44" resource="crestBianco_png" opacity="1.0"
           mode="0"/>
    <IMAGE pos="528 184 68 60" resource="bassWhiteLulu_png" opacity="1.0"
           mode="0"/>
    <IMAGE pos="435 192 44 44" resource="guitarBianca_png" opacity="1.0"
           mode="0"/>
    <TEXT pos="218 237 220 68" fill="solid: ffffffff" hasStroke="0" text="DETECTION"
          fontname="Bell MT" fontsize="18.1" kerning="0.0" bold="1" italic="0"
          justification="36" typefaceStyle="Bold"/>
    <TEXT pos="215 250 220 68" fill="solid: ffffffff" hasStroke="0" text="MODE"
          fontname="Bell MT" fontsize="18.1" kerning="0.0" bold="1" italic="0"
          justification="36" typefaceStyle="Bold"/>
    <IMAGE pos="260 156 20 30" resource="v_png" opacity="1.0" mode="0"/>
    <IMAGE pos="364 156 20 30" resource="u_png" opacity="1.0" mode="0"/>
    <TEXT pos="-39 370 452 18" fill="solid: fff0f8ff" hasStroke="0" text="Coded at Laboratorio di Informatica Musicale by Matteo Insarauto"
          fontname="Bell MT" fontsize="13.0" kerning="0.0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="560 18 68 18" fill="solid: fff0f8ff" hasStroke="0" text="Ver. 1.0.0"
          fontname="Bell MT" fontsize="13.0" kerning="0.0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="63 156 28 31" fill="solid: fff0f8ff" hasStroke="0" text="0"
          fontname="Bell MT" fontsize="32.0" kerning="0.0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="150 156 28 31" fill="solid: fff0f8ff" hasStroke="0" text="12"
          fontname="Bell MT" fontsize="32.0" kerning="0.0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="454 156 28 31" fill="solid: fff0f8ff" hasStroke="0" text="0"
          fontname="Bell MT" fontsize="32.0" kerning="0.0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="543 156 28 31" fill="solid: fff0f8ff" hasStroke="0" text="12"
          fontname="Bell MT" fontsize="32.0" kerning="0.0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="313 60 20 20" fill="solid: fff0f8ff" hasStroke="0" text="0"
          fontname="Bell MT" fontsize="32.0" kerning="0.0" bold="0" italic="0"
          justification="36"/>
  </BACKGROUND>
  <SLIDER name="Compression" id="65c1d47599d9e927" memberName="compressionSlider"
          virtualName="" explicitFocusOrder="0" pos="56 56 128 120" min="0.0"
          max="1.0" int="0.001" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="0.9"
          needsCallback="1"/>
  <SLIDER name="Level" id="eed5f5983ad3de98" memberName="levelSlider" virtualName=""
          explicitFocusOrder="0" pos="448 56 128 120" min="0.0" max="1.0"
          int="0.001" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="Time Scale" id="eebc96b27595be7c" memberName="timeScaleSlider"
          virtualName="" explicitFocusOrder="0" pos="267 80 112 97" min="-0.5"
          max="0.5" int="0.1" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <GENERICCOMPONENT name="Vu Meter" id="281a2800d8c71aab" memberName="vuMeter" virtualName=""
                    explicitFocusOrder="0" pos="586 63 16 96" class="Meter" params=""/>
  <TOGGLEBUTTON name="Bypass" id="176520cd410d2f70" memberName="bypassButton"
                virtualName="" explicitFocusOrder="0" pos="240 299 168 56" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <SLIDER name="Knee" id="259f5421cd85def3" memberName="kneeSlider" virtualName=""
          explicitFocusOrder="0" pos="67 186 115 40" bkgcol="ffceb3af"
          thumbcol="ffdcc38c" trackcol="ffceb3af" min="0.0" max="2.0" int="1.0"
          style="LinearHorizontal" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="Factor Mode" id="2a61a129e2978851" memberName="factorSlider"
          virtualName="" explicitFocusOrder="0" pos="265 186 115 40" bkgcol="ffceb3af"
          thumbcol="ffdcc38c" trackcol="ffceb3af" min="0.0" max="2.0" int="1.0"
          style="LinearHorizontal" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="Instrument" id="85336e73809abcfe" memberName="instrumentSlider"
          virtualName="" explicitFocusOrder="0" pos="468 186 90 40" bkgcol="ffceb3af"
          thumbcol="ffdcc38c" trackcol="ffceb3af" rotarysliderfill="ff96b5c3"
          min="0.0" max="1.0" int="1.0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: _160_jpg2, 4876, "../images/160.jpg"
static const unsigned char resource_PluginEditor__160_jpg2[] = { 255,216,255,224,0,16,74,70,73,70,0,1,1,1,0,96,0,96,0,0,255,219,0,67,0,6,4,5,6,5,4,6,6,5,6,7,7,6,8,10,16,10,10,9,9,10,20,14,15,12,16,23,
20,24,24,23,20,22,22,26,29,37,31,26,27,35,28,22,22,32,44,32,35,38,39,41,42,41,25,31,45,48,45,40,48,37,40,41,40,255,219,0,67,1,7,7,7,10,8,10,19,10,10,19,40,26,22,26,40,40,40,40,40,40,40,40,40,40,40,40,
40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,255,192,0,17,8,1,1,0,160,3,1,34,0,2,17,1,3,17,1,255,196,0,31,0,0,1,5,1,1,1,1,1,1,0,0,0,
0,0,0,0,0,1,2,3,4,5,6,7,8,9,10,11,255,196,0,181,16,0,2,1,3,3,2,4,3,5,5,4,4,0,0,1,125,1,2,3,0,4,17,5,18,33,49,65,6,19,81,97,7,34,113,20,50,129,145,161,8,35,66,177,193,21,82,209,240,36,51,98,114,130,9,10,
22,23,24,25,26,37,38,39,40,41,42,52,53,54,55,56,57,58,67,68,69,70,71,72,73,74,83,84,85,86,87,88,89,90,99,100,101,102,103,104,105,106,115,116,117,118,119,120,121,122,131,132,133,134,135,136,137,138,146,
147,148,149,150,151,152,153,154,162,163,164,165,166,167,168,169,170,178,179,180,181,182,183,184,185,186,194,195,196,197,198,199,200,201,202,210,211,212,213,214,215,216,217,218,225,226,227,228,229,230,
231,232,233,234,241,242,243,244,245,246,247,248,249,250,255,196,0,31,1,0,3,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,2,3,4,5,6,7,8,9,10,11,255,196,0,181,17,0,2,1,2,4,4,3,4,7,5,4,4,0,1,2,119,0,1,2,3,17,4,5,33,49,
6,18,65,81,7,97,113,19,34,50,129,8,20,66,145,161,177,193,9,35,51,82,240,21,98,114,209,10,22,36,52,225,37,241,23,24,25,26,38,39,40,41,42,53,54,55,56,57,58,67,68,69,70,71,72,73,74,83,84,85,86,87,88,89,90,
99,100,101,102,103,104,105,106,115,116,117,118,119,120,121,122,130,131,132,133,134,135,136,137,138,146,147,148,149,150,151,152,153,154,162,163,164,165,166,167,168,169,170,178,179,180,181,182,183,184,185,
186,194,195,196,197,198,199,200,201,202,210,211,212,213,214,215,216,217,218,226,227,228,229,230,231,232,233,234,242,243,244,245,246,247,248,249,250,255,218,0,12,3,1,0,2,17,3,17,0,63,0,247,186,40,162,160,
244,2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,
138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,
160,2,138,40,160,2,138,41,146,58,198,133,221,149,85,70,73,39,0,80,3,232,174,35,92,248,169,224,173,21,217,47,60,65,104,242,14,10,91,147,57,7,211,228,7,31,141,115,135,227,191,134,100,114,182,58,118,191,
122,59,52,22,89,7,243,96,104,212,158,120,247,61,106,138,242,79,248,94,222,29,137,135,219,116,159,17,218,3,252,83,88,128,7,254,61,91,186,47,197,239,3,234,206,177,193,175,91,193,41,254,11,165,104,49,248,
176,3,245,160,57,227,220,239,168,168,173,231,138,230,21,154,222,88,229,137,134,85,209,131,43,15,98,42,74,10,22,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,145,136,80,73,224,14,73,
166,79,44,112,66,242,204,235,28,113,169,103,118,56,10,7,36,147,233,94,45,123,169,106,255,0,24,117,73,244,205,2,121,180,223,4,91,185,142,239,80,81,182,75,210,58,164,127,236,255,0,250,207,97,65,50,149,180,
54,188,69,241,77,238,117,73,52,47,135,154,115,120,131,88,94,36,153,78,45,109,253,217,250,31,204,15,126,213,78,31,133,122,191,137,220,93,124,74,241,37,213,246,78,225,166,216,183,147,108,158,222,255,0,92,
3,238,107,210,60,47,225,205,43,194,250,84,122,118,137,105,29,181,178,117,218,62,103,63,222,99,212,159,115,90,55,115,173,181,172,179,55,68,82,126,180,165,37,20,219,216,35,77,205,164,245,102,47,135,126,
29,248,115,69,137,127,178,60,63,97,9,94,146,24,131,185,255,0,129,182,91,245,174,131,103,151,242,237,219,142,216,198,43,43,195,186,170,235,119,80,218,234,202,173,44,50,11,139,102,66,83,12,160,140,112,121,
224,158,58,117,205,117,26,148,33,162,243,7,222,95,212,86,88,124,68,49,52,253,165,61,138,173,78,120,106,190,202,162,177,150,70,122,214,22,185,224,255,0,14,235,168,203,171,104,186,125,209,97,130,239,2,239,
252,24,114,63,3,91,212,86,193,107,158,71,121,240,130,93,22,103,188,248,115,226,11,237,10,231,59,190,203,36,134,107,103,62,133,78,79,231,186,141,43,226,110,165,225,221,66,45,35,226,134,153,253,151,52,135,
108,58,164,0,181,172,223,83,252,63,231,32,87,174,85,29,103,74,176,214,244,233,172,53,107,88,174,237,38,24,120,165,92,131,254,7,220,115,71,169,28,150,214,37,168,38,142,226,20,150,9,18,72,164,80,200,232,
114,172,15,66,15,122,146,188,62,104,117,127,130,215,194,107,102,185,213,124,1,52,152,146,38,59,165,211,137,61,71,170,254,135,190,15,39,217,180,187,251,93,83,79,183,190,211,231,142,226,210,225,4,145,74,
135,33,148,210,28,101,125,30,229,170,40,162,153,65,69,20,80,1,69,20,80,1,73,75,92,191,196,191,20,39,131,252,23,168,234,237,131,52,105,178,221,15,241,202,220,32,252,249,62,192,210,19,118,87,103,9,241,14,
250,243,199,254,48,95,0,232,83,180,58,117,184,19,107,151,145,159,186,189,161,7,212,255,0,63,161,175,86,209,180,187,61,23,75,182,211,180,200,18,222,206,221,2,71,26,14,0,254,167,212,247,174,63,224,207,133,
95,195,62,16,142,77,67,47,173,106,109,246,219,249,95,239,153,31,144,167,232,15,231,159,90,239,105,147,21,213,133,115,151,15,119,174,77,119,5,175,149,21,132,18,121,69,223,37,165,144,117,199,160,7,143,115,
93,29,97,104,18,11,75,237,67,76,152,237,152,78,247,49,103,254,90,70,231,118,71,174,9,32,214,117,41,198,172,28,37,179,52,133,71,78,106,81,232,84,178,142,95,14,95,36,183,105,27,218,204,203,24,186,76,131,
11,30,48,192,255,0,9,63,196,63,26,244,43,191,248,246,147,233,92,183,136,4,7,65,212,190,214,64,128,91,72,91,63,238,156,126,57,198,61,235,106,204,204,60,55,103,246,172,253,163,236,241,121,153,235,187,3,
63,174,105,209,163,10,48,228,166,172,140,177,21,39,86,170,148,221,217,82,138,40,171,52,10,40,162,128,34,186,183,134,238,218,91,123,152,146,88,37,82,146,70,227,42,202,120,32,142,226,188,103,67,105,126,
18,248,238,61,6,230,71,111,6,235,146,150,211,229,144,228,89,206,122,198,79,96,120,253,15,247,171,218,235,151,248,145,225,88,124,101,225,11,237,38,93,171,51,175,153,109,33,255,0,150,115,47,42,223,159,7,
216,154,9,146,190,171,115,167,165,174,7,224,183,138,39,241,47,131,99,93,75,112,214,52,217,13,141,242,191,222,243,19,141,199,220,140,103,223,53,223,82,26,119,87,10,40,162,152,194,138,40,160,2,188,131,226,
128,255,0,132,155,226,159,130,252,38,126,107,72,89,181,107,196,234,10,166,118,3,245,218,195,254,5,94,189,94,75,224,209,253,169,251,64,120,218,253,198,70,157,105,111,99,31,251,59,130,177,253,85,191,58,
17,19,232,143,91,172,127,19,248,151,72,240,189,128,188,215,111,163,180,129,155,98,150,4,179,183,162,168,201,39,232,41,60,81,226,93,39,194,218,122,223,107,183,95,101,182,105,4,74,254,91,62,88,130,64,194,
130,122,3,94,51,109,241,19,194,218,231,197,153,53,141,78,234,102,211,116,219,116,181,210,148,218,74,225,166,115,153,36,218,20,237,35,133,231,29,168,28,164,150,135,178,120,87,197,26,63,138,236,30,243,66,
188,91,152,99,127,45,198,210,140,141,232,202,192,17,73,226,235,8,175,116,178,210,40,243,34,96,81,186,17,147,130,1,28,140,230,185,143,8,248,98,195,225,187,120,139,87,214,60,64,36,139,84,185,89,158,107,
194,35,88,249,109,163,36,242,223,55,95,97,197,118,182,223,99,241,62,151,25,176,187,142,123,43,140,50,207,110,225,148,133,108,156,30,71,81,138,79,200,47,167,188,82,240,223,135,34,186,190,121,239,222,230,
104,173,217,113,111,44,153,140,72,57,206,209,212,14,49,156,215,103,127,255,0,30,143,248,127,58,229,188,45,175,217,223,120,179,196,26,78,154,37,149,116,215,138,43,137,138,252,130,79,47,238,131,220,140,
96,251,214,237,214,189,164,91,106,214,218,93,206,165,103,30,163,115,196,54,175,50,137,36,227,60,46,115,216,213,244,56,239,105,92,167,73,156,117,165,184,241,15,134,198,187,30,139,46,171,167,174,175,39,
11,106,38,81,41,62,152,207,95,106,196,248,139,225,88,53,109,33,164,191,212,239,173,180,187,68,146,123,168,45,165,242,133,194,5,201,87,96,51,142,15,0,142,180,172,116,170,201,154,54,58,133,158,160,178,181,
141,212,23,34,39,49,72,97,144,56,71,29,84,227,161,228,113,86,171,204,62,17,197,101,224,223,131,73,175,106,187,44,44,110,12,154,148,196,2,66,172,141,132,85,29,79,203,176,10,244,93,34,250,223,87,209,44,
53,91,6,103,179,189,136,77,17,116,40,219,72,207,32,244,165,98,163,52,244,45,81,89,186,126,187,164,234,87,179,218,105,250,157,149,213,213,191,250,216,97,157,93,227,231,28,128,114,57,167,207,171,216,65,
172,90,233,83,93,70,154,133,212,111,44,48,19,243,58,174,55,17,244,207,243,244,160,187,158,95,165,47,252,34,191,180,38,163,98,159,37,143,137,172,133,218,40,233,246,136,243,187,244,14,127,224,66,189,126,
188,147,227,64,54,30,50,248,113,173,39,202,209,106,223,99,118,31,221,151,104,35,242,13,249,215,173,10,8,142,237,11,69,20,80,88,81,69,20,0,134,188,159,225,30,63,225,102,124,81,39,239,253,190,1,248,98,76,
87,172,87,146,248,20,255,0,103,124,121,241,246,158,220,11,216,45,175,80,127,120,5,0,159,206,67,66,34,91,163,211,53,235,248,180,173,14,255,0,81,184,0,197,105,111,37,195,3,220,42,147,253,43,147,248,41,167,
73,99,240,239,78,184,186,230,243,82,47,168,206,216,251,207,51,110,7,254,249,43,249,87,19,241,23,226,20,126,39,155,90,248,123,163,233,215,233,172,220,92,37,138,200,202,2,20,220,60,199,60,228,40,80,126,
160,230,189,174,206,218,59,59,56,45,160,93,177,67,26,198,131,209,64,192,254,84,2,105,187,163,156,248,143,6,138,190,25,184,213,60,67,105,13,212,26,82,181,228,73,48,202,249,129,72,94,58,28,147,140,28,245,
174,31,71,241,36,127,9,254,4,233,255,0,104,199,246,253,205,179,189,173,177,25,99,44,133,164,36,175,101,64,192,159,166,59,215,119,241,27,195,47,226,255,0,9,221,104,209,222,125,141,166,104,220,74,99,243,
0,216,225,176,87,35,32,226,176,172,254,22,193,113,99,172,29,103,84,159,84,241,14,169,107,37,167,246,156,232,7,144,172,48,22,56,199,8,190,160,117,201,245,166,137,168,155,189,145,209,124,10,209,164,210,
126,26,233,146,94,18,250,142,164,27,81,187,149,142,90,73,37,59,178,199,215,105,81,248,87,152,248,199,193,209,127,194,228,240,247,135,252,5,4,90,85,220,86,179,223,223,234,60,203,44,107,46,99,221,185,137,
59,128,7,111,60,23,7,222,189,103,225,191,133,117,143,15,192,242,248,135,89,58,133,217,134,43,104,226,132,20,183,130,40,198,20,42,158,172,122,150,60,213,175,15,120,81,244,207,28,120,159,196,87,23,43,113,
38,173,228,36,43,183,6,8,227,76,109,207,187,18,120,246,170,57,14,10,111,6,232,218,127,196,79,7,248,103,64,179,138,31,236,240,218,245,253,227,13,211,205,176,249,113,239,126,164,179,179,19,219,142,43,160,
253,160,245,57,172,62,24,234,22,182,73,36,183,250,171,166,157,111,20,99,47,35,74,112,84,14,231,104,106,179,226,47,135,183,90,175,196,8,252,73,105,226,75,237,54,51,107,29,165,197,181,178,0,210,162,72,100,
10,36,206,84,19,215,3,159,94,107,95,196,254,24,147,93,241,71,134,53,9,46,17,108,116,137,166,185,123,114,188,203,41,77,177,176,63,236,229,143,227,64,30,81,224,93,42,227,226,94,163,45,135,139,199,246,118,
143,225,137,34,183,139,195,11,212,226,49,229,201,59,127,24,199,64,56,224,254,62,213,169,36,66,56,237,145,21,98,84,219,177,70,0,94,152,199,210,184,255,0,27,120,15,82,185,241,17,241,63,131,53,193,161,235,
173,0,183,185,47,0,150,27,152,193,200,220,167,248,135,99,236,5,106,233,137,113,166,104,80,141,103,81,107,219,139,120,115,113,121,34,4,243,8,25,44,64,224,10,76,218,140,110,238,121,95,195,253,15,72,181,
248,177,226,77,71,70,181,183,176,209,52,59,69,211,67,39,202,175,49,59,229,102,99,212,174,48,73,62,149,55,130,175,237,124,119,241,147,86,241,37,139,25,116,189,18,205,116,235,89,122,44,146,59,49,103,30,
216,220,62,132,26,200,208,124,45,166,120,131,77,214,53,97,227,9,46,124,11,54,161,113,168,220,217,71,110,96,46,249,220,203,36,132,134,42,48,56,192,207,21,214,252,2,211,86,211,192,102,252,91,45,169,213,
238,230,212,4,42,187,68,104,205,132,80,61,54,170,145,245,164,107,27,221,35,55,246,142,227,65,240,185,92,239,26,253,182,220,127,186,245,235,66,188,151,227,121,251,111,137,126,29,232,235,201,184,214,82,
225,151,253,152,177,147,249,49,175,90,20,138,143,196,197,162,138,40,44,40,162,138,0,43,200,126,32,31,248,70,190,51,248,59,196,103,228,179,212,81,244,139,166,232,1,39,41,159,197,135,253,241,94,189,92,111,
197,175,11,31,23,120,26,255,0,79,128,127,167,32,23,22,141,208,137,147,149,193,237,158,87,254,5,65,51,87,90,29,106,219,194,183,13,58,195,24,157,134,211,32,81,184,143,76,245,169,107,140,248,75,226,193,226,
255,0,5,218,94,74,113,168,193,254,141,123,25,225,150,101,224,228,118,207,7,241,174,206,129,167,117,116,20,3,131,145,214,138,40,25,187,19,239,137,27,212,102,159,89,81,234,86,214,118,160,222,76,177,0,112,
11,119,169,91,81,27,190,68,202,250,147,138,106,113,110,215,212,228,116,103,189,180,52,40,168,160,157,38,92,161,250,131,212,84,132,128,9,61,7,53,70,109,52,236,202,122,148,219,80,70,189,91,175,210,178,164,
69,146,54,73,20,50,48,42,202,70,65,7,181,75,60,134,89,89,207,115,197,50,161,179,178,17,229,141,143,53,131,224,215,134,161,115,18,220,106,231,73,50,249,199,74,55,141,246,66,217,207,41,212,143,169,175,70,
130,40,224,134,56,96,69,142,40,212,34,34,12,5,3,128,0,236,42,74,193,241,199,136,237,188,39,225,109,67,89,188,32,173,180,100,162,103,253,100,135,133,81,245,56,160,171,40,234,121,252,109,255,0,9,63,237,
18,210,39,205,103,225,141,63,97,35,149,243,229,200,199,215,12,127,239,138,245,234,243,143,129,158,30,185,210,124,39,38,169,171,130,117,157,114,99,168,93,51,12,48,221,202,175,228,115,142,197,141,122,61,
4,195,107,190,161,69,20,80,88,81,69,20,0,81,69,20,128,241,127,22,197,55,194,239,30,183,139,172,98,119,240,198,176,235,22,175,4,99,62,68,164,241,48,30,228,254,100,143,226,21,236,86,119,80,94,218,67,117,
105,42,77,111,50,9,35,145,14,85,148,242,8,52,205,70,198,219,81,177,158,206,250,24,231,181,157,12,114,69,32,202,178,158,160,215,140,67,46,169,240,91,82,48,220,45,198,165,240,254,226,92,199,42,130,242,233,
204,199,161,245,95,231,245,224,179,63,129,249,30,225,69,83,210,117,43,45,95,79,134,251,76,185,138,234,210,101,220,146,196,217,82,63,207,106,203,213,53,107,251,91,134,137,45,147,212,48,5,184,253,43,159,
17,136,134,30,60,211,58,168,80,149,121,114,192,151,197,152,254,207,139,63,243,217,127,145,173,170,226,119,234,26,220,130,50,75,170,156,244,194,175,214,187,72,148,164,72,172,219,138,168,4,250,215,30,6,
191,214,42,212,171,24,181,23,109,252,174,117,98,232,251,10,112,167,38,155,87,252,108,75,20,141,19,134,67,131,77,183,214,255,0,180,162,153,98,137,163,84,125,140,196,231,119,210,160,188,184,75,91,105,38,
144,128,20,100,100,245,62,149,75,195,105,183,73,141,143,222,145,153,207,231,255,0,214,174,185,85,126,222,52,226,250,54,255,0,11,28,138,140,93,39,82,75,91,164,141,74,40,168,174,174,33,180,182,146,226,234,
88,225,130,53,44,242,72,193,85,64,234,73,61,5,116,153,18,51,4,82,204,66,168,25,36,156,1,94,38,242,31,139,254,62,141,98,5,188,15,160,77,185,156,143,150,254,228,116,30,234,63,150,127,188,40,214,181,221,
83,226,222,161,46,129,225,7,150,207,194,113,182,205,71,87,218,84,220,14,241,197,236,127,94,248,28,31,90,240,238,137,97,225,221,30,219,75,210,96,88,44,237,215,106,32,234,125,73,61,201,234,77,27,25,252,
126,134,144,24,233,75,69,20,26,5,20,81,64,5,20,81,64,5,20,81,64,5,69,115,4,87,86,242,65,115,26,75,12,138,85,227,117,12,172,15,80,65,234,42,90,41,1,228,58,143,195,157,107,194,90,132,218,175,194,221,65,
109,150,67,190,125,22,232,238,182,155,253,210,126,233,252,190,160,113,86,52,159,140,118,86,183,75,167,120,239,76,188,240,206,167,208,153,227,47,3,251,171,129,211,240,199,189,122,181,83,212,180,219,45,
82,213,173,181,43,75,123,187,118,235,28,241,135,83,248,26,126,164,114,219,225,35,209,245,77,47,83,182,18,232,247,182,119,80,30,119,91,72,174,63,74,179,120,183,13,14,45,30,52,147,61,92,100,98,188,223,83,
248,35,224,235,171,143,62,194,11,221,34,227,57,243,52,251,150,143,31,129,200,31,134,42,159,252,42,93,102,6,198,157,241,31,196,208,70,58,44,146,153,113,255,0,143,10,153,69,56,242,236,82,156,162,238,213,
206,175,80,210,117,73,174,127,120,77,198,122,62,224,0,252,15,74,210,211,174,215,70,211,100,26,212,208,89,195,9,202,203,52,170,170,65,231,169,63,231,53,193,31,132,250,236,199,23,159,18,188,75,34,119,88,
220,199,255,0,179,26,177,99,240,59,194,137,112,46,53,119,213,53,169,251,181,253,219,54,79,252,7,111,235,92,52,50,234,116,42,186,209,147,187,58,235,99,234,214,166,169,74,42,195,245,207,140,186,28,87,63,
96,240,181,189,223,137,117,86,225,32,176,140,148,207,187,227,167,184,6,179,33,240,71,138,188,125,115,29,223,196,139,209,99,164,171,7,143,66,177,124,3,233,230,184,60,254,100,250,109,175,82,209,180,77,51,
68,181,251,62,143,97,107,101,15,116,130,32,128,253,113,212,253,107,66,189,11,156,92,173,252,76,171,165,233,214,154,85,140,54,90,117,180,86,214,176,174,216,226,137,118,170,143,165,91,162,138,69,133,20,
81,76,2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,
2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,138,
40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,
2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,2,138,40,160,12,26,40,162,164,65,69,20,80,1,69,20,80,1,69,20,80,1,69,20,80,1,69,20,80,1,69,20,80,1,69,20,80,1,69,20,80,1,69,20,80,7,255,217,0,0};

const char* PluginEditor::_160_jpg2 = (const char*) resource_PluginEditor__160_jpg2;
const int PluginEditor::_160_jpg2Size = 4876;

// JUCER_RESOURCE: kneeBianco_png, 18981, "../images/knee bianco.png"
static const unsigned char resource_PluginEditor_kneeBianco_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,2,0,0,0,2,0,8,6,0,0,0,244,120,212,250,0,0,0,4,103,65,77,65,0,0,177,143,11,252,97,
5,0,0,10,55,105,67,67,80,115,82,71,66,32,73,69,67,54,49,57,54,54,45,50,46,49,0,0,72,137,157,150,119,84,83,217,22,135,207,189,55,189,80,146,16,138,148,208,107,104,82,2,72,13,189,72,145,46,42,49,9,16,74,
192,144,0,34,54,68,84,112,68,81,145,166,8,50,40,224,128,163,67,145,177,34,138,133,1,81,177,235,4,25,68,212,113,112,20,27,150,73,100,173,25,223,188,121,239,205,155,223,31,247,126,107,159,189,207,221,103,
239,125,214,186,0,144,252,131,5,194,76,88,9,128,12,161,88,20,225,231,197,136,141,139,103,96,7,1,12,240,0,3,108,0,224,112,179,179,66,22,248,70,2,153,2,124,216,140,108,153,19,248,23,189,186,14,32,249,251,
42,211,63,140,193,0,255,159,148,185,89,34,49,0,80,152,140,231,242,248,217,92,25,23,201,56,61,87,156,37,183,79,201,152,182,52,77,206,48,74,206,34,89,130,50,86,147,115,242,44,91,124,246,153,101,15,57,243,
50,132,60,25,203,115,206,226,101,240,228,220,39,227,141,57,18,190,140,145,96,25,23,231,8,248,185,50,190,38,99,131,116,73,134,64,198,111,228,177,25,124,78,54,0,40,146,220,46,230,115,83,100,108,45,99,146,
40,50,130,45,227,121,0,224,72,201,95,240,210,47,88,204,207,19,203,15,197,206,204,90,46,18,36,167,136,25,38,92,83,134,141,147,19,139,225,207,207,77,231,139,197,204,48,14,55,141,35,226,49,216,153,25,89,
28,225,114,0,102,207,252,89,20,121,109,25,178,34,59,216,56,57,56,48,109,45,109,190,40,212,127,93,252,155,146,247,118,150,94,132,127,238,25,68,31,248,195,246,87,126,153,13,0,176,166,101,181,217,250,135,
109,105,21,0,93,235,1,80,187,253,135,205,96,47,0,138,178,190,117,14,125,113,30,186,124,94,82,196,226,44,103,43,171,220,220,92,75,1,159,107,41,47,232,239,250,159,14,127,67,95,124,207,82,190,221,239,229,
97,120,243,147,56,146,116,49,67,94,55,110,102,122,166,68,196,200,206,226,112,249,12,230,159,135,248,31,7,254,117,30,22,17,252,36,190,136,47,148,69,68,203,166,76,32,76,150,181,91,200,19,136,5,153,66,134,
64,248,159,154,248,15,195,254,164,217,185,150,137,218,248,17,208,150,88,2,165,33,26,64,126,30,0,40,42,17,32,9,123,100,43,208,239,125,11,198,71,3,249,205,139,209,153,152,157,251,207,130,254,125,87,184,
76,254,200,22,36,127,142,99,71,68,50,184,18,81,206,236,154,252,90,2,52,32,0,69,64,3,234,64,27,232,3,19,192,4,182,192,17,184,0,15,224,3,2,65,40,136,4,113,96,49,224,130,20,144,1,68,32,23,20,128,181,160,
24,148,130,173,96,39,168,6,117,160,17,52,131,54,112,24,116,129,99,224,52,56,7,46,129,203,96,4,220,1,82,48,14,158,128,41,240,10,204,64,16,132,133,200,16,21,82,135,116,32,67,200,28,178,133,88,144,27,228,
3,5,67,17,80,28,148,8,37,67,66,72,2,21,64,235,160,82,168,28,170,134,234,161,102,232,91,232,40,116,26,186,0,13,67,183,160,81,104,18,250,21,122,7,35,48,9,166,193,90,176,17,108,5,179,96,79,56,8,142,132,23,
193,201,240,50,56,31,46,130,183,192,149,112,3,124,16,238,132,79,195,151,224,17,88,10,63,129,167,17,128,16,17,58,162,139,48,17,22,194,70,66,145,120,36,9,17,33,171,144,18,164,2,105,64,218,144,30,164,31,
185,138,72,145,167,200,91,20,6,69,69,49,80,76,148,11,202,31,21,133,226,162,150,161,86,161,54,163,170,81,7,80,157,168,62,212,85,212,40,106,10,245,17,77,70,107,162,205,209,206,232,0,116,44,58,25,157,139,
46,70,87,160,155,208,29,232,179,232,17,244,56,250,21,6,131,161,99,140,49,142,24,127,76,28,38,21,179,2,179,25,179,27,211,142,57,133,25,198,140,97,166,177,88,172,58,214,28,235,138,13,197,114,176,98,108,
49,182,10,123,16,123,18,123,5,59,142,125,131,35,226,116,112,182,56,95,92,60,78,136,43,196,85,224,90,112,39,112,87,112,19,184,25,188,18,222,16,239,140,15,197,243,240,203,241,101,248,70,124,15,126,8,63,
142,159,33,40,19,140,9,174,132,72,66,42,97,45,161,146,208,70,56,75,184,75,120,65,36,18,245,136,78,196,112,162,128,184,134,88,73,60,68,60,79,28,37,190,37,81,72,102,36,54,41,129,36,33,109,33,237,39,157,
34,221,34,189,32,147,201,70,100,15,114,60,89,76,222,66,110,38,159,33,223,39,191,81,160,42,88,42,4,40,240,20,86,43,212,40,116,42,92,81,120,166,136,87,52,84,244,84,92,172,152,175,88,161,120,68,113,72,241,
169,18,94,201,72,137,173,196,81,90,165,84,163,116,84,233,134,210,180,50,85,217,70,57,84,57,67,121,179,114,139,242,5,229,71,20,44,197,136,226,67,225,81,138,40,251,40,103,40,99,84,132,170,79,101,83,185,
212,117,212,70,234,89,234,56,13,67,51,166,5,208,82,105,165,180,111,104,131,180,41,21,138,138,157,74,180,74,158,74,141,202,113,21,41,29,161,27,209,3,232,233,244,50,250,97,250,117,250,59,85,45,85,79,85,
190,234,38,213,54,213,43,170,175,213,230,168,121,168,241,213,74,212,218,213,70,212,222,169,51,212,125,212,211,212,183,169,119,169,223,211,64,105,152,105,132,107,228,106,236,209,56,171,241,116,14,109,142,
203,28,238,156,146,57,135,231,220,214,132,53,205,52,35,52,87,104,238,211,28,208,156,214,210,214,242,211,202,210,170,210,58,163,245,84,155,174,237,161,157,170,189,67,251,132,246,164,14,85,199,77,71,160,
179,67,231,164,206,99,134,10,195,147,145,206,168,100,244,49,166,116,53,117,253,117,37,186,245,186,131,186,51,122,198,122,81,122,133,122,237,122,247,244,9,250,44,253,36,253,29,250,189,250,83,6,58,6,33,
6,5,6,173,6,183,13,241,134,44,195,20,195,93,134,253,134,175,141,140,141,98,140,54,24,117,25,61,50,86,51,14,48,206,55,110,53,190,107,66,54,113,55,89,102,210,96,114,205,20,99,202,50,77,51,221,109,122,217,
12,54,179,55,75,49,171,49,27,50,135,205,29,204,5,230,187,205,135,45,208,22,78,22,66,139,6,139,27,76,18,211,147,153,195,108,101,142,90,210,45,131,45,11,45,187,44,159,89,25,88,197,91,109,179,234,183,250,
104,109,111,157,110,221,104,125,199,134,98,19,104,83,104,211,99,243,171,173,153,45,215,182,198,246,218,92,242,92,223,185,171,231,118,207,125,110,103,110,199,183,219,99,119,211,158,106,31,98,191,193,190,
215,254,131,131,163,131,200,161,205,97,210,209,192,49,209,177,214,241,6,139,198,10,99,109,102,157,119,66,59,121,57,173,118,58,230,244,214,217,193,89,236,124,216,249,23,23,166,75,154,75,139,203,163,121,
198,243,248,243,26,231,141,185,234,185,114,92,235,93,165,110,12,183,68,183,189,110,82,119,93,119,142,123,131,251,3,15,125,15,158,71,147,199,132,167,169,103,170,231,65,207,103,94,214,94,34,175,14,175,215,
108,103,246,74,246,41,111,196,219,207,187,196,123,208,135,226,19,229,83,237,115,223,87,207,55,217,183,213,119,202,207,222,111,133,223,41,127,180,127,144,255,54,255,27,1,90,1,220,128,230,128,169,64,199,
192,149,129,125,65,164,160,5,65,213,65,15,130,205,130,69,193,61,33,112,72,96,200,246,144,187,243,13,231,11,231,119,133,130,208,128,208,237,161,247,194,140,195,150,133,125,31,142,9,15,11,175,9,127,24,97,
19,81,16,209,191,128,186,96,201,130,150,5,175,34,189,34,203,34,239,68,153,68,73,162,122,163,21,163,19,162,155,163,95,199,120,199,148,199,72,99,173,98,87,198,94,138,211,136,19,196,117,199,99,227,163,227,
155,226,167,23,250,44,220,185,112,60,193,62,161,56,225,250,34,227,69,121,139,46,44,214,88,156,190,248,248,18,197,37,156,37,71,18,209,137,49,137,45,137,239,57,161,156,6,206,244,210,128,165,181,75,167,184,
108,238,46,238,19,158,7,111,7,111,146,239,202,47,231,79,36,185,38,149,39,61,74,118,77,222,158,60,153,226,158,82,145,242,84,192,22,84,11,158,167,250,167,214,165,190,78,11,77,219,159,246,41,61,38,189,61,
3,151,145,152,113,84,72,17,166,9,251,50,181,51,243,50,135,179,204,179,138,179,164,203,156,151,237,92,54,37,10,18,53,101,67,217,139,178,187,197,52,217,207,212,128,196,68,178,94,50,154,227,150,83,147,243,
38,55,58,247,72,158,114,158,48,111,96,185,217,242,77,203,39,242,125,243,191,94,129,90,193,93,209,91,160,91,176,182,96,116,165,231,202,250,85,208,170,165,171,122,87,235,175,46,90,61,190,198,111,205,129,
181,132,181,105,107,127,40,180,46,44,47,124,185,46,102,93,79,145,86,209,154,162,177,245,126,235,91,139,21,138,69,197,55,54,184,108,168,219,136,218,40,216,56,184,105,238,166,170,77,31,75,120,37,23,75,173,
75,43,74,223,111,230,110,190,248,149,205,87,149,95,125,218,146,180,101,176,204,161,108,207,86,204,86,225,214,235,219,220,183,29,40,87,46,207,47,31,219,30,178,189,115,7,99,71,201,142,151,59,151,236,188,
80,97,87,81,183,139,176,75,178,75,90,25,92,217,93,101,80,181,181,234,125,117,74,245,72,141,87,77,123,173,102,237,166,218,215,187,121,187,175,236,241,216,211,86,167,85,87,90,247,110,175,96,239,205,122,
191,250,206,6,163,134,138,125,152,125,57,251,30,54,70,55,246,127,205,250,186,185,73,163,169,180,233,195,126,225,126,233,129,136,3,125,205,142,205,205,45,154,45,101,173,112,171,164,117,242,96,194,193,203,
223,120,127,211,221,198,108,171,111,167,183,151,30,2,135,36,135,30,127,155,248,237,245,195,65,135,123,143,176,142,180,125,103,248,93,109,7,181,163,164,19,234,92,222,57,213,149,210,37,237,142,235,30,62,
26,120,180,183,199,165,167,227,123,203,239,247,31,211,61,86,115,92,229,120,217,9,194,137,162,19,159,78,230,159,156,62,149,117,234,233,233,228,211,99,189,75,122,239,156,137,61,115,173,47,188,111,240,108,
208,217,243,231,124,207,157,233,247,236,63,121,222,245,252,177,11,206,23,142,94,100,93,236,186,228,112,169,115,192,126,160,227,7,251,31,58,6,29,6,59,135,28,135,186,47,59,93,238,25,158,55,124,226,138,251,
149,211,87,189,175,158,187,22,112,237,210,200,252,145,225,235,81,215,111,222,72,184,33,189,201,187,249,232,86,250,173,231,183,115,110,207,220,89,115,23,125,183,228,158,210,189,138,251,154,247,27,126,52,
253,177,93,234,32,61,62,234,61,58,240,96,193,131,59,99,220,177,39,63,101,255,244,126,188,232,33,249,97,197,132,206,68,243,35,219,71,199,38,125,39,47,63,94,248,120,252,73,214,147,153,167,197,63,43,255,
92,251,204,228,217,119,191,120,252,50,48,21,59,53,254,92,244,252,211,175,155,95,168,191,216,255,210,238,101,239,116,216,244,253,87,25,175,102,94,151,188,81,127,115,224,45,235,109,255,187,152,119,19,51,
185,239,177,239,43,63,152,126,232,249,24,244,241,238,167,140,79,159,126,3,247,132,243,251,199,209,59,120,0,0,0,32,99,72,82,77,0,0,122,38,0,0,128,132,0,0,250,0,0,0,128,232,0,0,117,48,0,0,234,96,0,0,58,
152,0,0,23,112,156,186,81,60,0,0,0,9,112,72,89,115,0,0,14,195,0,0,14,195,1,199,111,168,100,0,0,0,27,116,69,88,116,83,111,102,116,119,97,114,101,0,67,101,108,115,121,115,32,83,116,117,100,105,111,32,84,
111,111,108,193,167,225,124,0,0,32,0,73,68,65,84,120,156,237,221,117,184,85,117,218,198,241,239,1,164,68,176,91,84,196,238,238,174,177,176,59,199,126,237,22,219,113,236,64,29,187,6,187,29,187,49,177,91,
176,21,11,69,65,197,0,145,222,239,31,207,65,224,112,14,231,28,216,123,221,107,175,223,253,185,46,46,222,119,70,185,159,107,20,246,189,215,250,69,77,169,84,162,9,90,2,171,3,91,2,171,1,93,128,25,128,105,
154,242,55,155,25,67,128,209,192,24,224,143,218,255,236,175,218,31,191,0,63,215,254,24,247,127,15,170,253,249,123,224,27,96,84,198,243,154,53,102,58,96,35,226,179,97,85,96,126,160,53,208,130,248,119,247,
67,160,47,112,63,240,182,104,70,155,140,154,70,10,64,59,224,112,224,40,96,150,76,38,50,179,186,198,0,223,1,95,1,95,214,254,252,21,240,57,240,1,48,76,55,154,37,104,46,224,4,96,79,160,67,19,255,158,15,129,
43,129,107,137,34,108,57,48,185,2,176,3,208,131,248,135,109,102,249,52,6,248,2,120,127,130,31,125,128,254,202,161,172,144,218,1,135,1,39,211,244,15,254,186,222,7,254,15,120,181,92,67,217,148,171,175,0,
180,0,206,2,186,103,63,142,153,149,201,47,192,43,64,111,224,101,224,45,96,164,116,34,171,102,91,0,255,1,230,43,195,175,85,34,158,42,95,82,134,95,203,166,66,221,2,208,2,184,131,248,246,111,102,197,241,
23,240,6,81,8,94,170,253,217,175,14,172,49,203,17,31,212,107,86,224,215,62,15,127,209,148,170,91,0,206,193,255,64,204,82,48,156,40,2,189,128,7,129,79,180,227,88,206,204,4,156,10,28,76,44,2,175,148,195,
137,39,11,38,48,97,1,216,1,184,75,56,139,153,233,124,4,60,6,60,74,20,3,47,212,74,83,107,226,67,249,100,160,99,6,121,163,136,29,4,222,37,32,48,174,0,180,3,62,5,230,209,142,99,102,57,48,152,40,2,55,3,207,
16,239,108,173,248,186,1,23,1,93,51,206,125,23,88,1,24,155,113,110,242,198,21,128,19,128,179,197,179,152,89,254,124,7,252,15,184,135,120,50,96,197,179,24,241,158,127,67,225,12,59,3,119,10,243,147,84,83,
42,149,90,2,63,224,125,254,102,54,121,159,0,55,2,61,137,131,138,172,186,205,0,28,15,28,73,60,250,87,122,149,56,100,206,50,84,83,42,149,214,6,158,87,15,98,102,85,99,36,177,112,240,90,252,138,160,26,181,
2,14,0,254,69,44,246,203,139,249,129,175,213,67,164,164,166,84,42,245,32,26,160,153,89,115,125,6,252,23,184,158,56,123,192,242,109,93,226,113,255,82,234,65,234,177,27,112,155,122,136,148,212,148,74,165,
87,129,85,212,131,152,89,85,27,70,188,26,184,136,56,166,216,242,101,30,226,128,183,221,213,131,76,198,149,196,182,67,203,72,77,169,84,26,132,223,255,155,89,121,140,6,238,6,206,39,142,125,53,173,233,128,
147,128,35,128,54,226,89,26,243,12,176,129,122,136,148,212,148,74,165,17,232,23,128,152,89,241,188,76,156,246,246,176,122,144,4,213,0,219,17,79,100,170,101,123,119,111,96,45,245,16,41,169,41,53,241,62,
96,51,179,41,244,42,113,176,204,179,234,65,18,177,34,112,41,113,192,78,53,121,29,191,142,206,148,11,128,153,101,165,23,113,230,200,91,234,65,10,106,110,224,92,96,23,226,9,64,181,121,10,216,88,61,68,74,
92,0,204,44,75,37,226,148,193,19,129,190,226,89,138,162,5,112,40,112,38,83,126,77,111,30,92,76,220,18,104,25,113,1,48,51,133,209,196,161,66,167,1,3,180,163,84,181,14,192,237,196,117,189,213,110,95,224,
6,245,16,41,113,1,48,51,165,97,192,5,196,77,164,35,196,179,84,155,214,196,2,203,141,212,131,148,193,88,96,62,160,191,120,142,164,184,0,152,89,30,124,70,220,66,247,132,122,144,42,209,146,216,110,185,141,
122,144,50,121,18,248,135,122,136,212,184,0,152,89,158,60,2,28,2,124,163,30,36,231,142,4,122,168,135,40,163,237,128,251,212,67,164,198,5,192,204,242,230,79,224,12,226,3,110,180,120,150,60,154,3,248,24,
232,164,30,164,76,122,3,107,227,59,37,50,231,2,96,102,121,245,62,176,23,240,158,120,142,188,185,153,124,31,233,219,28,35,129,101,136,66,99,25,115,1,48,179,60,27,5,156,13,252,27,24,35,158,37,15,166,39,
118,77,180,83,15,82,6,37,96,63,188,242,95,198,5,192,204,170,193,235,192,63,241,55,197,253,129,107,212,67,148,201,113,196,14,16,19,113,1,48,179,106,49,28,56,133,88,27,48,86,60,139,202,131,64,55,245,16,
83,105,12,112,60,113,79,129,9,185,0,152,89,181,121,22,216,21,248,81,61,136,192,23,192,2,234,33,166,194,231,192,62,196,194,63,19,115,1,48,179,106,52,8,216,13,120,90,61,72,134,218,3,67,136,163,127,171,205,
80,226,176,167,30,196,147,28,203,1,23,0,51,171,86,99,136,243,239,83,89,32,56,59,240,131,122,136,102,42,1,247,2,199,0,223,138,103,177,58,148,5,160,26,111,171,50,155,82,29,128,105,106,255,239,25,106,127,
238,8,204,60,193,143,153,106,127,204,5,204,79,28,141,58,3,214,152,94,196,211,128,129,234,65,42,108,6,96,176,122,136,102,120,11,56,2,120,89,61,136,213,207,5,192,44,223,58,49,190,12,44,10,44,13,44,5,44,
8,180,210,141,149,59,63,0,91,19,187,5,138,170,61,113,72,82,222,13,0,186,3,183,226,195,125,114,205,5,192,172,58,181,5,22,39,10,193,170,192,234,192,34,164,253,251,106,56,113,163,220,109,234,65,42,232,27,
160,179,122,136,6,140,4,174,38,118,106,252,33,158,197,154,192,5,192,172,56,102,6,86,3,214,4,214,2,86,160,58,23,140,77,141,18,112,46,112,50,197,220,42,120,7,176,147,122,136,122,60,66,92,230,244,165,122,
16,107,58,23,0,179,226,154,9,88,15,216,128,216,59,62,187,118,156,76,61,6,236,76,241,190,137,30,2,92,166,30,98,2,125,136,247,252,207,169,7,177,230,115,1,48,75,67,75,96,21,226,61,249,14,192,60,218,113,50,
209,135,40,62,69,186,89,112,54,160,63,227,23,148,170,12,38,46,108,186,156,52,118,96,20,146,11,128,89,154,150,7,246,32,202,64,145,159,12,252,72,220,51,255,190,122,144,50,186,149,56,8,73,97,20,112,5,241,
225,255,171,104,6,43,19,23,0,179,180,181,34,94,17,236,15,108,65,49,119,22,252,10,108,14,188,162,30,164,76,186,2,125,137,133,160,89,122,2,56,18,248,36,227,92,171,16,23,0,51,27,103,118,96,79,224,64,98,219,
97,145,12,3,182,39,214,6,20,193,177,192,249,25,101,125,14,156,4,220,147,81,158,101,196,5,192,204,234,106,73,124,99,62,2,88,71,59,74,89,141,2,246,2,110,23,207,81,14,45,137,139,129,54,171,96,198,239,196,
41,139,151,17,91,252,172,96,92,0,204,108,114,150,37,30,251,238,66,124,232,84,187,18,113,44,109,15,245,32,101,48,45,113,23,194,170,101,254,117,199,2,55,16,91,41,7,149,249,215,182,28,113,1,48,179,166,88,
132,120,236,188,27,208,90,60,75,57,28,67,49,174,163,109,11,220,8,236,88,166,95,239,117,98,63,127,145,79,84,180,90,46,0,102,214,28,243,16,223,12,247,161,250,159,8,28,7,92,160,30,162,12,106,128,253,128,
11,129,233,166,240,215,248,142,120,207,127,11,62,190,55,25,46,0,102,54,37,22,5,254,5,108,71,245,254,94,46,17,7,235,92,169,30,164,76,230,32,158,108,236,71,211,139,192,215,68,9,186,1,24,81,153,177,44,175,
92,0,204,108,106,172,14,156,87,251,115,53,42,17,31,152,55,168,7,41,163,118,192,38,192,134,192,114,140,191,85,114,52,177,37,242,19,226,166,190,135,128,87,41,230,145,201,214,4,46,0,102,54,181,106,128,221,
137,109,105,179,137,103,153,18,37,224,0,224,58,245,32,102,89,114,1,48,179,114,233,68,156,16,119,16,213,119,160,208,24,226,146,157,123,213,131,152,101,197,5,192,204,202,109,41,226,189,122,181,189,22,24,
78,60,54,127,73,61,136,89,22,92,0,204,172,18,198,173,76,239,65,236,87,175,22,131,137,226,226,227,110,173,240,92,0,204,172,146,22,0,122,2,107,170,7,105,134,175,137,195,117,126,20,207,97,86,81,46,0,102,
86,105,45,128,67,137,221,2,109,196,179,52,213,59,192,218,192,80,245,32,102,149,226,2,96,102,89,89,22,184,11,88,80,61,72,19,61,14,116,35,182,207,153,21,142,11,128,153,101,105,58,224,90,98,197,125,53,184,
148,184,20,201,172,112,92,0,204,76,97,15,224,106,226,208,154,188,251,39,113,222,190,89,161,184,0,152,153,202,114,192,125,196,73,117,121,54,12,88,13,120,95,61,136,89,57,185,0,152,153,210,76,196,225,59,
235,136,231,104,204,55,192,10,192,207,234,65,204,202,197,5,192,204,212,90,3,215,0,123,137,231,104,76,47,224,31,196,169,129,102,85,207,5,192,204,242,226,88,224,92,98,219,96,94,157,77,92,155,107,217,235,
0,76,3,140,4,254,20,207,82,8,46,0,102,150,39,91,2,119,144,223,197,129,37,96,99,224,105,245,32,5,215,18,88,17,216,128,56,68,106,69,226,70,195,113,74,192,199,196,177,205,207,3,247,19,71,57,91,51,184,0,152,
89,222,172,69,92,85,219,73,61,72,3,6,0,75,227,245,0,229,182,16,241,129,191,1,176,46,48,125,51,254,222,65,192,229,192,21,196,113,206,214,4,46,0,102,150,71,75,0,79,2,115,170,7,105,192,3,192,214,234,33,170,
220,204,196,7,253,6,192,70,148,103,55,200,32,96,111,224,209,50,252,90,133,231,2,96,102,121,213,5,120,138,184,79,32,143,246,7,174,83,15,81,69,218,17,143,243,199,125,203,95,154,202,172,247,40,1,23,2,199,
215,254,223,214,0,23,0,51,203,179,185,129,103,136,199,195,121,243,39,113,150,193,103,234,65,114,170,5,113,252,243,184,15,252,53,128,182,25,230,95,6,28,150,97,94,213,113,1,48,179,188,155,27,120,129,120,
34,144,55,111,17,135,4,141,82,15,146,19,243,3,27,18,31,248,235,17,231,60,40,157,2,156,41,158,33,183,92,0,204,172,26,204,67,148,128,249,213,131,212,35,229,15,153,14,192,42,140,255,150,191,188,118,156,73,
140,1,86,6,222,86,15,146,71,46,0,102,86,45,58,3,47,2,243,170,7,169,99,4,241,168,251,99,245,32,25,104,69,188,187,31,247,129,191,54,177,55,63,207,222,39,78,113,244,173,142,117,184,0,152,89,53,89,136,216,
247,61,135,120,142,186,94,32,86,180,23,113,209,89,27,96,123,96,7,96,125,160,189,118,156,41,226,11,157,234,225,2,96,102,213,102,73,160,55,249,59,39,96,63,224,122,245,16,101,84,67,28,207,124,14,48,155,118,
148,169,246,46,177,96,211,38,224,2,96,102,213,104,93,224,9,226,30,129,188,248,29,88,28,248,94,61,72,25,116,37,182,56,174,35,158,163,156,22,198,59,54,38,226,2,96,102,213,106,87,224,22,242,245,103,201,61,
196,163,242,106,182,44,113,8,211,44,234,65,202,236,16,226,164,64,171,229,2,96,102,213,236,52,224,116,245,16,117,108,66,60,157,168,70,171,2,143,147,191,215,43,229,208,147,56,37,208,106,185,0,152,89,181,
187,25,216,93,61,196,4,62,34,86,202,87,219,170,243,153,129,62,228,111,129,101,185,60,75,44,98,180,90,46,0,102,86,237,218,18,219,3,87,84,15,50,129,131,129,43,213,67,52,211,61,192,118,234,33,42,232,21,96,
117,245,16,121,226,2,96,102,69,208,153,56,149,47,47,239,173,7,3,11,82,61,55,211,109,73,92,112,84,100,207,16,103,23,88,45,23,0,51,43,138,117,137,203,131,90,169,7,169,117,17,112,140,122,136,38,122,137,226,
127,59,126,24,232,166,30,34,79,92,0,204,172,72,142,34,62,120,243,96,36,113,173,241,231,234,65,26,177,42,241,120,188,232,46,4,142,85,15,145,39,46,0,102,86,52,15,16,143,180,243,224,127,192,182,234,33,26,
113,54,112,130,122,136,12,116,35,158,2,88,45,23,0,51,43,154,153,137,243,223,231,84,15,82,107,37,224,77,245,16,147,209,155,184,170,183,200,198,0,179,82,61,107,50,50,225,2,96,102,69,180,33,177,23,191,133,
122,16,224,33,242,243,68,162,174,86,192,80,226,188,255,34,187,27,216,81,61,68,222,184,0,152,89,81,93,8,28,173,30,162,86,94,159,2,76,15,252,170,30,34,3,171,0,175,171,135,200,27,23,0,51,43,170,214,192,107,
196,209,182,106,121,93,129,62,39,197,184,187,96,114,30,5,54,87,15,145,71,46,0,102,86,100,75,17,231,3,228,225,206,250,60,62,5,152,23,248,90,61,68,5,13,34,78,101,252,81,61,72,30,185,0,152,89,209,157,3,116,
87,15,65,62,215,2,180,3,254,164,152,127,30,143,33,158,186,60,166,30,36,175,92,0,204,172,232,218,17,187,2,22,20,207,81,34,238,164,127,79,60,71,93,253,128,46,234,33,202,108,20,113,91,228,61,234,65,242,204,
5,192,204,82,176,54,240,28,250,63,119,110,2,246,18,207,80,87,222,46,83,154,90,127,16,31,254,143,168,7,201,59,23,0,51,75,197,117,192,190,226,25,70,0,243,145,175,119,210,155,83,156,3,114,30,33,46,98,250,
86,61,72,53,112,1,48,179,84,204,72,28,203,59,163,120,142,127,1,167,139,103,152,208,52,196,78,128,188,92,164,212,92,37,226,233,206,133,192,227,226,89,170,138,11,128,153,165,36,15,119,5,252,68,220,94,56,
92,60,199,132,142,1,46,80,15,209,12,127,0,207,3,79,3,15,2,253,165,211,84,41,23,0,51,75,201,52,192,7,192,66,226,57,246,6,122,138,103,152,80,107,226,127,23,245,66,201,134,140,33,22,79,246,170,253,241,34,
113,217,146,77,5,23,0,51,75,77,55,226,91,163,210,7,196,25,5,170,63,127,235,179,54,241,141,58,15,103,38,0,124,76,204,211,139,248,182,63,68,58,77,1,185,0,152,89,138,158,6,54,16,207,176,38,240,146,120,134,
186,14,6,46,23,101,255,68,124,208,247,34,238,113,240,66,190,10,115,1,48,179,20,45,79,156,202,167,252,115,232,6,244,187,18,234,115,56,208,131,202,95,164,52,12,120,133,241,143,245,223,33,95,79,68,10,207,
5,192,204,82,245,48,218,51,226,135,2,115,212,254,156,55,59,1,215,0,29,203,248,107,142,33,142,101,30,247,129,255,10,126,143,47,229,2,96,102,169,90,142,248,64,82,254,89,180,23,113,56,80,30,205,77,188,14,
152,154,227,139,191,96,252,123,252,231,72,227,230,193,170,225,2,96,102,41,123,16,237,45,125,47,0,235,8,243,155,98,89,224,48,96,59,160,67,35,127,237,207,192,179,140,255,208,255,186,162,147,217,84,113,1,
48,179,148,45,11,188,141,238,207,163,18,177,245,174,159,40,191,57,90,1,43,2,43,19,175,46,102,37,206,220,255,5,248,148,248,223,241,67,96,172,106,64,107,30,23,0,51,75,221,163,192,166,194,252,127,3,167,10,
243,45,81,46,0,102,150,186,13,136,71,214,42,95,2,11,8,243,45,81,46,0,102,102,113,93,240,82,194,252,101,201,223,53,193,86,112,46,0,102,102,176,15,112,189,48,223,175,1,44,115,46,0,102,102,208,6,248,6,152,
77,148,255,33,176,132,40,219,18,229,2,96,102,22,206,4,78,18,230,47,66,172,166,55,203,132,11,128,153,89,152,159,216,142,167,250,179,233,68,224,28,81,182,37,200,5,192,204,108,188,231,137,91,241,20,222,4,
86,18,101,91,130,92,0,204,204,198,219,3,221,209,188,37,96,46,224,7,81,190,37,198,5,192,204,108,188,105,129,1,148,247,18,156,230,216,29,184,85,148,109,137,113,1,48,51,155,216,245,196,182,64,133,155,129,
61,69,217,150,24,23,0,51,179,137,173,79,92,100,163,48,128,120,13,96,86,113,46,0,102,102,19,107,9,252,8,204,44,202,95,12,248,88,148,109,9,113,1,48,51,155,212,127,129,127,138,178,15,7,254,35,202,182,132,
184,0,152,153,77,106,11,224,33,81,246,67,192,150,162,108,75,136,11,128,153,217,164,218,2,131,128,233,4,217,127,0,51,0,99,5,217,150,16,23,0,51,179,250,221,13,108,47,202,94,130,184,31,192,172,98,92,0,204,
204,234,183,63,112,141,40,123,111,160,167,40,219,18,225,2,96,102,86,191,249,128,175,68,217,87,3,255,39,202,182,68,184,0,152,153,53,172,31,208,69,144,251,14,176,188,32,215,18,226,2,96,102,214,176,107,136,
87,1,89,27,5,76,15,12,19,100,91,34,92,0,204,204,26,182,3,112,151,40,123,13,224,101,81,182,37,192,5,192,204,172,97,179,17,167,2,42,28,9,92,34,202,182,4,184,0,152,153,77,222,215,192,188,130,220,235,208,
188,126,176,68,184,0,152,153,77,158,234,60,128,151,128,53,5,185,205,213,146,120,93,177,37,176,26,48,63,48,35,208,74,52,207,104,96,48,177,131,227,101,224,193,218,159,199,136,230,201,45,23,0,51,179,201,
59,22,56,95,144,251,11,186,11,137,154,162,29,113,111,193,209,228,123,78,128,159,128,139,136,59,22,254,18,207,146,27,46,0,102,102,147,183,54,240,188,40,123,86,226,195,43,111,118,0,122,80,125,87,23,127,
71,172,173,184,87,61,72,30,184,0,152,153,77,94,7,224,55,226,81,119,214,214,1,94,16,228,54,164,6,56,13,56,149,234,253,51,188,68,60,209,57,145,196,239,91,112,1,48,51,107,220,23,192,2,130,220,3,209,29,71,
92,87,11,224,14,226,219,127,17,220,5,236,66,194,37,192,5,192,204,172,113,15,3,155,11,114,255,67,188,103,207,131,115,128,238,234,33,202,236,44,224,100,245,16,42,46,0,102,102,141,187,0,56,70,144,251,48,
208,77,144,91,151,242,64,164,74,42,17,59,60,238,83,15,162,224,2,96,102,214,184,125,137,125,249,89,203,195,157,0,237,128,79,129,121,196,115,84,202,247,192,66,36,120,236,178,11,128,153,89,227,214,0,122,
11,114,7,17,167,17,42,157,0,156,45,158,161,210,142,71,179,213,83,202,5,192,204,172,113,51,1,63,11,114,75,64,91,96,164,32,27,98,231,195,15,192,44,162,252,172,12,36,182,52,38,117,88,144,11,128,153,89,211,
12,5,166,21,228,206,79,28,71,172,160,60,3,33,107,107,18,167,47,38,195,5,192,204,172,105,62,3,22,20,228,42,111,5,236,65,28,156,147,130,11,137,83,31,147,225,2,96,102,214,52,207,17,7,243,100,109,39,116,43,
240,95,3,86,22,101,103,237,21,96,117,245,16,89,114,1,48,51,107,154,91,129,93,5,185,71,0,151,10,114,33,22,33,22,253,253,255,56,3,129,217,213,67,100,201,5,192,204,172,105,206,71,243,136,248,52,224,12,65,
46,192,8,160,181,40,59,107,35,136,5,151,201,112,1,48,51,107,154,35,128,139,5,185,23,161,57,132,8,92,0,10,205,5,192,204,172,105,254,9,252,87,144,123,29,176,191,32,23,226,177,248,172,162,236,172,249,21,
64,150,217,162,92,51,179,41,177,45,154,107,100,239,34,22,2,42,188,10,172,34,202,206,218,203,196,142,139,100,184,0,152,153,53,205,70,192,147,130,220,39,128,77,4,185,16,91,227,142,22,101,103,237,124,226,
68,192,100,184,0,152,153,53,205,42,196,55,226,172,41,183,167,173,9,188,40,202,206,218,234,196,255,214,201,112,1,48,51,107,154,197,128,15,5,185,31,2,75,8,114,33,142,2,30,64,241,215,1,252,72,28,5,60,86,
61,72,150,92,0,204,204,154,166,51,240,141,32,247,51,96,97,65,238,56,199,1,231,9,243,179,112,12,177,219,34,41,46,0,102,102,77,51,55,208,95,144,251,57,113,93,173,74,91,226,58,224,206,194,25,42,233,27,162,
96,141,80,15,146,53,23,0,51,179,166,81,21,128,47,208,220,65,48,161,109,129,123,40,222,159,219,37,96,27,224,1,245,32,10,46,0,102,102,77,51,23,240,157,32,183,31,208,85,144,91,215,153,192,73,234,33,202,236,
12,226,164,197,36,185,0,152,153,53,141,170,0,124,9,44,32,200,173,171,5,112,27,186,51,9,202,237,14,226,110,7,213,103,160,156,11,128,153,89,211,168,10,192,87,64,23,65,110,125,106,136,69,129,231,80,189,127,
134,151,136,61,255,39,146,216,170,255,186,92,0,204,204,154,70,85,0,190,6,230,23,228,78,206,54,196,189,8,213,182,48,240,27,226,78,135,36,223,249,215,229,2,96,102,214,52,11,17,171,225,179,150,151,87,0,117,
181,5,14,5,142,34,255,103,232,255,72,156,106,120,57,9,174,246,111,136,11,128,153,89,211,44,15,188,37,200,237,3,44,45,200,109,170,22,192,170,192,150,192,106,196,130,197,78,232,110,214,27,14,252,78,236,
158,120,25,120,16,120,141,196,31,247,215,71,89,0,204,148,254,36,78,56,251,145,248,195,225,81,226,15,139,209,202,161,44,215,214,6,158,23,228,42,143,2,182,2,115,1,48,27,111,16,177,56,232,74,224,47,241,44,
150,63,155,1,143,8,114,159,2,54,22,228,90,193,185,0,152,77,106,0,240,127,192,67,234,65,44,87,118,4,238,20,228,254,143,56,136,199,172,172,92,0,204,234,87,34,182,58,157,10,140,17,207,98,249,176,47,112,157,
32,247,102,96,79,65,174,21,156,11,128,217,228,221,66,252,225,235,223,39,166,186,20,231,10,224,16,65,174,21,156,11,128,89,227,206,33,14,13,177,180,157,15,28,43,200,61,15,232,46,200,181,130,115,1,48,107,
154,110,192,195,234,33,76,234,6,96,111,65,110,119,138,127,29,175,9,184,0,152,53,205,183,192,162,192,48,245,32,38,243,32,81,4,179,182,47,81,62,204,202,202,5,192,172,233,78,36,94,7,88,154,122,3,107,8,114,
183,1,238,23,228,90,193,185,0,152,53,221,215,196,165,44,254,61,147,166,143,129,69,4,185,107,17,229,195,172,172,92,0,204,154,103,77,224,37,245,16,38,49,8,152,69,144,187,56,240,145,32,215,10,206,5,192,172,
121,206,7,142,87,15,97,153,171,1,70,2,173,4,217,115,16,71,86,155,149,149,11,128,89,243,60,140,102,33,152,105,205,0,12,22,228,150,128,54,192,40,65,182,21,156,11,128,89,243,244,35,110,59,179,180,116,5,62,
23,228,254,14,76,47,200,181,4,184,0,152,53,207,40,226,27,153,127,223,164,101,101,226,214,200,172,125,69,44,60,53,43,187,154,82,169,52,2,104,173,30,196,172,138,116,2,254,80,15,97,153,218,148,184,50,58,
107,111,2,43,9,114,45,1,53,165,82,105,32,48,171,122,16,179,42,50,31,240,141,122,8,203,212,238,196,165,60,89,123,2,216,68,144,107,9,168,41,149,74,175,2,171,168,7,49,171,34,203,1,239,170,135,176,76,29,9,
244,16,228,222,74,148,15,179,178,171,41,149,74,23,2,71,171,7,49,171,34,27,0,207,168,135,176,76,157,9,156,36,200,189,20,56,66,144,107,9,168,41,149,74,107,2,47,170,7,49,171,34,59,0,247,168,135,176,76,93,
5,28,40,200,61,21,248,183,32,215,18,80,83,42,149,90,2,3,240,58,0,179,166,58,0,184,86,61,132,101,234,46,162,248,101,237,16,224,10,65,174,37,160,166,118,23,224,113,248,186,73,179,166,242,165,64,233,121,
6,88,79,144,187,19,81,62,204,202,110,92,1,104,11,124,10,116,214,142,99,86,21,46,32,74,179,165,227,61,96,105,65,238,134,64,47,65,174,37,160,102,130,115,128,182,37,222,107,214,232,198,49,171,10,55,16,119,
180,91,58,250,3,115,11,114,151,7,222,17,228,90,2,106,234,28,4,168,90,233,106,86,77,254,71,20,102,75,67,13,48,28,205,129,105,157,137,242,97,86,118,117,11,64,11,224,54,226,189,147,153,213,239,121,96,93,
245,16,150,153,153,129,159,68,217,211,1,67,69,217,86,112,117,11,0,68,9,56,131,88,232,228,215,1,102,147,234,131,230,125,176,105,44,1,244,21,228,254,5,180,23,228,90,34,234,43,0,227,108,3,92,140,23,6,154,
213,245,29,48,143,122,8,203,204,134,192,83,130,92,95,4,100,21,53,185,2,0,177,59,224,80,224,40,96,246,76,38,50,203,191,225,64,59,245,16,150,153,61,128,155,4,185,175,0,171,11,114,45,17,141,21,128,113,90,
0,171,2,91,2,171,17,119,99,119,34,10,130,89,138,124,35,96,58,142,7,206,21,228,222,7,108,39,200,181,68,52,181,0,152,229,213,159,104,222,147,46,8,124,33,200,181,236,93,2,28,46,200,189,156,120,2,107,86,17,
46,0,86,237,190,6,230,21,228,174,78,60,162,181,226,83,29,3,124,18,112,182,32,215,18,225,2,96,213,238,77,96,5,65,238,214,192,3,130,92,203,222,139,192,154,130,220,189,129,158,130,92,75,132,11,128,85,187,
71,129,77,5,185,7,2,215,8,114,45,123,159,19,235,158,178,182,9,240,132,32,215,18,225,2,96,213,174,39,176,151,32,215,215,180,166,99,8,208,65,144,187,12,240,190,32,215,18,225,2,96,213,238,124,224,88,65,238,
101,192,97,130,92,203,86,7,162,0,40,204,14,12,20,101,91,2,92,0,172,218,29,75,148,128,172,221,133,143,204,78,193,130,192,103,130,220,209,196,54,235,49,130,108,75,132,11,128,85,187,61,129,27,5,185,207,161,
185,31,222,178,181,22,240,130,32,119,0,48,151,32,215,18,226,2,96,213,110,19,224,49,65,238,135,196,25,241,86,108,59,2,119,10,114,223,70,179,187,197,18,226,2,96,213,110,121,224,45,65,238,79,192,172,130,
92,203,214,17,196,157,40,89,123,4,216,66,144,107,9,113,1,176,106,215,25,248,70,144,59,150,184,31,222,239,104,139,237,28,160,187,32,247,122,96,63,65,174,37,196,5,192,170,93,91,226,218,84,133,57,129,31,
68,217,150,141,155,136,203,128,178,118,6,112,154,32,215,18,226,2,96,69,240,27,113,57,79,214,86,68,243,250,193,178,243,36,176,145,32,247,96,224,74,65,174,37,196,5,192,138,224,35,96,81,65,238,86,192,131,
130,92,203,78,95,52,139,61,125,212,180,85,156,11,128,21,65,47,96,125,65,238,65,192,85,130,92,203,206,79,192,204,130,220,85,128,215,5,185,150,16,23,0,43,130,155,129,221,5,185,103,1,39,11,114,45,27,173,
129,225,64,141,32,123,94,224,91,65,174,37,196,5,192,138,224,60,224,56,65,110,79,226,198,54,43,166,121,208,124,8,151,128,118,192,8,65,182,37,196,5,192,138,64,181,87,251,41,96,99,65,174,101,99,37,52,143,
225,7,3,51,9,114,45,49,46,0,86,4,59,16,103,243,103,205,167,1,22,219,150,104,22,226,249,223,43,203,132,11,128,21,193,26,64,111,65,238,175,192,140,130,92,203,198,129,104,22,121,246,2,54,20,228,90,98,92,
0,172,8,186,0,253,68,217,29,128,63,69,217,86,89,167,163,57,140,231,22,52,135,15,89,98,92,0,172,8,218,2,195,208,172,214,94,16,248,66,144,107,149,119,13,176,191,32,247,124,224,120,65,174,37,198,5,192,138,
226,23,52,143,227,215,65,115,93,172,85,222,67,104,46,228,57,10,205,162,86,75,140,11,128,21,133,234,196,182,221,128,219,4,185,86,121,111,16,199,61,103,109,23,224,14,65,174,37,198,5,192,138,226,113,224,
31,130,220,147,128,179,5,185,86,121,223,1,115,9,114,215,193,79,149,44,3,46,0,86,20,170,247,181,215,2,7,8,114,173,178,106,136,131,120,166,17,100,47,12,124,38,200,181,196,184,0,88,81,156,4,156,41,200,245,
97,64,197,52,11,48,72,148,221,17,24,34,202,182,132,184,0,88,81,236,78,220,9,144,181,207,136,111,108,86,44,75,1,239,11,114,135,1,211,10,114,45,65,46,0,86,20,107,161,121,111,58,2,104,15,140,21,100,91,229,
108,4,60,41,200,237,7,116,21,228,90,130,92,0,172,40,230,3,190,18,101,207,5,12,16,101,91,101,236,1,220,36,200,125,9,88,83,144,107,9,114,1,176,162,152,6,248,11,104,41,200,94,29,120,69,144,107,149,115,12,
112,129,32,247,94,96,123,65,174,37,200,5,192,138,164,63,48,183,32,215,251,182,139,231,34,226,64,158,172,93,6,28,38,200,181,4,185,0,88,145,188,12,172,38,200,61,17,56,71,144,107,149,115,43,176,171,32,247,
100,224,44,65,174,37,200,5,192,138,228,14,96,39,65,238,53,196,205,113,86,28,189,128,245,5,185,251,2,55,8,114,45,65,46,0,86,36,231,162,185,68,197,103,1,20,79,31,96,73,65,110,55,224,97,65,174,37,200,5,192,
138,228,0,224,106,65,238,23,196,173,128,86,28,3,129,89,5,185,43,1,111,10,114,45,65,46,0,86,36,27,0,79,11,114,71,19,135,183,140,20,100,91,249,181,34,206,119,104,33,200,238,76,44,102,53,171,56,23,0,43,146,
249,129,47,69,217,62,191,189,56,230,4,190,23,228,150,128,118,68,249,48,171,56,23,0,43,146,150,196,81,170,173,5,217,91,0,143,8,114,173,252,150,5,222,17,228,14,6,102,18,228,90,162,92,0,172,104,62,67,243,
62,254,40,224,98,65,174,149,223,38,192,99,130,220,143,129,197,4,185,150,40,23,0,43,154,199,129,127,8,114,175,2,14,18,228,90,249,237,5,244,20,228,62,7,172,39,200,181,68,185,0,88,209,92,14,28,44,200,125,
134,88,132,104,213,175,59,154,131,157,238,4,118,22,228,90,162,92,0,172,104,142,4,122,8,114,251,19,43,184,173,250,93,12,28,33,200,189,132,248,247,215,44,19,46,0,86,52,91,0,15,9,114,75,64,7,98,17,162,85,
183,219,209,124,19,63,129,56,204,202,44,19,46,0,86,52,139,1,31,138,178,151,2,250,138,178,173,124,158,5,214,21,228,238,141,102,237,129,37,202,5,192,138,166,45,240,39,154,67,92,182,3,238,19,228,90,121,125,
0,44,46,200,221,12,205,238,3,75,148,11,128,21,81,63,160,139,32,215,55,185,21,195,207,104,246,227,175,0,188,45,200,181,68,185,0,88,17,61,10,108,42,200,189,3,216,69,144,107,229,211,26,24,14,212,8,178,231,
2,6,8,114,45,81,46,0,86,68,23,17,7,243,100,173,47,177,14,192,170,215,220,104,206,226,47,1,109,128,81,130,108,75,148,11,128,21,209,126,192,181,130,220,81,196,78,0,95,10,84,189,86,64,115,27,223,207,192,
44,130,92,75,152,11,128,21,209,26,64,111,81,246,18,232,118,33,216,212,219,12,205,157,14,31,0,75,10,114,45,97,46,0,86,68,51,17,223,168,20,118,2,238,18,101,219,212,219,7,184,94,144,235,147,36,45,115,46,
0,86,84,131,208,60,82,61,19,56,69,144,107,229,113,34,154,157,28,183,1,187,9,114,45,97,46,0,86,84,47,2,107,10,114,31,0,182,22,228,90,121,92,10,28,38,200,237,1,28,45,200,181,132,185,0,88,81,93,3,236,47,
200,253,2,205,117,196,86,30,119,1,59,8,114,143,7,206,23,228,90,194,92,0,172,168,142,32,46,117,201,218,88,160,35,113,26,161,85,159,231,128,117,4,185,123,1,55,9,114,45,97,46,0,86,84,235,3,189,68,217,43,
161,217,74,102,83,239,99,96,17,65,238,38,192,19,130,92,75,152,11,128,21,149,114,39,192,129,196,43,8,171,62,191,2,211,11,114,151,1,222,23,228,90,194,92,0,172,200,190,7,230,20,228,94,135,102,253,129,77,
157,54,192,95,104,142,1,158,3,248,81,144,107,9,115,1,176,34,123,140,120,180,154,181,119,128,229,5,185,54,117,230,5,190,22,228,142,37,202,199,104,65,182,37,204,5,192,138,236,92,98,117,117,214,70,18,11,
1,71,8,178,109,202,173,4,188,46,200,29,8,204,46,200,181,196,185,0,88,145,237,66,28,176,162,176,34,240,150,40,219,166,76,55,224,65,65,110,31,96,105,65,174,37,206,5,192,138,108,113,226,140,117,5,47,4,172,
62,170,75,164,158,6,54,18,228,90,226,92,0,172,200,90,1,67,128,182,130,108,47,4,172,62,167,0,103,8,114,111,1,246,16,228,90,226,92,0,172,232,222,1,150,21,229,122,33,96,117,185,28,56,88,144,123,33,112,172,
32,215,18,231,2,96,69,119,3,176,183,32,215,11,1,171,207,221,192,246,130,220,99,137,18,96,150,41,23,0,43,186,255,3,174,20,101,251,68,192,234,242,2,176,150,32,119,15,226,53,128,89,166,92,0,172,232,150,71,
183,26,255,72,224,18,81,182,53,223,39,192,194,130,220,141,136,133,128,102,153,114,1,176,162,107,13,252,65,28,180,146,181,123,209,60,82,182,41,51,24,152,65,144,187,20,208,87,144,107,137,115,1,176,20,188,
78,60,142,207,154,15,120,169,30,173,129,225,104,142,1,158,13,24,36,200,181,196,185,0,88,10,84,171,187,1,186,2,253,68,217,214,116,115,3,253,5,185,99,137,242,49,70,144,109,137,115,1,176,20,236,9,220,40,
202,222,11,223,243,94,13,150,3,222,22,228,14,34,158,0,152,101,206,5,192,82,176,24,240,161,40,219,7,2,85,135,127,0,143,11,114,63,0,150,20,228,154,185,0,88,18,90,16,247,188,119,20,100,127,68,28,73,108,249,
182,7,154,39,53,207,2,235,11,114,205,92,0,44,25,207,1,235,8,114,75,192,44,192,47,130,108,107,186,163,128,139,4,185,119,1,59,9,114,205,92,0,44,25,255,6,78,22,101,119,3,30,22,101,91,211,156,7,28,39,200,
189,12,56,76,144,107,230,2,96,201,80,189,227,133,248,112,233,46,202,182,166,233,73,44,216,204,218,41,192,153,130,92,51,23,0,75,70,71,226,160,151,150,130,236,151,129,53,4,185,214,116,143,2,155,10,114,15,
64,115,5,177,153,11,128,37,229,93,96,25,65,238,8,96,122,226,160,25,203,167,55,129,21,4,185,91,3,15,8,114,205,92,0,44,41,255,1,14,21,101,175,14,188,34,202,182,198,125,3,116,22,228,174,6,188,42,200,53,115,
1,176,164,236,8,220,41,202,62,14,184,64,148,109,141,251,11,104,43,200,245,73,145,38,227,2,96,41,153,19,248,94,148,253,32,176,149,40,219,38,175,19,240,155,40,187,35,48,68,148,109,137,115,1,176,212,244,
3,186,8,114,125,49,80,126,117,5,62,23,228,14,7,218,9,114,205,0,23,0,75,207,205,192,238,162,236,185,209,61,129,176,134,173,70,236,212,200,218,183,192,188,130,92,51,192,5,192,210,115,0,112,181,40,123,75,
224,33,81,182,53,108,107,224,127,130,220,55,209,92,83,109,6,184,0,88,122,150,0,250,138,178,255,5,156,46,202,182,134,169,74,225,163,192,230,130,92,51,192,5,192,210,83,3,252,12,204,40,200,126,4,216,66,144,
107,147,119,10,112,134,32,183,39,176,183,32,215,12,112,1,176,52,61,6,108,34,200,253,17,152,67,144,107,147,167,58,31,194,71,68,155,148,11,128,165,232,100,226,114,32,133,57,136,34,96,249,113,39,113,70,68,
214,142,65,115,3,161,25,224,2,96,105,218,132,120,10,160,176,62,113,7,188,229,199,179,192,186,130,220,221,129,91,5,185,102,128,11,128,165,105,22,96,30,177,229,20,0,0,31,37,73,68,65,84,144,40,251,48,226,
10,88,203,143,15,128,197,5,185,27,3,79,9,114,205,0,23,0,75,87,127,98,95,126,214,174,6,254,79,144,107,13,27,68,148,194,172,45,11,188,39,200,53,3,92,0,44,93,15,2,221,4,185,189,129,181,4,185,86,191,150,192,
72,160,133,32,123,46,96,128,32,215,12,112,1,176,116,157,74,236,203,207,218,175,104,182,32,90,253,102,7,126,16,228,150,128,54,192,40,65,182,25,224,2,96,233,218,10,184,95,148,237,157,0,249,177,36,208,71,
144,235,34,104,114,46,0,150,170,133,128,79,69,217,107,17,175,2,76,111,3,224,105,65,238,39,192,162,130,92,179,191,185,0,88,170,90,2,67,209,220,1,255,79,224,70,65,174,77,106,23,224,54,65,238,139,192,218,
130,92,179,191,185,0,88,202,222,7,150,18,228,158,73,28,63,107,122,71,0,23,11,114,239,5,182,23,228,154,253,205,5,192,82,118,7,176,147,32,247,78,96,103,65,174,77,234,44,224,68,65,238,149,192,193,130,92,
179,191,185,0,88,202,84,151,192,248,26,216,252,184,14,216,87,144,235,155,33,77,206,5,192,82,166,122,255,235,21,224,249,161,58,15,226,32,224,42,65,174,217,223,92,0,44,101,43,1,175,139,178,167,7,126,23,
101,219,120,175,0,171,10,114,183,39,214,1,152,201,184,0,88,202,102,6,126,18,101,47,73,156,65,111,90,253,128,46,130,92,111,5,53,57,23,0,75,221,175,196,183,241,172,109,2,60,33,200,181,137,13,5,166,21,228,
46,130,238,28,10,51,192,5,192,236,29,226,82,150,172,237,7,92,47,200,181,241,218,3,127,138,178,103,36,202,167,153,140,11,128,165,238,127,192,214,130,220,51,128,211,4,185,54,222,188,192,215,130,220,81,196,
61,0,254,195,215,164,92,0,44,117,87,162,185,158,247,191,192,62,130,92,27,111,5,98,75,102,214,190,71,115,21,181,217,68,92,0,44,117,170,179,0,158,2,54,22,228,218,120,27,163,89,135,241,30,154,215,78,102,
19,113,1,176,212,237,75,28,6,147,53,127,8,232,237,6,220,34,200,117,249,179,92,112,1,176,212,109,6,60,34,200,253,1,152,83,144,107,227,169,238,1,184,29,216,85,144,107,54,17,23,0,75,221,114,192,219,130,220,
209,196,66,176,177,130,108,11,255,6,78,22,228,254,7,56,92,144,107,54,17,23,0,75,221,28,192,0,81,246,204,192,47,162,108,139,163,120,15,20,228,158,134,102,221,137,217,68,92,0,44,117,45,129,17,181,63,103,
109,49,224,99,65,174,133,123,128,237,4,185,7,19,187,79,204,164,92,0,204,226,125,252,236,130,220,117,128,23,4,185,22,158,35,254,25,100,109,39,224,46,65,174,217,68,92,0,204,224,93,96,25,65,238,214,192,3,
130,92,11,125,129,37,4,185,235,3,207,10,114,205,38,226,2,96,6,143,17,103,243,103,109,15,52,219,208,44,168,158,252,44,13,244,17,228,154,77,196,5,192,12,110,4,246,20,228,30,2,92,33,200,53,168,33,214,126,
76,35,200,158,155,56,13,208,76,202,5,192,44,182,101,29,42,200,61,1,56,87,144,107,113,3,164,234,50,158,182,68,249,48,147,114,1,48,131,179,128,19,5,185,103,3,39,9,114,13,186,2,159,11,114,255,0,58,9,114,
205,38,225,2,96,6,221,129,115,4,185,151,163,121,242,96,176,10,240,170,32,247,43,160,139,32,215,108,18,46,0,102,177,47,251,114,65,238,77,192,94,130,92,131,205,129,135,5,185,111,2,43,9,114,205,38,225,2,
96,6,187,3,55,11,114,239,7,182,17,228,90,20,175,158,130,220,199,129,77,5,185,102,147,112,1,48,131,173,136,15,227,172,245,2,54,20,228,26,28,3,92,32,200,189,133,216,254,105,38,231,2,96,22,7,179,244,18,228,
190,1,172,44,200,181,88,243,209,93,144,123,49,112,148,32,215,108,18,46,0,102,176,34,241,97,156,181,143,137,251,0,44,123,215,1,251,10,114,79,38,118,157,152,201,185,0,152,193,34,104,46,229,249,158,56,20,
198,178,119,63,241,234,39,107,7,2,215,8,114,205,38,225,2,96,6,115,162,57,153,205,123,194,117,122,3,107,8,114,183,3,238,19,228,154,77,194,5,192,12,58,2,191,11,114,135,3,237,4,185,6,31,1,139,10,114,215,
193,55,64,90,78,184,0,152,65,123,224,79,65,238,40,160,181,32,215,224,39,96,102,65,238,18,192,135,130,92,179,73,184,0,152,65,27,226,219,120,214,198,2,45,5,185,169,107,1,140,68,243,191,253,236,192,64,65,
174,217,36,92,0,204,160,21,241,109,92,161,5,224,223,132,217,154,153,120,2,144,181,18,241,196,103,180,32,219,108,18,46,0,102,241,33,60,70,148,221,74,152,157,42,213,174,143,95,129,25,5,185,102,245,114,1,
48,11,99,137,59,226,179,214,134,120,28,109,217,89,131,216,5,144,181,207,129,133,4,185,102,245,114,1,48,11,163,209,188,19,110,15,252,37,200,77,153,234,232,231,87,129,213,4,185,102,245,114,1,48,11,35,208,
172,200,159,14,24,42,200,77,217,190,196,73,128,89,123,24,232,38,200,53,171,151,11,128,89,24,134,102,79,254,244,104,206,32,72,89,119,226,46,128,172,245,4,246,22,228,154,213,203,5,192,44,12,1,58,8,114,103,
2,6,11,114,83,118,1,113,27,160,34,247,56,65,174,89,189,92,0,204,194,111,104,142,229,157,21,205,150,180,148,245,4,246,18,228,118,7,206,19,228,154,213,203,5,192,44,252,130,102,139,214,156,192,15,130,220,
148,61,12,108,46,200,221,15,184,94,144,107,86,47,23,0,179,240,59,113,39,64,214,92,0,178,247,42,176,138,32,119,107,224,1,65,174,89,189,92,0,204,194,112,98,79,126,214,102,38,158,62,88,118,62,7,186,10,114,
215,0,94,22,228,154,213,203,5,192,44,140,33,78,4,204,90,71,98,1,162,101,103,48,48,131,32,119,81,224,19,65,174,89,189,92,0,204,180,119,1,180,37,206,32,176,108,212,16,135,62,41,202,158,159,246,88,174,184,
0,152,233,174,3,6,95,6,148,181,142,104,206,93,24,75,28,52,229,123,31,44,55,92,0,204,226,48,158,95,5,185,163,208,156,62,152,178,121,128,111,5,185,191,161,121,237,96,214,32,23,0,179,216,139,175,184,163,
253,79,52,135,15,165,108,9,160,175,32,247,59,162,124,152,229,134,11,128,25,204,13,244,23,228,250,122,216,236,173,14,188,36,200,253,132,88,4,104,150,27,46,0,102,208,5,232,39,200,29,8,204,46,200,77,217,
166,192,163,130,220,55,129,149,4,185,102,13,114,1,48,131,133,209,108,207,234,15,116,22,228,166,108,7,224,46,65,238,243,192,186,130,92,179,6,185,0,152,193,82,192,251,130,220,126,104,14,164,73,217,238,192,
205,130,92,95,5,108,185,227,2,96,22,39,180,245,22,228,126,12,44,38,200,77,217,190,192,117,130,220,59,128,93,4,185,102,13,114,1,48,131,77,128,199,4,185,239,1,203,10,114,83,118,16,112,133,32,247,58,96,127,
65,174,89,131,92,0,204,96,71,224,78,65,238,139,192,218,130,220,148,29,9,244,16,228,94,12,28,37,200,53,107,144,11,128,89,92,211,122,173,32,247,17,96,11,65,110,202,78,0,206,22,228,94,0,28,39,200,53,107,
144,11,128,89,124,51,187,72,144,123,59,176,171,32,55,101,167,0,103,8,114,47,2,142,17,228,154,53,200,5,192,12,78,7,78,19,228,94,69,188,147,182,236,184,0,152,213,114,1,48,139,119,194,71,10,114,207,3,186,
11,114,83,118,18,112,166,32,215,107,0,44,119,92,0,204,224,122,96,31,65,238,73,104,222,71,167,236,68,224,44,65,238,37,104,74,166,89,131,92,0,204,224,110,96,123,65,238,161,192,229,130,220,148,169,22,1,94,
10,28,33,200,53,107,144,11,128,25,60,14,252,67,144,187,39,154,83,233,82,118,60,112,174,32,247,50,224,48,65,174,89,131,92,0,204,224,117,52,23,181,108,13,60,32,200,77,217,209,192,133,130,220,43,128,67,4,
185,102,13,114,1,48,131,47,129,249,5,185,235,1,207,9,114,83,166,58,9,240,6,226,24,98,179,220,112,1,48,131,33,64,7,65,238,10,192,219,130,220,148,237,5,244,20,228,222,7,108,39,200,53,107,144,11,128,165,
174,45,240,151,40,123,1,226,233,131,101,71,117,29,112,47,96,67,65,174,89,131,92,0,44,117,243,0,223,138,178,167,3,134,138,178,83,181,5,240,144,32,247,45,96,69,65,174,89,131,92,0,44,117,203,0,239,10,114,
135,3,237,4,185,169,91,15,120,70,144,251,57,176,144,32,215,172,65,46,0,150,186,141,128,39,5,185,223,2,243,10,114,83,183,28,154,117,23,63,1,179,10,114,205,26,228,2,96,169,219,21,184,85,144,251,54,177,8,
208,178,53,31,240,149,32,119,20,208,90,144,107,214,32,23,0,75,221,97,196,41,109,89,123,2,216,68,144,155,186,142,192,239,194,236,33,162,108,179,73,184,0,88,234,206,36,206,228,207,218,205,196,73,128,150,
189,145,192,52,130,220,197,129,143,4,185,102,245,114,1,176,212,169,46,2,242,245,176,58,3,209,188,143,223,12,120,76,144,107,86,47,23,0,75,221,99,104,30,197,159,128,230,76,122,131,190,192,18,130,220,131,
128,171,4,185,102,245,114,1,176,212,245,1,150,20,228,238,141,230,68,58,139,245,23,27,11,114,207,3,186,11,114,205,234,229,2,96,169,251,5,152,81,144,187,5,240,136,32,215,116,175,125,238,4,118,22,228,154,
213,203,5,192,82,214,14,248,19,168,17,100,175,12,188,33,200,53,248,23,112,170,32,247,85,96,53,65,174,89,189,92,0,44,101,93,137,19,218,20,230,4,126,16,101,167,110,127,224,26,65,238,96,96,38,65,174,89,189,
92,0,44,101,107,1,47,8,114,71,17,79,31,198,8,178,45,222,255,63,33,202,238,12,244,23,101,155,77,196,5,192,82,182,11,112,155,32,247,27,226,68,58,211,80,62,249,217,28,120,84,148,109,54,17,23,0,75,217,113,
196,202,236,172,189,12,172,33,200,181,208,10,24,134,230,48,160,147,128,179,5,185,102,147,112,1,176,148,93,74,28,5,156,181,187,129,29,5,185,54,222,103,192,130,130,92,255,179,183,220,112,1,176,148,61,8,
116,19,228,246,0,142,22,228,218,120,143,2,155,10,114,63,5,22,17,228,154,77,194,5,192,82,166,58,4,232,72,224,18,65,174,141,119,1,154,163,152,75,196,49,196,63,11,178,205,38,226,2,96,41,251,3,152,78,144,
187,61,112,175,32,215,198,219,3,184,73,148,189,13,112,191,40,219,236,111,46,0,150,170,153,129,159,68,217,171,2,175,137,178,45,44,3,188,43,202,254,15,112,184,40,219,236,111,46,0,150,170,21,209,157,196,
55,15,240,157,40,219,66,27,96,8,154,157,0,125,129,165,4,185,102,19,113,1,176,84,109,79,172,200,206,218,8,160,61,48,86,144,109,19,83,173,1,41,1,179,161,123,2,101,6,184,0,88,186,84,103,0,124,6,44,44,200,
181,73,93,7,236,43,202,222,5,184,67,148,109,6,184,0,88,186,174,2,14,20,228,62,1,108,34,200,181,73,237,75,148,0,133,251,128,237,68,217,102,128,11,128,165,235,41,96,67,65,238,85,192,65,130,92,155,212,146,
196,107,0,133,63,137,237,128,195,68,249,102,46,0,150,172,111,137,197,120,89,59,22,184,80,144,107,147,106,73,220,208,215,81,148,191,45,240,63,81,182,153,11,128,37,169,3,113,6,64,141,32,123,59,226,241,175,
229,195,99,232,94,201,220,14,236,42,202,54,115,1,176,36,45,15,188,37,202,94,14,221,254,115,155,212,177,192,249,162,236,191,128,185,128,95,69,249,150,56,23,0,75,209,174,192,173,162,236,25,128,223,68,217,
54,41,101,25,4,56,20,184,92,152,111,9,115,1,176,20,157,1,156,34,200,29,12,204,36,200,181,134,181,32,246,227,207,40,202,255,0,205,89,4,102,46,0,150,164,187,137,131,128,178,246,6,176,178,32,215,38,239,78,
180,87,244,174,9,188,36,204,183,68,185,0,88,138,84,39,192,221,12,236,41,200,181,201,83,190,18,130,184,24,104,27,97,190,37,202,5,192,82,211,130,216,131,221,86,144,125,18,112,182,32,215,38,111,70,96,32,
208,74,148,95,2,150,38,238,8,48,203,140,11,128,165,166,11,208,79,148,237,45,128,249,245,2,176,150,48,255,78,96,103,97,190,37,200,5,192,82,179,41,240,168,40,123,73,98,209,151,229,207,161,196,53,189,42,
99,136,167,0,31,10,103,176,196,184,0,88,106,142,70,115,18,223,88,96,90,96,184,32,219,26,55,59,113,69,115,75,225,12,207,2,235,11,243,45,49,46,0,150,154,107,129,253,4,185,253,128,174,130,92,107,186,103,
128,245,196,51,108,9,60,36,158,193,18,225,2,96,169,81,189,235,125,156,120,253,96,249,181,55,112,131,120,134,47,129,165,136,133,170,102,21,229,2,96,169,25,72,220,194,150,181,139,129,163,4,185,214,116,211,
2,223,3,157,196,115,92,1,28,34,158,193,18,224,2,96,41,153,29,248,65,148,189,47,250,111,151,214,184,255,16,11,2,149,74,196,85,213,207,136,231,176,130,115,1,176,148,108,66,220,254,166,176,10,240,186,40,
219,154,110,81,98,37,190,226,166,200,9,13,34,238,41,248,78,60,135,21,152,11,128,165,164,59,112,142,32,183,68,60,86,30,34,200,182,230,83,159,9,48,206,171,196,174,128,191,212,131,88,49,185,0,88,74,238,2,
118,16,228,126,69,28,64,100,213,97,23,224,54,245,16,181,158,2,186,1,35,212,131,88,241,184,0,88,74,62,5,22,18,228,62,2,108,33,200,181,41,211,6,248,22,205,98,209,250,220,69,220,87,48,70,61,136,21,139,11,
128,165,162,3,240,59,113,23,64,214,206,5,78,16,228,218,148,59,9,56,83,61,196,4,238,3,246,0,134,169,7,177,226,112,1,176,84,172,6,188,44,202,222,141,252,60,82,182,166,153,142,120,117,51,147,122,144,9,124,
2,28,9,60,161,30,196,138,193,5,192,82,113,48,112,185,40,123,9,124,198,123,53,58,129,124,222,222,216,11,56,2,255,59,101,83,201,5,192,82,113,29,177,23,63,107,195,136,29,0,163,5,217,54,117,166,37,78,230,
203,203,90,128,9,141,2,122,18,175,42,126,22,207,98,85,202,5,192,82,241,22,177,175,58,107,175,0,171,11,114,173,60,142,39,214,112,228,213,96,224,12,226,233,150,23,9,90,179,184,0,88,10,90,19,11,0,219,10,
178,125,172,107,117,155,150,184,200,105,54,245,32,141,120,159,120,45,240,188,120,14,171,34,46,0,150,130,149,208,157,194,183,55,241,168,214,170,215,94,84,207,63,195,71,128,195,137,87,23,102,147,229,2,96,
41,56,148,56,227,93,97,25,226,219,153,85,175,26,224,57,96,109,245,32,77,52,18,184,26,56,5,248,67,60,139,229,152,11,128,165,224,86,226,32,149,172,13,7,58,18,11,182,172,186,45,1,188,3,76,163,30,164,25,126,
0,78,7,174,7,198,106,71,177,60,114,1,176,20,124,14,116,21,228,190,1,172,44,200,181,202,232,65,236,195,175,54,111,19,235,3,94,82,15,98,249,226,2,96,69,55,59,48,0,205,237,110,215,0,7,10,114,173,50,166,3,
62,2,230,86,15,50,5,74,192,237,196,133,88,190,97,208,0,23,0,43,190,221,128,91,68,217,251,19,231,15,88,113,172,13,60,3,180,84,15,50,133,134,1,151,17,199,28,15,21,207,98,98,46,0,86,116,55,17,103,168,43,
172,64,60,126,181,98,57,151,56,31,160,154,125,11,28,7,220,77,60,29,176,4,185,0,88,209,245,71,243,200,246,47,96,122,98,69,182,21,75,43,226,125,122,17,214,119,188,65,108,27,124,77,61,136,101,207,5,192,138,
108,113,224,3,81,246,75,192,154,162,108,171,188,5,137,93,1,29,212,131,148,193,88,198,31,43,60,80,60,139,101,200,5,192,138,236,112,224,18,81,246,5,196,35,86,43,174,173,136,107,122,21,87,76,87,194,31,192,
89,192,165,192,8,241,44,150,1,23,0,43,178,123,129,109,69,217,91,3,15,136,178,45,59,121,191,43,96,74,124,1,156,8,220,163,30,196,42,203,5,192,138,76,245,254,191,4,204,9,252,40,200,182,236,221,8,236,169,
30,162,2,122,17,231,30,168,94,163,89,133,185,0,88,81,205,77,20,0,133,15,128,37,69,217,150,189,54,192,163,192,250,234,65,42,96,52,112,45,112,42,240,139,120,22,43,51,23,0,43,170,29,128,187,68,217,151,18,
39,175,89,58,218,19,37,96,29,241,28,149,242,43,112,30,112,49,222,217,82,24,46,0,86,84,202,99,91,187,1,15,139,178,77,103,90,224,113,138,189,251,227,51,224,40,162,236,88,149,115,1,176,162,122,25,88,77,144,
59,26,152,25,248,93,144,109,122,211,3,15,81,236,18,0,113,237,240,209,68,33,176,42,229,2,96,69,212,6,248,13,104,43,200,126,13,88,85,144,107,249,209,6,184,153,120,13,85,100,163,128,171,128,211,136,223,111,
86,101,92,0,172,136,86,70,119,178,217,217,196,129,42,150,182,150,192,69,196,89,20,69,247,19,112,50,112,3,48,70,60,139,53,131,11,128,21,145,242,0,160,141,128,167,69,217,150,63,187,17,171,232,219,169,7,
201,192,251,196,226,215,231,197,115,88,19,185,0,88,17,221,10,236,42,200,45,1,51,226,199,161,54,177,37,136,179,2,150,23,207,145,149,251,128,99,129,175,212,131,216,228,185,0,88,17,245,65,179,15,255,51,96,
97,65,174,229,95,43,98,209,220,191,136,53,2,69,55,18,184,26,56,133,56,98,216,114,200,5,192,138,166,53,48,164,246,231,172,221,70,60,242,53,107,72,87,98,157,200,246,234,65,50,242,3,112,58,112,61,113,233,
144,229,136,11,128,21,205,210,192,123,162,236,35,209,173,61,176,234,178,30,113,168,206,82,234,65,50,242,54,177,62,224,37,245,32,54,158,11,128,21,205,238,196,22,44,133,53,241,31,112,214,116,173,128,189,
129,51,129,89,196,179,100,161,68,92,208,117,44,240,141,120,22,195,5,192,138,231,124,226,15,152,172,141,1,58,1,127,10,178,173,186,205,64,220,42,120,36,154,87,87,89,27,6,92,70,20,159,161,226,89,146,230,
2,96,69,243,48,176,185,32,183,47,233,60,206,181,202,88,152,56,59,96,51,245,32,25,249,142,56,51,227,22,226,233,128,101,204,5,192,138,230,19,52,43,241,111,2,246,18,228,90,241,108,65,20,129,5,213,131,100,
164,55,177,62,224,29,245,32,169,113,1,176,34,105,73,60,94,84,60,70,61,158,120,253,96,86,14,211,0,7,17,219,6,59,137,103,201,66,137,56,191,227,56,224,71,241,44,201,112,1,176,34,233,2,244,19,101,111,13,60,
32,202,182,226,154,9,56,21,56,152,40,184,69,247,39,112,33,112,46,48,92,60,75,225,185,0,88,145,108,12,60,33,202,94,28,248,72,148,109,197,183,44,177,197,116,45,245,32,25,249,138,120,250,113,43,190,95,160,
98,92,0,172,72,14,33,86,23,103,109,12,113,23,252,8,65,182,165,101,11,162,8,116,81,15,146,145,175,136,167,1,190,104,168,2,92,0,172,72,46,38,22,19,101,173,31,113,194,155,89,22,218,1,71,1,39,16,197,51,5,
125,129,30,192,93,192,95,226,89,10,195,5,192,138,228,94,96,91,65,238,227,192,166,130,92,75,219,156,192,105,192,190,64,11,241,44,89,249,157,40,1,87,16,119,126,216,84,112,1,176,34,121,5,88,85,144,123,41,
154,39,15,102,0,43,19,255,14,174,172,30,36,99,189,129,251,137,179,63,190,16,207,82,149,92,0,172,72,190,1,58,11,114,15,6,174,20,228,154,141,83,67,92,68,117,14,48,151,120,22,133,143,137,34,240,56,240,22,
217,156,48,56,7,176,40,113,238,72,103,160,61,208,22,152,158,216,138,60,28,248,21,24,92,251,243,64,224,3,98,177,240,200,12,230,107,148,11,128,21,69,11,226,55,220,52,130,236,13,128,103,4,185,102,117,77,
75,172,13,56,138,88,43,144,162,49,196,129,96,111,18,101,224,125,226,203,193,15,192,232,102,254,90,45,128,121,129,197,106,127,44,74,236,248,89,152,41,63,159,97,20,81,88,250,0,207,3,143,34,58,251,192,5,
192,138,98,14,96,128,40,123,126,224,107,81,182,89,125,230,35,14,166,74,229,218,225,166,24,67,124,11,255,150,248,192,29,85,251,159,15,97,124,49,152,9,152,113,130,31,179,16,223,234,43,105,44,113,91,226,
195,192,125,100,184,157,216,5,192,138,98,5,162,241,103,173,68,124,211,242,22,64,203,163,149,137,109,131,171,168,7,177,38,123,153,88,211,113,63,205,127,98,209,44,46,0,86,20,91,0,15,9,114,127,2,102,21,228,
154,53,85,11,96,31,226,246,61,255,187,90,61,190,1,46,39,118,60,84,100,235,163,11,128,21,197,158,192,141,130,220,247,136,83,218,204,242,110,90,226,170,236,238,64,27,241,44,214,116,223,1,255,6,174,39,94,
23,148,141,11,128,21,197,97,196,99,179,172,61,70,58,215,183,90,49,44,72,220,54,184,133,122,16,107,150,215,137,237,198,175,149,235,23,116,1,176,162,56,5,56,67,144,251,95,226,241,170,89,181,217,136,56,61,
115,49,245,32,214,100,99,129,243,136,3,160,70,53,242,215,54,202,5,192,138,162,7,112,164,32,247,66,226,177,170,89,53,106,5,236,77,172,15,152,69,60,139,53,221,155,192,46,76,229,1,72,46,0,86,20,55,16,127,
144,101,237,100,224,44,65,174,89,57,205,72,220,190,119,32,81,10,44,255,254,0,246,39,142,70,158,34,46,0,86,20,247,1,219,8,114,15,2,174,18,228,154,85,194,194,196,211,52,223,109,81,29,74,196,193,79,231,77,
201,223,236,2,96,69,209,11,88,95,144,187,11,112,135,32,215,172,146,186,17,175,183,22,84,15,98,77,114,17,241,42,178,89,31,232,46,0,86,20,189,129,53,4,185,155,18,231,143,155,21,77,107,224,112,226,53,87,
71,241,44,214,184,91,129,127,210,140,195,131,92,0,172,40,84,55,1,174,7,60,39,200,53,203,202,76,192,169,196,165,87,45,197,179,216,228,221,64,92,15,221,36,46,0,86,20,175,3,43,9,114,87,39,202,135,89,209,
45,75,28,43,188,150,122,16,155,172,83,137,131,131,26,229,2,96,69,241,22,176,188,32,119,197,218,108,179,84,108,65,28,186,53,191,122,16,171,87,137,56,155,164,103,99,127,161,11,128,21,197,187,192,50,130,
220,165,137,107,61,205,82,210,14,56,154,56,86,120,90,241,44,54,169,81,192,58,52,242,116,210,5,192,138,162,15,176,164,32,119,81,226,238,113,179,20,205,5,156,11,236,10,212,136,103,177,137,245,35,94,219,
12,105,232,47,112,1,176,162,248,136,248,48,206,218,226,100,120,127,183,89,78,173,64,172,15,88,93,61,136,77,100,178,71,149,187,0,88,81,124,64,124,24,103,109,57,226,245,131,89,234,106,128,221,136,39,2,115,
138,103,177,241,182,1,238,175,239,191,112,1,176,162,120,13,88,89,144,187,10,177,3,193,204,66,7,98,109,192,209,64,91,241,44,6,63,18,7,58,13,173,251,95,184,0,88,81,168,78,2,92,139,56,132,200,204,38,54,47,
177,29,109,87,160,133,120,150,212,253,11,56,189,238,127,232,2,96,69,241,0,176,165,32,119,67,162,124,152,89,253,150,33,206,170,223,72,61,72,194,134,18,79,1,126,156,240,63,116,1,176,162,184,149,248,166,
145,181,237,136,139,136,204,108,242,86,39,94,13,108,134,119,12,40,92,67,220,246,248,55,23,0,43,138,171,168,243,47,119,70,124,27,160,89,243,172,4,156,72,28,40,228,87,3,217,25,77,28,222,244,221,184,255,
192,5,192,138,226,2,224,24,65,238,233,196,251,53,51,107,158,46,196,125,246,251,1,51,138,103,73,197,68,107,1,92,0,172,40,78,163,158,69,46,25,184,2,56,68,144,107,86,20,29,128,157,129,189,128,213,180,163,
20,222,0,98,113,230,104,112,1,176,226,56,4,184,76,144,123,55,176,163,32,215,172,136,22,1,246,4,118,32,158,16,88,249,253,189,110,201,5,192,138,98,91,224,94,65,238,91,196,133,64,102,86,94,203,17,191,175,
183,2,22,19,207,82,36,143,17,11,49,93,0,172,48,86,69,115,45,239,16,160,19,113,3,151,153,85,70,103,96,99,98,43,225,186,192,76,218,113,170,218,112,226,127,191,97,46,0,86,20,243,1,95,137,178,59,3,253,69,
217,102,169,169,33,94,21,172,74,108,45,92,142,120,66,208,90,52,207,48,226,40,242,247,128,79,137,85,246,37,160,61,176,48,81,88,86,38,95,91,31,55,7,30,117,1,176,162,152,134,248,141,216,74,144,189,17,240,
180,32,215,204,194,52,196,101,96,75,18,7,222,116,1,22,32,182,189,205,10,180,156,202,95,127,4,48,136,248,146,241,197,4,63,62,0,62,3,198,52,242,247,47,1,28,69,220,149,48,205,84,206,82,14,87,0,135,184,0,
88,145,124,65,252,166,207,218,17,192,165,130,92,51,107,92,13,48,75,237,143,89,137,111,230,237,129,142,76,90,12,198,2,191,3,127,0,127,2,131,137,211,243,6,151,105,150,229,129,155,209,175,105,232,7,116,117,
1,176,34,121,18,205,113,163,247,16,171,150,205,204,26,51,45,113,116,249,6,226,57,102,113,1,176,34,185,130,56,153,47,107,63,1,179,225,133,128,102,214,52,237,128,151,136,245,11,42,107,187,0,88,145,28,68,
148,0,133,37,128,15,69,217,102,86,125,186,2,111,19,175,34,20,254,207,5,192,138,100,117,162,85,43,28,10,92,46,202,174,38,45,136,5,90,75,2,139,215,254,223,179,3,243,16,239,101,59,49,254,124,248,145,140,
127,15,59,128,88,93,221,15,232,3,244,5,6,102,57,184,89,5,28,134,110,253,208,229,46,0,86,36,29,129,223,208,108,183,121,18,248,135,32,183,26,44,65,92,155,188,46,176,38,48,125,153,126,221,111,129,231,107,
127,60,73,148,4,179,106,210,150,248,247,120,22,65,246,211,46,0,86,52,253,208,28,33,58,134,56,139,224,187,70,254,186,84,44,78,92,207,188,45,176,80,6,121,99,137,131,160,238,3,238,192,79,7,172,122,252,135,
120,130,152,181,55,93,0,172,104,110,37,62,120,20,78,4,206,17,101,231,65,107,226,156,241,3,137,111,250,42,35,129,251,129,171,137,167,3,102,121,182,21,241,239,107,214,62,115,1,176,162,81,46,4,252,140,56,
161,44,181,223,84,109,128,125,128,227,137,83,17,243,228,117,226,10,212,199,213,131,152,53,96,126,224,75,65,238,143,46,0,86,52,203,0,239,10,243,55,0,158,17,230,103,169,134,56,217,236,108,96,110,241,44,
141,121,157,56,176,233,53,245,32,102,117,116,32,238,20,201,218,95,46,0,86,52,45,137,125,249,51,136,242,123,3,107,137,178,179,180,44,113,253,242,234,234,65,154,161,4,220,4,116,199,107,4,44,63,218,19,187,
93,178,54,202,5,192,138,232,110,96,123,97,254,22,192,35,194,252,74,154,14,248,55,112,8,83,127,190,186,202,239,192,41,192,149,52,126,134,187,89,165,117,5,62,23,228,14,118,1,176,34,218,23,184,78,152,255,
37,177,245,237,47,225,12,149,176,21,241,173,63,239,143,251,155,234,93,224,96,224,85,245,32,150,180,13,208,92,38,246,141,11,128,21,209,60,196,222,90,165,203,209,108,237,169,132,46,64,15,96,75,245,32,21,
80,2,122,18,79,4,124,142,128,41,92,0,28,35,200,253,192,5,192,138,234,109,180,231,108,151,136,11,130,238,21,206,48,181,58,16,91,27,143,36,14,44,41,178,97,196,126,236,243,136,195,164,204,178,80,67,236,30,
234,42,200,238,237,2,96,69,117,60,112,174,120,134,191,136,199,123,175,136,231,104,174,150,192,238,192,89,192,156,226,89,178,54,152,56,203,225,74,162,20,152,85,210,142,192,157,162,236,255,186,0,88,81,205,
79,156,10,168,56,22,120,66,191,3,219,0,207,138,231,104,138,105,136,15,254,19,208,124,35,201,147,159,137,18,112,57,177,171,196,172,220,218,2,31,0,11,136,242,143,119,1,176,34,123,13,88,89,61,4,113,50,221,
161,196,194,196,60,254,134,155,29,216,25,56,28,152,87,60,75,222,12,3,110,36,22,63,126,162,29,197,10,230,102,162,112,171,108,229,2,96,69,182,31,112,173,122,136,9,60,65,156,84,248,149,122,16,96,102,96,83,
226,216,228,245,169,222,45,125,89,122,133,88,48,120,23,154,131,91,172,56,78,7,78,19,207,176,144,11,128,21,89,7,98,101,247,116,234,65,38,48,138,248,70,121,62,240,69,134,185,179,0,107,215,254,88,135,184,
172,71,253,122,164,90,253,9,60,12,60,68,148,186,95,181,227,88,21,105,75,124,41,81,126,243,7,248,1,152,203,5,192,138,238,42,226,114,154,188,41,1,47,3,183,17,123,128,251,149,241,215,158,153,216,1,49,225,
143,46,248,3,191,18,70,19,167,63,246,34,206,19,120,19,24,42,157,200,242,168,134,88,240,119,22,154,219,74,235,186,13,216,205,5,192,138,110,113,160,47,249,255,240,251,22,120,139,152,245,115,226,90,225,129,
196,163,230,113,171,209,219,16,199,134,118,34,190,73,116,34,206,60,152,159,184,138,120,62,226,15,151,217,178,27,219,234,24,3,124,8,244,33,14,132,250,146,120,229,51,144,216,21,50,164,246,199,104,213,128,
150,137,246,196,129,89,243,2,27,19,135,104,169,22,251,213,103,31,188,11,192,18,113,63,241,27,208,204,44,117,37,226,203,194,183,46,0,150,130,21,129,55,212,67,152,153,229,192,75,192,154,0,46,0,150,138,39,
129,141,212,67,152,153,137,29,8,92,3,46,0,150,142,165,137,227,129,189,221,205,204,82,53,146,56,221,243,23,112,1,176,180,252,23,248,167,122,8,51,51,145,59,128,93,198,253,63,46,0,150,146,57,137,139,55,166,
85,15,98,102,150,177,18,176,44,240,254,184,255,192,5,192,82,115,4,112,177,122,8,51,179,140,61,72,157,221,80,46,0,150,154,22,192,11,192,26,234,65,204,204,50,180,18,113,80,213,223,92,0,44,69,139,0,239,82,
252,59,238,205,204,0,238,5,182,175,251,31,186,0,88,170,14,2,174,80,15,97,102,86,97,67,129,197,128,254,117,255,11,23,0,75,217,77,192,30,234,33,204,204,42,232,88,224,194,250,254,11,23,0,75,217,180,196,9,
129,139,169,7,49,51,171,128,247,137,147,80,71,213,247,95,186,0,88,234,186,18,183,242,205,170,30,36,81,37,224,21,226,106,221,55,136,91,17,127,5,90,17,183,26,46,6,172,10,108,71,252,179,50,179,166,25,10,
172,0,124,218,208,95,224,2,96,6,203,3,207,1,211,169,7,73,200,88,224,118,224,12,226,246,195,198,212,0,235,16,215,169,174,90,185,177,204,10,99,55,226,218,223,6,185,0,152,133,13,129,71,128,214,234,65,18,
240,54,113,30,249,91,83,240,247,214,0,59,0,23,1,115,149,115,40,179,2,185,22,56,160,177,191,200,5,192,108,188,245,137,171,131,253,36,160,50,134,17,223,248,47,4,198,76,229,175,213,30,56,14,232,14,180,153,
202,95,203,172,72,158,1,54,37,206,253,159,44,23,0,179,137,173,8,60,70,188,127,182,242,121,4,56,24,248,182,204,191,238,66,192,101,248,166,71,51,136,131,126,214,35,222,255,55,202,5,192,108,82,139,19,215,
7,251,17,243,212,251,28,56,134,88,228,87,73,59,19,79,22,230,172,112,142,89,94,125,12,172,5,252,220,212,191,193,5,192,172,126,243,2,15,0,203,168,7,169,82,191,1,103,18,223,206,27,125,20,89,38,237,129,195,
136,125,207,51,102,148,105,150,7,111,0,155,209,140,15,127,112,1,48,155,156,54,192,249,192,161,196,226,51,107,220,88,98,229,241,177,192,64,209,12,211,17,39,61,158,8,116,20,205,96,150,149,103,128,173,129,
33,205,253,27,93,0,204,26,183,53,112,3,48,131,122,144,28,43,1,15,3,39,1,31,136,103,25,103,54,162,4,28,128,23,10,90,49,93,11,28,66,3,7,253,52,198,5,192,172,105,230,5,174,7,54,80,15,146,51,227,62,248,255,
5,188,35,158,165,33,243,16,175,6,246,3,58,137,103,49,43,135,33,196,86,218,219,167,230,23,113,1,48,107,158,173,137,61,232,243,171,7,17,27,14,220,10,92,2,124,40,158,165,169,166,3,246,33,202,64,234,255,252,
172,122,189,7,236,196,100,78,248,107,42,23,0,179,230,107,11,28,13,156,64,220,39,144,146,207,129,27,137,167,33,131,180,163,76,177,150,192,54,192,17,192,106,226,89,204,154,106,40,241,164,237,82,166,240,
145,127,93,46,0,102,83,110,14,226,253,219,1,192,76,226,89,42,233,103,224,65,226,246,196,151,136,199,254,69,177,8,176,59,113,108,106,103,241,44,102,13,185,23,56,18,248,174,156,191,168,11,128,217,212,107,
15,236,73,124,163,92,72,60,75,57,148,136,61,197,79,18,31,252,47,49,245,39,247,229,93,11,96,109,226,122,232,109,241,105,144,166,87,34,206,207,56,139,56,224,167,236,92,0,204,202,167,5,113,167,192,118,192,
86,84,207,105,130,99,129,190,192,11,192,139,64,111,170,247,241,126,57,180,3,214,5,54,169,253,177,128,118,28,75,204,112,224,127,192,121,64,159,74,6,185,0,152,85,70,75,226,27,229,182,64,55,96,110,237,56,
19,25,76,44,36,122,151,241,31,248,191,74,39,202,183,5,137,34,240,15,226,38,194,233,181,227,88,1,149,136,39,109,183,0,247,16,7,105,85,156,11,128,89,54,58,19,31,30,171,0,43,3,203,81,249,189,233,35,129,126,
196,183,136,247,106,127,238,67,153,223,35,38,166,6,232,74,220,179,62,238,199,114,64,7,229,80,86,149,6,16,135,248,60,91,251,115,255,172,7,112,1,48,211,104,13,204,87,251,99,222,9,126,238,76,172,41,152,174,
246,175,233,68,236,58,104,7,252,65,124,168,255,1,252,69,60,42,252,157,248,182,208,31,248,166,246,231,113,63,126,160,88,11,246,242,170,134,88,16,58,31,241,207,112,220,143,206,196,226,208,186,255,28,59,
17,175,139,172,184,70,18,171,246,127,35,246,236,255,14,124,70,108,221,251,20,248,136,40,231,82,255,15,157,235,150,92,121,58,30,99,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* PluginEditor::kneeBianco_png = (const char*) resource_PluginEditor_kneeBianco_png;
const int PluginEditor::kneeBianco_pngSize = 18981;

// JUCER_RESOURCE: kobe_cattivoBianco_png, 5399, "../images/kobe_cattivo bianco.png"
static const unsigned char resource_PluginEditor_kobe_cattivoBianco_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,1,0,0,0,1,0,8,4,0,0,0,246,123,96,237,0,0,0,9,112,72,89,115,0,0,11,18,0,0,
11,18,1,210,221,126,252,0,0,0,27,116,69,88,116,83,111,102,116,119,97,114,101,0,67,101,108,115,121,115,32,83,116,117,100,105,111,32,84,111,111,108,193,167,225,124,0,0,20,162,73,68,65,84,120,156,237,157,
121,156,20,213,181,199,191,213,221,179,15,139,200,34,138,128,236,6,5,34,40,26,49,32,96,98,18,80,35,139,38,106,224,161,49,81,227,115,195,23,163,230,185,128,146,247,2,137,81,140,49,24,54,159,18,130,104,
158,248,76,158,34,8,138,70,37,46,160,25,101,0,5,84,22,25,37,108,14,12,204,228,15,134,97,166,251,222,234,170,234,186,117,235,118,213,151,207,135,207,244,173,91,117,78,119,255,186,110,213,173,115,207,177,
234,136,137,50,86,44,128,104,19,11,32,226,196,2,136,56,177,0,34,78,44,128,136,19,11,32,226,196,2,136,56,193,11,192,194,60,205,37,72,114,144,90,221,110,168,64,135,0,48,80,2,38,202,214,17,58,134,128,68,
126,254,150,124,64,131,204,244,92,3,228,237,239,41,39,180,124,42,177,0,34,142,122,1,88,180,160,37,73,224,0,155,26,78,254,177,4,228,88,116,166,23,21,108,163,90,253,96,169,94,0,23,178,176,225,239,13,12,
96,187,106,131,134,115,6,43,168,37,89,255,234,59,60,171,214,156,95,2,144,253,162,203,168,162,168,209,235,29,116,163,202,31,147,121,73,171,140,79,39,169,246,44,160,90,0,23,241,199,180,150,85,156,194,65,
127,140,230,33,153,159,98,63,222,81,105,80,237,16,80,194,179,12,201,104,189,137,95,169,52,106,48,163,120,34,163,109,35,157,84,154,84,43,128,175,241,2,197,25,173,27,233,70,141,74,179,134,146,224,99,218,
11,218,203,217,163,206,168,74,1,88,220,200,84,225,150,107,248,173,58,179,198,114,57,143,8,219,135,176,76,157,81,149,2,40,102,46,99,132,91,182,210,141,221,234,12,27,73,57,187,36,91,110,150,252,140,124,
65,165,0,58,178,130,14,146,109,83,185,89,157,97,3,177,120,155,62,146,109,79,50,74,161,97,133,2,248,186,205,169,107,31,61,217,160,206,180,113,156,197,114,233,182,77,116,84,103,88,165,0,198,51,203,102,235,
2,46,166,54,158,17,4,160,144,47,40,149,110,253,210,102,91,206,248,41,128,244,47,115,10,183,216,246,31,206,11,130,189,162,200,93,252,167,237,246,132,186,207,72,165,0,22,49,194,182,255,71,244,101,167,96,
191,168,209,147,247,179,244,80,56,27,168,110,8,176,120,131,254,89,250,60,196,245,236,87,229,128,33,20,177,34,235,231,84,168,110,222,68,229,53,192,108,198,101,233,81,203,143,152,19,233,73,161,36,183,48,
57,107,47,133,83,65,42,5,240,103,206,207,218,231,0,227,249,83,132,37,240,75,38,58,232,85,198,94,85,14,168,20,192,139,12,118,208,171,134,75,121,202,131,4,44,44,195,67,203,44,30,97,130,163,158,134,14,1,
11,185,208,81,191,26,38,176,128,125,234,28,9,24,11,200,30,248,90,232,226,29,27,114,23,144,206,125,92,231,176,231,1,238,230,215,236,201,203,187,1,241,61,206,213,60,232,234,24,202,80,41,128,159,113,175,
139,222,47,243,67,214,114,0,48,249,198,208,194,194,162,78,48,56,29,126,79,197,156,200,114,202,93,28,115,27,237,124,242,78,128,74,1,92,203,253,174,250,87,51,157,187,217,227,120,100,63,134,145,92,193,105,
84,113,20,137,180,109,117,84,179,143,26,246,83,195,1,14,80,139,133,69,130,84,253,191,66,82,88,36,41,104,8,190,202,133,17,252,181,73,144,75,130,58,137,132,79,230,127,57,193,229,209,23,113,158,103,207,178,
162,82,0,167,242,186,235,125,182,114,15,51,216,39,248,248,44,44,202,233,70,37,187,56,147,139,56,79,109,160,132,7,42,168,224,9,158,101,151,80,194,41,198,48,149,99,61,28,247,106,30,202,213,53,57,42,5,208,
142,45,158,246,219,196,125,60,202,246,52,17,88,124,155,95,112,18,21,180,82,121,74,244,133,87,185,148,13,13,231,132,20,199,48,134,137,158,190,124,128,190,172,242,203,177,76,84,10,160,132,42,74,60,239,189,
154,10,94,226,77,214,80,77,107,254,131,203,92,141,155,97,160,3,155,73,50,141,107,115,60,78,59,182,249,226,143,16,149,2,72,241,10,167,170,59,124,68,56,72,129,202,75,98,181,49,129,51,184,66,229,225,35,193,
42,250,170,60,188,90,1,12,226,37,149,135,143,4,51,184,82,229,225,213,10,160,152,47,85,30,62,18,92,206,76,149,135,87,43,0,139,74,186,170,52,16,1,58,240,137,202,195,171,94,27,248,176,218,19,88,222,243,14,
253,212,26,80,45,128,46,172,83,107,32,207,153,204,207,213,26,80,45,128,100,253,236,126,140,55,148,78,2,65,16,203,195,231,114,153,106,19,121,203,102,207,179,135,142,81,47,128,142,113,252,191,103,166,112,
171,106,19,234,5,144,164,210,245,243,175,24,128,47,105,207,63,85,27,9,34,71,208,119,120,70,189,145,60,100,122,206,79,17,28,16,132,0,138,249,64,229,226,166,60,165,134,238,65,12,158,193,100,9,187,158,95,
7,97,38,175,152,195,248,32,204,4,35,128,98,214,11,83,31,196,200,168,163,55,21,65,24,10,42,79,224,143,248,93,48,134,242,132,167,28,70,84,231,76,80,2,72,240,150,116,253,123,76,58,123,233,161,246,9,192,17,
130,203,20,218,141,202,160,76,25,207,88,22,4,101,42,200,84,177,211,184,49,56,99,6,19,192,244,207,17,212,9,32,5,28,108,18,204,100,177,211,184,184,190,224,249,11,223,14,210,92,176,201,162,83,124,78,179,
32,13,26,71,37,253,212,45,4,21,17,116,182,240,34,170,131,53,104,20,159,50,152,181,193,154,12,62,93,124,138,42,154,7,109,212,8,158,102,60,95,4,109,84,71,189,0,139,45,180,13,222,108,168,169,230,102,166,
235,48,172,171,106,88,91,182,234,49,28,74,42,184,88,117,224,135,12,125,101,227,82,236,203,88,210,25,69,54,48,153,89,46,243,167,91,28,90,109,236,195,151,167,183,110,160,93,42,201,40,176,158,187,153,227,
106,15,103,201,39,196,251,9,247,202,46,128,50,202,40,165,132,22,148,115,144,253,236,97,47,187,217,195,126,106,210,238,243,189,209,158,74,202,114,62,138,121,188,207,36,30,119,181,135,93,214,4,139,36,41,
10,216,215,144,76,38,189,111,41,251,68,231,153,108,2,104,193,142,140,182,26,62,101,9,85,36,72,240,28,75,235,83,157,228,114,74,138,226,21,65,31,86,231,176,183,69,130,18,202,56,157,222,20,81,78,27,218,210,
156,18,74,129,90,246,179,143,90,146,164,120,139,59,216,84,191,79,210,189,0,70,176,200,177,75,181,236,101,23,143,243,12,107,169,162,218,165,24,162,183,134,40,229,161,110,74,146,54,204,99,96,147,53,215,
251,216,159,101,114,109,10,183,201,191,13,123,1,44,225,108,119,30,54,80,199,249,245,129,96,206,132,224,38,101,82,126,80,224,56,96,62,73,119,250,48,137,30,30,45,189,205,16,121,108,161,92,0,9,106,217,155,
195,250,254,67,188,207,48,54,59,16,65,175,96,194,31,66,132,147,228,143,205,24,195,100,31,66,105,158,231,27,178,77,246,103,0,255,110,17,142,230,115,219,237,159,168,143,128,15,25,253,121,211,118,251,16,
166,113,138,111,214,164,121,198,236,4,144,240,181,186,215,110,202,233,192,86,225,157,67,244,6,0,251,135,190,195,120,216,231,69,181,33,16,192,97,54,210,53,99,244,107,174,62,254,61,116,172,161,167,176,189,
59,247,115,174,239,214,60,9,32,165,44,65,233,199,252,158,73,141,94,183,230,51,69,150,194,76,179,140,186,73,163,25,205,40,82,10,108,121,18,64,153,226,194,78,91,232,88,47,177,104,134,139,93,201,140,134,
191,7,112,5,163,104,173,200,210,118,218,200,54,217,9,32,136,223,229,102,78,102,103,68,107,6,188,199,73,64,17,227,152,72,119,165,150,108,242,12,217,9,160,51,31,170,240,38,166,17,239,208,153,22,202,173,
216,132,153,217,9,32,154,39,230,124,228,94,110,147,109,178,19,64,246,90,54,49,102,48,154,133,178,77,118,2,56,129,245,42,188,137,9,156,238,242,72,67,221,23,129,49,65,96,83,117,204,126,42,120,62,99,253,
247,38,38,112,108,10,78,216,11,32,190,10,200,15,60,11,32,206,241,149,31,120,22,0,236,138,23,115,25,79,165,93,36,65,54,1,124,159,199,252,245,38,38,112,206,231,105,249,70,47,49,129,49,102,209,130,157,242,
141,217,163,130,77,173,223,21,115,24,219,162,115,217,5,240,127,193,46,87,142,241,157,28,5,112,82,78,225,203,49,186,89,105,95,182,39,187,0,212,133,133,196,4,193,233,188,102,183,217,201,210,176,47,41,246,
203,155,152,192,201,82,118,214,137,0,226,20,111,230,178,58,91,110,54,39,2,40,9,54,105,73,140,143,100,173,57,232,108,117,240,108,198,249,225,77,76,224,100,173,59,238,76,0,81,140,219,207,7,110,102,106,182,
46,78,243,3,196,57,254,76,36,235,239,223,185,0,226,155,65,243,216,235,36,239,130,243,12,33,183,55,89,202,17,19,126,50,23,158,8,112,46,128,56,54,192,44,158,230,124,39,221,220,228,8,250,119,126,227,213,
155,152,192,177,137,3,108,140,27,1,168,89,44,26,163,130,219,185,199,89,71,119,89,194,46,99,174,23,111,98,2,167,200,233,114,59,119,2,176,216,166,108,1,99,140,127,92,204,124,167,93,221,230,9,44,136,232,
66,78,147,88,202,80,231,157,221,39,138,140,98,50,7,147,168,166,212,77,20,151,151,76,161,157,248,200,253,78,49,1,81,236,110,218,222,91,170,216,86,84,121,217,45,70,57,109,216,238,110,7,175,185,130,75,88,
27,185,188,94,225,167,171,251,229,188,222,147,69,39,248,127,134,123,221,217,33,119,114,167,98,11,249,68,153,151,184,141,220,178,133,223,161,240,11,58,20,205,126,58,175,42,179,144,79,116,108,200,8,236,
146,92,211,197,39,232,207,3,12,204,237,32,2,154,179,171,254,47,211,215,37,116,99,27,253,57,131,4,151,112,162,18,11,63,224,81,239,59,251,83,47,160,152,129,76,163,191,31,135,2,160,117,163,139,76,179,5,176,
149,99,26,254,46,229,1,38,248,122,244,106,6,241,247,220,14,225,103,193,136,2,250,114,151,15,203,72,190,193,243,141,94,153,93,103,172,75,147,68,91,73,214,209,201,167,35,207,230,114,103,143,123,236,81,81,
49,164,37,208,7,139,179,56,154,33,244,115,239,83,218,43,31,222,166,54,18,105,103,176,235,184,47,135,163,237,99,9,139,88,202,122,255,230,99,117,149,140,105,207,42,201,83,133,244,165,140,102,199,33,164,
7,101,181,204,82,24,174,142,26,18,105,185,66,247,179,145,239,242,15,127,106,4,165,163,175,102,80,63,222,18,180,238,201,200,71,96,246,25,32,93,0,178,119,51,153,197,44,35,209,176,213,106,248,95,201,215,
222,200,33,109,2,232,200,6,65,107,161,32,246,176,107,208,213,52,125,227,78,238,202,104,27,194,82,65,207,249,92,172,222,29,17,250,4,112,22,203,5,173,226,56,86,83,239,4,210,175,0,14,181,137,194,106,214,
209,77,189,59,34,244,9,224,102,254,59,163,173,78,82,73,208,84,1,136,228,44,27,4,74,244,220,237,232,19,192,219,130,4,198,221,88,39,236,155,79,2,128,215,133,11,182,93,62,197,243,11,125,2,16,25,150,45,100,
200,47,1,148,55,204,114,54,70,52,92,4,128,46,1,136,79,132,50,1,76,229,38,149,206,40,226,52,222,144,108,17,125,232,177,0,144,135,50,155,185,54,81,254,149,186,57,251,41,70,159,0,182,10,170,88,200,107,233,
153,56,8,200,191,210,248,12,128,248,67,144,47,102,200,39,1,136,111,4,35,38,0,113,116,177,236,67,48,115,54,80,38,0,241,123,119,184,146,199,111,116,9,224,56,62,22,180,70,67,0,226,58,201,142,151,114,248,
139,46,1,220,42,92,186,36,251,21,88,172,166,183,90,135,20,32,19,64,169,176,104,108,196,4,176,77,88,200,76,254,33,152,87,96,254,88,54,75,182,136,203,241,69,108,38,80,108,214,46,173,177,105,151,129,242,
139,186,193,188,40,104,141,5,0,184,189,117,10,51,242,119,178,185,81,152,216,17,28,165,115,240,159,88,0,170,144,189,19,139,237,180,18,180,31,47,188,44,86,78,44,0,85,200,103,1,14,8,183,125,151,63,171,116,
71,134,30,1,200,111,235,100,137,205,76,187,17,172,37,41,217,210,155,119,133,237,139,56,79,157,59,114,244,8,192,46,206,79,124,241,100,222,178,116,217,69,224,4,254,32,108,95,201,105,58,206,114,118,2,176,
148,57,100,247,123,190,132,199,5,173,167,242,186,34,95,84,209,155,127,8,90,19,44,230,108,97,255,149,12,212,113,150,179,19,64,18,20,101,5,178,63,161,103,222,16,153,54,0,0,44,97,152,160,85,94,125,225,53,
6,233,136,127,14,223,16,0,117,36,51,206,61,166,93,2,130,232,50,176,140,245,180,149,244,94,193,80,29,195,156,30,1,100,203,59,122,118,218,84,137,121,243,128,144,25,224,86,202,44,155,74,172,203,248,166,142,
168,135,76,1,168,27,249,143,32,158,12,109,76,227,104,154,4,159,9,239,156,195,78,5,95,105,244,170,7,211,24,97,211,123,9,35,132,15,137,20,163,71,0,206,74,80,28,154,27,51,57,59,225,77,252,149,181,36,104,
199,108,78,200,178,42,112,9,35,117,212,101,208,51,4,44,178,253,45,228,19,251,169,166,185,163,158,47,50,82,199,100,176,30,1,84,83,164,195,108,168,121,153,145,58,138,116,234,16,128,137,55,117,234,89,201,
185,58,82,111,233,16,128,217,235,125,85,81,193,80,182,4,111,86,135,0,204,12,242,86,205,39,12,210,145,127,81,135,0,196,43,99,162,206,78,206,148,60,38,82,202,33,1,4,113,235,119,132,99,249,36,64,107,166,
80,203,183,120,46,120,179,135,5,16,228,133,89,123,62,13,204,150,73,252,132,7,131,55,170,99,8,104,147,173,152,97,68,153,207,247,130,127,230,161,67,0,241,25,64,204,22,142,141,134,0,58,120,205,106,153,247,
104,88,29,164,67,0,157,155,228,206,139,57,66,42,248,231,30,58,4,208,69,146,7,36,38,34,2,48,55,235,151,106,34,50,4,28,207,198,224,141,26,65,68,4,16,223,6,202,136,136,0,178,199,3,69,21,13,73,34,226,167,
129,97,66,67,158,32,61,1,33,159,197,229,39,5,124,66,135,224,141,234,17,192,247,132,139,63,162,142,139,122,159,254,161,71,0,113,229,65,17,26,102,1,116,9,32,193,14,154,233,48,28,106,180,100,10,212,181,60,
124,158,174,244,232,161,165,134,66,29,102,117,9,96,172,142,241,46,212,108,162,163,14,179,186,4,80,196,14,138,245,152,14,41,95,161,66,135,89,125,153,66,159,102,164,46,211,161,196,176,92,193,185,71,17,254,
27,51,115,60,66,62,241,18,95,215,99,88,159,0,90,178,93,154,70,37,122,136,211,73,100,226,123,248,174,190,33,0,150,72,114,101,68,17,167,3,64,210,239,185,2,157,2,184,132,255,209,103,60,84,236,164,133,195,
158,121,117,6,40,100,43,45,245,153,15,17,3,29,103,64,202,43,1,192,116,174,209,105,62,52,104,170,21,0,186,5,240,85,222,212,105,62,36,44,100,180,62,227,122,5,0,43,125,44,58,111,42,110,210,68,231,217,16,
0,151,49,87,175,3,218,249,59,3,28,247,85,176,134,83,183,0,146,84,114,130,94,23,52,115,148,139,188,32,190,223,4,234,23,128,211,132,81,249,202,198,44,169,163,154,146,151,2,40,224,67,142,211,237,132,54,228,
117,69,68,228,225,16,0,112,21,191,205,249,24,251,89,197,118,254,70,1,101,12,228,12,31,188,146,177,134,103,27,254,30,197,241,57,29,235,35,87,195,159,146,44,14,97,16,64,138,53,57,92,7,108,103,36,127,19,
180,23,50,152,199,132,149,137,220,178,128,27,37,197,28,44,206,98,38,93,61,31,185,157,254,21,18,97,16,0,140,103,150,167,253,42,184,128,53,182,61,10,25,203,163,158,142,125,136,71,184,61,75,154,90,139,159,
50,197,211,177,215,210,221,211,126,190,18,14,1,36,120,143,94,46,247,217,195,73,142,67,75,91,49,133,43,93,30,255,41,30,96,133,195,244,205,222,162,156,91,241,133,135,189,124,38,28,2,128,139,248,163,171,
254,213,28,195,63,93,237,97,209,139,5,142,170,15,78,226,1,62,115,117,108,56,157,87,93,238,209,52,147,176,54,194,34,0,139,149,156,226,184,247,94,90,102,201,55,30,60,93,88,77,169,139,254,161,248,253,135,
71,0,112,22,203,29,246,220,67,203,80,46,46,107,77,165,227,167,155,31,184,30,242,20,17,30,1,192,159,24,227,160,87,53,205,66,249,245,3,180,97,173,195,212,208,205,195,146,43,49,76,2,232,76,133,131,72,97,
77,21,54,29,210,150,74,7,18,88,69,223,0,124,113,68,152,4,0,247,112,107,150,30,61,168,12,196,19,239,180,99,45,229,89,250,180,116,121,1,171,144,112,9,160,156,53,180,183,217,62,193,227,124,65,176,100,203,
128,242,27,174,15,200,19,7,132,75,0,246,83,66,79,50,42,64,79,114,225,26,166,75,183,213,81,26,166,65,44,108,2,176,120,67,18,34,162,37,141,162,71,18,172,150,222,229,143,225,137,64,125,201,66,216,4,0,103,
242,178,176,189,216,168,36,243,178,100,152,27,233,28,46,25,135,79,0,176,144,11,51,218,186,219,164,150,235,66,159,38,175,235,248,139,162,10,124,205,25,199,253,0,188,193,28,96,169,205,114,142,135,248,177,
160,181,189,142,162,16,118,132,81,0,61,121,151,84,147,150,53,244,148,244,77,241,50,3,5,237,139,57,215,231,224,137,54,204,225,91,130,246,225,188,32,236,127,156,224,9,226,131,252,196,87,159,124,32,140,2,
200,252,245,244,226,3,97,191,238,182,207,2,103,114,165,79,34,232,202,60,78,149,110,125,140,75,133,237,203,50,214,251,149,234,168,12,104,79,56,5,208,142,117,148,53,122,93,206,30,65,47,39,5,165,231,113,
27,31,229,48,234,38,24,204,162,38,190,136,152,197,4,65,107,63,222,106,242,122,34,211,60,251,161,140,112,10,0,238,228,142,70,175,202,4,37,21,7,52,170,45,154,141,21,76,226,21,151,147,175,69,12,228,6,46,
112,216,251,23,252,76,208,186,161,73,210,135,80,94,198,134,85,0,229,172,107,40,179,188,129,206,25,219,189,45,41,185,157,221,44,103,23,91,40,173,127,114,87,131,69,49,69,156,71,33,5,20,144,34,65,45,221,
61,228,46,184,174,254,242,176,49,167,241,90,195,223,55,112,159,7,143,149,19,86,1,192,213,13,5,84,50,151,78,119,100,67,208,238,56,224,146,140,176,144,226,134,49,191,138,227,92,254,254,3,170,227,20,94,1,
20,176,137,118,64,230,210,233,163,248,60,120,119,28,145,57,199,191,166,62,236,107,60,115,92,30,43,242,2,128,41,220,2,236,201,120,180,242,101,104,179,11,205,227,251,105,45,87,48,3,248,148,78,46,31,97,7,
86,199,45,204,2,232,194,90,44,218,166,133,103,141,99,182,30,119,28,145,254,176,186,136,106,224,106,30,210,227,78,118,194,44,0,120,158,225,105,3,64,216,139,201,79,201,120,160,189,147,102,20,134,46,128,
173,129,112,11,224,58,142,103,98,147,150,240,47,38,77,95,235,255,95,192,79,245,184,226,132,112,11,160,28,210,106,11,236,206,58,41,163,155,244,197,30,67,89,22,230,179,86,184,5,144,142,9,5,231,126,144,182,
16,165,80,209,131,41,159,48,75,0,147,185,77,183,11,89,249,56,199,245,130,1,99,146,0,44,62,55,34,169,84,136,47,249,50,49,73,0,166,148,157,119,154,244,49,20,152,36,128,65,188,164,219,5,71,136,159,13,134,
20,147,4,176,152,97,130,214,45,116,103,47,5,60,195,240,192,60,121,143,10,110,96,39,251,249,21,87,101,108,173,37,149,195,60,94,96,115,128,245,230,12,18,64,21,173,4,173,199,55,68,222,148,8,30,26,171,96,
6,55,54,220,156,90,194,74,127,33,138,251,207,134,57,2,144,21,155,107,60,83,216,67,18,57,228,47,77,159,235,139,62,192,126,188,19,128,31,190,96,142,0,100,151,128,77,167,138,127,172,124,214,253,148,180,56,
31,209,7,120,5,127,80,236,133,111,152,35,128,190,188,45,108,79,127,88,172,182,54,249,76,46,111,242,186,80,248,148,127,1,99,21,250,224,43,230,8,160,146,110,194,246,204,68,235,234,222,82,102,108,210,209,
108,23,244,219,75,63,214,134,43,254,95,134,41,2,144,79,2,101,10,64,93,109,226,204,168,94,217,121,9,10,66,187,136,189,9,166,8,64,254,24,88,84,106,97,148,146,229,87,91,57,38,163,173,51,31,10,251,30,164,
32,62,3,248,73,177,52,162,126,176,48,179,136,138,183,37,74,234,126,139,36,67,152,72,44,161,196,20,1,148,10,87,6,28,226,171,130,211,176,255,213,72,68,19,188,69,210,117,190,239,114,178,207,246,21,97,138,
0,236,159,3,36,51,166,99,196,87,231,185,32,250,253,203,163,19,150,50,212,103,251,138,200,15,1,136,114,110,221,193,157,62,218,31,194,178,180,150,34,246,146,144,246,159,111,74,105,220,124,17,0,188,203,128,
38,191,250,148,175,15,101,59,177,17,104,78,51,182,112,80,122,233,119,132,233,92,235,163,117,133,152,34,128,230,46,103,215,63,35,193,209,62,251,240,145,96,133,146,140,59,184,219,103,235,138,200,87,1,232,
230,42,83,170,32,152,34,0,83,130,65,14,51,154,133,186,93,112,134,41,2,48,237,12,32,158,157,8,33,166,8,160,133,139,202,58,97,224,68,222,215,237,130,51,76,17,64,130,151,149,214,1,241,155,214,84,233,118,
193,25,166,8,0,138,216,158,53,3,103,88,168,166,212,140,39,1,38,9,0,158,227,28,221,46,56,36,20,181,64,156,97,146,0,126,110,202,189,181,57,19,193,102,9,96,8,75,117,187,224,144,135,133,57,2,67,137,73,2,40,
97,7,133,186,157,112,68,230,147,3,49,1,135,128,11,93,208,238,129,27,86,240,53,221,46,56,160,146,158,250,191,88,167,152,37,128,1,44,115,85,151,71,15,231,176,88,183,11,206,49,75,0,112,1,79,10,131,192,194,
195,35,252,80,183,11,110,48,77,0,48,145,95,234,118,193,134,87,248,166,178,144,84,37,152,39,0,184,87,152,149,51,12,188,198,57,134,61,180,50,82,0,48,146,185,33,204,20,176,146,97,236,212,237,132,91,204,20,
0,116,98,129,77,254,110,29,188,197,160,128,22,167,250,138,169,2,136,241,137,88,0,17,39,22,64,196,137,5,16,113,98,1,68,156,88,0,17,39,22,64,196,137,5,16,113,98,1,68,156,88,0,17,39,22,64,196,137,5,16,113,
98,1,248,79,8,34,253,156,19,11,192,95,140,250,242,1,254,5,152,99,36,76,185,179,4,225,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* PluginEditor::kobe_cattivoBianco_png = (const char*) resource_PluginEditor_kobe_cattivoBianco_png;
const int PluginEditor::kobe_cattivoBianco_pngSize = 5399;

// JUCER_RESOURCE: kobe_softBianco_png, 8216, "../images/kobe_soft bianco.png"
static const unsigned char resource_PluginEditor_kobe_softBianco_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,200,0,0,0,200,8,6,0,0,0,173,88,174,158,0,0,0,4,103,65,77,65,0,0,177,143,11,
252,97,5,0,0,10,55,105,67,67,80,115,82,71,66,32,73,69,67,54,49,57,54,54,45,50,46,49,0,0,72,137,157,150,119,84,83,217,22,135,207,189,55,189,80,146,16,138,148,208,107,104,82,2,72,13,189,72,145,46,42,49,
9,16,74,192,144,0,34,54,68,84,112,68,81,145,166,8,50,40,224,128,163,67,145,177,34,138,133,1,81,177,235,4,25,68,212,113,112,20,27,150,73,100,173,25,223,188,121,239,205,155,223,31,247,126,107,159,189,207,
221,103,239,125,214,186,0,144,252,131,5,194,76,88,9,128,12,161,88,20,225,231,197,136,141,139,103,96,7,1,12,240,0,3,108,0,224,112,179,179,66,22,248,70,2,153,2,124,216,140,108,153,19,248,23,189,186,14,32,
249,251,42,211,63,140,193,0,255,159,148,185,89,34,49,0,80,152,140,231,242,248,217,92,25,23,201,56,61,87,156,37,183,79,201,152,182,52,77,206,48,74,206,34,89,130,50,86,147,115,242,44,91,124,246,153,101,
15,57,243,50,132,60,25,203,115,206,226,101,240,228,220,39,227,141,57,18,190,140,145,96,25,23,231,8,248,185,50,190,38,99,131,116,73,134,64,198,111,228,177,25,124,78,54,0,40,146,220,46,230,115,83,100,108,
45,99,146,40,50,130,45,227,121,0,224,72,201,95,240,210,47,88,204,207,19,203,15,197,206,204,90,46,18,36,167,136,25,38,92,83,134,141,147,19,139,225,207,207,77,231,139,197,204,48,14,55,141,35,226,49,216,
153,25,89,28,225,114,0,102,207,252,89,20,121,109,25,178,34,59,216,56,57,56,48,109,45,109,190,40,212,127,93,252,155,146,247,118,150,94,132,127,238,25,68,31,248,195,246,87,126,153,13,0,176,166,101,181,217,
250,135,109,105,21,0,93,235,1,80,187,253,135,205,96,47,0,138,178,190,117,14,125,113,30,186,124,94,82,196,226,44,103,43,171,220,220,92,75,1,159,107,41,47,232,239,250,159,14,127,67,95,124,207,82,190,221,
239,229,97,120,243,147,56,146,116,49,67,94,55,110,102,122,166,68,196,200,206,226,112,249,12,230,159,135,248,31,7,254,117,30,22,17,252,36,190,136,47,148,69,68,203,166,76,32,76,150,181,91,200,19,136,5,153,
66,134,64,248,159,154,248,15,195,254,164,217,185,150,137,218,248,17,208,150,88,2,165,33,26,64,126,30,0,40,42,17,32,9,123,100,43,208,239,125,11,198,71,3,249,205,139,209,153,152,157,251,207,130,254,125,
87,184,76,254,200,22,36,127,142,99,71,68,50,184,18,81,206,236,154,252,90,2,52,32,0,69,64,3,234,64,27,232,3,19,192,4,182,192,17,184,0,15,224,3,2,65,40,136,4,113,96,49,224,130,20,144,1,68,32,23,20,128,181,
160,24,148,130,173,96,39,168,6,117,160,17,52,131,54,112,24,116,129,99,224,52,56,7,46,129,203,96,4,220,1,82,48,14,158,128,41,240,10,204,64,16,132,133,200,16,21,82,135,116,32,67,200,28,178,133,88,144,27,
228,3,5,67,17,80,28,148,8,37,67,66,72,2,21,64,235,160,82,168,28,170,134,234,161,102,232,91,232,40,116,26,186,0,13,67,183,160,81,104,18,250,21,122,7,35,48,9,166,193,90,176,17,108,5,179,96,79,56,8,142,132,
23,193,201,240,50,56,31,46,130,183,192,149,112,3,124,16,238,132,79,195,151,224,17,88,10,63,129,167,17,128,16,17,58,162,139,48,17,22,194,70,66,145,120,36,9,17,33,171,144,18,164,2,105,64,218,144,30,164,
31,185,138,72,145,167,200,91,20,6,69,69,49,80,76,148,11,202,31,21,133,226,162,150,161,86,161,54,163,170,81,7,80,157,168,62,212,85,212,40,106,10,245,17,77,70,107,162,205,209,206,232,0,116,44,58,25,157,
139,46,70,87,160,155,208,29,232,179,232,17,244,56,250,21,6,131,161,99,140,49,142,24,127,76,28,38,21,179,2,179,25,179,27,211,142,57,133,25,198,140,97,166,177,88,172,58,214,28,235,138,13,197,114,176,98,
108,49,182,10,123,16,123,18,123,5,59,142,125,131,35,226,116,112,182,56,95,92,60,78,136,43,196,85,224,90,112,39,112,87,112,19,184,25,188,18,222,16,239,140,15,197,243,240,203,241,101,248,70,124,15,126,8,
63,142,159,33,40,19,140,9,174,132,72,66,42,97,45,161,146,208,70,56,75,184,75,120,65,36,18,245,136,78,196,112,162,128,184,134,88,73,60,68,60,79,28,37,190,37,81,72,102,36,54,41,129,36,33,109,33,237,39,157,
34,221,34,189,32,147,201,70,100,15,114,60,89,76,222,66,110,38,159,33,223,39,191,81,160,42,88,42,4,40,240,20,86,43,212,40,116,42,92,81,120,166,136,87,52,84,244,84,92,172,152,175,88,161,120,68,113,72,241,
169,18,94,201,72,137,173,196,81,90,165,84,163,116,84,233,134,210,180,50,85,217,70,57,84,57,67,121,179,114,139,242,5,229,71,20,44,197,136,226,67,225,81,138,40,251,40,103,40,99,84,132,170,79,101,83,185,
212,117,212,70,234,89,234,56,13,67,51,166,5,208,82,105,165,180,111,104,131,180,41,21,138,138,157,74,180,74,158,74,141,202,113,21,41,29,161,27,209,3,232,233,244,50,250,97,250,117,250,59,85,45,85,79,85,
190,234,38,213,54,213,43,170,175,213,230,168,121,168,241,213,74,212,218,213,70,212,222,169,51,212,125,212,211,212,183,169,119,169,223,211,64,105,152,105,132,107,228,106,236,209,56,171,241,116,14,109,142,
203,28,238,156,146,57,135,231,220,214,132,53,205,52,35,52,87,104,238,211,28,208,156,214,210,214,242,211,202,210,170,210,58,163,245,84,155,174,237,161,157,170,189,67,251,132,246,164,14,85,199,77,71,160,
179,67,231,164,206,99,134,10,195,147,145,206,168,100,244,49,166,116,53,117,253,117,37,186,245,186,131,186,51,122,198,122,81,122,133,122,237,122,247,244,9,250,44,253,36,253,29,250,189,250,83,6,58,6,33,
6,5,6,173,6,183,13,241,134,44,195,20,195,93,134,253,134,175,141,140,141,98,140,54,24,117,25,61,50,86,51,14,48,206,55,110,53,190,107,66,54,113,55,89,102,210,96,114,205,20,99,202,50,77,51,221,109,122,217,
12,54,179,55,75,49,171,49,27,50,135,205,29,204,5,230,187,205,135,45,208,22,78,22,66,139,6,139,27,76,18,211,147,153,195,108,101,142,90,210,45,131,45,11,45,187,44,159,89,25,88,197,91,109,179,234,183,250,
104,109,111,157,110,221,104,125,199,134,98,19,104,83,104,211,99,243,171,173,153,45,215,182,198,246,218,92,242,92,223,185,171,231,118,207,125,110,103,110,199,183,219,99,119,211,158,106,31,98,191,193,190,
215,254,131,131,163,131,200,161,205,97,210,209,192,49,209,177,214,241,6,139,198,10,99,109,102,157,119,66,59,121,57,173,118,58,230,244,214,217,193,89,236,124,216,249,23,23,166,75,154,75,139,203,163,121,
198,243,248,243,26,231,141,185,234,185,114,92,235,93,165,110,12,183,68,183,189,110,82,119,93,119,142,123,131,251,3,15,125,15,158,71,147,199,132,167,169,103,170,231,65,207,103,94,214,94,34,175,14,175,215,
108,103,246,74,246,41,111,196,219,207,187,196,123,208,135,226,19,229,83,237,115,223,87,207,55,217,183,213,119,202,207,222,111,133,223,41,127,180,127,144,255,54,255,27,1,90,1,220,128,230,128,169,64,199,
192,149,129,125,65,164,160,5,65,213,65,15,130,205,130,69,193,61,33,112,72,96,200,246,144,187,243,13,231,11,231,119,133,130,208,128,208,237,161,247,194,140,195,150,133,125,31,142,9,15,11,175,9,127,24,97,
19,81,16,209,191,128,186,96,201,130,150,5,175,34,189,34,203,34,239,68,153,68,73,162,122,163,21,163,19,162,155,163,95,199,120,199,148,199,72,99,173,98,87,198,94,138,211,136,19,196,117,199,99,227,163,227,
155,226,167,23,250,44,220,185,112,60,193,62,161,56,225,250,34,227,69,121,139,46,44,214,88,156,190,248,248,18,197,37,156,37,71,18,209,137,49,137,45,137,239,57,161,156,6,206,244,210,128,165,181,75,167,184,
108,238,46,238,19,158,7,111,7,111,146,239,202,47,231,79,36,185,38,149,39,61,74,118,77,222,158,60,153,226,158,82,145,242,84,192,22,84,11,158,167,250,167,214,165,190,78,11,77,219,159,246,41,61,38,189,61,
3,151,145,152,113,84,72,17,166,9,251,50,181,51,243,50,135,179,204,179,138,179,164,203,156,151,237,92,54,37,10,18,53,101,67,217,139,178,187,197,52,217,207,212,128,196,68,178,94,50,154,227,150,83,147,243,
38,55,58,247,72,158,114,158,48,111,96,185,217,242,77,203,39,242,125,243,191,94,129,90,193,93,209,91,160,91,176,182,96,116,165,231,202,250,85,208,170,165,171,122,87,235,175,46,90,61,190,198,111,205,129,
181,132,181,105,107,127,40,180,46,44,47,124,185,46,102,93,79,145,86,209,154,162,177,245,126,235,91,139,21,138,69,197,55,54,184,108,168,219,136,218,40,216,56,184,105,238,166,170,77,31,75,120,37,23,75,173,
75,43,74,223,111,230,110,190,248,149,205,87,149,95,125,218,146,180,101,176,204,161,108,207,86,204,86,225,214,235,219,220,183,29,40,87,46,207,47,31,219,30,178,189,115,7,99,71,201,142,151,59,151,236,188,
80,97,87,81,183,139,176,75,178,75,90,25,92,217,93,101,80,181,181,234,125,117,74,245,72,141,87,77,123,173,102,237,166,218,215,187,121,187,175,236,241,216,211,86,167,85,87,90,247,110,175,96,239,205,122,
191,250,206,6,163,134,138,125,152,125,57,251,30,54,70,55,246,127,205,250,186,185,73,163,169,180,233,195,126,225,126,233,129,136,3,125,205,142,205,205,45,154,45,101,173,112,171,164,117,242,96,194,193,203,
223,120,127,211,221,198,108,171,111,167,183,151,30,2,135,36,135,30,127,155,248,237,245,195,65,135,123,143,176,142,180,125,103,248,93,109,7,181,163,164,19,234,92,222,57,213,149,210,37,237,142,235,30,62,
26,120,180,183,199,165,167,227,123,203,239,247,31,211,61,86,115,92,229,120,217,9,194,137,162,19,159,78,230,159,156,62,149,117,234,233,233,228,211,99,189,75,122,239,156,137,61,115,173,47,188,111,240,108,
208,217,243,231,124,207,157,233,247,236,63,121,222,245,252,177,11,206,23,142,94,100,93,236,186,228,112,169,115,192,126,160,227,7,251,31,58,6,29,6,59,135,28,135,186,47,59,93,238,25,158,55,124,226,138,251,
149,211,87,189,175,158,187,22,112,237,210,200,252,145,225,235,81,215,111,222,72,184,33,189,201,187,249,232,86,250,173,231,183,115,110,207,220,89,115,23,125,183,228,158,210,189,138,251,154,247,27,126,52,
253,177,93,234,32,61,62,234,61,58,240,96,193,131,59,99,220,177,39,63,101,255,244,126,188,232,33,249,97,197,132,206,68,243,35,219,71,199,38,125,39,47,63,94,248,120,252,73,214,147,153,167,197,63,43,255,
92,251,204,228,217,119,191,120,252,50,48,21,59,53,254,92,244,252,211,175,155,95,168,191,216,255,210,238,101,239,116,216,244,253,87,25,175,102,94,151,188,81,127,115,224,45,235,109,255,187,152,119,19,51,
185,239,177,239,43,63,152,126,232,249,24,244,241,238,167,140,79,159,126,3,247,132,243,251,199,209,59,120,0,0,0,32,99,72,82,77,0,0,122,38,0,0,128,132,0,0,250,0,0,0,128,232,0,0,117,48,0,0,234,96,0,0,58,
152,0,0,23,112,156,186,81,60,0,0,0,9,112,72,89,115,0,0,11,18,0,0,11,18,1,210,221,126,252,0,0,0,27,116,69,88,116,83,111,102,116,119,97,114,101,0,67,101,108,115,121,115,32,83,116,117,100,105,111,32,84,111,
111,108,193,167,225,124,0,0,21,36,73,68,65,84,120,156,237,157,121,184,95,211,185,199,63,39,9,73,200,64,141,53,68,68,144,186,74,81,74,66,212,80,90,180,77,185,189,104,208,20,65,141,105,35,53,213,92,83,112,
105,169,177,170,169,18,83,175,86,212,216,154,82,46,90,49,4,145,154,130,36,68,201,136,200,124,255,248,158,115,37,39,231,236,189,246,222,107,255,246,218,123,191,159,231,201,147,60,57,123,191,191,247,156,
243,251,254,246,90,239,122,135,166,37,75,150,96,24,70,219,52,153,64,12,163,125,76,32,134,17,129,9,196,48,34,48,129,24,70,4,38,16,195,136,192,4,98,24,17,152,64,12,35,2,19,136,97,68,96,2,49,140,8,76,32,
134,17,129,9,196,48,34,48,129,24,70,4,38,16,195,136,192,4,98,24,17,152,64,12,35,2,19,136,97,68,96,2,49,140,8,76,32,134,17,129,9,196,48,34,48,129,24,70,4,117,18,72,19,176,9,176,21,176,17,208,11,88,23,232,
6,172,4,116,2,158,0,78,5,230,20,228,99,209,236,6,92,11,108,8,204,111,254,51,29,152,2,76,6,94,1,158,3,158,5,166,22,228,99,67,169,186,64,54,6,246,2,190,5,236,0,244,112,184,231,190,230,123,234,198,218,192,
235,192,202,142,215,79,0,30,0,238,6,30,3,22,231,228,87,161,84,81,32,171,3,7,1,135,160,167,69,26,214,67,159,154,117,98,127,224,214,148,247,78,6,110,1,174,6,38,249,114,40,4,170,36,144,141,128,19,129,33,
64,151,12,118,230,3,107,0,179,61,248,84,38,190,130,150,79,89,88,4,252,17,56,31,120,33,179,71,1,80,5,129,172,9,156,3,28,14,116,244,96,239,36,96,164,7,59,101,228,116,224,108,180,95,203,194,98,224,38,224,
231,232,233,82,90,202,44,144,38,224,120,224,92,160,187,7,123,159,2,135,145,126,153,81,21,246,3,70,225,190,23,137,226,19,224,100,224,215,64,41,223,104,101,21,72,31,224,70,96,160,39,123,239,3,223,6,254,
233,201,94,217,217,10,184,7,88,199,147,189,199,128,193,148,112,95,87,70,129,236,131,30,223,171,120,178,247,58,176,7,240,150,39,123,85,97,3,224,33,20,9,244,193,52,224,0,224,81,79,246,26,66,217,4,114,26,
90,82,101,93,35,183,240,47,96,23,106,18,211,79,193,23,209,27,122,19,79,246,22,2,67,129,223,121,178,151,59,101,17,72,19,112,25,112,130,71,155,239,2,3,154,255,54,218,103,125,116,128,186,190,39,123,75,128,
17,192,165,158,236,229,74,89,4,114,13,112,164,71,123,115,144,56,198,123,180,89,101,182,0,158,196,207,198,189,133,227,129,43,60,218,203,133,50,8,228,23,104,105,229,147,3,128,219,60,219,172,58,131,129,63,
120,180,183,164,217,230,104,143,54,189,19,186,64,134,160,104,149,79,70,3,63,240,108,179,46,220,14,124,223,163,189,207,128,254,100,63,160,204,141,144,5,178,5,240,20,208,213,163,205,57,40,42,51,205,163,
205,58,177,46,240,26,126,127,39,111,2,219,0,51,61,218,244,70,168,2,233,12,60,15,244,243,108,247,66,224,20,207,54,235,198,21,192,177,158,109,222,8,28,234,217,166,23,66,21,72,30,251,142,37,40,141,251,109,
207,118,235,198,150,232,195,203,55,187,1,15,231,96,55,19,33,10,100,19,224,37,96,5,207,118,159,3,182,246,108,179,174,76,193,223,41,123,11,19,128,205,9,44,109,62,68,129,220,138,82,175,125,115,45,112,84,
14,118,235,200,253,192,158,57,216,253,33,240,251,28,236,166,38,52,129,124,25,165,73,251,58,41,95,154,51,208,41,188,145,157,188,62,196,222,64,43,136,96,158,34,161,9,228,122,148,182,158,7,103,3,103,229,
100,187,110,220,7,124,51,39,219,123,53,219,15,130,144,4,210,3,229,68,249,60,173,93,154,81,232,92,197,200,206,100,20,242,205,131,63,3,131,114,178,157,152,144,4,242,67,242,77,98,155,132,162,88,70,54,242,
138,98,181,48,31,149,77,7,209,56,35,36,129,220,137,138,117,242,100,32,48,54,231,215,104,77,19,18,230,151,208,250,122,67,148,248,183,54,42,237,237,137,158,154,43,162,138,200,197,192,2,116,202,60,7,152,
1,124,0,188,135,66,212,111,1,19,81,135,145,233,13,252,62,90,184,22,56,34,231,215,248,79,84,186,91,56,161,8,164,19,250,101,251,168,12,140,226,1,242,91,59,183,208,29,216,169,249,207,246,40,180,236,210,77,
37,13,239,160,34,175,255,5,254,222,252,239,133,57,189,22,72,224,227,145,152,243,228,6,242,219,139,38,34,20,129,108,67,227,170,249,246,5,238,242,108,115,35,180,110,222,7,101,9,251,62,195,113,101,54,58,
108,187,7,24,131,158,60,190,232,136,42,3,7,120,180,217,30,175,0,255,209,128,215,137,37,20,129,28,141,234,150,27,193,135,72,144,239,100,180,179,38,106,47,52,152,48,15,32,23,161,55,244,45,40,201,48,235,
154,254,18,96,120,86,167,28,89,140,150,158,31,55,232,245,218,37,20,129,252,10,56,174,129,175,55,30,237,71,210,36,200,237,132,124,29,68,113,79,138,164,124,130,210,251,175,36,93,230,236,9,192,229,94,61,
138,103,43,242,13,6,56,17,138,64,198,160,229,73,35,121,6,237,71,102,56,92,219,4,124,15,117,232,216,54,79,167,26,192,88,148,180,121,175,227,245,195,209,211,163,209,228,177,20,78,76,40,2,121,26,216,174,
128,215,125,25,9,115,82,196,53,223,6,206,67,167,252,85,226,57,212,7,235,47,237,124,189,35,18,198,176,134,121,180,44,67,129,223,20,244,218,255,79,40,2,121,25,216,172,160,215,254,8,56,152,229,79,111,183,
4,126,9,236,220,112,143,26,203,88,224,39,168,33,117,11,107,162,189,203,110,133,120,36,126,138,250,16,20,74,40,2,153,128,255,218,143,36,44,65,65,130,147,209,114,234,124,20,56,240,209,169,177,12,44,65,161,
213,147,80,104,250,6,116,78,83,36,38,144,165,24,71,250,70,211,62,121,27,9,164,87,209,142,20,196,28,242,63,139,114,229,24,224,170,162,157,8,69,32,127,3,118,45,218,9,35,40,130,104,172,17,138,64,110,196,
18,9,141,101,233,143,50,4,10,37,20,129,156,138,34,69,134,209,194,106,20,147,107,182,12,161,8,100,15,148,39,101,24,160,132,204,62,69,59,1,225,8,164,39,74,1,233,84,180,35,70,16,252,1,133,222,11,39,20,129,
128,242,134,124,141,51,48,202,205,129,4,50,167,37,36,129,12,35,128,184,183,81,56,115,81,87,249,89,69,59,2,97,9,100,13,212,78,166,44,9,128,70,62,4,213,26,54,36,129,64,126,221,50,140,242,176,35,26,183,16,
4,161,9,196,199,164,85,163,188,140,37,176,125,104,104,2,1,213,34,239,91,180,19,70,33,20,209,51,32,146,16,5,210,7,149,92,118,46,218,17,163,161,220,78,128,203,235,16,5,2,170,83,56,167,104,39,140,134,49,
29,245,229,125,175,104,71,90,19,170,64,58,161,60,156,175,22,237,136,209,16,6,163,250,147,224,8,85,32,0,125,129,127,224,111,220,179,17,38,215,225,119,254,164,87,66,22,8,192,222,192,221,64,135,162,29,49,
114,225,73,52,134,123,126,209,142,180,71,232,2,1,248,49,1,20,206,24,222,121,25,117,136,113,105,154,81,24,101,16,8,192,207,177,209,5,85,226,95,168,64,110,74,209,142,196,81,22,129,128,234,165,47,44,218,
9,35,51,47,1,187,83,146,65,170,101,18,8,168,95,235,213,88,90,124,89,121,8,141,145,14,34,17,209,133,178,9,4,244,233,115,59,176,106,209,142,24,137,184,2,117,42,201,179,185,182,119,202,40,16,128,13,144,72,
138,104,54,103,36,99,22,112,24,129,140,51,72,74,89,5,2,58,121,29,95,180,19,70,44,19,81,167,246,69,69,59,146,134,50,11,228,106,108,106,109,89,56,8,184,185,104,39,210,80,86,129,124,1,205,201,235,90,180,
35,134,19,207,227,222,24,176,43,234,234,216,3,29,16,127,140,26,218,125,72,1,251,151,70,9,164,23,240,117,84,239,209,15,13,156,89,5,253,16,186,160,113,99,51,208,16,207,55,128,23,81,247,245,39,81,235,254,
214,252,12,184,40,111,167,13,175,12,64,191,207,165,89,25,29,22,14,68,93,243,55,167,253,150,167,11,129,55,81,166,247,83,192,163,168,159,112,174,162,201,83,32,219,162,238,120,131,72,223,194,101,62,170,15,
184,11,109,202,255,141,62,85,222,0,122,103,119,209,104,32,45,99,213,186,163,122,159,255,66,205,177,179,148,53,76,7,254,7,85,162,62,140,122,12,123,197,183,64,186,163,105,181,71,163,161,149,62,89,128,70,
4,63,15,252,194,179,109,35,127,102,161,72,214,1,192,74,57,216,127,29,165,36,221,128,70,209,121,193,151,64,122,160,22,250,195,176,236,91,163,88,102,0,151,162,169,101,153,71,73,103,21,72,39,244,180,56,19,
109,156,13,35,20,166,161,150,182,55,146,97,233,149,69,32,253,81,46,127,16,211,72,13,163,29,158,70,7,149,47,167,185,57,141,64,186,160,164,193,227,176,58,13,163,28,204,7,206,70,239,219,197,73,110,76,42,
144,45,80,99,175,162,198,165,25,70,22,30,67,77,233,166,186,222,144,68,32,135,0,215,96,135,115,160,136,218,59,40,90,178,18,58,231,9,237,231,242,41,242,113,46,106,14,222,11,203,130,6,237,77,246,71,98,137,
197,69,32,29,128,139,81,38,102,157,153,135,186,142,223,140,14,188,230,45,245,181,14,192,214,40,132,121,56,122,67,22,193,76,224,122,116,46,240,60,203,46,39,186,160,174,133,7,163,230,208,117,110,241,186,
0,5,151,98,167,232,198,9,164,11,90,82,13,242,227,87,105,25,131,102,230,189,235,112,237,23,208,7,202,161,185,122,180,60,215,161,162,178,153,14,215,246,69,66,250,122,158,14,149,128,243,80,181,106,187,68,
9,164,27,112,15,213,31,131,28,199,89,104,131,151,148,161,104,73,154,119,32,99,17,112,4,240,219,132,247,117,64,99,174,143,245,238,81,185,184,10,253,12,218,20,66,123,2,233,134,38,62,245,207,207,175,82,112,
33,112,74,134,251,143,67,7,86,121,114,52,202,108,78,203,40,180,191,172,51,87,161,21,194,114,180,37,144,38,224,94,224,155,57,59,21,58,79,160,36,186,68,97,193,54,184,139,252,150,168,119,162,18,214,44,116,
5,94,0,54,206,238,78,169,25,14,252,119,235,255,108,75,32,123,2,247,55,194,163,192,217,14,53,174,203,202,134,168,139,135,239,8,210,2,180,151,120,199,131,173,65,72,200,117,102,18,250,93,45,67,91,2,57,12,
135,221,125,197,121,10,216,193,163,189,59,129,253,60,218,3,184,3,101,196,250,160,9,165,146,247,246,100,175,140,60,135,34,145,203,208,150,64,250,0,19,128,21,27,224,84,168,156,130,223,22,67,131,81,136,216,
39,190,231,248,93,134,146,77,235,200,2,212,197,243,161,214,95,104,111,147,62,4,69,69,154,114,117,43,92,190,133,223,101,230,198,104,153,229,147,190,168,46,198,23,7,18,104,3,233,156,89,140,130,20,109,150,
4,71,133,121,143,66,187,251,58,138,100,27,96,156,71,123,93,209,201,182,79,186,162,74,76,95,236,4,60,238,209,94,25,88,140,194,241,237,134,200,227,14,10,135,160,253,72,71,175,110,133,207,87,81,57,167,47,
58,161,199,184,79,58,225,183,83,200,246,104,228,68,93,88,128,222,223,145,79,77,151,84,147,189,209,90,183,155,23,183,202,193,158,192,131,30,237,173,141,255,225,48,107,1,31,120,180,183,15,202,24,168,3,179,
80,120,124,185,61,71,107,92,147,21,183,68,229,174,27,100,243,171,52,180,25,19,207,192,238,56,252,50,18,178,43,240,136,71,123,39,3,23,120,180,23,42,111,0,223,65,205,31,98,73,146,205,187,26,218,200,236,
153,206,175,82,241,32,126,191,207,145,192,8,143,246,64,93,93,78,246,104,239,97,52,171,163,202,140,65,27,114,151,124,53,32,121,61,72,19,250,116,61,143,106,135,129,23,161,40,209,36,15,182,58,55,219,105,
175,157,77,90,166,162,131,45,31,195,103,250,162,14,136,85,45,128,155,135,90,69,37,78,251,73,91,114,251,101,212,61,98,219,52,55,151,132,223,163,14,45,89,25,14,92,226,193,78,91,12,67,9,135,89,25,141,82,
245,171,200,83,232,240,219,105,73,213,154,44,53,233,29,81,130,215,217,84,183,147,201,119,200,182,113,221,12,53,192,91,217,143,59,203,241,49,138,184,77,204,96,99,63,116,210,95,53,62,66,211,146,175,37,67,
62,157,143,182,63,171,3,103,160,148,235,170,205,54,255,24,248,6,250,20,74,74,47,84,181,214,219,167,67,109,240,38,42,73,152,156,226,222,29,81,214,118,30,125,170,138,226,51,148,221,124,46,30,198,187,249,
108,28,183,46,90,231,253,8,53,144,171,10,159,160,67,211,36,169,34,3,209,178,101,157,92,60,90,158,201,104,137,244,68,130,123,134,160,131,224,208,74,133,211,50,27,45,251,47,198,99,72,61,143,214,163,61,208,
218,253,16,170,53,231,252,33,212,209,49,234,180,121,51,20,89,58,136,198,103,32,44,70,251,166,145,40,151,174,45,154,208,211,230,12,138,141,88,205,192,223,0,164,103,208,247,61,10,61,241,189,146,119,243,
234,141,80,42,245,46,40,149,161,71,130,123,39,163,37,202,189,232,151,63,218,187,119,233,120,27,53,78,158,200,231,77,27,250,160,229,202,230,197,185,181,12,47,162,167,201,91,40,197,165,39,176,41,42,177,
237,85,156,91,128,154,77,175,130,62,76,246,66,253,121,183,195,125,121,62,11,125,72,61,2,252,9,125,143,185,209,200,241,7,29,208,27,169,165,187,251,170,44,219,221,125,22,10,93,190,137,154,124,189,191,212,
189,61,208,167,78,85,195,144,117,226,25,224,107,173,254,111,69,36,152,126,232,48,122,13,244,193,243,25,250,16,154,129,122,239,190,138,4,145,181,136,205,153,50,205,7,121,26,27,185,86,5,98,27,37,132,68,
153,4,114,26,214,213,189,10,244,167,68,73,145,101,18,200,151,72,121,216,99,4,195,20,96,125,114,152,227,145,23,101,18,8,104,253,90,229,211,251,170,115,9,254,115,210,114,165,108,2,57,18,245,154,50,202,201,
230,164,236,178,94,20,101,19,72,55,212,197,195,87,12,221,104,28,143,81,194,78,142,101,19,8,192,249,100,107,230,102,20,195,32,84,83,84,42,202,40,144,181,208,89,73,149,242,135,170,206,4,52,104,169,116,111,
182,50,10,4,84,249,230,179,88,200,200,151,3,128,219,138,118,34,13,101,21,200,170,232,100,213,230,34,134,207,115,168,75,76,41,223,104,101,21,8,168,105,243,175,139,118,194,136,197,119,237,124,67,41,179,
64,58,162,222,185,91,21,237,136,209,46,183,81,242,74,197,50,11,4,36,142,103,176,209,98,33,50,19,37,32,250,110,119,212,80,202,46,16,80,126,214,105,69,59,97,44,199,161,104,70,121,169,169,130,64,86,64,51,
3,171,84,156,85,118,254,76,69,198,246,85,65,32,160,230,208,227,168,87,247,199,80,121,15,141,11,255,176,104,71,124,80,21,129,128,102,101,148,50,214,94,33,22,162,168,213,216,162,29,241,69,149,4,2,112,41,
54,174,186,72,124,183,108,45,156,170,9,164,35,154,204,91,247,249,138,69,224,171,209,94,80,84,77,32,160,250,245,39,8,167,129,66,29,120,28,245,15,243,209,6,53,40,170,40,16,128,245,80,100,107,253,162,29,
169,1,175,2,3,128,233,69,59,146,7,85,21,8,168,68,119,44,234,74,111,228,195,187,72,28,239,22,237,72,94,84,89,32,160,169,165,127,163,186,189,131,139,228,125,212,132,206,247,236,197,160,168,186,64,64,61,
152,30,36,89,211,58,35,154,105,168,225,91,169,202,103,211,80,7,129,128,26,61,60,128,149,234,250,224,77,96,15,252,78,216,13,150,186,8,4,52,70,238,65,96,205,162,29,41,49,47,162,201,91,239,199,93,88,21,234,
36,16,208,36,165,7,209,100,38,35,25,143,162,252,170,89,5,251,209,80,234,38,16,208,40,180,123,80,149,155,111,38,161,89,127,227,80,197,227,44,252,206,50,111,139,46,40,8,209,23,5,37,118,197,255,176,213,91,
209,184,132,121,158,237,6,79,29,5,2,106,248,48,26,77,144,202,202,2,52,59,228,26,84,155,18,2,219,3,63,6,126,64,246,90,153,11,80,57,65,45,223,40,117,21,8,168,83,252,249,192,73,25,108,140,1,78,32,231,22,
252,25,216,8,13,174,220,43,197,189,243,80,163,190,81,94,61,42,25,117,22,72,11,39,1,23,38,188,103,46,112,44,240,91,255,238,228,194,145,192,229,104,57,230,202,238,232,12,169,214,152,64,224,47,36,251,132,
157,9,236,67,178,113,103,33,48,16,184,27,13,211,113,225,76,224,156,252,220,41,7,117,23,200,118,104,238,136,43,159,162,3,178,52,67,61,67,96,0,26,37,231,50,151,112,22,218,236,215,42,106,213,154,186,11,228,
54,84,104,229,202,129,40,162,83,102,6,227,62,144,116,4,249,205,120,47,5,117,22,200,90,104,14,162,107,148,167,74,245,14,55,163,8,87,28,175,163,114,230,218,82,103,129,28,15,252,210,241,218,217,232,156,225,
223,9,236,175,129,194,173,95,68,117,18,19,81,31,175,133,9,108,180,197,10,40,117,102,211,230,127,79,69,75,190,36,53,224,107,3,175,225,86,195,63,0,149,14,212,146,58,11,228,17,220,219,241,95,0,156,234,120,
109,63,20,62,254,46,203,15,29,157,6,92,214,252,39,105,113,81,23,84,210,122,2,18,223,210,44,2,238,106,246,241,53,71,123,35,113,27,102,115,41,112,162,163,205,202,81,87,129,172,140,38,167,174,224,112,237,
98,180,89,157,236,112,237,254,192,239,136,15,167,254,19,69,194,166,57,216,4,88,7,141,195,222,50,230,186,185,192,193,192,31,29,108,246,66,39,255,113,243,220,199,163,46,37,181,164,174,2,217,13,248,171,227,
181,143,162,57,239,113,236,133,14,14,93,71,85,191,8,236,128,34,99,81,116,71,75,168,205,28,237,46,66,53,249,46,223,223,227,104,126,125,20,75,80,22,116,45,163,89,117,21,200,137,192,197,142,215,158,138,150,
88,81,244,68,133,67,73,51,133,93,102,246,253,10,56,46,161,221,169,104,143,242,113,204,117,167,227,118,214,49,144,10,181,242,73,66,93,5,114,61,112,184,227,181,46,39,202,195,73,23,14,253,12,45,159,102,180,
243,245,53,81,57,235,138,41,108,31,15,92,17,115,205,30,168,78,38,142,195,129,27,82,248,80,122,234,42,144,251,112,111,13,212,139,248,154,235,39,209,114,41,13,131,129,91,218,249,218,143,72,159,206,242,40,
241,75,195,222,184,229,145,213,246,84,189,174,2,121,26,157,162,187,176,50,241,251,132,57,164,111,123,58,146,246,19,38,47,3,134,165,180,59,157,248,134,21,221,144,239,113,92,14,252,36,165,31,165,166,174,
2,25,135,251,92,145,142,40,146,21,69,150,31,226,213,104,24,80,91,36,89,10,182,102,1,241,75,179,142,184,157,203,92,5,28,147,210,143,82,83,87,129,60,1,244,119,188,182,7,241,159,178,31,146,190,189,208,185,
192,25,237,124,45,203,44,198,247,208,254,38,138,158,40,249,50,14,151,96,66,37,169,171,64,238,71,181,213,46,108,66,252,225,91,146,61,77,107,246,70,103,28,109,177,47,110,103,26,109,241,39,224,123,49,215,
108,138,26,191,197,97,123,144,154,225,154,139,4,170,58,28,19,115,77,146,4,192,165,249,0,5,1,218,43,101,237,138,14,40,211,12,43,253,62,112,103,204,53,223,69,66,138,227,24,180,204,170,29,117,21,200,153,
192,89,142,215,94,68,252,50,167,19,58,29,143,59,233,110,205,81,192,181,49,215,156,128,54,201,73,248,7,138,170,45,138,185,238,18,20,162,142,227,27,184,31,172,86,138,186,10,228,0,84,147,238,130,107,170,
69,63,20,238,117,237,189,117,123,179,31,113,191,128,14,104,153,229,58,177,233,35,148,36,249,186,195,181,47,227,118,66,239,18,234,174,36,117,21,72,31,146,53,62,251,10,240,130,195,117,155,163,164,193,190,
49,215,93,141,158,12,11,28,95,191,51,112,37,241,17,173,87,209,190,101,130,131,205,173,129,103,29,174,115,217,236,87,150,186,10,4,148,168,231,218,30,231,38,224,16,199,107,187,162,53,251,161,168,129,118,
11,159,161,158,92,23,3,127,119,180,213,154,93,208,146,104,119,36,154,22,94,66,39,221,215,224,222,102,104,52,110,35,154,111,65,123,172,90,82,103,129,92,7,12,117,188,118,17,58,55,25,159,240,53,86,67,159,
190,243,144,32,125,205,207,232,140,196,221,25,152,66,242,209,3,91,161,61,147,75,98,229,16,106,220,217,164,206,2,217,25,165,99,184,242,36,74,218,139,219,248,134,78,39,244,4,251,154,195,181,115,81,229,165,
203,105,123,37,169,179,64,154,80,35,230,222,9,238,73,82,56,21,42,23,1,63,115,188,246,86,84,135,95,91,234,44,16,80,126,81,210,161,147,67,129,223,228,224,75,35,56,130,248,176,242,210,108,79,178,174,47,149,
163,238,2,89,9,120,27,88,61,193,61,139,81,4,234,202,92,60,202,143,97,232,195,32,174,130,176,133,191,162,243,143,90,83,119,129,64,186,131,56,128,27,81,33,211,39,126,221,241,78,55,116,10,126,112,130,123,
150,160,131,198,90,63,61,192,4,2,202,104,125,150,228,167,224,160,195,179,17,192,29,196,103,252,54,154,14,104,255,112,17,176,110,194,123,175,71,203,177,218,99,2,17,219,161,12,223,180,157,208,95,69,111,
170,219,80,216,181,72,214,67,231,27,67,81,162,101,82,166,162,204,129,143,124,58,85,86,76,32,159,51,2,21,47,101,101,34,159,207,7,153,129,66,165,121,210,21,165,183,108,140,78,199,211,136,162,133,69,104,
190,200,227,30,252,170,4,38,144,207,105,66,75,165,253,138,118,164,64,106,223,106,180,53,38,144,101,233,140,154,24,236,92,180,35,5,80,219,178,218,40,76,32,203,211,3,141,68,216,177,104,71,26,200,117,40,
245,222,222,12,173,48,129,180,77,87,116,138,236,99,68,91,232,156,131,234,99,140,54,48,129,180,79,7,84,43,126,58,238,221,18,203,196,108,148,62,127,71,209,142,132,140,9,36,158,93,80,42,121,149,70,71,143,
69,61,183,146,212,196,212,18,19,136,27,93,80,146,226,137,184,77,103,10,149,105,168,7,87,109,211,215,147,98,2,73,198,90,192,79,209,136,229,238,5,251,146,132,201,168,80,235,122,242,63,151,169,20,38,144,
116,172,132,90,234,28,132,150,96,157,163,47,47,132,153,40,26,119,19,74,60,44,123,29,75,33,152,64,178,211,5,77,97,234,143,26,55,108,138,158,52,61,80,162,96,158,27,252,133,168,152,105,54,202,11,155,8,188,
130,78,194,199,17,94,126,88,233,48,129,24,70,4,38,16,195,136,192,4,98,24,17,152,64,12,35,2,19,136,97,68,96,2,49,140,8,76,32,134,17,129,9,196,48,34,48,129,24,70,4,38,16,195,136,192,4,98,24,17,152,64,12,
35,2,19,136,97,68,96,2,49,140,8,76,32,134,17,129,9,196,48,34,48,129,24,70,4,38,16,195,136,192,4,98,24,17,152,64,12,35,2,19,136,97,68,240,127,198,61,219,188,0,202,252,213,0,0,0,0,73,69,78,68,174,66,96,
130,0,0};

const char* PluginEditor::kobe_softBianco_png = (const char*) resource_PluginEditor_kobe_softBianco_png;
const int PluginEditor::kobe_softBianco_pngSize = 8216;

// JUCER_RESOURCE: bassWhiteLulu_png, 13081, "../images/bass white lulu.png"
static const unsigned char resource_PluginEditor_bassWhiteLulu_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,2,102,0,0,1,204,8,6,0,0,0,127,67,100,159,0,0,0,4,103,65,77,65,0,0,177,143,11,
252,97,5,0,0,10,55,105,67,67,80,115,82,71,66,32,73,69,67,54,49,57,54,54,45,50,46,49,0,0,72,137,157,150,119,84,83,217,22,135,207,189,55,189,80,146,16,138,148,208,107,104,82,2,72,13,189,72,145,46,42,49,
9,16,74,192,144,0,34,54,68,84,112,68,81,145,166,8,50,40,224,128,163,67,145,177,34,138,133,1,81,177,235,4,25,68,212,113,112,20,27,150,73,100,173,25,223,188,121,239,205,155,223,31,247,126,107,159,189,207,
221,103,239,125,214,186,0,144,252,131,5,194,76,88,9,128,12,161,88,20,225,231,197,136,141,139,103,96,7,1,12,240,0,3,108,0,224,112,179,179,66,22,248,70,2,153,2,124,216,140,108,153,19,248,23,189,186,14,32,
249,251,42,211,63,140,193,0,255,159,148,185,89,34,49,0,80,152,140,231,242,248,217,92,25,23,201,56,61,87,156,37,183,79,201,152,182,52,77,206,48,74,206,34,89,130,50,86,147,115,242,44,91,124,246,153,101,
15,57,243,50,132,60,25,203,115,206,226,101,240,228,220,39,227,141,57,18,190,140,145,96,25,23,231,8,248,185,50,190,38,99,131,116,73,134,64,198,111,228,177,25,124,78,54,0,40,146,220,46,230,115,83,100,108,
45,99,146,40,50,130,45,227,121,0,224,72,201,95,240,210,47,88,204,207,19,203,15,197,206,204,90,46,18,36,167,136,25,38,92,83,134,141,147,19,139,225,207,207,77,231,139,197,204,48,14,55,141,35,226,49,216,
153,25,89,28,225,114,0,102,207,252,89,20,121,109,25,178,34,59,216,56,57,56,48,109,45,109,190,40,212,127,93,252,155,146,247,118,150,94,132,127,238,25,68,31,248,195,246,87,126,153,13,0,176,166,101,181,217,
250,135,109,105,21,0,93,235,1,80,187,253,135,205,96,47,0,138,178,190,117,14,125,113,30,186,124,94,82,196,226,44,103,43,171,220,220,92,75,1,159,107,41,47,232,239,250,159,14,127,67,95,124,207,82,190,221,
239,229,97,120,243,147,56,146,116,49,67,94,55,110,102,122,166,68,196,200,206,226,112,249,12,230,159,135,248,31,7,254,117,30,22,17,252,36,190,136,47,148,69,68,203,166,76,32,76,150,181,91,200,19,136,5,153,
66,134,64,248,159,154,248,15,195,254,164,217,185,150,137,218,248,17,208,150,88,2,165,33,26,64,126,30,0,40,42,17,32,9,123,100,43,208,239,125,11,198,71,3,249,205,139,209,153,152,157,251,207,130,254,125,
87,184,76,254,200,22,36,127,142,99,71,68,50,184,18,81,206,236,154,252,90,2,52,32,0,69,64,3,234,64,27,232,3,19,192,4,182,192,17,184,0,15,224,3,2,65,40,136,4,113,96,49,224,130,20,144,1,68,32,23,20,128,181,
160,24,148,130,173,96,39,168,6,117,160,17,52,131,54,112,24,116,129,99,224,52,56,7,46,129,203,96,4,220,1,82,48,14,158,128,41,240,10,204,64,16,132,133,200,16,21,82,135,116,32,67,200,28,178,133,88,144,27,
228,3,5,67,17,80,28,148,8,37,67,66,72,2,21,64,235,160,82,168,28,170,134,234,161,102,232,91,232,40,116,26,186,0,13,67,183,160,81,104,18,250,21,122,7,35,48,9,166,193,90,176,17,108,5,179,96,79,56,8,142,132,
23,193,201,240,50,56,31,46,130,183,192,149,112,3,124,16,238,132,79,195,151,224,17,88,10,63,129,167,17,128,16,17,58,162,139,48,17,22,194,70,66,145,120,36,9,17,33,171,144,18,164,2,105,64,218,144,30,164,
31,185,138,72,145,167,200,91,20,6,69,69,49,80,76,148,11,202,31,21,133,226,162,150,161,86,161,54,163,170,81,7,80,157,168,62,212,85,212,40,106,10,245,17,77,70,107,162,205,209,206,232,0,116,44,58,25,157,
139,46,70,87,160,155,208,29,232,179,232,17,244,56,250,21,6,131,161,99,140,49,142,24,127,76,28,38,21,179,2,179,25,179,27,211,142,57,133,25,198,140,97,166,177,88,172,58,214,28,235,138,13,197,114,176,98,
108,49,182,10,123,16,123,18,123,5,59,142,125,131,35,226,116,112,182,56,95,92,60,78,136,43,196,85,224,90,112,39,112,87,112,19,184,25,188,18,222,16,239,140,15,197,243,240,203,241,101,248,70,124,15,126,8,
63,142,159,33,40,19,140,9,174,132,72,66,42,97,45,161,146,208,70,56,75,184,75,120,65,36,18,245,136,78,196,112,162,128,184,134,88,73,60,68,60,79,28,37,190,37,81,72,102,36,54,41,129,36,33,109,33,237,39,157,
34,221,34,189,32,147,201,70,100,15,114,60,89,76,222,66,110,38,159,33,223,39,191,81,160,42,88,42,4,40,240,20,86,43,212,40,116,42,92,81,120,166,136,87,52,84,244,84,92,172,152,175,88,161,120,68,113,72,241,
169,18,94,201,72,137,173,196,81,90,165,84,163,116,84,233,134,210,180,50,85,217,70,57,84,57,67,121,179,114,139,242,5,229,71,20,44,197,136,226,67,225,81,138,40,251,40,103,40,99,84,132,170,79,101,83,185,
212,117,212,70,234,89,234,56,13,67,51,166,5,208,82,105,165,180,111,104,131,180,41,21,138,138,157,74,180,74,158,74,141,202,113,21,41,29,161,27,209,3,232,233,244,50,250,97,250,117,250,59,85,45,85,79,85,
190,234,38,213,54,213,43,170,175,213,230,168,121,168,241,213,74,212,218,213,70,212,222,169,51,212,125,212,211,212,183,169,119,169,223,211,64,105,152,105,132,107,228,106,236,209,56,171,241,116,14,109,142,
203,28,238,156,146,57,135,231,220,214,132,53,205,52,35,52,87,104,238,211,28,208,156,214,210,214,242,211,202,210,170,210,58,163,245,84,155,174,237,161,157,170,189,67,251,132,246,164,14,85,199,77,71,160,
179,67,231,164,206,99,134,10,195,147,145,206,168,100,244,49,166,116,53,117,253,117,37,186,245,186,131,186,51,122,198,122,81,122,133,122,237,122,247,244,9,250,44,253,36,253,29,250,189,250,83,6,58,6,33,
6,5,6,173,6,183,13,241,134,44,195,20,195,93,134,253,134,175,141,140,141,98,140,54,24,117,25,61,50,86,51,14,48,206,55,110,53,190,107,66,54,113,55,89,102,210,96,114,205,20,99,202,50,77,51,221,109,122,217,
12,54,179,55,75,49,171,49,27,50,135,205,29,204,5,230,187,205,135,45,208,22,78,22,66,139,6,139,27,76,18,211,147,153,195,108,101,142,90,210,45,131,45,11,45,187,44,159,89,25,88,197,91,109,179,234,183,250,
104,109,111,157,110,221,104,125,199,134,98,19,104,83,104,211,99,243,171,173,153,45,215,182,198,246,218,92,242,92,223,185,171,231,118,207,125,110,103,110,199,183,219,99,119,211,158,106,31,98,191,193,190,
215,254,131,131,163,131,200,161,205,97,210,209,192,49,209,177,214,241,6,139,198,10,99,109,102,157,119,66,59,121,57,173,118,58,230,244,214,217,193,89,236,124,216,249,23,23,166,75,154,75,139,203,163,121,
198,243,248,243,26,231,141,185,234,185,114,92,235,93,165,110,12,183,68,183,189,110,82,119,93,119,142,123,131,251,3,15,125,15,158,71,147,199,132,167,169,103,170,231,65,207,103,94,214,94,34,175,14,175,215,
108,103,246,74,246,41,111,196,219,207,187,196,123,208,135,226,19,229,83,237,115,223,87,207,55,217,183,213,119,202,207,222,111,133,223,41,127,180,127,144,255,54,255,27,1,90,1,220,128,230,128,169,64,199,
192,149,129,125,65,164,160,5,65,213,65,15,130,205,130,69,193,61,33,112,72,96,200,246,144,187,243,13,231,11,231,119,133,130,208,128,208,237,161,247,194,140,195,150,133,125,31,142,9,15,11,175,9,127,24,97,
19,81,16,209,191,128,186,96,201,130,150,5,175,34,189,34,203,34,239,68,153,68,73,162,122,163,21,163,19,162,155,163,95,199,120,199,148,199,72,99,173,98,87,198,94,138,211,136,19,196,117,199,99,227,163,227,
155,226,167,23,250,44,220,185,112,60,193,62,161,56,225,250,34,227,69,121,139,46,44,214,88,156,190,248,248,18,197,37,156,37,71,18,209,137,49,137,45,137,239,57,161,156,6,206,244,210,128,165,181,75,167,184,
108,238,46,238,19,158,7,111,7,111,146,239,202,47,231,79,36,185,38,149,39,61,74,118,77,222,158,60,153,226,158,82,145,242,84,192,22,84,11,158,167,250,167,214,165,190,78,11,77,219,159,246,41,61,38,189,61,
3,151,145,152,113,84,72,17,166,9,251,50,181,51,243,50,135,179,204,179,138,179,164,203,156,151,237,92,54,37,10,18,53,101,67,217,139,178,187,197,52,217,207,212,128,196,68,178,94,50,154,227,150,83,147,243,
38,55,58,247,72,158,114,158,48,111,96,185,217,242,77,203,39,242,125,243,191,94,129,90,193,93,209,91,160,91,176,182,96,116,165,231,202,250,85,208,170,165,171,122,87,235,175,46,90,61,190,198,111,205,129,
181,132,181,105,107,127,40,180,46,44,47,124,185,46,102,93,79,145,86,209,154,162,177,245,126,235,91,139,21,138,69,197,55,54,184,108,168,219,136,218,40,216,56,184,105,238,166,170,77,31,75,120,37,23,75,173,
75,43,74,223,111,230,110,190,248,149,205,87,149,95,125,218,146,180,101,176,204,161,108,207,86,204,86,225,214,235,219,220,183,29,40,87,46,207,47,31,219,30,178,189,115,7,99,71,201,142,151,59,151,236,188,
80,97,87,81,183,139,176,75,178,75,90,25,92,217,93,101,80,181,181,234,125,117,74,245,72,141,87,77,123,173,102,237,166,218,215,187,121,187,175,236,241,216,211,86,167,85,87,90,247,110,175,96,239,205,122,
191,250,206,6,163,134,138,125,152,125,57,251,30,54,70,55,246,127,205,250,186,185,73,163,169,180,233,195,126,225,126,233,129,136,3,125,205,142,205,205,45,154,45,101,173,112,171,164,117,242,96,194,193,203,
223,120,127,211,221,198,108,171,111,167,183,151,30,2,135,36,135,30,127,155,248,237,245,195,65,135,123,143,176,142,180,125,103,248,93,109,7,181,163,164,19,234,92,222,57,213,149,210,37,237,142,235,30,62,
26,120,180,183,199,165,167,227,123,203,239,247,31,211,61,86,115,92,229,120,217,9,194,137,162,19,159,78,230,159,156,62,149,117,234,233,233,228,211,99,189,75,122,239,156,137,61,115,173,47,188,111,240,108,
208,217,243,231,124,207,157,233,247,236,63,121,222,245,252,177,11,206,23,142,94,100,93,236,186,228,112,169,115,192,126,160,227,7,251,31,58,6,29,6,59,135,28,135,186,47,59,93,238,25,158,55,124,226,138,251,
149,211,87,189,175,158,187,22,112,237,210,200,252,145,225,235,81,215,111,222,72,184,33,189,201,187,249,232,86,250,173,231,183,115,110,207,220,89,115,23,125,183,228,158,210,189,138,251,154,247,27,126,52,
253,177,93,234,32,61,62,234,61,58,240,96,193,131,59,99,220,177,39,63,101,255,244,126,188,232,33,249,97,197,132,206,68,243,35,219,71,199,38,125,39,47,63,94,248,120,252,73,214,147,153,167,197,63,43,255,
92,251,204,228,217,119,191,120,252,50,48,21,59,53,254,92,244,252,211,175,155,95,168,191,216,255,210,238,101,239,116,216,244,253,87,25,175,102,94,151,188,81,127,115,224,45,235,109,255,187,152,119,19,51,
185,239,177,239,43,63,152,126,232,249,24,244,241,238,167,140,79,159,126,3,247,132,243,251,199,209,59,120,0,0,0,32,99,72,82,77,0,0,122,38,0,0,128,132,0,0,250,0,0,0,128,232,0,0,117,48,0,0,234,96,0,0,58,
152,0,0,23,112,156,186,81,60,0,0,0,9,112,72,89,115,0,0,11,18,0,0,11,18,1,210,221,126,252,0,0,0,27,116,69,88,116,83,111,102,116,119,97,114,101,0,67,101,108,115,121,115,32,83,116,117,100,105,111,32,84,111,
111,108,193,167,225,124,0,0,32,0,73,68,65,84,120,156,237,221,121,204,95,213,157,223,241,119,158,145,156,103,36,215,76,61,166,114,156,202,64,106,136,234,216,45,203,196,1,21,136,106,32,3,102,194,146,176,
116,108,50,97,25,177,180,4,90,22,5,130,2,130,148,192,136,37,98,153,178,164,44,18,75,4,120,6,226,17,224,134,69,98,19,155,88,18,12,21,96,137,165,133,208,129,56,197,117,36,198,154,58,253,227,107,215,246,
227,159,159,231,183,156,123,207,185,247,190,95,82,100,252,227,247,156,251,53,68,226,163,123,206,249,126,63,247,251,223,255,30,73,146,36,229,247,57,131,153,36,73,82,25,12,102,146,36,73,133,48,152,73,146,
36,21,194,96,38,73,146,84,8,131,153,36,73,82,33,12,102,146,36,73,133,48,152,73,146,36,21,194,96,38,73,146,84,8,131,153,36,73,82,33,12,102,146,36,73,133,48,152,73,146,36,21,194,96,38,73,146,84,8,131,153,
36,73,82,33,12,102,146,36,73,133,48,152,73,146,36,21,194,96,38,73,146,84,8,131,153,36,73,82,33,12,102,146,36,73,133,48,152,73,146,36,21,194,96,38,73,146,84,8,131,153,36,73,82,33,12,102,146,36,73,133,48,
152,73,146,36,21,194,96,38,73,146,84,8,131,153,36,73,82,33,12,102,146,36,73,133,48,152,73,146,36,21,194,96,38,73,146,84,8,131,153,36,73,82,33,12,102,146,36,73,133,48,152,73,146,36,21,194,96,38,73,146,
84,8,131,153,36,73,82,33,12,102,146,36,73,133,48,152,73,146,36,21,194,96,38,73,146,84,8,131,153,36,73,82,33,12,102,146,36,73,133,48,152,73,146,36,21,194,96,38,73,146,84,8,131,153,36,73,82,33,12,102,146,
36,73,133,48,152,73,146,36,21,194,96,38,73,146,84,8,131,153,36,73,82,33,12,102,146,36,73,133,48,152,73,146,36,21,194,96,38,73,146,84,8,131,153,36,73,82,33,12,102,146,36,73,133,48,152,73,146,36,21,194,
96,38,73,146,84,8,131,153,36,73,82,33,12,102,146,36,73,133,48,152,73,146,36,21,194,96,38,73,146,84,8,131,153,36,73,82,33,12,102,146,36,73,133,48,152,73,146,36,21,194,96,38,73,146,84,8,131,153,36,73,82,
33,12,102,146,36,73,133,48,152,73,146,36,21,194,96,38,73,146,84,8,131,153,36,73,82,33,12,102,146,36,73,133,48,152,73,146,36,21,194,96,38,73,146,84,8,131,153,36,73,82,33,12,102,146,36,73,133,48,152,73,
146,36,21,194,96,38,73,146,84,8,131,153,36,73,82,33,12,102,146,36,73,133,48,152,73,146,36,21,194,96,38,73,146,84,8,131,153,36,73,82,33,12,102,146,36,73,133,48,152,73,146,36,21,194,96,38,73,245,154,1,44,
218,248,191,157,128,63,1,102,1,115,39,124,111,3,240,234,198,191,254,8,248,159,192,43,192,147,192,27,181,84,42,169,118,6,51,73,170,222,34,224,80,224,91,192,130,4,235,173,1,158,6,158,5,150,3,171,19,172,
41,169,0,6,51,73,170,198,44,224,47,129,147,128,121,21,63,235,113,224,6,224,111,137,55,109,146,26,202,96,38,73,105,237,12,156,15,28,15,76,171,249,217,31,1,183,2,63,1,62,169,249,217,146,18,48,152,73,82,
26,51,128,43,136,183,100,99,153,107,89,11,252,16,184,30,223,160,73,141,98,48,147,164,209,29,1,252,53,48,39,119,33,19,188,1,156,70,92,24,144,212,0,6,51,73,26,222,44,34,144,29,147,187,144,41,44,7,78,0,214,
229,46,68,210,228,12,102,146,52,156,35,128,159,18,225,172,9,222,34,110,134,122,131,83,42,152,193,76,146,6,119,30,112,89,238,34,134,176,6,88,6,172,204,93,136,164,222,12,102,146,212,191,49,226,45,217,137,
185,11,25,193,6,224,63,1,215,230,46,68,210,182,12,102,146,212,159,49,224,14,96,105,238,66,18,185,4,184,40,119,17,146,182,102,48,147,84,130,217,192,98,96,38,176,144,56,164,254,38,209,151,235,23,192,103,
249,74,251,255,238,162,61,161,108,147,139,136,128,38,169,16,6,51,73,185,140,1,127,1,156,9,236,62,201,247,62,35,194,217,85,228,107,251,112,25,113,174,172,141,150,1,119,231,46,66,82,48,152,73,202,97,95,
224,22,96,183,1,127,110,37,112,10,240,126,242,138,182,239,68,162,214,182,90,15,28,132,189,206,164,34,24,204,36,213,237,28,224,175,24,190,59,254,71,192,225,192,11,201,42,218,190,249,192,75,192,120,13,207,
202,233,35,98,11,217,49,78,82,102,6,51,73,117,74,213,102,98,61,112,8,49,188,187,42,227,68,40,155,95,225,51,74,178,146,248,103,42,41,35,131,153,164,186,44,37,14,208,167,178,22,248,42,209,56,181,10,87,16,
111,247,186,228,36,98,8,186,164,76,12,102,146,234,48,19,120,123,227,175,41,61,13,236,151,120,77,136,203,8,47,145,127,24,121,221,214,0,187,110,252,85,82,6,6,51,73,117,184,13,56,190,162,181,15,7,86,36,94,
243,41,226,130,66,23,221,76,92,176,144,148,129,193,76,82,213,230,0,239,0,211,42,90,127,21,113,112,61,149,131,129,135,19,174,215,52,235,129,93,128,15,115,23,34,117,145,193,76,82,213,206,0,174,169,248,25,
11,137,128,150,194,75,192,158,137,214,106,170,171,129,179,115,23,33,117,145,193,76,82,213,30,4,150,84,252,140,115,129,43,19,172,115,32,240,72,130,117,154,110,29,241,214,204,246,25,82,205,12,102,146,170,
246,1,177,157,89,165,59,129,239,36,88,231,231,192,97,9,214,105,3,103,105,74,25,24,204,36,165,50,131,56,159,117,52,240,37,96,22,48,183,166,103,63,14,28,48,226,26,115,128,255,65,247,110,98,110,207,58,96,
71,202,152,83,42,117,134,193,76,210,168,118,7,46,37,66,89,174,80,243,36,240,245,17,215,56,135,232,93,166,205,14,5,30,202,93,132,212,37,6,51,73,195,218,153,8,100,75,51,215,1,105,250,153,117,185,69,198,
246,164,218,34,150,212,39,131,153,164,97,236,15,220,79,250,134,177,195,26,53,152,45,0,126,137,219,152,19,173,33,182,51,55,228,46,68,234,10,131,153,164,65,157,12,92,71,117,125,201,134,49,106,48,187,20,
248,65,162,90,218,230,107,212,51,48,94,18,6,51,73,131,57,130,120,83,86,154,81,131,153,219,152,219,119,54,209,215,76,82,13,12,102,146,250,181,0,120,17,24,207,93,72,15,163,4,179,113,224,183,84,247,231,250,
4,248,5,113,203,113,147,69,196,165,137,38,120,0,56,50,119,17,82,87,24,204,36,245,99,58,240,26,113,224,191,68,163,4,179,125,137,55,102,169,61,14,92,76,220,24,237,101,14,240,31,136,201,8,211,43,120,126,
42,31,2,95,204,93,132,212,21,6,51,73,253,40,253,12,214,40,193,236,60,224,178,132,181,124,6,124,23,184,183,207,239,207,33,182,135,23,37,172,33,181,47,0,31,229,46,66,234,2,131,153,164,169,204,4,222,163,
236,183,58,253,186,17,56,109,194,103,15,19,61,216,82,88,75,244,83,123,117,192,159,27,7,238,161,220,169,3,135,0,43,115,23,33,117,129,193,76,210,84,206,2,174,202,93,68,34,203,128,187,183,248,253,24,113,
190,108,70,130,181,55,0,223,100,248,134,172,51,128,103,136,179,124,165,57,19,184,54,119,17,82,23,24,204,36,77,229,21,154,115,80,125,42,95,36,206,76,109,178,39,240,82,162,181,83,52,99,173,234,188,219,168,
110,6,78,201,93,132,212,5,6,51,73,147,153,9,124,76,59,26,175,190,11,236,50,225,179,51,128,107,18,172,189,97,227,218,239,39,88,171,196,65,234,143,2,7,229,46,66,234,2,131,153,164,201,28,76,156,193,106,131,
219,129,19,38,124,118,63,209,155,109,84,43,137,115,88,41,148,216,43,238,45,224,203,185,139,144,186,192,96,38,105,50,169,222,40,149,224,36,224,214,9,159,125,12,204,74,176,246,5,192,143,19,172,3,81,207,
199,137,214,74,101,13,240,199,185,139,144,186,192,96,38,105,50,165,183,201,24,196,174,192,234,45,126,191,27,240,102,162,181,143,6,150,39,90,11,224,55,148,51,135,20,98,171,246,15,114,23,33,117,129,193,
76,210,100,46,35,250,124,53,93,175,38,169,39,3,55,37,90,255,80,134,191,141,217,203,7,68,127,179,146,252,33,209,163,77,82,133,12,102,146,38,115,49,112,97,238,34,18,184,23,56,118,194,103,119,0,199,37,90,
127,98,27,142,81,253,3,101,13,137,7,216,129,232,211,38,169,66,6,51,73,147,57,29,184,46,119,17,9,156,70,52,151,221,210,123,192,220,68,235,95,2,92,148,104,173,185,68,109,165,241,141,153,84,3,131,153,164,
201,236,15,60,145,187,136,4,22,2,171,182,248,125,234,240,243,28,176,79,162,181,142,35,222,230,149,196,51,102,82,77,12,102,146,38,51,29,248,148,102,247,49,235,117,163,112,41,112,87,226,231,236,193,224,
163,152,122,121,22,216,59,193,58,41,125,2,236,152,187,8,169,11,12,102,146,166,242,4,241,230,172,169,86,0,135,79,248,236,6,224,212,196,207,73,209,203,172,196,30,102,0,47,3,123,229,46,66,234,2,131,153,164,
169,156,8,220,146,187,136,17,156,13,92,61,225,179,215,129,249,21,60,171,215,89,182,126,205,1,94,164,188,219,152,16,23,27,150,229,46,66,234,2,131,153,164,169,76,35,250,125,237,156,185,142,201,172,35,186,
211,247,114,18,91,111,49,206,36,250,132,85,97,61,209,211,108,197,128,63,55,155,24,197,180,40,121,69,105,140,18,56,37,13,192,96,38,169,31,85,156,201,74,233,105,96,191,62,191,91,199,118,225,5,192,149,68,
80,155,202,222,192,61,164,187,33,90,133,157,72,51,7,84,210,20,12,102,146,250,49,70,108,179,237,153,187,144,237,24,36,152,93,5,156,85,97,45,155,172,38,26,244,222,75,188,209,155,232,64,224,20,224,168,26,
106,25,197,42,226,86,171,164,26,24,204,36,245,107,14,240,75,210,204,150,76,109,144,96,246,18,245,7,204,151,137,112,246,247,192,151,136,109,225,146,70,46,77,38,229,28,80,73,83,48,152,73,26,196,222,196,
45,205,210,186,210,247,27,204,218,208,254,163,78,235,128,93,136,118,25,146,106,96,48,147,52,168,3,137,51,81,37,189,241,233,55,152,29,8,60,82,113,45,109,114,46,113,86,78,82,77,12,102,146,134,49,15,120,
120,227,175,37,232,55,152,93,10,252,160,226,90,218,98,37,49,156,125,67,238,66,164,46,49,152,73,26,214,116,226,141,202,89,27,255,58,167,126,131,89,211,155,229,214,101,53,209,80,214,161,229,82,205,12,102,
146,70,53,11,248,33,49,227,49,215,246,102,63,193,108,28,248,237,198,95,181,125,143,2,199,18,163,172,36,213,204,96,38,41,149,105,196,219,168,127,75,132,181,127,181,241,179,221,169,254,176,253,163,192,65,
83,124,103,95,224,169,138,235,104,178,117,192,21,192,127,198,237,75,41,27,131,153,164,170,189,9,236,86,241,51,110,38,122,130,77,230,60,162,175,152,182,246,33,240,19,226,159,161,91,151,82,102,6,51,73,85,
187,131,216,230,172,82,63,35,131,30,4,150,84,92,71,19,172,7,174,5,158,7,94,192,142,254,82,81,12,102,146,170,118,60,112,91,197,207,216,5,120,119,146,191,63,70,156,47,155,81,113,29,77,176,22,216,33,119,
17,146,122,51,152,73,170,218,56,240,1,213,93,12,232,231,224,255,238,192,43,21,61,191,105,12,102,82,193,12,102,146,234,80,101,255,176,67,136,158,91,147,57,3,184,166,162,231,55,205,251,196,80,114,73,5,50,
152,73,170,195,116,226,141,85,234,134,180,43,128,195,251,248,222,125,148,63,44,188,46,6,51,169,96,6,51,73,117,217,159,24,135,148,106,206,230,32,77,80,63,166,204,225,235,57,172,6,118,205,93,132,164,222,
12,102,146,234,116,20,49,103,115,212,190,102,31,1,95,7,222,234,227,187,187,17,45,59,20,86,1,11,115,23,33,169,55,131,153,164,186,45,33,90,104,12,123,25,96,21,49,195,177,223,54,15,39,2,183,12,249,172,54,
50,152,73,5,51,152,73,202,97,103,224,175,25,172,175,216,58,162,255,214,143,128,207,6,248,185,58,250,168,53,73,191,115,69,37,101,96,48,147,148,211,158,192,247,137,128,182,189,65,232,171,128,191,5,110,32,
182,48,7,245,14,17,4,21,12,102,82,193,12,102,146,74,177,59,177,189,57,143,232,78,255,43,224,19,70,235,76,63,23,120,111,244,210,90,165,159,185,162,146,50,49,152,73,106,179,165,192,93,185,139,40,204,67,
196,25,61,73,5,50,152,73,74,105,55,224,159,1,243,129,127,4,94,5,214,48,249,184,164,42,221,0,156,154,233,217,165,50,152,73,5,51,152,73,26,213,2,224,123,192,159,1,115,182,243,157,183,128,229,192,79,169,
55,164,189,70,212,167,205,12,102,82,193,12,102,146,134,53,27,184,138,216,46,236,215,6,224,191,0,231,19,183,44,171,52,19,248,77,197,207,104,162,7,128,35,115,23,33,169,55,131,153,164,97,44,38,206,110,205,
30,242,231,87,1,223,164,218,183,103,135,1,63,175,112,253,166,186,27,88,150,187,8,73,189,25,204,36,13,234,96,34,240,140,58,90,105,13,209,189,127,213,200,21,245,118,21,112,86,69,107,55,153,193,76,42,152,
193,76,210,32,246,4,158,1,198,19,173,247,46,240,85,162,45,70,106,207,3,139,42,88,183,233,12,102,82,193,12,102,146,250,53,13,120,133,184,113,153,82,21,125,181,166,3,159,50,250,76,206,54,186,29,56,33,119,
17,146,122,51,152,73,234,215,57,192,21,21,173,125,36,113,40,61,149,3,129,71,18,174,215,38,55,2,167,229,46,66,82,111,6,51,73,253,24,3,62,96,248,195,254,83,121,1,248,90,194,245,46,6,46,76,184,94,155,24,
204,164,130,25,204,36,245,227,8,224,254,138,159,241,21,224,141,68,107,61,1,236,159,104,173,182,49,152,73,5,51,152,73,234,199,53,192,25,21,63,227,108,224,234,4,235,76,35,206,151,165,186,160,208,54,6,51,
169,96,6,51,73,253,168,227,134,227,157,192,119,18,172,179,47,240,84,130,117,218,202,96,38,21,204,96,38,105,162,5,192,183,128,47,2,243,128,63,218,248,217,168,125,203,166,242,52,176,95,130,117,206,3,46,
75,176,78,91,93,77,188,157,148,84,32,131,153,36,128,25,192,247,129,227,128,185,153,106,120,25,216,43,193,58,15,2,75,18,172,211,86,151,19,35,177,36,21,200,96,38,117,219,56,240,239,129,139,136,112,150,211,
42,96,225,136,107,140,1,31,19,115,50,213,155,193,76,42,152,193,76,234,174,185,192,125,148,211,29,63,69,48,219,157,104,130,171,237,51,152,73,5,51,152,73,221,180,136,152,119,89,85,95,178,97,164,8,102,167,
3,215,37,168,165,205,12,102,82,193,12,102,82,247,44,32,230,93,230,222,186,156,40,69,48,187,15,56,42,65,45,109,102,48,147,10,102,48,147,186,101,22,240,34,176,115,230,58,122,73,17,204,126,77,189,111,1,95,
6,214,1,107,136,173,225,121,148,23,120,39,50,152,73,5,51,152,73,221,242,48,112,112,238,34,182,99,212,96,182,27,240,102,162,90,38,243,22,240,35,98,182,231,186,30,127,127,49,209,142,162,212,155,161,6,51,
169,96,6,51,169,59,150,16,173,36,74,53,106,48,59,17,184,37,81,45,189,108,32,90,138,92,189,241,175,167,178,24,184,139,178,206,241,129,193,76,42,154,193,76,234,134,49,224,37,226,214,98,169,62,163,255,89,
153,63,3,174,156,240,217,109,192,241,41,11,218,194,103,192,145,192,202,1,127,110,46,17,134,23,36,175,104,120,6,51,169,96,6,51,169,27,234,24,66,94,167,101,192,221,19,62,123,135,234,206,206,245,122,94,191,
118,38,206,245,205,74,86,205,104,12,102,82,193,12,102,82,55,220,79,132,179,182,216,9,120,127,139,223,207,1,62,168,232,89,247,2,199,142,184,198,82,98,91,179,4,151,16,13,133,37,21,200,96,38,181,223,24,240,
41,48,61,119,33,137,188,79,4,179,45,85,21,124,54,0,95,6,86,143,184,206,24,240,75,202,216,210,60,159,120,107,38,169,64,6,51,169,253,218,214,13,255,78,224,59,19,62,187,1,56,181,130,103,165,26,172,14,229,
12,87,247,141,153,84,48,131,153,212,126,199,0,247,228,46,34,161,147,128,91,39,124,246,26,213,188,141,74,249,118,105,30,240,118,162,181,70,225,25,51,169,96,6,51,169,253,206,2,174,202,93,68,66,95,38,122,
137,109,50,147,24,92,62,86,193,179,14,97,240,155,152,219,51,13,248,135,68,107,141,194,96,38,21,204,96,38,181,95,41,91,104,41,124,4,124,97,194,103,135,17,115,63,171,176,31,177,157,153,202,167,228,159,12,
96,48,147,10,102,48,147,218,239,28,224,138,220,69,36,178,28,56,122,194,103,87,16,127,198,42,28,0,60,158,112,189,255,67,254,75,24,6,51,169,96,6,51,169,253,142,3,238,200,93,68,34,223,3,174,159,240,217,243,
192,162,138,158,119,26,112,99,162,181,170,108,233,49,8,131,153,84,48,131,153,212,126,123,3,207,230,46,34,145,61,128,87,183,248,253,56,240,59,170,57,95,6,105,122,152,109,114,42,113,123,52,55,131,153,84,
48,131,153,212,126,227,192,111,55,254,218,100,107,128,29,217,122,78,229,129,192,35,21,62,243,51,224,139,27,159,61,170,199,136,249,153,185,25,204,164,130,25,204,164,110,120,2,216,63,119,17,35,122,8,56,
116,194,103,23,3,23,86,252,220,107,129,51,71,92,99,49,17,204,74,96,48,147,10,102,48,147,186,225,68,224,150,220,69,140,168,87,79,177,58,222,66,173,39,46,1,12,123,59,115,6,49,43,115,183,100,21,141,198,96,
38,21,204,96,38,117,195,116,98,200,119,41,131,180,135,177,15,240,220,22,191,159,70,180,159,168,99,139,246,19,224,223,176,117,255,180,126,140,3,127,71,108,185,150,194,96,38,21,204,96,38,117,71,233,109,
51,86,1,11,7,248,126,221,151,26,214,16,163,160,30,234,243,251,59,19,19,23,170,186,49,58,172,171,129,179,115,23,33,169,55,131,153,212,29,211,136,209,69,165,108,169,77,52,104,48,203,213,56,119,5,112,41,
240,194,118,254,254,28,162,173,199,127,164,204,11,23,55,18,109,64,36,21,200,96,38,117,203,110,196,121,167,220,221,231,123,25,52,152,61,8,44,169,168,150,126,124,8,252,130,56,131,182,158,8,190,127,2,236,
153,177,166,126,24,204,164,130,25,204,164,238,57,152,8,53,85,245,254,26,214,32,193,108,140,152,143,57,179,186,114,90,203,96,38,21,204,96,38,117,211,113,192,79,41,107,171,109,144,96,182,128,216,150,213,
224,12,102,82,193,12,102,82,119,45,34,134,127,207,206,93,200,70,131,4,179,211,129,235,42,172,165,205,12,102,82,193,12,102,82,183,205,38,14,178,159,152,187,16,6,11,102,247,0,199,84,88,75,155,221,73,220,
46,149,84,32,131,153,36,136,173,193,31,1,135,145,239,236,217,171,196,44,204,126,252,154,114,222,244,53,205,221,192,178,220,69,72,234,205,96,38,105,75,51,128,111,0,71,3,243,54,254,126,94,77,207,126,26,
216,175,143,239,205,3,222,174,184,150,54,51,152,73,5,51,152,73,234,199,235,192,252,138,159,113,47,112,108,31,223,107,195,120,169,156,86,0,135,231,46,66,82,111,6,51,73,253,184,11,88,90,241,51,46,0,126,
220,199,247,110,3,142,175,182,148,86,235,53,12,94,82,33,12,102,146,250,113,50,112,83,197,207,216,143,254,6,133,191,77,125,219,171,109,100,48,147,10,102,48,147,212,143,153,192,7,84,215,247,236,93,96,151,
62,190,55,103,99,29,26,94,191,103,249,36,101,96,48,147,212,175,235,136,254,97,85,88,70,28,74,159,202,49,68,171,12,13,207,96,38,21,204,96,38,169,95,51,137,110,251,115,18,175,251,42,176,23,176,161,143,239,
222,0,156,154,248,249,93,243,28,176,79,238,34,36,245,102,48,147,52,136,35,128,251,19,174,183,150,8,9,111,244,249,253,215,136,158,107,26,222,160,195,226,37,213,200,96,38,105,80,169,198,33,109,0,190,73,
28,70,239,199,76,98,112,121,105,195,215,155,198,96,38,21,204,96,38,105,24,167,3,87,1,211,134,252,249,53,192,145,192,147,3,252,204,18,224,193,33,159,167,205,222,0,190,146,187,8,73,189,25,204,36,13,107,
111,162,209,235,160,141,103,159,6,78,0,86,15,248,115,87,0,231,12,248,51,218,214,251,192,78,185,139,144,212,155,193,76,210,168,150,2,103,2,139,38,249,206,122,224,81,224,167,192,3,67,62,231,89,34,12,106,
52,6,51,169,96,6,51,73,169,204,6,22,19,103,193,22,2,159,17,163,156,254,158,8,101,235,70,88,123,28,248,29,158,47,75,225,35,224,11,185,139,144,212,155,193,76,82,19,44,6,30,203,93,68,75,172,5,118,200,93,
132,164,222,12,102,146,182,103,62,155,59,253,191,65,188,1,203,229,98,224,194,140,207,111,19,131,153,84,48,131,153,164,77,230,0,127,9,28,66,239,179,92,107,128,149,192,125,192,10,250,107,8,155,202,99,196,
91,51,141,110,61,240,249,220,69,72,234,205,96,38,105,38,241,70,234,100,250,111,127,241,6,112,62,17,208,170,54,70,156,47,171,106,78,103,23,125,46,119,1,146,122,51,152,73,221,182,55,49,123,114,238,144,63,
127,59,112,10,241,22,166,42,123,19,55,50,149,206,231,169,246,223,153,164,33,25,204,164,238,58,140,216,150,28,182,73,236,38,207,1,127,74,156,93,170,194,57,68,15,51,165,179,3,213,253,251,146,52,2,131,153,
212,77,123,2,207,144,110,123,112,5,209,201,191,138,115,103,15,18,93,255,149,206,78,68,63,51,73,133,49,152,73,221,51,141,232,47,54,47,241,186,23,1,151,36,94,115,140,152,143,57,51,241,186,93,183,43,131,
79,94,144,84,3,131,153,212,61,85,181,158,88,15,124,25,120,55,225,154,11,128,215,18,174,167,176,144,24,102,46,169,48,6,51,169,91,198,129,255,5,204,168,104,253,155,137,203,0,169,156,10,220,144,112,61,133,
125,136,179,129,146,10,99,48,147,186,229,120,224,182,10,215,95,7,236,72,186,102,180,247,0,199,36,90,75,155,29,0,60,158,187,8,73,219,50,152,73,221,82,199,65,250,67,129,135,18,173,245,1,209,248,86,105,165,
252,119,36,41,33,131,153,212,45,117,4,157,11,128,31,39,88,103,30,240,118,130,117,180,173,99,129,123,115,23,33,105,91,6,51,169,189,102,2,7,18,205,99,119,5,254,136,122,182,5,111,7,78,72,176,206,241,84,187,
237,218,101,223,1,238,204,93,132,164,109,25,204,164,118,25,39,2,205,183,137,80,150,195,114,224,232,4,235,220,70,252,89,148,222,105,192,141,185,139,144,180,45,131,153,212,30,199,19,173,48,134,29,175,148,
202,67,196,25,166,81,189,77,250,94,107,10,231,2,87,230,46,66,210,182,12,102,82,243,205,2,254,6,216,63,119,33,27,165,8,102,179,129,95,39,168,69,189,165,58,7,40,41,49,131,153,212,108,11,136,155,150,185,
223,146,109,41,69,48,59,134,104,149,161,106,92,14,156,159,187,8,73,219,50,152,73,205,181,128,152,119,89,85,179,216,97,165,8,102,215,1,167,39,168,69,189,93,11,156,153,187,8,73,219,50,152,73,205,52,11,120,
150,50,207,96,165,8,102,175,17,193,51,167,213,68,163,220,220,117,84,33,245,132,6,73,137,24,204,164,102,122,132,124,183,46,167,50,106,48,155,73,12,46,31,75,83,78,223,214,16,55,21,255,6,120,121,194,223,
219,25,248,119,192,247,104,71,195,219,187,129,101,185,139,144,180,45,131,153,212,60,71,1,247,229,46,98,18,163,6,179,37,196,185,185,58,93,11,252,16,88,59,197,247,102,16,179,59,151,86,94,81,181,30,0,142,
204,93,132,164,109,25,204,164,102,153,6,188,78,153,91,152,155,188,15,172,236,243,187,143,16,125,207,182,116,25,112,94,210,138,182,111,3,112,18,209,20,119,16,7,3,119,16,91,202,77,148,170,165,137,164,196,
12,102,82,179,28,79,187,186,225,247,234,64,255,44,176,119,77,207,255,30,112,253,144,63,187,24,120,152,8,203,77,243,52,176,95,238,34,36,109,203,96,38,53,203,19,148,211,175,44,133,157,136,55,108,155,140,
3,159,82,79,216,73,241,214,232,98,224,194,4,181,212,237,85,96,143,220,69,72,218,150,193,76,106,142,92,135,226,171,242,62,17,204,182,180,24,120,172,134,103,111,0,254,37,240,214,136,235,76,39,38,20,204,
30,185,162,122,245,250,103,47,169,0,6,51,169,57,14,38,182,206,218,162,215,205,192,11,137,183,80,85,75,185,149,119,21,112,86,162,181,234,178,22,216,33,119,17,146,182,101,48,147,154,227,28,224,138,220,69,
36,116,10,209,79,107,75,143,17,111,205,170,54,202,217,178,137,246,39,182,152,155,230,115,185,11,144,180,45,131,153,212,28,215,0,103,228,46,34,161,175,0,111,108,241,251,49,224,119,196,57,179,170,125,29,
120,50,209,90,77,157,235,185,3,83,183,7,145,84,51,131,153,212,28,55,1,39,231,46,34,145,79,128,29,39,124,182,8,120,190,166,231,47,4,86,37,90,107,12,248,191,137,214,170,211,46,192,187,185,139,144,180,53,
131,153,212,28,55,0,167,230,46,34,145,229,192,209,19,62,171,115,171,118,15,226,102,98,10,77,13,102,41,255,25,72,74,196,96,38,53,71,83,91,51,244,114,38,209,109,127,75,63,7,14,171,233,249,71,18,221,239,
83,152,71,220,204,108,154,148,219,185,146,18,49,152,73,205,113,28,209,109,190,13,38,190,173,25,35,90,129,204,172,233,249,55,2,167,37,90,235,84,226,109,102,211,28,14,172,200,93,132,164,173,25,204,164,230,
88,0,188,150,187,136,4,214,2,255,148,232,37,182,73,221,127,182,15,137,51,86,235,19,172,85,242,64,249,201,244,154,186,32,41,51,131,153,212,44,31,211,220,249,140,155,244,234,184,159,227,173,83,138,150,25,
251,2,79,37,168,37,135,94,219,201,146,50,51,152,73,205,210,134,150,25,231,3,151,79,248,236,46,96,105,205,117,172,33,110,103,126,56,228,207,143,3,207,0,123,38,171,168,94,23,1,151,228,46,66,210,214,12,102,
82,179,204,39,182,252,154,60,150,105,63,162,243,254,150,62,0,230,100,168,101,21,176,15,176,110,192,159,27,3,126,6,28,147,188,162,250,92,13,156,157,187,8,73,91,51,152,73,205,115,31,112,84,238,34,38,49,
232,112,240,157,129,119,170,41,165,47,47,3,223,166,255,158,94,211,137,75,24,71,84,85,80,77,110,5,78,202,93,132,164,173,25,204,164,230,153,3,188,73,4,132,18,13,26,204,142,7,110,171,166,148,190,173,35,206,
91,253,21,219,239,134,63,13,56,145,216,2,108,218,208,242,94,30,32,218,134,72,42,136,193,76,106,166,147,137,73,0,37,26,52,152,221,66,4,158,18,108,0,126,1,188,64,108,175,66,180,240,248,26,113,243,178,212,
48,60,140,199,129,3,114,23,33,105,107,6,51,169,185,74,157,4,48,104,48,123,155,104,210,170,122,189,12,236,149,187,8,73,91,51,152,73,205,53,70,188,109,58,62,115,29,19,13,18,204,154,58,0,188,13,86,3,187,
230,46,66,210,214,12,102,82,243,157,1,252,132,114,110,106,14,18,204,142,34,46,51,168,126,189,6,201,75,202,204,96,38,181,195,98,224,58,162,157,70,110,131,4,179,235,128,211,43,172,69,219,183,1,248,131,220,
69,72,218,154,193,76,106,143,49,98,91,243,71,228,233,9,182,201,10,98,14,99,63,94,1,118,175,176,22,77,238,143,137,70,187,146,10,97,48,147,218,105,111,224,155,192,18,234,15,62,119,3,203,250,248,222,76,98,
196,84,41,91,176,93,244,101,224,173,220,69,72,218,204,96,38,117,195,24,17,208,158,37,250,113,85,233,122,98,14,229,84,150,0,15,86,92,139,38,215,107,10,131,164,140,12,102,82,183,212,177,117,120,10,112,115,
31,223,187,12,56,175,226,90,52,185,35,137,70,179,146,10,97,48,147,186,165,142,33,232,187,18,173,24,166,242,20,176,111,197,181,104,114,253,134,104,73,53,49,152,73,221,178,8,120,190,194,245,251,109,90,58,
14,124,74,245,219,170,154,220,69,192,37,185,139,144,180,153,193,76,234,158,103,137,203,1,85,232,119,107,108,127,224,137,138,106,80,255,174,5,206,204,93,132,164,205,12,102,82,247,236,9,188,72,250,219,144,
207,1,251,244,249,221,11,129,139,19,63,95,131,187,23,56,54,119,17,146,54,51,152,73,221,116,21,112,86,194,245,214,18,161,236,141,62,191,255,8,49,20,92,121,57,200,92,42,140,193,76,234,166,49,224,126,224,
176,4,107,109,32,122,166,61,52,192,179,127,71,156,51,83,94,171,128,133,185,139,144,180,153,193,76,234,174,113,224,103,192,17,35,172,177,14,56,26,88,57,192,207,84,125,1,65,253,115,94,166,84,24,131,153,
164,179,128,75,25,252,13,214,42,224,207,55,254,58,232,243,174,26,240,103,84,157,207,3,235,115,23,33,41,24,204,36,65,204,214,252,33,49,107,115,170,128,182,138,24,62,254,95,137,109,204,65,253,156,52,91,
168,74,163,223,190,115,146,106,96,48,147,180,165,105,192,98,224,32,96,58,48,31,248,16,248,223,192,219,196,45,190,247,71,124,198,111,136,57,153,42,131,99,153,164,130,24,204,36,213,105,1,240,90,238,34,180,
149,163,129,229,185,139,144,20,12,102,146,234,116,42,112,67,238,34,180,149,51,137,70,179,146,10,96,48,147,218,99,9,240,167,68,87,253,45,7,149,127,6,252,10,120,20,248,59,162,17,108,46,119,1,75,51,62,95,
219,186,28,56,63,119,17,146,130,193,76,106,190,99,136,153,135,243,251,252,254,115,196,91,146,23,42,171,104,251,222,3,230,102,120,174,182,239,110,96,89,238,34,36,5,131,153,212,92,51,128,59,24,254,134,227,
245,68,64,27,230,102,229,48,118,6,222,169,233,89,234,159,221,255,165,130,24,204,164,102,154,5,60,3,236,54,226,58,143,18,131,199,215,141,92,209,212,142,35,130,164,202,178,154,104,153,33,169,0,6,51,169,
121,102,16,161,108,65,162,245,86,0,135,39,90,107,50,183,0,39,214,240,28,13,102,61,240,135,212,247,230,84,210,36,12,102,82,243,220,65,188,125,74,233,34,224,146,196,107,78,244,38,163,191,225,83,53,190,72,
244,171,147,148,153,193,76,106,150,197,192,99,21,172,187,30,248,10,213,117,128,159,13,252,186,162,181,53,58,155,204,74,133,48,152,73,205,242,20,176,111,69,107,87,121,59,239,40,224,190,138,214,214,232,
150,17,255,254,37,101,102,48,147,154,99,55,98,59,176,42,235,129,47,0,107,42,88,251,26,224,140,10,214,85,26,23,0,63,206,93,132,36,131,153,212,36,23,3,23,86,252,140,170,222,156,188,194,214,77,111,85,150,
155,129,83,114,23,33,201,96,38,53,201,195,192,193,21,63,163,138,255,64,207,0,126,11,140,37,94,87,233,60,74,12,174,151,148,153,193,76,42,215,60,162,155,255,108,96,39,98,206,228,204,138,159,89,69,179,209,
37,192,131,137,215,84,90,246,50,147,10,97,48,147,202,178,55,112,52,113,88,62,199,232,162,151,129,189,18,175,121,25,112,94,226,53,149,150,189,204,164,66,24,204,164,50,204,7,46,5,142,200,92,199,171,192,
30,137,215,172,242,38,169,210,217,5,120,55,119,17,82,215,25,204,164,252,46,37,222,40,149,112,6,107,21,176,48,225,122,227,196,249,178,241,132,107,170,26,135,2,15,229,46,66,234,58,131,153,148,207,116,162,
139,127,238,183,100,91,74,29,204,246,7,158,72,184,158,170,115,46,112,101,238,34,164,174,51,152,73,121,140,19,243,46,247,204,93,200,4,169,131,217,15,136,55,130,42,159,45,51,164,2,24,204,164,60,238,35,14,
248,151,38,117,48,123,4,56,48,225,122,170,206,147,192,215,115,23,33,117,157,193,76,170,95,201,111,145,82,6,179,49,224,83,98,203,182,46,235,129,21,192,61,192,175,128,183,54,126,62,15,88,64,220,120,253,
22,158,121,235,229,67,98,152,185,164,140,12,102,82,189,230,19,93,240,167,229,46,100,59,82,6,179,69,192,243,137,214,234,199,114,224,124,166,30,196,62,151,104,225,177,180,242,138,154,231,159,0,235,114,23,
33,117,153,193,76,170,215,207,129,195,114,23,49,137,15,137,209,79,131,250,21,240,220,132,207,206,2,174,26,185,162,254,156,15,92,62,224,207,156,78,204,240,44,225,54,108,41,246,34,122,217,73,202,196,96,
38,213,167,234,33,228,57,157,0,220,62,225,179,251,169,231,198,233,40,3,184,207,32,194,153,194,73,192,173,185,139,144,186,204,96,38,213,231,10,224,156,220,69,84,100,87,182,221,66,252,13,213,143,144,90,
9,28,50,226,26,247,0,199,36,168,165,13,174,5,206,204,93,132,212,101,6,51,169,62,111,19,135,208,219,166,215,161,241,249,192,235,21,63,119,3,240,175,137,115,113,163,152,71,212,90,234,185,191,58,61,13,236,
151,187,8,169,203,12,102,82,61,230,0,31,228,46,162,34,247,2,199,78,248,236,84,224,134,138,159,155,226,109,217,38,165,182,47,169,219,90,96,135,220,69,72,93,102,48,147,234,113,48,240,112,238,34,42,114,26,
112,227,132,207,238,162,250,91,143,189,158,59,172,165,68,205,114,102,166,148,149,193,76,170,199,201,192,77,185,139,168,200,66,182,221,78,124,143,104,75,81,165,148,55,8,23,0,175,37,90,171,233,142,4,30,
200,93,132,212,85,6,51,169,30,117,182,142,168,211,26,96,71,226,188,215,38,115,137,96,86,181,157,128,247,19,173,53,11,248,56,209,90,77,119,9,112,81,238,34,164,174,50,152,73,245,104,107,91,134,135,128,67,
39,124,118,28,49,156,189,106,41,131,217,108,224,215,137,214,106,186,7,136,183,102,146,50,48,152,73,245,56,17,184,37,119,17,21,56,23,184,114,194,103,55,17,91,183,85,219,135,109,155,218,14,107,79,224,165,
68,107,53,221,71,192,23,114,23,33,117,149,193,76,170,199,254,192,19,185,139,168,64,175,112,244,38,209,76,183,106,195,116,251,223,158,58,110,145,54,73,202,183,145,146,6,96,48,147,234,49,147,56,195,212,
166,241,63,159,17,173,21,214,111,241,89,157,103,181,158,35,130,97,10,143,0,7,38,90,171,13,142,38,102,143,74,170,153,193,76,170,207,107,196,237,191,182,120,28,56,96,194,103,71,17,61,193,234,114,16,240,
232,136,107,212,61,108,189,9,174,6,206,206,93,132,212,69,6,51,169,62,63,0,46,205,93,68,66,189,110,239,93,67,92,116,168,203,42,224,171,196,219,187,97,76,35,182,152,247,78,86,81,59,188,0,124,45,119,17,82,
23,25,204,164,250,204,1,222,161,61,163,127,14,32,222,154,109,233,37,226,32,125,157,238,6,150,13,249,179,55,16,231,203,180,181,13,196,54,245,186,220,133,72,93,99,48,147,234,117,11,113,67,179,84,171,217,
118,188,210,246,172,98,235,243,101,51,128,223,146,231,28,221,189,192,119,233,255,205,217,52,226,246,232,241,85,21,212,2,135,16,99,175,36,53,231,103,50,0,0,8,25,73,68,65,84,213,200,96,38,213,107,14,240,
223,137,16,83,162,85,68,39,255,97,228,30,59,245,6,113,46,106,170,48,177,152,104,246,187,123,229,21,53,219,229,196,205,87,73,53,50,152,73,245,59,6,184,39,119,17,219,49,74,48,187,12,56,47,97,45,195,90,5,
172,0,94,100,115,203,135,127,78,140,112,250,22,237,186,128,81,165,81,254,191,32,105,72,6,51,41,143,75,137,203,0,165,25,229,63,198,79,1,251,38,172,69,121,109,32,198,109,173,201,93,136,212,37,6,51,41,159,
123,136,183,103,37,25,54,152,141,19,231,203,198,211,150,163,204,150,17,151,43,36,213,196,96,38,229,117,33,112,113,238,34,182,48,108,48,219,151,120,99,166,118,25,229,198,171,164,33,24,204,164,252,142,32,
218,54,204,206,93,8,195,7,179,182,245,104,83,88,67,108,103,110,200,93,136,212,21,6,51,169,12,227,192,89,192,247,201,123,99,243,85,96,143,33,126,238,97,226,86,166,218,231,80,224,161,220,69,72,93,97,48,
147,202,50,3,248,6,209,75,236,27,212,31,210,134,233,248,62,6,124,10,76,79,95,142,10,112,59,112,66,238,34,164,174,48,152,73,101,155,67,108,113,206,38,182,59,231,86,252,188,149,68,99,209,65,236,73,116,252,
87,59,125,70,108,103,58,5,64,170,129,193,76,106,142,251,137,243,104,85,186,22,56,115,192,159,57,139,104,216,170,246,58,129,120,115,38,169,98,6,51,169,57,206,1,174,168,248,25,71,2,15,12,248,51,117,4,70,
229,245,56,49,27,85,82,197,12,102,82,115,236,76,12,65,175,202,58,98,203,170,223,121,147,155,124,12,204,74,95,142,10,178,1,248,23,192,187,153,235,144,90,207,96,38,53,203,131,192,146,138,214,30,102,54,226,
124,224,245,10,106,81,89,214,19,103,15,31,207,93,136,212,118,6,51,169,89,22,16,7,237,167,37,94,119,13,176,43,131,143,223,57,25,184,41,113,45,42,203,187,192,183,129,151,51,215,33,117,130,193,76,106,158,
42,230,108,14,59,122,231,46,96,105,226,90,84,142,135,128,239,224,188,76,169,54,6,51,169,121,198,136,3,247,135,37,90,239,74,224,220,33,127,246,61,170,111,225,161,250,109,0,46,32,182,183,37,213,200,96,38,
53,211,56,113,222,108,241,136,235,92,79,180,199,24,102,228,206,92,34,152,169,93,214,16,183,115,159,204,93,136,212,69,6,51,169,185,198,128,139,136,65,232,131,90,7,124,143,209,122,83,45,37,182,50,213,30,
171,136,17,76,239,231,46,68,234,42,131,153,212,124,11,136,128,118,84,31,223,93,15,220,10,252,16,248,100,196,231,222,68,28,254,87,59,44,39,26,201,218,225,95,202,200,96,38,181,199,28,224,207,128,131,128,
47,17,55,55,215,3,255,72,220,168,251,111,192,163,164,251,15,239,235,68,187,12,53,223,37,68,184,151,148,153,193,76,210,48,102,17,141,101,213,108,159,17,183,46,151,231,46,68,82,48,152,73,26,198,17,196,205,
80,53,215,251,196,121,178,85,185,11,145,180,153,193,76,210,48,174,1,206,200,93,132,134,246,36,209,52,118,212,115,134,146,18,51,152,73,26,134,141,101,155,235,102,226,70,238,250,220,133,72,218,150,193,76,
210,176,102,1,7,3,135,19,253,212,102,230,45,71,83,88,15,156,77,244,174,147,84,40,131,153,164,84,14,4,142,38,218,118,24,210,202,178,142,56,79,102,211,88,169,112,6,51,73,169,77,35,194,217,41,192,254,153,
107,17,124,68,180,80,241,144,191,212,0,6,51,73,85,90,0,124,159,56,143,54,150,185,150,46,90,13,28,128,157,252,165,198,48,152,73,170,195,206,192,249,192,95,16,115,62,85,189,23,136,237,75,111,94,74,13,98,
48,147,84,167,217,192,165,192,137,185,11,105,185,71,137,65,228,142,87,146,26,198,96,38,41,135,221,137,94,104,158,65,75,239,78,224,36,108,135,33,53,146,193,76,82,78,71,16,1,109,110,238,66,90,226,118,34,
148,109,200,92,135,164,33,25,204,36,229,54,29,184,10,56,57,119,33,13,119,39,240,93,12,101,82,163,25,204,36,149,226,96,224,22,96,78,238,66,26,232,94,224,207,49,148,73,141,103,48,147,84,146,25,192,29,192,
97,185,11,105,144,229,192,177,24,202,164,86,48,152,73,42,209,121,196,237,77,123,159,77,238,1,34,148,121,208,95,106,9,131,153,164,82,45,6,238,33,102,114,106,91,143,3,135,96,40,147,90,197,96,38,169,100,
243,128,135,55,254,170,205,222,2,190,10,172,205,93,136,164,180,12,102,146,74,55,19,184,31,123,158,109,242,9,176,15,49,110,73,82,203,24,204,36,53,193,56,177,173,233,165,128,216,190,92,153,187,8,73,213,
48,152,73,106,138,105,192,93,192,81,185,11,201,232,90,224,204,220,69,72,170,142,193,76,82,147,116,57,156,173,6,190,130,135,253,165,86,51,152,73,106,154,105,196,133,128,197,185,11,169,217,145,68,123,12,
73,45,102,48,147,212,68,51,128,103,128,5,185,11,169,201,203,192,94,185,139,144,84,61,131,153,164,166,154,3,188,72,55,70,56,157,6,220,152,187,8,73,213,51,152,73,106,178,5,196,155,179,25,185,11,169,216,
94,196,91,51,73,45,103,48,147,212,116,139,137,51,103,211,114,23,82,161,133,192,170,220,69,72,170,158,193,76,82,27,156,3,92,145,187,136,10,25,204,164,142,48,152,73,106,139,135,129,131,115,23,81,17,131,
153,212,17,6,51,73,109,49,11,120,13,152,157,187,144,10,24,204,164,142,48,152,73,106,147,197,192,35,192,88,238,66,18,51,152,73,29,97,48,147,212,54,55,0,167,230,46,34,49,131,153,212,17,6,51,73,109,51,19,
120,123,227,175,109,97,48,147,58,194,96,38,169,141,78,37,222,156,181,133,193,76,234,8,131,153,164,54,26,3,126,6,204,203,93,72,34,199,18,67,204,37,181,156,193,76,146,36,169,16,6,51,73,146,164,66,24,204,
36,73,146,10,97,48,147,36,73,42,132,193,76,146,36,169,16,6,51,73,146,164,66,24,204,36,181,213,82,224,235,185,139,72,228,98,224,195,220,69,72,170,158,193,76,82,91,181,105,52,147,13,102,165,142,48,152,73,
106,43,131,153,164,198,49,152,73,106,43,131,153,164,198,49,152,73,106,43,131,153,164,198,49,152,73,106,43,131,153,164,198,49,152,73,106,43,131,153,164,198,49,152,73,106,43,131,153,164,198,49,152,73,106,
43,131,153,164,198,49,152,73,106,43,131,153,164,198,49,152,73,106,43,131,153,164,198,49,152,73,106,43,131,153,164,198,49,152,73,106,43,131,153,164,198,49,152,73,106,43,131,153,164,198,49,152,73,106,43,
131,153,164,198,49,152,73,106,43,131,153,164,198,49,152,73,106,43,131,153,164,198,49,152,73,146,36,21,194,96,38,73,146,84,8,131,153,36,73,82,33,12,102,146,36,73,133,48,152,73,146,36,21,194,96,38,73,146,
84,8,131,153,36,73,82,33,12,102,146,36,73,133,48,152,73,146,36,21,194,96,38,73,146,84,8,131,153,36,73,82,33,12,102,146,36,73,133,48,152,73,146,36,21,194,96,38,73,146,84,8,131,153,36,73,82,33,12,102,146,
36,73,133,48,152,73,146,36,21,194,96,38,73,146,84,8,131,153,36,73,82,33,12,102,146,36,73,133,48,152,73,146,36,21,194,96,38,73,146,84,8,131,153,36,73,82,33,12,102,146,36,73,133,48,152,73,146,36,21,194,
96,38,73,146,84,8,131,153,36,73,82,33,12,102,146,36,73,133,48,152,73,146,36,21,194,96,38,73,146,84,8,131,153,36,73,82,33,12,102,146,36,73,133,48,152,73,146,36,21,194,96,38,73,146,84,8,131,153,36,73,82,
33,12,102,146,36,73,133,48,152,73,146,36,21,194,96,38,73,146,84,8,131,153,36,73,82,33,12,102,146,36,73,133,48,152,73,146,36,21,194,96,38,73,146,84,8,131,153,36,73,82,33,12,102,146,36,73,133,48,152,73,
146,36,21,194,96,38,73,146,84,8,131,153,36,73,82,33,12,102,146,36,73,133,48,152,73,146,36,21,194,96,38,73,146,84,8,131,153,36,73,82,33,12,102,146,36,73,133,48,152,73,146,36,21,194,96,38,73,146,84,8,131,
153,36,73,82,33,12,102,146,36,73,133,48,152,73,146,36,21,194,96,38,73,146,84,8,131,153,36,73,82,33,12,102,146,36,73,133,48,152,73,146,36,21,194,96,38,73,146,84,8,131,153,36,73,82,33,12,102,146,36,73,133,
48,152,73,146,36,21,194,96,38,73,146,84,8,131,153,36,73,82,33,12,102,146,36,73,133,48,152,73,146,36,21,194,96,38,73,146,84,8,131,153,36,73,82,33,12,102,146,36,73,133,48,152,73,146,36,21,194,96,38,73,146,
84,8,131,153,36,73,82,33,12,102,146,36,73,133,48,152,73,146,36,21,194,96,38,73,146,84,8,131,153,36,73,82,33,12,102,146,36,73,133,248,127,92,32,228,255,174,239,90,88,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* PluginEditor::bassWhiteLulu_png = (const char*) resource_PluginEditor_bassWhiteLulu_png;
const int PluginEditor::bassWhiteLulu_pngSize = 13081;

// JUCER_RESOURCE: guitarBianca_png, 7335, "../images/guitar bianca.png"
static const unsigned char resource_PluginEditor_guitarBianca_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,200,0,0,0,200,8,6,0,0,0,173,88,174,158,0,0,0,4,103,65,77,65,0,0,177,143,11,252,
97,5,0,0,10,55,105,67,67,80,115,82,71,66,32,73,69,67,54,49,57,54,54,45,50,46,49,0,0,72,137,157,150,119,84,83,217,22,135,207,189,55,189,80,146,16,138,148,208,107,104,82,2,72,13,189,72,145,46,42,49,9,16,
74,192,144,0,34,54,68,84,112,68,81,145,166,8,50,40,224,128,163,67,145,177,34,138,133,1,81,177,235,4,25,68,212,113,112,20,27,150,73,100,173,25,223,188,121,239,205,155,223,31,247,126,107,159,189,207,221,
103,239,125,214,186,0,144,252,131,5,194,76,88,9,128,12,161,88,20,225,231,197,136,141,139,103,96,7,1,12,240,0,3,108,0,224,112,179,179,66,22,248,70,2,153,2,124,216,140,108,153,19,248,23,189,186,14,32,249,
251,42,211,63,140,193,0,255,159,148,185,89,34,49,0,80,152,140,231,242,248,217,92,25,23,201,56,61,87,156,37,183,79,201,152,182,52,77,206,48,74,206,34,89,130,50,86,147,115,242,44,91,124,246,153,101,15,57,
243,50,132,60,25,203,115,206,226,101,240,228,220,39,227,141,57,18,190,140,145,96,25,23,231,8,248,185,50,190,38,99,131,116,73,134,64,198,111,228,177,25,124,78,54,0,40,146,220,46,230,115,83,100,108,45,99,
146,40,50,130,45,227,121,0,224,72,201,95,240,210,47,88,204,207,19,203,15,197,206,204,90,46,18,36,167,136,25,38,92,83,134,141,147,19,139,225,207,207,77,231,139,197,204,48,14,55,141,35,226,49,216,153,25,
89,28,225,114,0,102,207,252,89,20,121,109,25,178,34,59,216,56,57,56,48,109,45,109,190,40,212,127,93,252,155,146,247,118,150,94,132,127,238,25,68,31,248,195,246,87,126,153,13,0,176,166,101,181,217,250,
135,109,105,21,0,93,235,1,80,187,253,135,205,96,47,0,138,178,190,117,14,125,113,30,186,124,94,82,196,226,44,103,43,171,220,220,92,75,1,159,107,41,47,232,239,250,159,14,127,67,95,124,207,82,190,221,239,
229,97,120,243,147,56,146,116,49,67,94,55,110,102,122,166,68,196,200,206,226,112,249,12,230,159,135,248,31,7,254,117,30,22,17,252,36,190,136,47,148,69,68,203,166,76,32,76,150,181,91,200,19,136,5,153,66,
134,64,248,159,154,248,15,195,254,164,217,185,150,137,218,248,17,208,150,88,2,165,33,26,64,126,30,0,40,42,17,32,9,123,100,43,208,239,125,11,198,71,3,249,205,139,209,153,152,157,251,207,130,254,125,87,
184,76,254,200,22,36,127,142,99,71,68,50,184,18,81,206,236,154,252,90,2,52,32,0,69,64,3,234,64,27,232,3,19,192,4,182,192,17,184,0,15,224,3,2,65,40,136,4,113,96,49,224,130,20,144,1,68,32,23,20,128,181,
160,24,148,130,173,96,39,168,6,117,160,17,52,131,54,112,24,116,129,99,224,52,56,7,46,129,203,96,4,220,1,82,48,14,158,128,41,240,10,204,64,16,132,133,200,16,21,82,135,116,32,67,200,28,178,133,88,144,27,
228,3,5,67,17,80,28,148,8,37,67,66,72,2,21,64,235,160,82,168,28,170,134,234,161,102,232,91,232,40,116,26,186,0,13,67,183,160,81,104,18,250,21,122,7,35,48,9,166,193,90,176,17,108,5,179,96,79,56,8,142,132,
23,193,201,240,50,56,31,46,130,183,192,149,112,3,124,16,238,132,79,195,151,224,17,88,10,63,129,167,17,128,16,17,58,162,139,48,17,22,194,70,66,145,120,36,9,17,33,171,144,18,164,2,105,64,218,144,30,164,
31,185,138,72,145,167,200,91,20,6,69,69,49,80,76,148,11,202,31,21,133,226,162,150,161,86,161,54,163,170,81,7,80,157,168,62,212,85,212,40,106,10,245,17,77,70,107,162,205,209,206,232,0,116,44,58,25,157,
139,46,70,87,160,155,208,29,232,179,232,17,244,56,250,21,6,131,161,99,140,49,142,24,127,76,28,38,21,179,2,179,25,179,27,211,142,57,133,25,198,140,97,166,177,88,172,58,214,28,235,138,13,197,114,176,98,
108,49,182,10,123,16,123,18,123,5,59,142,125,131,35,226,116,112,182,56,95,92,60,78,136,43,196,85,224,90,112,39,112,87,112,19,184,25,188,18,222,16,239,140,15,197,243,240,203,241,101,248,70,124,15,126,8,
63,142,159,33,40,19,140,9,174,132,72,66,42,97,45,161,146,208,70,56,75,184,75,120,65,36,18,245,136,78,196,112,162,128,184,134,88,73,60,68,60,79,28,37,190,37,81,72,102,36,54,41,129,36,33,109,33,237,39,157,
34,221,34,189,32,147,201,70,100,15,114,60,89,76,222,66,110,38,159,33,223,39,191,81,160,42,88,42,4,40,240,20,86,43,212,40,116,42,92,81,120,166,136,87,52,84,244,84,92,172,152,175,88,161,120,68,113,72,241,
169,18,94,201,72,137,173,196,81,90,165,84,163,116,84,233,134,210,180,50,85,217,70,57,84,57,67,121,179,114,139,242,5,229,71,20,44,197,136,226,67,225,81,138,40,251,40,103,40,99,84,132,170,79,101,83,185,
212,117,212,70,234,89,234,56,13,67,51,166,5,208,82,105,165,180,111,104,131,180,41,21,138,138,157,74,180,74,158,74,141,202,113,21,41,29,161,27,209,3,232,233,244,50,250,97,250,117,250,59,85,45,85,79,85,
190,234,38,213,54,213,43,170,175,213,230,168,121,168,241,213,74,212,218,213,70,212,222,169,51,212,125,212,211,212,183,169,119,169,223,211,64,105,152,105,132,107,228,106,236,209,56,171,241,116,14,109,142,
203,28,238,156,146,57,135,231,220,214,132,53,205,52,35,52,87,104,238,211,28,208,156,214,210,214,242,211,202,210,170,210,58,163,245,84,155,174,237,161,157,170,189,67,251,132,246,164,14,85,199,77,71,160,
179,67,231,164,206,99,134,10,195,147,145,206,168,100,244,49,166,116,53,117,253,117,37,186,245,186,131,186,51,122,198,122,81,122,133,122,237,122,247,244,9,250,44,253,36,253,29,250,189,250,83,6,58,6,33,
6,5,6,173,6,183,13,241,134,44,195,20,195,93,134,253,134,175,141,140,141,98,140,54,24,117,25,61,50,86,51,14,48,206,55,110,53,190,107,66,54,113,55,89,102,210,96,114,205,20,99,202,50,77,51,221,109,122,217,
12,54,179,55,75,49,171,49,27,50,135,205,29,204,5,230,187,205,135,45,208,22,78,22,66,139,6,139,27,76,18,211,147,153,195,108,101,142,90,210,45,131,45,11,45,187,44,159,89,25,88,197,91,109,179,234,183,250,
104,109,111,157,110,221,104,125,199,134,98,19,104,83,104,211,99,243,171,173,153,45,215,182,198,246,218,92,242,92,223,185,171,231,118,207,125,110,103,110,199,183,219,99,119,211,158,106,31,98,191,193,190,
215,254,131,131,163,131,200,161,205,97,210,209,192,49,209,177,214,241,6,139,198,10,99,109,102,157,119,66,59,121,57,173,118,58,230,244,214,217,193,89,236,124,216,249,23,23,166,75,154,75,139,203,163,121,
198,243,248,243,26,231,141,185,234,185,114,92,235,93,165,110,12,183,68,183,189,110,82,119,93,119,142,123,131,251,3,15,125,15,158,71,147,199,132,167,169,103,170,231,65,207,103,94,214,94,34,175,14,175,215,
108,103,246,74,246,41,111,196,219,207,187,196,123,208,135,226,19,229,83,237,115,223,87,207,55,217,183,213,119,202,207,222,111,133,223,41,127,180,127,144,255,54,255,27,1,90,1,220,128,230,128,169,64,199,
192,149,129,125,65,164,160,5,65,213,65,15,130,205,130,69,193,61,33,112,72,96,200,246,144,187,243,13,231,11,231,119,133,130,208,128,208,237,161,247,194,140,195,150,133,125,31,142,9,15,11,175,9,127,24,97,
19,81,16,209,191,128,186,96,201,130,150,5,175,34,189,34,203,34,239,68,153,68,73,162,122,163,21,163,19,162,155,163,95,199,120,199,148,199,72,99,173,98,87,198,94,138,211,136,19,196,117,199,99,227,163,227,
155,226,167,23,250,44,220,185,112,60,193,62,161,56,225,250,34,227,69,121,139,46,44,214,88,156,190,248,248,18,197,37,156,37,71,18,209,137,49,137,45,137,239,57,161,156,6,206,244,210,128,165,181,75,167,184,
108,238,46,238,19,158,7,111,7,111,146,239,202,47,231,79,36,185,38,149,39,61,74,118,77,222,158,60,153,226,158,82,145,242,84,192,22,84,11,158,167,250,167,214,165,190,78,11,77,219,159,246,41,61,38,189,61,
3,151,145,152,113,84,72,17,166,9,251,50,181,51,243,50,135,179,204,179,138,179,164,203,156,151,237,92,54,37,10,18,53,101,67,217,139,178,187,197,52,217,207,212,128,196,68,178,94,50,154,227,150,83,147,243,
38,55,58,247,72,158,114,158,48,111,96,185,217,242,77,203,39,242,125,243,191,94,129,90,193,93,209,91,160,91,176,182,96,116,165,231,202,250,85,208,170,165,171,122,87,235,175,46,90,61,190,198,111,205,129,
181,132,181,105,107,127,40,180,46,44,47,124,185,46,102,93,79,145,86,209,154,162,177,245,126,235,91,139,21,138,69,197,55,54,184,108,168,219,136,218,40,216,56,184,105,238,166,170,77,31,75,120,37,23,75,173,
75,43,74,223,111,230,110,190,248,149,205,87,149,95,125,218,146,180,101,176,204,161,108,207,86,204,86,225,214,235,219,220,183,29,40,87,46,207,47,31,219,30,178,189,115,7,99,71,201,142,151,59,151,236,188,
80,97,87,81,183,139,176,75,178,75,90,25,92,217,93,101,80,181,181,234,125,117,74,245,72,141,87,77,123,173,102,237,166,218,215,187,121,187,175,236,241,216,211,86,167,85,87,90,247,110,175,96,239,205,122,
191,250,206,6,163,134,138,125,152,125,57,251,30,54,70,55,246,127,205,250,186,185,73,163,169,180,233,195,126,225,126,233,129,136,3,125,205,142,205,205,45,154,45,101,173,112,171,164,117,242,96,194,193,203,
223,120,127,211,221,198,108,171,111,167,183,151,30,2,135,36,135,30,127,155,248,237,245,195,65,135,123,143,176,142,180,125,103,248,93,109,7,181,163,164,19,234,92,222,57,213,149,210,37,237,142,235,30,62,
26,120,180,183,199,165,167,227,123,203,239,247,31,211,61,86,115,92,229,120,217,9,194,137,162,19,159,78,230,159,156,62,149,117,234,233,233,228,211,99,189,75,122,239,156,137,61,115,173,47,188,111,240,108,
208,217,243,231,124,207,157,233,247,236,63,121,222,245,252,177,11,206,23,142,94,100,93,236,186,228,112,169,115,192,126,160,227,7,251,31,58,6,29,6,59,135,28,135,186,47,59,93,238,25,158,55,124,226,138,251,
149,211,87,189,175,158,187,22,112,237,210,200,252,145,225,235,81,215,111,222,72,184,33,189,201,187,249,232,86,250,173,231,183,115,110,207,220,89,115,23,125,183,228,158,210,189,138,251,154,247,27,126,52,
253,177,93,234,32,61,62,234,61,58,240,96,193,131,59,99,220,177,39,63,101,255,244,126,188,232,33,249,97,197,132,206,68,243,35,219,71,199,38,125,39,47,63,94,248,120,252,73,214,147,153,167,197,63,43,255,
92,251,204,228,217,119,191,120,252,50,48,21,59,53,254,92,244,252,211,175,155,95,168,191,216,255,210,238,101,239,116,216,244,253,87,25,175,102,94,151,188,81,127,115,224,45,235,109,255,187,152,119,19,51,
185,239,177,239,43,63,152,126,232,249,24,244,241,238,167,140,79,159,126,3,247,132,243,251,199,209,59,120,0,0,0,32,99,72,82,77,0,0,122,38,0,0,128,132,0,0,250,0,0,0,128,232,0,0,117,48,0,0,234,96,0,0,58,
152,0,0,23,112,156,186,81,60,0,0,0,9,112,72,89,115,0,0,11,18,0,0,11,18,1,210,221,126,252,0,0,0,27,116,69,88,116,83,111,102,116,119,97,114,101,0,67,101,108,115,121,115,32,83,116,117,100,105,111,32,84,111,
111,108,193,167,225,124,0,0,17,179,73,68,65,84,120,156,237,221,121,188,28,85,153,198,241,95,72,98,4,2,136,64,34,18,246,85,89,132,8,195,34,8,137,104,16,84,16,70,152,17,20,28,22,247,5,68,150,17,28,22,81,
22,119,68,71,84,100,80,68,24,65,24,144,132,65,150,17,7,8,16,212,152,1,20,100,53,32,17,50,26,118,72,114,253,227,185,247,67,167,111,109,221,125,186,78,85,215,243,253,143,234,234,219,135,124,250,185,183,
170,206,57,239,59,102,104,104,8,51,75,54,198,1,49,75,231,128,152,101,112,64,204,50,56,32,102,25,28,16,179,12,14,136,89,6,7,196,44,131,3,98,150,193,1,49,203,224,128,12,142,177,192,238,192,94,192,118,192,
134,192,202,192,175,129,171,128,75,128,123,163,141,174,166,28,144,250,27,15,124,8,248,12,176,118,206,185,55,1,223,4,46,5,150,244,121,92,3,193,1,169,183,173,128,11,129,45,58,124,223,125,192,137,192,197,
128,191,0,25,28,144,250,218,7,133,99,133,30,126,198,45,192,161,192,221,65,70,52,128,28,144,120,54,5,118,2,86,2,30,2,102,1,47,20,124,239,190,232,158,98,108,128,113,188,0,28,11,124,61,192,207,26,56,14,72,
249,166,0,223,3,102,180,29,159,15,28,134,130,146,101,107,224,102,96,249,192,227,250,209,240,231,23,13,105,35,56,32,229,90,11,93,214,164,221,76,47,1,246,3,174,72,121,125,28,240,27,96,243,240,67,3,20,206,
119,3,207,247,233,231,215,142,3,82,174,255,6,222,154,115,206,147,192,6,192,162,132,215,118,7,174,13,61,168,54,63,7,222,5,44,237,243,231,212,130,3,82,158,221,128,27,10,158,123,56,186,12,107,247,85,224,
83,161,6,148,225,52,224,132,18,62,167,242,28,144,242,252,16,56,168,224,185,223,5,142,72,56,126,31,154,0,236,183,33,244,151,238,186,18,62,171,210,28,144,242,44,0,214,40,120,238,37,192,1,109,199,54,163,
220,199,177,119,1,111,0,22,151,248,153,149,227,128,148,99,77,224,209,14,206,191,22,120,63,240,231,150,99,159,1,206,12,57,168,2,62,2,124,187,228,207,172,20,7,164,28,155,3,243,58,124,207,16,48,23,61,89,
186,6,56,5,216,57,240,184,242,220,69,255,158,152,213,130,3,82,142,41,192,35,177,7,209,165,93,128,95,197,30,68,44,14,72,121,230,3,175,45,112,222,111,128,59,209,68,226,90,125,29,81,49,95,66,151,119,141,
228,128,148,231,4,224,212,156,115,134,128,93,209,170,91,208,98,196,61,128,163,128,201,253,27,90,166,91,129,29,35,125,118,116,14,72,121,38,0,215,163,245,87,105,62,199,232,16,141,5,254,2,172,218,167,113,
229,121,17,237,43,105,228,18,20,7,164,92,19,129,179,129,131,129,49,45,199,159,4,142,35,121,114,112,23,224,151,253,31,90,166,245,208,130,202,198,113,64,226,216,4,61,145,154,0,220,15,252,15,233,235,159,
206,0,142,41,105,92,105,182,5,230,68,30,67,20,14,72,245,253,31,240,250,132,227,207,3,231,2,51,129,103,128,109,128,143,3,27,245,97,12,51,208,58,178,198,113,64,170,109,125,244,23,166,221,66,224,45,232,137,
87,171,229,129,159,2,123,6,30,199,116,138,175,35,27,40,14,72,181,125,12,221,179,180,123,31,218,191,145,100,21,180,102,107,245,128,227,152,138,138,63,52,142,3,82,109,51,209,99,222,86,139,128,213,200,94,
35,117,14,90,38,18,202,250,192,131,1,127,94,109,56,32,229,24,143,102,211,95,68,107,178,138,252,163,175,8,60,1,188,178,237,248,60,96,203,156,247,126,10,45,141,15,97,8,61,125,123,54,208,207,171,21,7,164,
191,214,7,62,143,118,233,141,108,145,125,24,56,25,56,47,231,189,123,3,151,39,28,95,64,254,164,225,233,104,159,121,8,15,160,13,92,141,228,128,244,207,14,104,161,225,42,41,175,159,11,124,48,227,253,223,
69,123,196,147,76,3,110,76,121,109,28,90,22,31,234,105,214,149,104,135,97,35,57,32,253,177,26,90,9,59,41,231,188,195,128,239,167,188,150,181,118,235,247,192,155,208,4,99,187,179,128,163,11,140,177,168,
227,209,95,164,70,114,64,250,227,43,192,145,5,206,251,35,201,191,233,183,65,11,22,179,60,136,214,119,93,141,230,65,166,162,203,170,125,10,143,178,152,29,209,122,172,70,114,64,194,123,37,186,79,88,169,
224,249,73,79,136,78,68,251,63,98,123,28,253,21,107,108,1,7,7,36,188,25,228,215,182,106,181,19,42,5,212,106,54,240,15,193,70,212,189,115,208,92,76,99,57,32,225,125,22,61,185,42,234,141,44,123,57,53,25,
120,140,101,23,51,198,178,21,240,187,216,131,136,201,1,9,175,211,73,186,167,208,50,248,89,104,98,112,58,249,143,128,203,112,45,240,182,216,131,136,205,1,9,239,235,192,39,122,120,255,115,132,47,43,218,
169,33,96,123,224,246,200,227,136,206,1,9,239,8,224,59,5,207,189,15,88,23,205,180,87,73,90,93,174,198,113,64,194,155,132,54,23,181,47,17,105,183,128,151,31,241,78,71,107,174,222,129,150,164,196,244,32,
170,135,149,84,250,180,113,28,144,254,200,171,97,181,20,205,87,92,217,118,188,232,252,73,191,188,136,118,48,222,22,113,12,149,226,128,244,207,191,161,249,140,246,30,30,139,80,237,221,75,18,222,243,7,96,
227,62,143,43,203,7,128,243,35,126,126,229,56,32,253,181,37,90,78,178,1,90,13,123,27,112,1,42,194,208,110,19,180,132,36,150,51,208,190,120,107,225,128,84,199,145,232,18,43,6,183,60,72,225,128,84,199,47,
208,54,218,52,143,161,165,31,235,18,182,4,208,159,81,19,208,164,133,143,141,231,128,84,195,202,104,115,84,210,227,222,123,208,178,248,145,210,63,99,129,253,81,59,231,87,7,248,236,172,237,187,141,231,128,
84,195,126,168,216,66,187,135,209,82,148,39,18,94,219,26,173,178,157,208,195,231,62,128,30,53,251,210,42,133,3,82,13,63,0,14,73,56,158,247,84,233,27,168,212,79,183,206,36,220,206,195,129,228,128,132,179,
22,240,81,180,219,111,117,116,109,255,19,52,171,158,85,96,97,204,240,185,73,155,171,214,100,217,30,33,237,222,142,246,131,116,107,63,224,178,30,222,63,240,28,144,48,246,70,215,241,19,19,94,155,141,102,
200,147,46,147,64,203,218,103,167,188,182,50,90,204,152,230,205,168,42,99,183,146,150,218,91,11,7,164,119,59,160,47,233,43,50,206,185,9,85,109,79,250,199,62,5,77,40,38,217,149,236,186,188,189,86,47,121,
11,90,73,108,41,28,144,222,140,1,126,75,126,25,30,128,125,129,159,37,28,159,131,182,203,38,185,26,216,43,229,181,21,208,94,141,94,42,142,124,20,248,86,15,239,31,120,14,72,111,58,185,7,248,33,234,59,216,
106,77,84,156,33,107,115,212,55,80,17,134,151,90,142,173,10,92,132,118,47,246,34,169,89,168,181,112,64,122,115,1,154,71,40,226,102,84,137,164,213,97,104,105,121,158,7,129,75,209,100,225,198,192,123,8,
51,7,242,55,180,131,177,145,189,63,138,112,64,122,115,63,42,186,80,196,45,140,110,158,115,57,186,193,143,233,221,36,23,168,51,28,144,94,140,69,203,195,151,43,120,254,66,116,153,53,11,21,125,27,66,203,
59,86,236,199,224,58,208,232,194,112,121,28,144,238,141,71,1,233,198,115,168,198,238,118,225,134,211,181,37,168,131,212,159,34,143,163,146,28,144,222,60,138,110,180,235,238,84,212,31,209,218,56,32,189,
201,170,159,219,234,114,84,194,115,15,244,228,105,87,226,23,102,104,245,56,176,14,221,255,69,28,88,14,72,111,54,0,230,146,125,31,241,20,218,227,253,64,203,177,173,169,94,67,154,3,129,31,199,30,68,213,
56,32,189,219,19,248,79,52,113,215,110,17,122,74,212,62,91,125,52,42,50,93,37,73,143,161,27,207,1,9,99,19,116,29,191,7,170,201,59,31,184,10,248,2,240,72,194,249,55,0,187,149,53,184,14,108,195,232,190,
135,141,230,128,148,111,21,180,112,113,92,236,129,36,248,22,90,126,98,195,28,144,242,237,15,92,28,123,16,41,254,134,158,202,61,23,123,32,85,225,128,148,175,147,229,41,49,252,19,213,13,112,233,28,144,114,
45,135,54,64,173,145,240,218,179,192,105,232,73,210,163,104,9,203,97,104,73,123,153,151,99,158,89,111,225,128,148,107,123,146,187,53,61,135,110,218,147,42,26,190,19,205,163,20,93,210,210,171,23,80,128,
179,54,106,53,134,3,210,157,87,161,223,178,91,160,165,234,191,70,171,109,243,86,197,158,76,242,140,245,201,192,73,25,239,59,15,237,79,47,139,47,179,134,57,32,157,251,23,180,139,111,229,182,227,247,163,
47,86,86,203,128,59,209,163,212,118,175,71,157,105,211,116,218,181,170,87,23,0,7,151,248,121,149,229,128,116,230,195,100,239,192,123,26,53,189,156,151,240,218,107,209,252,72,146,213,201,46,220,86,246,
204,251,163,168,8,69,227,57,32,197,109,132,190,248,121,117,168,126,133,42,164,183,59,28,245,70,79,178,3,233,133,27,64,27,164,146,138,93,247,211,166,168,152,118,163,57,32,197,125,15,56,180,224,185,27,161,
22,207,173,178,54,71,157,151,243,179,243,202,146,246,195,65,192,133,37,127,102,229,56,32,197,116,218,218,249,31,209,77,251,136,9,100,111,142,26,66,143,116,147,122,19,158,132,90,41,148,237,107,196,237,
85,82,9,14,72,49,59,163,210,61,69,189,31,237,30,28,177,7,106,208,153,231,10,52,15,50,31,216,16,253,85,121,115,7,159,27,210,44,84,148,162,209,28,144,98,58,233,59,8,240,109,224,108,94,126,50,117,54,245,
235,55,126,31,113,155,249,84,130,3,82,204,167,129,47,117,241,190,135,208,111,226,189,136,223,123,176,83,47,144,223,103,113,224,57,32,197,28,130,10,76,55,205,138,104,9,76,99,57,32,197,108,136,46,57,138,
248,10,154,93,223,3,120,93,223,70,84,142,41,164,207,221,52,130,3,82,220,21,228,47,226,251,29,234,231,49,82,5,113,29,224,58,94,110,247,92,55,235,161,203,196,198,114,64,138,123,13,240,191,164,215,194,125,
28,61,113,106,157,92,171,242,230,168,34,214,33,121,71,100,99,56,32,157,153,132,106,229,238,207,203,245,116,151,160,73,192,35,25,253,101,138,49,3,30,210,107,80,240,27,203,1,233,206,20,96,51,116,41,53,143,
244,117,84,105,157,163,234,96,49,154,224,108,116,123,54,7,164,127,198,160,98,211,147,99,15,164,75,15,163,142,186,141,230,128,244,207,118,36,111,128,170,11,151,1,194,1,233,167,147,200,94,67,245,34,186,
161,127,5,122,202,85,214,142,193,162,126,2,252,115,236,65,196,230,128,244,207,237,192,182,9,199,135,128,211,129,51,80,21,17,128,181,129,47,163,155,250,170,248,28,170,245,213,104,14,72,190,177,192,86,104,
195,211,66,224,14,150,237,246,148,100,50,186,255,72,234,28,117,20,233,125,5,47,4,222,219,221,48,131,75,107,25,215,40,14,72,182,15,163,6,155,173,21,220,31,67,107,179,46,202,120,223,33,36,47,77,249,3,122,
250,149,246,143,62,9,181,33,24,223,233,64,251,96,19,224,222,216,131,136,205,1,73,119,14,240,145,140,215,143,5,206,76,121,237,167,168,7,121,187,111,2,31,207,249,220,217,168,53,116,76,207,162,189,47,141,
126,196,11,14,72,154,131,88,118,63,71,146,165,232,139,60,167,237,248,120,52,123,222,94,212,1,20,168,99,115,126,238,245,192,180,2,99,236,167,155,136,183,15,165,82,28,144,209,198,163,237,178,107,23,56,55,
169,250,199,52,210,123,143,255,2,120,107,198,207,27,135,102,174,67,52,232,236,197,89,192,49,145,199,80,9,14,200,104,239,66,11,19,139,184,31,173,244,109,245,101,116,35,158,100,8,21,143,75,43,13,148,87,
53,165,44,190,65,31,230,128,140,214,73,113,134,191,162,158,229,173,238,70,55,226,105,230,163,106,137,237,101,124,246,69,79,177,170,176,73,105,77,84,34,181,241,28,144,209,230,0,83,11,158,187,0,109,75,93,
52,252,223,27,48,186,154,73,146,37,168,6,238,108,52,81,184,59,201,165,130,98,184,23,61,193,50,28,144,36,15,83,236,254,99,196,75,104,89,198,44,96,53,212,61,170,206,254,29,93,234,25,14,72,146,123,80,209,
180,166,218,31,181,148,51,28,144,36,23,161,26,187,121,94,2,126,14,76,39,249,145,110,29,13,161,201,202,39,98,15,164,42,28,144,209,222,6,92,83,224,188,145,118,101,227,129,157,128,79,160,27,237,58,187,19,
109,25,182,97,14,72,178,188,46,80,243,80,40,90,123,104,124,7,213,207,170,179,207,163,165,53,54,204,1,73,54,14,85,39,249,24,163,23,28,206,68,147,131,127,105,59,254,8,245,171,125,213,110,39,224,150,216,
131,168,18,7,36,219,230,168,207,249,106,40,16,215,146,60,201,183,21,240,219,18,199,213,15,79,162,251,143,198,175,191,106,229,128,132,113,28,240,197,216,131,232,209,133,104,13,154,181,112,64,194,184,9,
21,184,174,51,63,222,77,224,128,244,110,85,116,249,53,54,246,64,122,224,198,157,41,28,144,222,29,128,246,111,167,153,131,102,217,159,65,253,9,247,70,203,75,170,100,38,176,103,236,65,84,145,3,146,108,57,
138,223,172,254,7,234,7,210,110,9,240,65,224,251,109,199,55,3,174,98,244,42,224,152,62,68,103,237,29,26,195,1,145,49,104,155,236,17,104,161,226,120,180,61,246,108,212,235,35,45,44,203,161,45,184,147,18,
94,59,17,205,43,36,217,20,152,75,53,254,146,44,69,251,237,27,93,65,49,141,3,162,234,129,151,162,30,30,73,102,162,25,242,231,19,94,219,30,184,53,225,248,243,232,154,254,233,140,207,189,24,221,24,199,150,
214,116,212,112,64,160,216,254,143,115,72,238,16,117,10,201,51,207,115,129,55,228,252,204,99,80,233,159,216,142,68,253,8,45,65,211,3,82,180,250,225,18,84,134,179,189,87,198,29,36,175,93,42,210,190,236,
100,84,123,42,182,117,209,18,127,75,208,244,128,252,8,56,176,224,185,31,0,206,111,249,239,172,218,87,144,95,54,167,10,213,75,238,64,191,36,44,69,147,3,50,22,109,153,157,88,240,252,147,208,111,253,17,135,
144,221,150,109,22,240,14,244,215,167,221,193,44,27,182,88,142,163,26,151,121,149,213,228,128,116,186,126,234,4,224,180,150,255,190,132,252,82,161,51,81,29,172,145,109,184,43,160,101,241,167,82,141,166,
58,27,83,188,181,92,35,53,57,32,239,4,254,171,131,243,23,160,47,252,44,224,6,224,247,168,131,84,158,33,116,169,245,12,154,3,89,190,179,97,246,77,145,7,9,141,231,128,116,103,136,244,123,143,186,112,113,
234,2,154,28,144,205,80,137,158,34,158,65,151,71,117,15,69,171,205,129,187,98,15,162,234,154,28,16,208,23,164,72,171,230,125,81,3,207,25,168,189,243,1,212,123,113,226,61,212,191,69,117,41,154,30,144,183,
163,194,11,89,127,25,46,99,217,66,212,83,168,127,231,215,47,0,159,141,61,136,58,104,122,64,0,14,71,51,229,73,45,7,174,68,21,78,158,109,59,255,220,18,198,213,79,219,50,186,232,182,37,112,64,228,117,104,
233,199,27,209,95,147,187,209,36,98,210,77,252,207,128,125,202,27,90,112,110,206,217,1,7,164,51,227,209,222,237,149,98,15,164,7,103,163,185,24,43,192,1,233,204,116,224,186,216,131,232,209,238,212,255,
255,161,52,14,72,103,206,162,222,181,119,255,31,237,93,89,28,123,32,117,225,128,116,102,30,154,63,168,171,31,83,124,113,166,225,128,116,98,109,210,151,133,47,70,95,190,107,208,102,169,169,104,187,237,
234,229,12,173,176,3,209,56,173,32,7,164,184,35,72,222,183,189,8,205,167,220,220,118,124,117,52,199,18,123,73,251,136,165,232,242,234,201,216,3,169,19,7,164,184,203,80,149,197,118,135,160,194,13,73,214,
66,123,219,87,232,211,152,58,113,43,176,99,236,65,212,141,3,82,76,218,227,221,191,162,189,231,89,55,189,23,2,239,237,211,184,58,225,197,137,93,112,64,138,217,21,184,49,225,120,145,29,121,39,80,141,47,
230,246,20,219,94,108,45,28,144,98,78,3,254,53,225,248,3,168,47,97,150,175,1,159,12,62,162,206,44,66,173,165,147,118,55,90,6,7,164,152,172,198,158,83,25,221,177,118,196,56,180,89,106,189,62,140,169,19,
87,161,253,47,214,33,7,36,223,36,212,18,57,109,197,239,237,192,110,44,187,160,113,196,23,209,190,239,216,142,2,190,26,123,16,117,228,128,228,59,16,45,92,204,50,23,45,118,188,30,245,46,220,28,93,146,85,
225,230,28,178,255,202,89,6,7,36,223,249,168,10,73,17,139,81,64,170,178,239,28,180,27,114,21,124,255,209,21,7,36,223,159,208,124,70,93,221,8,76,139,61,136,186,114,64,178,109,138,182,167,214,217,233,192,
241,177,7,81,87,14,72,182,67,81,237,222,58,219,7,184,34,246,32,234,202,1,201,118,52,90,226,94,103,235,1,15,197,30,68,93,57,32,217,222,131,42,40,214,213,211,192,202,168,142,151,117,193,1,201,54,17,221,
164,23,169,160,88,69,183,161,37,38,214,37,7,36,95,85,250,120,116,227,60,242,123,159,88,6,7,36,223,56,84,52,174,42,251,58,58,113,60,122,138,101,93,114,64,138,89,23,45,41,89,35,246,64,58,244,62,242,87,1,
88,6,7,164,184,237,81,53,144,21,99,15,164,3,211,72,94,166,111,5,57,32,157,153,134,86,198,86,97,135,96,17,27,241,114,111,18,235,130,3,210,185,157,81,73,210,87,197,30,72,1,19,209,90,44,235,146,3,210,157,
45,80,65,134,117,98,15,36,199,114,120,14,164,39,14,72,247,38,163,254,234,111,138,61,144,20,207,83,173,85,197,181,228,128,244,102,60,112,53,42,231,89,53,11,129,213,98,15,162,238,28,144,222,77,66,141,120,
170,246,101,156,143,122,153,88,15,28,144,48,170,56,219,238,128,4,224,128,132,177,42,240,24,48,33,246,64,90,56,32,1,56,32,225,92,5,236,21,123,16,45,28,144,0,28,144,112,62,137,106,96,85,133,3,18,128,3,18,
206,14,192,45,177,7,209,194,1,9,192,1,9,103,34,240,84,236,65,180,112,64,2,112,64,194,90,64,117,86,252,58,32,1,56,32,97,205,5,182,140,61,136,97,14,72,0,14,72,88,191,4,118,137,61,136,97,14,72,0,14,72,88,
179,128,25,177,7,49,204,1,9,192,1,9,235,106,212,142,173,10,28,144,0,28,144,176,62,77,117,238,65,22,162,170,238,214,3,7,196,44,131,3,98,150,193,1,49,203,224,128,152,101,112,64,194,26,75,122,171,182,24,
178,218,83,91,1,14,72,88,85,154,7,249,35,42,251,99,61,112,64,194,114,64,6,140,3,18,150,3,50,96,28,144,176,28,144,1,227,128,132,229,128,12,24,7,36,44,7,100,192,56,32,97,57,32,3,198,1,9,203,1,25,48,14,72,
88,14,200,128,113,64,194,114,64,6,140,3,18,150,3,50,96,28,144,176,28,144,1,227,128,132,229,128,12,24,7,36,44,7,100,192,56,32,97,57,32,3,198,1,9,203,1,25,48,14,72,88,14,200,128,113,64,194,114,64,6,140,
3,98,150,193,1,49,203,224,128,152,101,112,64,204,50,56,32,102,25,28,16,179,12,14,136,89,6,7,196,44,131,3,98,150,193,1,49,203,240,119,57,15,76,188,180,78,42,129,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* PluginEditor::guitarBianca_png = (const char*) resource_PluginEditor_guitarBianca_png;
const int PluginEditor::guitarBianca_pngSize = 7335;

// JUCER_RESOURCE: crestBianco_png, 31711, "../images/crest bianco.png"
static const unsigned char resource_PluginEditor_crestBianco_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,2,0,0,0,2,0,8,6,0,0,0,244,120,212,250,0,0,0,4,103,65,77,65,0,0,177,143,11,252,97,
5,0,0,10,55,105,67,67,80,115,82,71,66,32,73,69,67,54,49,57,54,54,45,50,46,49,0,0,72,137,157,150,119,84,83,217,22,135,207,189,55,189,80,146,16,138,148,208,107,104,82,2,72,13,189,72,145,46,42,49,9,16,74,
192,144,0,34,54,68,84,112,68,81,145,166,8,50,40,224,128,163,67,145,177,34,138,133,1,81,177,235,4,25,68,212,113,112,20,27,150,73,100,173,25,223,188,121,239,205,155,223,31,247,126,107,159,189,207,221,103,
239,125,214,186,0,144,252,131,5,194,76,88,9,128,12,161,88,20,225,231,197,136,141,139,103,96,7,1,12,240,0,3,108,0,224,112,179,179,66,22,248,70,2,153,2,124,216,140,108,153,19,248,23,189,186,14,32,249,251,
42,211,63,140,193,0,255,159,148,185,89,34,49,0,80,152,140,231,242,248,217,92,25,23,201,56,61,87,156,37,183,79,201,152,182,52,77,206,48,74,206,34,89,130,50,86,147,115,242,44,91,124,246,153,101,15,57,243,
50,132,60,25,203,115,206,226,101,240,228,220,39,227,141,57,18,190,140,145,96,25,23,231,8,248,185,50,190,38,99,131,116,73,134,64,198,111,228,177,25,124,78,54,0,40,146,220,46,230,115,83,100,108,45,99,146,
40,50,130,45,227,121,0,224,72,201,95,240,210,47,88,204,207,19,203,15,197,206,204,90,46,18,36,167,136,25,38,92,83,134,141,147,19,139,225,207,207,77,231,139,197,204,48,14,55,141,35,226,49,216,153,25,89,
28,225,114,0,102,207,252,89,20,121,109,25,178,34,59,216,56,57,56,48,109,45,109,190,40,212,127,93,252,155,146,247,118,150,94,132,127,238,25,68,31,248,195,246,87,126,153,13,0,176,166,101,181,217,250,135,
109,105,21,0,93,235,1,80,187,253,135,205,96,47,0,138,178,190,117,14,125,113,30,186,124,94,82,196,226,44,103,43,171,220,220,92,75,1,159,107,41,47,232,239,250,159,14,127,67,95,124,207,82,190,221,239,229,
97,120,243,147,56,146,116,49,67,94,55,110,102,122,166,68,196,200,206,226,112,249,12,230,159,135,248,31,7,254,117,30,22,17,252,36,190,136,47,148,69,68,203,166,76,32,76,150,181,91,200,19,136,5,153,66,134,
64,248,159,154,248,15,195,254,164,217,185,150,137,218,248,17,208,150,88,2,165,33,26,64,126,30,0,40,42,17,32,9,123,100,43,208,239,125,11,198,71,3,249,205,139,209,153,152,157,251,207,130,254,125,87,184,
76,254,200,22,36,127,142,99,71,68,50,184,18,81,206,236,154,252,90,2,52,32,0,69,64,3,234,64,27,232,3,19,192,4,182,192,17,184,0,15,224,3,2,65,40,136,4,113,96,49,224,130,20,144,1,68,32,23,20,128,181,160,
24,148,130,173,96,39,168,6,117,160,17,52,131,54,112,24,116,129,99,224,52,56,7,46,129,203,96,4,220,1,82,48,14,158,128,41,240,10,204,64,16,132,133,200,16,21,82,135,116,32,67,200,28,178,133,88,144,27,228,
3,5,67,17,80,28,148,8,37,67,66,72,2,21,64,235,160,82,168,28,170,134,234,161,102,232,91,232,40,116,26,186,0,13,67,183,160,81,104,18,250,21,122,7,35,48,9,166,193,90,176,17,108,5,179,96,79,56,8,142,132,23,
193,201,240,50,56,31,46,130,183,192,149,112,3,124,16,238,132,79,195,151,224,17,88,10,63,129,167,17,128,16,17,58,162,139,48,17,22,194,70,66,145,120,36,9,17,33,171,144,18,164,2,105,64,218,144,30,164,31,
185,138,72,145,167,200,91,20,6,69,69,49,80,76,148,11,202,31,21,133,226,162,150,161,86,161,54,163,170,81,7,80,157,168,62,212,85,212,40,106,10,245,17,77,70,107,162,205,209,206,232,0,116,44,58,25,157,139,
46,70,87,160,155,208,29,232,179,232,17,244,56,250,21,6,131,161,99,140,49,142,24,127,76,28,38,21,179,2,179,25,179,27,211,142,57,133,25,198,140,97,166,177,88,172,58,214,28,235,138,13,197,114,176,98,108,
49,182,10,123,16,123,18,123,5,59,142,125,131,35,226,116,112,182,56,95,92,60,78,136,43,196,85,224,90,112,39,112,87,112,19,184,25,188,18,222,16,239,140,15,197,243,240,203,241,101,248,70,124,15,126,8,63,
142,159,33,40,19,140,9,174,132,72,66,42,97,45,161,146,208,70,56,75,184,75,120,65,36,18,245,136,78,196,112,162,128,184,134,88,73,60,68,60,79,28,37,190,37,81,72,102,36,54,41,129,36,33,109,33,237,39,157,
34,221,34,189,32,147,201,70,100,15,114,60,89,76,222,66,110,38,159,33,223,39,191,81,160,42,88,42,4,40,240,20,86,43,212,40,116,42,92,81,120,166,136,87,52,84,244,84,92,172,152,175,88,161,120,68,113,72,241,
169,18,94,201,72,137,173,196,81,90,165,84,163,116,84,233,134,210,180,50,85,217,70,57,84,57,67,121,179,114,139,242,5,229,71,20,44,197,136,226,67,225,81,138,40,251,40,103,40,99,84,132,170,79,101,83,185,
212,117,212,70,234,89,234,56,13,67,51,166,5,208,82,105,165,180,111,104,131,180,41,21,138,138,157,74,180,74,158,74,141,202,113,21,41,29,161,27,209,3,232,233,244,50,250,97,250,117,250,59,85,45,85,79,85,
190,234,38,213,54,213,43,170,175,213,230,168,121,168,241,213,74,212,218,213,70,212,222,169,51,212,125,212,211,212,183,169,119,169,223,211,64,105,152,105,132,107,228,106,236,209,56,171,241,116,14,109,142,
203,28,238,156,146,57,135,231,220,214,132,53,205,52,35,52,87,104,238,211,28,208,156,214,210,214,242,211,202,210,170,210,58,163,245,84,155,174,237,161,157,170,189,67,251,132,246,164,14,85,199,77,71,160,
179,67,231,164,206,99,134,10,195,147,145,206,168,100,244,49,166,116,53,117,253,117,37,186,245,186,131,186,51,122,198,122,81,122,133,122,237,122,247,244,9,250,44,253,36,253,29,250,189,250,83,6,58,6,33,
6,5,6,173,6,183,13,241,134,44,195,20,195,93,134,253,134,175,141,140,141,98,140,54,24,117,25,61,50,86,51,14,48,206,55,110,53,190,107,66,54,113,55,89,102,210,96,114,205,20,99,202,50,77,51,221,109,122,217,
12,54,179,55,75,49,171,49,27,50,135,205,29,204,5,230,187,205,135,45,208,22,78,22,66,139,6,139,27,76,18,211,147,153,195,108,101,142,90,210,45,131,45,11,45,187,44,159,89,25,88,197,91,109,179,234,183,250,
104,109,111,157,110,221,104,125,199,134,98,19,104,83,104,211,99,243,171,173,153,45,215,182,198,246,218,92,242,92,223,185,171,231,118,207,125,110,103,110,199,183,219,99,119,211,158,106,31,98,191,193,190,
215,254,131,131,163,131,200,161,205,97,210,209,192,49,209,177,214,241,6,139,198,10,99,109,102,157,119,66,59,121,57,173,118,58,230,244,214,217,193,89,236,124,216,249,23,23,166,75,154,75,139,203,163,121,
198,243,248,243,26,231,141,185,234,185,114,92,235,93,165,110,12,183,68,183,189,110,82,119,93,119,142,123,131,251,3,15,125,15,158,71,147,199,132,167,169,103,170,231,65,207,103,94,214,94,34,175,14,175,215,
108,103,246,74,246,41,111,196,219,207,187,196,123,208,135,226,19,229,83,237,115,223,87,207,55,217,183,213,119,202,207,222,111,133,223,41,127,180,127,144,255,54,255,27,1,90,1,220,128,230,128,169,64,199,
192,149,129,125,65,164,160,5,65,213,65,15,130,205,130,69,193,61,33,112,72,96,200,246,144,187,243,13,231,11,231,119,133,130,208,128,208,237,161,247,194,140,195,150,133,125,31,142,9,15,11,175,9,127,24,97,
19,81,16,209,191,128,186,96,201,130,150,5,175,34,189,34,203,34,239,68,153,68,73,162,122,163,21,163,19,162,155,163,95,199,120,199,148,199,72,99,173,98,87,198,94,138,211,136,19,196,117,199,99,227,163,227,
155,226,167,23,250,44,220,185,112,60,193,62,161,56,225,250,34,227,69,121,139,46,44,214,88,156,190,248,248,18,197,37,156,37,71,18,209,137,49,137,45,137,239,57,161,156,6,206,244,210,128,165,181,75,167,184,
108,238,46,238,19,158,7,111,7,111,146,239,202,47,231,79,36,185,38,149,39,61,74,118,77,222,158,60,153,226,158,82,145,242,84,192,22,84,11,158,167,250,167,214,165,190,78,11,77,219,159,246,41,61,38,189,61,
3,151,145,152,113,84,72,17,166,9,251,50,181,51,243,50,135,179,204,179,138,179,164,203,156,151,237,92,54,37,10,18,53,101,67,217,139,178,187,197,52,217,207,212,128,196,68,178,94,50,154,227,150,83,147,243,
38,55,58,247,72,158,114,158,48,111,96,185,217,242,77,203,39,242,125,243,191,94,129,90,193,93,209,91,160,91,176,182,96,116,165,231,202,250,85,208,170,165,171,122,87,235,175,46,90,61,190,198,111,205,129,
181,132,181,105,107,127,40,180,46,44,47,124,185,46,102,93,79,145,86,209,154,162,177,245,126,235,91,139,21,138,69,197,55,54,184,108,168,219,136,218,40,216,56,184,105,238,166,170,77,31,75,120,37,23,75,173,
75,43,74,223,111,230,110,190,248,149,205,87,149,95,125,218,146,180,101,176,204,161,108,207,86,204,86,225,214,235,219,220,183,29,40,87,46,207,47,31,219,30,178,189,115,7,99,71,201,142,151,59,151,236,188,
80,97,87,81,183,139,176,75,178,75,90,25,92,217,93,101,80,181,181,234,125,117,74,245,72,141,87,77,123,173,102,237,166,218,215,187,121,187,175,236,241,216,211,86,167,85,87,90,247,110,175,96,239,205,122,
191,250,206,6,163,134,138,125,152,125,57,251,30,54,70,55,246,127,205,250,186,185,73,163,169,180,233,195,126,225,126,233,129,136,3,125,205,142,205,205,45,154,45,101,173,112,171,164,117,242,96,194,193,203,
223,120,127,211,221,198,108,171,111,167,183,151,30,2,135,36,135,30,127,155,248,237,245,195,65,135,123,143,176,142,180,125,103,248,93,109,7,181,163,164,19,234,92,222,57,213,149,210,37,237,142,235,30,62,
26,120,180,183,199,165,167,227,123,203,239,247,31,211,61,86,115,92,229,120,217,9,194,137,162,19,159,78,230,159,156,62,149,117,234,233,233,228,211,99,189,75,122,239,156,137,61,115,173,47,188,111,240,108,
208,217,243,231,124,207,157,233,247,236,63,121,222,245,252,177,11,206,23,142,94,100,93,236,186,228,112,169,115,192,126,160,227,7,251,31,58,6,29,6,59,135,28,135,186,47,59,93,238,25,158,55,124,226,138,251,
149,211,87,189,175,158,187,22,112,237,210,200,252,145,225,235,81,215,111,222,72,184,33,189,201,187,249,232,86,250,173,231,183,115,110,207,220,89,115,23,125,183,228,158,210,189,138,251,154,247,27,126,52,
253,177,93,234,32,61,62,234,61,58,240,96,193,131,59,99,220,177,39,63,101,255,244,126,188,232,33,249,97,197,132,206,68,243,35,219,71,199,38,125,39,47,63,94,248,120,252,73,214,147,153,167,197,63,43,255,
92,251,204,228,217,119,191,120,252,50,48,21,59,53,254,92,244,252,211,175,155,95,168,191,216,255,210,238,101,239,116,216,244,253,87,25,175,102,94,151,188,81,127,115,224,45,235,109,255,187,152,119,19,51,
185,239,177,239,43,63,152,126,232,249,24,244,241,238,167,140,79,159,126,3,247,132,243,251,199,209,59,120,0,0,0,32,99,72,82,77,0,0,122,38,0,0,128,132,0,0,250,0,0,0,128,232,0,0,117,48,0,0,234,96,0,0,58,
152,0,0,23,112,156,186,81,60,0,0,0,9,112,72,89,115,0,0,14,195,0,0,14,195,1,199,111,168,100,0,0,0,27,116,69,88,116,83,111,102,116,119,97,114,101,0,67,101,108,115,121,115,32,83,116,117,100,105,111,32,84,
111,111,108,193,167,225,124,0,0,32,0,73,68,65,84,120,156,236,221,117,152,149,229,214,199,241,239,144,130,8,2,38,98,161,199,110,197,99,7,118,119,119,183,30,187,187,187,59,142,125,172,163,98,123,236,86,
236,110,197,0,69,66,1,165,97,222,63,126,51,175,3,12,51,179,247,189,238,39,215,231,186,246,5,232,176,158,155,137,253,172,231,142,181,106,106,107,107,113,206,181,72,27,96,62,96,81,96,97,96,49,96,14,160,
123,131,87,155,38,254,254,8,96,34,48,14,248,171,238,247,131,128,159,128,95,234,126,29,8,252,8,124,2,252,25,227,31,225,156,115,0,53,158,0,56,55,77,211,1,43,2,125,128,181,128,101,129,118,9,93,123,18,240,
45,240,1,240,97,221,171,31,240,91,66,215,119,206,21,156,39,0,206,77,174,27,176,13,176,21,176,10,208,33,221,225,76,166,22,37,2,207,214,189,94,1,70,165,58,34,231,92,110,121,2,224,156,158,244,55,1,118,2,
54,32,185,167,252,80,99,129,87,129,251,129,7,128,161,233,14,199,57,151,39,158,0,184,50,155,9,216,11,56,12,152,61,229,177,132,154,8,188,0,220,1,60,4,140,76,119,56,206,185,172,243,4,192,149,209,188,192,
17,192,158,64,199,148,199,18,195,95,192,127,128,203,128,79,83,30,139,115,46,163,60,1,112,101,210,13,56,13,216,31,104,155,238,80,18,81,11,60,3,92,10,60,93,247,231,164,212,160,19,18,51,1,51,0,157,81,178,
53,22,237,91,24,81,247,235,119,248,62,6,231,82,225,9,128,43,131,182,232,166,127,26,74,2,202,232,115,224,2,180,68,48,209,56,118,59,160,55,176,26,176,52,176,64,221,171,165,27,40,7,2,223,0,95,3,111,161,205,
141,95,24,143,209,57,55,5,79,0,92,209,173,4,220,132,206,237,59,248,12,56,1,232,27,24,103,102,96,75,116,90,98,101,236,151,82,126,5,94,70,51,23,15,2,127,24,199,119,174,244,60,1,112,69,213,22,61,241,31,11,
180,78,119,40,153,244,58,250,220,188,90,193,223,105,3,108,14,236,7,172,73,114,159,215,177,192,19,104,95,195,99,192,232,132,174,235,92,161,121,2,224,138,104,97,224,78,96,153,180,7,146,3,15,2,135,160,105,
248,105,233,2,28,12,28,128,214,245,211,52,2,205,232,92,134,42,39,58,231,170,228,9,128,43,154,157,128,27,201,86,1,159,172,27,14,28,131,62,111,13,223,16,58,163,35,146,135,3,93,83,24,87,83,198,163,25,129,
11,81,217,100,231,92,133,60,1,112,69,209,10,56,11,56,14,237,64,119,149,123,9,216,23,109,198,219,13,56,15,152,53,213,17,53,175,22,45,11,28,139,54,58,58,231,90,200,19,0,87,4,157,208,238,246,205,211,30,72,
1,140,1,190,2,150,72,123,32,21,26,15,92,11,156,14,12,75,121,44,206,229,130,39,0,46,239,102,2,254,135,142,159,57,55,20,56,21,184,30,152,144,242,88,156,203,52,79,0,92,158,205,132,154,226,44,153,246,64,92,
230,124,132,150,49,62,72,123,32,206,101,149,39,0,46,175,102,6,158,3,22,79,123,32,141,24,137,158,62,91,163,141,116,46,29,227,208,108,192,133,216,23,63,114,46,247,60,1,112,121,212,29,120,17,88,44,165,235,
79,0,62,6,222,68,237,121,251,215,189,126,164,241,51,234,51,160,51,244,245,59,233,103,68,27,21,103,6,230,110,240,154,7,88,136,242,86,43,140,229,117,96,87,224,219,180,7,226,92,150,120,2,224,242,166,29,170,
111,191,90,194,215,253,9,237,54,127,20,237,150,143,89,191,126,126,224,159,192,242,117,175,101,200,79,139,226,172,250,19,53,128,186,49,237,129,56,151,21,158,0,184,188,185,1,216,39,161,107,141,5,30,169,
187,230,115,36,219,76,167,161,142,192,90,192,54,192,38,104,6,193,85,231,78,116,212,209,171,9,186,210,243,4,192,229,201,9,192,217,9,92,231,15,224,114,224,74,180,171,60,75,218,2,171,3,59,2,219,227,5,143,
170,241,58,176,53,240,75,218,3,113,46,77,158,0,184,188,216,24,61,141,199,44,242,51,10,117,204,187,12,85,199,203,186,174,104,109,123,63,188,217,81,165,6,0,91,0,111,167,61,16,231,210,226,9,128,203,131,89,
209,177,174,89,34,94,163,47,42,123,251,67,196,107,196,82,3,172,1,156,4,244,73,119,40,185,50,6,37,79,183,167,61,16,231,210,224,9,128,203,186,26,244,228,191,113,164,248,67,209,154,240,131,145,226,39,109,
77,84,18,121,165,180,7,210,192,40,84,157,111,92,221,159,103,64,199,35,219,167,54,162,201,157,140,62,103,206,149,138,39,0,46,235,246,3,174,139,20,251,69,96,23,224,231,72,241,211,180,33,112,46,201,151,244,
29,141,54,76,190,140,142,73,126,5,12,106,228,227,90,3,115,1,11,162,19,15,171,2,43,162,13,143,105,184,4,56,138,244,54,122,58,151,56,79,0,92,150,205,13,124,10,76,31,33,246,101,232,13,191,200,5,98,218,0,
71,2,167,144,204,141,245,120,224,42,116,228,174,26,211,163,196,101,91,96,83,146,63,250,120,51,74,56,139,252,61,225,220,255,243,4,192,101,217,125,232,232,155,165,137,104,173,255,106,227,184,89,54,31,106,
148,179,78,228,235,124,2,172,130,205,6,202,89,129,61,129,131,128,57,12,226,181,212,253,192,206,252,189,92,225,92,97,121,2,224,178,106,117,52,69,111,105,2,58,62,119,191,113,220,188,216,29,29,109,236,20,
241,26,207,1,27,160,238,124,22,218,163,186,15,199,145,92,34,240,20,176,21,113,139,61,57,151,58,79,0,92,22,181,6,222,197,182,201,207,68,244,100,119,143,97,204,60,90,4,120,128,184,199,6,111,69,79,239,150,
111,46,29,128,163,129,99,73,102,57,227,101,180,28,241,87,2,215,114,46,21,158,0,184,44,218,7,85,223,179,180,39,240,111,227,152,121,213,9,125,126,119,136,120,141,99,80,19,30,107,115,162,34,77,91,68,136,
61,165,151,128,141,240,36,192,21,148,39,0,46,107,90,163,157,227,189,12,99,94,128,158,28,221,228,14,1,46,69,159,115,107,19,129,245,208,146,64,12,219,161,229,140,153,35,197,175,247,34,74,2,124,57,192,21,
142,39,0,46,107,182,7,254,99,24,239,49,96,51,96,146,97,204,34,217,2,125,190,99,156,201,31,2,44,139,186,36,198,48,11,112,27,176,126,164,248,245,158,68,223,67,86,251,26,156,203,4,79,0,92,214,188,139,186,
223,89,24,128,246,17,100,173,158,127,214,172,9,60,140,138,243,88,123,7,157,12,24,27,33,54,168,80,212,81,168,71,68,219,72,215,0,184,3,216,13,175,19,224,10,196,19,0,151,37,235,0,255,51,138,85,139,166,160,
159,49,138,87,116,203,160,39,221,24,229,150,47,69,173,120,99,90,5,248,47,113,203,69,95,132,54,34,58,87,8,158,0,184,44,121,24,77,181,90,184,22,56,208,40,86,89,44,6,188,0,204,100,28,183,22,77,211,91,37,
119,211,50,23,250,30,90,58,226,53,246,195,126,131,170,115,169,240,4,192,101,69,55,212,158,213,162,250,219,48,96,1,124,234,191,26,203,160,141,123,51,26,199,253,5,45,199,12,54,142,59,165,142,168,206,195,
134,145,226,143,7,214,197,190,70,133,115,137,243,4,192,101,197,254,232,169,221,194,33,168,36,173,171,206,10,232,105,125,6,227,184,125,129,205,141,99,54,166,45,218,28,24,235,152,227,80,212,191,224,219,
72,241,157,75,132,39,0,46,43,94,65,235,184,161,190,67,13,102,38,24,196,42,179,53,80,69,60,235,211,1,59,144,76,49,166,86,232,152,96,172,101,160,15,80,243,162,49,145,226,59,23,157,39,0,46,11,230,65,55,238,
26,131,88,7,98,55,147,80,118,59,3,183,99,243,117,169,247,27,170,70,152,212,242,204,153,192,73,145,98,223,136,90,73,59,151,75,158,0,184,44,56,0,184,198,32,206,32,148,76,248,83,153,157,211,81,55,65,75,183,
163,35,117,73,57,28,184,24,219,68,166,222,174,232,136,160,115,185,227,9,128,203,130,251,129,173,13,226,156,137,253,205,170,236,106,128,187,176,95,79,95,7,120,214,56,102,83,246,6,174,71,75,3,150,70,2,75,
161,25,44,231,114,197,19,0,151,182,26,52,45,28,122,244,172,22,173,253,127,29,60,34,55,165,233,128,215,176,43,208,4,240,41,186,113,38,185,87,35,86,18,240,42,218,51,49,209,56,174,115,81,121,2,224,210,182,
36,218,80,21,234,13,96,37,131,56,174,113,243,163,42,141,150,213,2,15,3,174,48,140,215,18,177,146,128,227,128,243,141,99,58,23,149,39,0,46,45,51,3,179,1,123,161,27,65,168,31,80,217,217,95,208,89,243,65,
192,175,104,118,97,32,240,19,222,15,32,212,182,192,189,134,241,126,71,245,26,134,24,198,108,137,127,161,234,132,150,198,162,25,141,47,140,227,58,23,141,39,0,46,166,30,192,226,104,106,126,33,244,102,63,
31,48,59,113,154,207,52,101,52,122,115,254,28,77,63,127,14,124,2,124,143,31,25,172,196,213,216,30,173,187,10,213,109,72,218,5,216,151,245,125,25,45,5,248,155,170,203,5,79,0,156,149,78,232,28,255,10,168,
3,220,178,232,70,159,117,163,129,126,232,205,251,21,180,148,240,103,170,35,202,182,233,128,247,81,66,103,97,28,74,16,251,27,197,107,169,26,116,26,97,103,227,184,123,3,55,27,199,116,46,10,79,0,92,181,218,
1,171,2,107,161,167,158,222,64,155,52,7,100,100,2,240,30,218,216,245,60,42,139,235,199,10,39,183,34,74,150,90,27,197,251,55,176,167,81,172,74,180,71,37,125,87,48,140,57,12,37,52,73,47,107,56,87,49,79,
0,92,37,186,163,26,235,155,160,122,232,93,210,29,78,34,254,68,93,242,30,4,158,0,70,164,59,156,204,184,4,157,175,183,48,1,88,20,248,202,40,94,37,122,160,189,35,150,179,85,87,3,7,27,198,115,46,10,79,0,92,
115,58,160,14,125,59,162,142,110,49,123,174,103,221,88,52,35,240,80,221,171,204,205,134,58,2,31,162,211,1,22,238,6,118,50,138,85,169,149,80,23,68,139,70,84,160,132,102,73,224,51,163,120,206,69,225,9,128,
155,150,127,162,214,167,91,99,223,20,166,8,198,160,254,243,55,160,253,3,101,180,54,240,140,81,172,9,192,63,72,126,47,64,189,163,128,11,13,227,61,5,108,96,24,207,57,115,158,0,184,134,58,161,39,253,253,
137,219,83,189,104,190,64,137,192,237,148,111,86,224,97,52,67,100,225,74,224,80,163,88,149,106,5,60,141,146,26,43,107,0,47,25,198,115,206,148,39,0,14,116,38,255,16,224,32,160,91,202,99,201,179,49,192,
3,232,136,217,199,41,143,37,41,243,163,99,149,22,211,231,127,1,115,147,94,18,213,3,248,8,237,117,177,240,10,176,154,81,44,231,204,121,2,80,110,115,2,199,160,29,216,29,83,30,75,145,212,2,125,129,179,80,
245,188,162,179,60,83,127,50,250,188,165,101,7,180,31,193,202,122,192,255,12,227,57,103,198,19,128,114,154,5,56,1,77,245,39,93,144,167,108,158,64,55,180,55,210,30,72,68,93,128,111,8,239,231,0,240,51,48,
47,233,22,103,122,2,187,245,251,215,129,149,141,98,57,103,202,19,128,114,153,1,213,44,63,20,173,247,187,228,60,135,146,174,126,105,15,36,146,227,129,115,140,98,109,142,102,80,210,50,55,90,214,152,222,
40,222,42,168,153,146,115,153,226,9,64,57,212,0,187,0,231,145,143,234,124,69,85,139,54,10,30,143,122,22,20,201,12,104,7,191,197,30,146,39,81,189,137,52,29,141,150,54,44,244,69,73,141,115,153,226,9,64,
241,45,135,118,87,91,86,59,115,97,70,2,103,3,151,161,218,2,69,113,18,112,166,65,156,73,168,103,68,127,131,88,213,106,143,206,241,247,50,136,53,9,88,4,248,210,32,150,115,102,60,1,40,174,142,192,25,168,
243,153,85,201,86,103,235,27,224,72,224,145,180,7,98,164,11,106,174,212,213,32,214,193,168,162,94,154,182,1,238,51,138,117,57,250,89,116,46,51,60,1,40,166,53,209,185,116,171,42,109,46,174,190,168,232,
210,160,180,7,98,192,234,68,192,205,168,177,78,154,106,208,218,253,138,6,177,126,7,122,2,163,12,98,57,103,194,19,128,98,105,15,156,143,54,249,213,164,60,22,87,153,193,192,1,168,186,96,158,205,139,102,
54,90,5,198,121,6,245,155,72,155,101,181,195,61,81,227,35,231,50,193,19,128,226,88,24,248,15,170,65,158,117,227,129,31,209,141,162,63,122,242,29,92,247,235,239,168,160,206,232,186,215,24,212,144,103,124,
221,255,3,245,35,168,63,197,208,5,237,214,238,140,142,55,246,0,102,69,55,162,133,81,103,182,206,145,255,61,150,238,66,69,153,126,111,238,3,51,236,81,96,227,192,24,247,1,219,25,140,197,194,27,216,236,161,
121,3,245,29,112,46,19,60,1,40,134,189,209,26,99,22,139,249,12,70,221,214,222,7,62,168,251,181,63,201,158,243,238,137,250,215,47,132,54,99,245,70,165,142,179,186,55,98,0,176,23,42,77,155,71,235,163,157,
252,33,46,70,245,249,179,96,67,224,113,131,56,181,168,223,193,183,6,177,156,11,230,9,64,190,181,7,174,34,253,181,210,134,134,160,41,211,151,235,94,159,163,55,190,172,233,140,202,180,174,94,247,90,134,
108,37,4,181,232,164,192,201,105,15,164,10,53,104,7,253,66,1,49,178,116,118,190,6,37,175,75,24,196,58,5,155,147,18,206,5,243,4,32,191,122,162,245,226,229,211,30,8,186,201,247,5,30,3,222,4,38,166,59,156,
170,212,39,4,91,212,189,44,118,178,91,72,187,52,110,181,118,5,110,171,242,239,126,141,150,110,178,244,230,180,15,218,88,27,234,11,180,52,229,92,234,60,1,200,167,229,209,209,177,89,83,28,195,79,192,61,
168,110,250,7,41,142,35,134,118,104,3,218,118,168,211,93,154,237,144,199,3,75,145,191,222,242,109,80,213,195,74,187,74,214,2,155,96,51,229,110,169,35,42,83,108,145,24,46,65,121,154,69,185,12,243,4,32,
127,54,67,55,221,52,214,251,39,162,58,233,215,162,245,233,73,41,140,33,105,29,80,93,248,93,208,141,41,141,101,130,199,9,223,84,151,134,57,208,140,80,207,10,254,206,25,192,169,113,134,19,236,34,84,183,
33,212,73,104,121,199,185,84,121,2,144,47,135,0,151,146,252,77,104,4,112,29,112,13,240,67,194,215,206,146,94,232,107,176,23,201,206,10,140,71,141,118,70,36,120,77,43,189,208,82,192,42,205,124,220,88,224,
88,180,153,53,171,22,5,62,49,136,243,54,217,88,186,115,37,231,9,64,126,156,142,54,16,37,105,16,122,67,190,6,24,158,240,181,179,172,51,218,120,121,8,48,79,66,215,76,187,65,78,136,86,104,13,253,64,166,222,
72,55,20,184,19,184,16,157,126,200,186,247,209,146,76,136,90,52,43,50,48,124,56,206,85,207,19,128,236,171,65,213,213,146,60,18,245,59,106,28,116,37,58,139,239,26,215,26,109,24,60,25,155,29,226,77,249,
23,217,126,58,110,169,217,208,81,184,118,168,14,68,222,102,148,142,68,75,1,161,118,67,141,161,156,75,141,39,0,217,86,131,142,249,29,152,208,245,198,160,155,204,249,228,187,16,77,210,90,1,219,162,89,154,
5,34,93,227,48,224,138,72,177,93,203,205,129,54,192,134,86,218,188,13,216,61,120,52,206,5,240,4,32,219,174,64,211,204,73,120,12,221,100,190,75,232,122,69,212,6,216,31,37,2,22,109,113,27,90,7,120,214,56,
166,171,206,219,168,203,102,136,159,128,185,12,198,226,92,213,60,1,200,174,51,209,110,225,216,250,163,222,1,143,38,112,173,178,232,134,118,179,239,143,205,134,205,49,117,49,125,57,38,27,78,65,73,94,168,
127,160,101,16,231,82,225,9,64,54,29,141,214,253,99,170,69,133,77,142,70,253,233,157,189,229,128,27,9,223,52,118,59,90,51,118,217,176,12,240,174,65,156,93,208,6,72,231,82,225,9,64,246,108,9,60,64,220,
110,126,63,161,163,108,86,93,206,220,180,181,65,27,199,78,3,166,171,226,239,143,66,85,241,126,54,28,147,11,83,3,252,138,154,79,133,184,138,228,150,248,156,155,138,39,0,217,50,63,106,156,211,37,226,53,
30,69,155,143,134,69,188,134,155,218,98,192,29,84,54,27,48,1,216,9,117,198,115,217,242,0,176,85,96,140,126,192,63,13,198,226,92,85,60,1,200,142,14,168,93,104,172,118,190,227,128,227,81,33,33,255,162,167,
163,29,218,27,112,36,154,25,104,202,104,212,63,254,158,216,131,114,85,57,148,240,99,153,99,81,65,169,241,225,195,113,174,114,158,0,100,199,77,104,90,62,134,223,208,210,66,86,186,171,149,221,66,232,168,
229,134,76,157,8,140,70,179,52,39,3,95,37,60,46,215,114,75,3,239,25,196,89,4,53,211,114,46,113,158,0,100,195,54,196,155,230,253,8,216,148,252,21,92,41,131,250,14,132,61,234,254,220,31,120,5,223,237,159,
7,109,208,230,217,106,246,117,52,180,13,90,78,112,46,113,158,0,164,111,6,244,4,48,71,132,216,143,3,219,3,127,70,136,237,92,217,189,3,44,27,24,227,84,180,44,228,92,226,60,1,72,223,133,196,41,243,123,7,
90,82,240,245,69,231,226,184,25,237,211,8,113,55,218,232,233,92,226,60,1,72,215,162,168,185,72,91,227,184,151,1,71,224,155,253,156,139,233,48,244,179,22,226,117,96,229,22,124,92,71,160,125,221,239,39,
224,181,59,156,1,79,0,210,245,60,176,166,113,204,115,129,19,140,99,58,231,166,182,17,42,161,29,98,32,147,47,255,117,1,214,64,199,3,23,67,53,32,122,0,157,166,248,123,99,129,193,192,151,192,103,104,57,226,
121,188,94,132,171,128,39,0,233,89,3,120,193,56,230,197,36,219,53,208,185,50,91,4,248,52,48,198,36,96,78,212,85,114,123,96,5,154,63,34,218,148,207,80,129,161,219,80,17,41,231,166,201,19,128,244,60,9,172,
111,24,239,74,116,54,217,57,151,140,233,209,84,124,104,213,206,137,216,244,140,104,104,8,112,73,221,107,172,113,108,87,16,158,0,164,99,9,224,3,236,202,253,62,141,206,148,79,50,138,231,156,107,153,223,
128,153,211,30,68,19,190,2,14,194,59,73,186,70,120,2,144,142,59,177,219,249,251,61,106,58,227,165,125,157,75,222,167,104,41,32,235,46,71,141,191,252,84,144,251,127,158,0,36,175,39,186,105,135,172,243,
213,27,143,54,11,189,111,16,203,57,87,185,87,128,85,210,30,68,11,189,12,108,11,12,74,123,32,46,27,60,1,72,222,145,192,69,70,177,124,199,191,115,233,122,24,216,44,237,65,84,224,107,160,15,126,90,192,225,
9,64,26,222,196,166,3,216,247,232,152,144,239,244,117,46,61,183,2,187,165,61,136,10,125,141,142,31,15,72,123,32,46,93,158,0,36,107,30,224,59,108,54,255,109,14,244,53,136,227,156,171,222,141,192,222,105,
15,162,10,31,3,43,2,127,165,61,16,151,30,79,0,146,117,44,112,158,65,156,15,81,55,50,255,226,57,151,174,107,129,253,211,30,68,149,30,4,182,198,223,71,74,203,19,128,100,89,77,255,111,71,188,238,129,206,
185,150,187,18,56,56,237,65,4,56,8,184,38,237,65,184,116,120,2,144,156,142,192,31,132,215,253,255,22,149,7,157,24,60,34,87,54,109,249,187,164,108,107,212,142,248,247,186,63,255,129,63,9,86,227,114,242,
93,128,107,4,176,16,240,75,218,3,113,201,243,4,32,57,171,1,47,25,196,57,29,56,205,32,142,43,150,118,232,60,250,98,192,124,168,188,108,207,186,215,140,117,175,233,155,137,49,22,85,144,27,130,10,220,12,
64,123,86,190,67,137,231,103,232,134,225,254,118,3,176,79,218,131,8,116,47,42,67,236,74,198,19,128,228,88,173,255,47,12,124,97,16,199,229,215,108,104,3,215,98,117,175,197,129,127,96,83,91,162,41,181,232,
244,201,251,104,31,202,107,104,89,171,204,39,81,238,0,118,78,123,16,6,150,5,222,75,123,16,46,89,158,0,36,199,226,188,240,7,104,243,159,43,151,110,192,234,232,232,86,31,212,70,58,43,198,3,111,163,34,51,
79,161,164,96,66,170,35,74,214,127,129,45,211,30,132,129,123,128,29,210,30,132,75,150,39,0,201,25,8,204,30,24,227,66,224,24,131,177,184,108,171,65,229,157,183,2,214,1,150,2,90,165,58,162,150,251,29,245,
166,120,12,120,132,226,247,173,255,31,250,26,229,221,4,52,139,212,63,229,113,184,4,121,2,144,140,233,208,52,105,232,249,255,205,208,155,170,43,166,69,129,109,128,29,209,155,113,222,141,65,77,104,110,71,
53,43,198,165,59,156,40,62,66,75,48,69,112,2,170,46,234,74,194,19,128,100,204,143,170,111,133,168,5,102,65,27,180,92,113,44,6,236,137,206,99,207,153,242,88,98,26,138,122,212,95,143,58,212,21,197,32,244,
115,25,195,55,192,235,104,207,197,247,104,167,254,68,52,27,212,21,77,217,239,138,221,236,208,59,64,111,163,88,46,7,60,1,72,198,26,192,11,129,49,126,2,230,10,31,138,203,128,142,168,150,195,62,104,51,95,
153,212,2,207,161,2,58,125,201,247,113,214,54,232,228,132,229,242,204,64,84,93,240,94,224,243,22,124,252,134,192,67,232,20,72,168,90,84,173,244,71,131,88,46,7,60,1,72,198,206,104,183,112,136,87,129,85,
13,198,226,210,179,36,176,47,106,5,221,37,229,177,100,193,55,104,95,203,109,232,70,154,55,115,96,215,84,231,103,224,12,212,91,160,210,150,189,59,2,119,25,141,99,127,52,75,227,74,192,19,128,100,88,28,1,
188,27,221,56,92,190,212,0,27,160,46,144,125,82,30,75,86,253,2,92,138,102,5,254,76,121,44,149,88,22,77,155,135,152,4,92,13,28,79,88,93,254,199,128,141,2,199,2,154,77,40,194,169,6,215,2,158,0,36,227,52,
224,212,192,24,126,2,32,95,218,163,153,159,35,80,129,30,215,188,223,128,179,129,235,200,199,134,193,77,9,111,200,213,15,155,242,224,255,64,75,6,173,3,227,12,71,199,78,39,5,143,200,101,158,39,0,201,56,
29,56,37,48,198,217,192,73,6,99,113,113,205,128,106,195,31,138,10,246,184,202,245,71,9,243,157,100,251,70,100,49,179,119,31,218,15,98,225,81,96,99,131,56,11,16,190,105,217,229,128,39,0,201,176,72,0,206,
52,136,225,226,233,12,28,2,28,14,116,79,121,44,69,241,33,74,166,94,77,123,32,211,112,59,176,75,96,140,11,80,34,97,97,19,108,142,9,111,141,10,28,185,130,243,4,32,25,103,0,39,7,198,240,30,0,217,212,25,61,
237,31,142,166,78,157,173,90,180,193,237,24,178,215,176,230,61,194,43,115,30,136,246,62,88,104,131,142,9,135,110,48,61,5,61,112,184,130,243,4,32,25,103,18,62,125,127,49,112,148,193,88,156,141,14,232,137,
255,88,252,198,159,132,145,40,1,190,156,108,28,29,108,141,198,212,33,48,206,134,192,147,225,195,249,127,143,160,153,128,16,87,147,239,22,199,174,133,60,1,72,198,49,192,249,129,49,254,131,142,251,184,116,
181,6,118,67,51,50,61,83,30,75,25,189,13,236,5,124,156,242,56,254,129,77,65,163,249,81,167,69,43,231,2,199,5,198,184,31,216,214,96,44,46,227,60,1,72,198,78,104,67,83,136,151,81,67,24,151,158,205,128,115,
240,93,253,105,27,135,190,14,231,146,222,105,129,205,80,131,175,16,127,161,37,36,203,141,142,7,0,215,4,198,120,6,88,215,96,44,46,227,60,1,72,198,26,132,87,2,236,15,204,27,60,18,87,141,149,209,12,206,202,
105,15,36,208,24,180,70,60,229,77,179,19,48,19,249,105,56,84,239,99,180,9,239,195,20,174,125,40,90,142,8,97,117,4,176,161,221,129,127,7,198,120,150,98,52,56,114,205,240,4,32,25,86,189,0,102,2,134,133,
15,199,181,208,162,232,73,115,211,180,7,210,66,195,129,47,234,94,95,162,41,234,159,208,249,250,33,52,95,100,103,38,116,130,97,38,244,61,187,48,154,237,88,4,149,136,13,61,99,30,195,88,52,229,125,57,250,
25,73,202,73,132,111,148,187,25,216,219,96,44,13,237,1,220,18,24,195,19,128,146,240,4,32,25,29,9,171,242,85,111,61,212,126,212,197,213,3,189,185,239,70,54,111,122,245,62,7,222,64,13,99,222,172,251,115,
172,115,243,29,129,149,208,50,212,26,192,242,216,212,159,183,242,20,122,250,29,148,208,245,246,37,188,100,238,225,192,101,6,99,153,50,230,37,129,49,30,35,124,35,161,203,1,79,0,146,243,27,48,115,96,140,
147,80,65,32,23,71,71,116,210,226,24,96,250,148,199,210,152,145,232,233,236,41,180,115,252,167,20,199,210,17,45,137,108,141,74,199,206,148,226,88,234,13,66,73,219,211,9,92,107,25,224,221,192,24,203,163,
77,141,150,46,3,14,11,140,113,43,154,73,112,5,231,9,64,114,94,2,86,11,140,209,23,216,220,96,44,110,114,173,208,70,205,115,200,222,206,254,145,232,235,126,15,218,156,149,197,18,185,109,128,181,208,206,
241,45,80,171,218,180,76,4,78,68,5,118,98,190,185,213,0,223,161,165,145,106,244,7,122,97,63,198,23,208,12,77,136,139,128,163,195,135,226,178,206,19,128,228,92,7,236,23,24,99,32,234,64,230,108,212,160,
221,220,103,0,139,167,60,150,134,38,162,167,252,91,129,199,129,209,169,142,166,50,211,1,219,163,26,9,203,164,56,142,123,208,113,193,81,17,175,177,39,90,199,175,198,190,168,237,175,181,97,132,39,96,135,
2,87,26,140,197,101,156,39,0,201,249,23,234,120,22,170,39,48,192,32,78,217,109,128,110,252,203,165,61,144,6,126,66,55,148,91,72,119,122,223,202,202,40,17,216,18,104,155,194,245,223,71,51,18,63,68,138,
223,10,173,151,111,80,225,223,123,26,21,0,178,222,175,49,23,54,255,214,245,73,102,25,197,165,204,19,128,228,172,135,158,234,66,237,66,120,77,129,178,106,133,150,80,142,69,235,175,89,241,42,218,184,245,
8,217,168,114,103,173,39,218,169,191,15,201,111,28,28,12,108,131,150,224,98,152,17,125,221,86,109,225,199,191,129,18,134,225,17,198,178,27,154,53,10,53,47,90,162,112,5,231,9,64,114,102,71,83,248,161,238,
36,188,1,73,217,180,7,118,69,27,252,22,72,121,44,13,189,133,234,174,151,229,100,199,60,232,223,187,11,218,55,144,148,241,104,119,252,213,145,226,183,67,179,73,135,161,37,144,198,140,69,71,21,79,69,245,
24,98,120,0,216,42,48,198,48,180,161,211,111,12,37,224,9,64,178,190,70,231,171,67,252,134,146,137,44,183,73,205,138,57,209,90,235,62,192,172,41,143,165,57,191,163,55,223,97,104,55,251,192,186,215,0,212,
4,231,71,84,50,54,230,154,118,82,22,68,117,253,183,37,217,226,67,151,162,36,48,214,207,206,28,232,223,212,7,152,27,237,49,249,1,205,62,220,73,220,102,70,237,209,108,199,12,129,113,158,162,242,37,13,151,
83,158,0,36,235,38,180,49,41,212,106,192,43,6,113,138,168,6,237,72,63,16,21,240,201,242,57,254,106,252,2,124,131,146,129,175,128,79,234,94,253,201,223,83,219,10,168,19,222,82,9,94,243,62,52,27,52,54,193,
107,38,97,125,108,154,10,157,134,250,92,184,18,240,4,32,89,187,2,183,25,196,185,10,109,174,114,127,235,137,10,193,236,14,204,151,234,72,210,49,2,248,20,109,124,235,87,247,250,130,236,39,5,173,81,231,185,
51,80,93,252,36,188,140,246,130,252,158,208,245,146,112,11,54,103,247,87,71,159,31,87,2,158,0,36,107,30,224,123,131,56,191,162,233,237,9,6,177,242,172,29,122,202,223,19,53,47,41,218,211,126,168,225,104,
159,193,43,232,124,120,63,180,30,158,69,61,80,203,235,237,19,186,222,103,104,39,126,172,19,2,73,234,140,150,139,66,139,87,141,68,165,160,179,250,61,226,140,121,2,144,188,175,80,43,209,80,155,161,221,199,
101,180,24,90,74,217,153,108,84,160,203,139,191,208,137,131,103,208,241,181,47,211,29,78,163,214,69,79,179,73,212,187,24,8,108,4,124,144,192,181,98,178,40,75,12,122,63,217,204,32,142,203,9,79,0,146,119,
14,112,188,65,156,178,213,235,110,135,54,88,29,140,125,7,181,178,250,6,120,20,189,241,191,76,118,54,150,118,67,133,179,182,73,224,90,35,128,141,201,247,158,154,126,64,111,131,56,187,1,183,27,196,113,57,
225,9,64,242,44,106,136,131,206,139,47,128,202,145,22,89,15,96,127,244,148,147,245,157,252,121,246,11,112,63,170,160,247,38,217,216,59,176,27,112,5,241,247,6,252,133,150,146,158,143,124,157,24,150,66,
251,62,66,141,70,63,95,35,13,98,185,156,240,4,32,29,223,162,58,224,161,174,1,14,50,136,147,69,43,163,167,253,173,72,167,138,92,153,125,135,166,225,111,37,253,170,147,243,2,119,160,239,135,152,70,163,239,
53,139,157,244,73,186,13,109,46,14,117,31,176,157,65,28,151,35,158,0,164,227,124,212,113,46,212,104,148,72,252,106,16,43,11,218,1,59,146,126,29,121,39,19,209,13,241,218,186,95,211,122,179,104,141,142,
166,157,128,142,121,198,50,22,221,4,251,70,188,134,165,30,104,83,177,69,117,197,45,128,135,13,226,184,28,241,4,32,29,11,163,35,91,22,111,102,87,163,39,229,60,235,132,54,245,29,69,246,186,241,57,249,6,
29,63,189,9,77,153,167,97,19,84,80,39,230,146,192,68,116,148,52,15,229,182,207,69,37,150,67,253,1,204,70,241,106,35,184,102,120,2,144,158,103,81,193,154,80,227,129,69,81,149,193,188,153,5,149,79,61,16,
213,84,119,217,55,20,85,212,187,18,109,160,75,218,18,232,73,117,222,136,215,152,136,206,212,223,17,241,26,161,166,71,213,33,187,25,196,186,9,85,203,116,37,227,9,64,122,182,0,30,52,138,245,56,218,201,156,
23,189,208,211,254,238,64,135,116,135,226,170,244,59,112,25,74,6,146,222,56,214,29,184,23,155,4,122,90,38,162,229,168,251,34,94,35,132,85,119,81,128,101,129,247,140,98,185,28,241,4,32,61,173,209,102,171,
185,140,226,109,143,222,20,179,108,49,224,68,116,188,203,139,246,20,195,111,168,138,223,13,36,91,64,166,13,112,33,186,17,198,50,30,37,234,143,71,188,70,53,166,67,27,137,123,24,196,122,157,248,27,44,93,
70,121,2,144,174,227,208,58,158,133,223,128,37,201,230,134,192,133,80,23,180,164,155,191,184,228,124,133,54,111,38,221,217,240,0,180,28,17,43,161,28,141,42,6,190,24,41,126,53,14,70,255,102,11,59,160,163,
159,174,132,60,1,72,87,39,148,201,207,98,20,239,5,96,29,178,211,83,126,30,84,244,104,79,146,109,255,234,210,115,63,58,154,58,56,193,107,110,10,252,7,232,24,41,254,40,96,61,84,69,49,109,237,80,178,53,183,
65,172,95,234,226,120,233,223,146,242,4,32,125,71,161,169,76,43,167,163,142,94,105,154,7,56,9,21,114,241,27,127,249,12,1,142,36,217,170,114,43,162,138,134,177,74,67,15,3,214,4,62,138,20,191,165,246,71,
199,50,45,156,138,150,111,92,73,121,2,144,190,14,104,22,96,118,163,120,181,168,70,254,221,70,241,42,49,39,122,226,223,11,155,179,201,89,242,7,106,174,83,255,106,120,100,106,56,147,151,209,29,135,142,202,
181,71,79,165,29,208,186,237,244,232,243,50,3,74,140,186,212,253,190,104,159,171,122,207,160,27,86,82,213,42,23,64,245,10,44,138,108,53,102,16,176,42,233,157,184,177,124,250,31,91,23,103,144,65,44,151,
83,158,0,100,195,65,232,140,181,149,177,168,221,233,83,134,49,155,50,15,218,207,176,7,249,184,153,77,64,111,124,63,163,61,19,13,127,29,202,223,55,249,63,26,252,26,83,119,180,12,52,51,58,143,61,107,131,
223,207,129,110,108,243,144,207,217,148,145,192,222,36,183,155,126,86,180,105,111,217,72,241,191,65,179,13,67,34,197,111,202,222,192,141,70,177,174,71,201,153,43,49,79,0,178,161,29,170,231,189,136,97,
204,49,168,179,87,204,77,89,243,161,234,108,187,144,221,114,189,63,0,255,70,199,156,6,214,189,6,145,157,198,55,45,213,22,61,217,46,136,18,130,5,80,87,201,37,176,57,11,30,219,21,192,209,104,118,36,182,
206,192,19,196,219,221,254,58,58,130,56,38,82,252,198,180,5,190,192,102,118,99,2,250,62,42,122,31,17,215,12,79,0,178,99,85,224,37,108,75,157,142,67,79,13,214,5,77,122,1,199,146,221,205,125,19,209,134,
200,27,128,135,208,27,94,145,245,64,55,187,85,208,147,239,178,104,201,33,107,222,65,71,64,251,39,112,173,142,168,164,239,218,145,226,223,143,142,222,38,149,72,238,129,250,51,88,184,19,37,237,174,228,60,
1,200,150,155,209,77,213,82,45,112,54,218,24,24,122,58,96,81,116,142,127,91,178,121,142,255,43,84,213,236,54,116,44,178,172,166,67,189,20,86,4,54,0,86,35,59,51,52,67,208,209,179,103,19,184,86,7,84,53,
112,221,72,241,207,199,166,20,111,115,218,0,159,3,243,27,196,170,69,179,70,159,24,196,114,57,231,9,64,182,116,71,211,124,49,118,50,191,12,236,132,214,185,43,181,52,154,234,223,146,236,157,227,159,128,
42,42,94,131,254,141,254,13,61,181,206,232,38,184,17,58,211,110,117,236,180,90,227,208,19,109,18,27,85,219,3,15,16,175,82,230,126,104,166,41,166,93,176,59,81,209,23,237,15,114,206,19,128,12,218,129,120,
111,140,35,128,147,81,3,161,230,102,3,106,80,77,129,163,137,55,141,26,98,8,218,16,117,13,213,37,53,101,213,10,88,14,37,115,187,96,83,77,174,26,147,80,21,63,171,130,54,77,105,135,234,4,108,25,33,246,4,
148,92,60,29,33,54,104,166,237,19,84,76,203,194,10,192,91,70,177,92,206,121,2,144,77,183,160,39,164,88,62,66,137,192,35,141,252,191,246,168,37,234,17,168,178,96,214,124,132,54,148,221,141,170,180,185,
234,181,70,75,4,123,162,155,88,26,203,4,103,161,239,197,216,218,0,255,69,69,131,172,253,1,44,79,156,227,129,219,163,228,197,194,83,232,235,237,28,224,9,64,86,77,15,188,141,218,6,199,244,14,112,57,58,162,
53,23,176,47,74,60,98,21,83,169,214,36,148,172,92,78,182,74,178,22,201,44,104,70,96,47,226,127,223,77,233,26,84,222,54,246,155,209,116,192,99,196,105,34,244,9,122,186,182,108,149,220,10,248,16,245,208,
176,176,34,240,166,81,44,87,0,158,0,100,215,18,232,135,53,137,110,121,127,160,117,226,172,173,239,143,67,79,250,23,160,77,80,46,190,26,180,79,224,88,116,50,37,41,73,109,168,235,132,142,198,174,24,33,246,
189,104,9,207,234,77,117,43,180,127,193,194,211,192,250,70,177,92,65,120,2,144,109,123,162,147,1,101,243,23,90,223,191,4,248,41,229,177,148,217,202,192,153,168,4,110,18,142,193,182,44,246,180,116,69,199,
68,99,44,113,29,5,92,108,165,127,195,141,0,0,32,0,73,68,65,84,16,167,6,213,174,88,202,32,22,192,74,192,27,70,177,92,65,120,2,144,125,231,160,242,186,101,48,20,85,68,188,178,238,247,69,211,26,157,209,95,
25,109,234,90,0,85,174,155,30,149,4,30,129,146,159,95,209,145,198,207,81,3,154,15,72,183,112,209,58,192,121,232,104,97,76,181,168,110,133,213,121,247,166,204,138,78,141,44,96,28,119,2,58,113,241,66,96,
156,77,209,142,125,11,254,244,239,26,229,9,64,246,213,160,105,240,237,211,30,72,68,67,208,52,255,53,216,174,161,102,65,27,116,67,216,5,109,192,234,82,69,140,97,168,188,237,29,192,115,164,147,12,180,66,
55,231,179,137,187,71,100,34,186,249,61,17,241,26,245,230,68,79,197,115,24,199,29,140,18,189,144,217,171,183,209,105,13,11,254,244,239,26,229,9,64,62,180,71,141,85,146,92,147,77,194,239,104,186,244,10,
84,51,190,72,166,71,155,42,143,196,246,6,211,31,77,147,223,66,178,165,104,235,117,67,95,179,221,35,94,227,119,160,55,106,146,21,219,82,104,38,96,6,227,184,111,161,159,215,106,90,237,110,136,18,62,11,79,
214,197,115,110,42,158,0,100,223,66,64,31,84,188,99,157,148,199,98,101,56,112,25,112,105,221,239,139,164,6,157,164,56,15,53,244,137,101,32,90,111,182,58,34,86,169,13,81,1,28,235,167,231,122,31,162,39,
215,81,145,226,55,180,33,58,101,98,93,221,242,92,84,64,171,82,111,160,19,5,161,106,209,241,196,119,12,98,185,2,242,4,32,123,102,70,111,72,107,161,27,127,172,55,216,52,252,137,158,246,47,70,211,218,69,
211,11,85,108,139,213,132,166,49,207,162,132,35,141,98,72,221,129,91,137,87,101,239,14,96,215,72,177,167,116,32,42,144,101,105,18,42,162,85,201,126,128,181,209,108,159,5,175,250,231,154,228,9,64,54,76,
143,58,247,237,132,214,139,179,216,96,39,196,72,180,185,239,18,210,105,163,154,132,173,81,31,130,106,214,248,67,13,65,55,202,39,83,184,118,13,170,22,121,14,113,250,67,236,137,186,57,38,225,98,84,0,203,
210,207,104,153,161,165,155,90,159,198,166,119,193,36,84,194,251,35,131,88,174,160,60,1,72,79,43,52,165,191,51,202,210,59,165,59,156,40,134,163,29,253,151,82,204,39,254,122,135,161,127,163,101,39,199,
74,213,162,253,6,151,166,116,253,13,129,123,176,95,75,31,142,10,225,36,49,195,209,10,157,187,223,194,56,238,67,180,172,12,241,18,232,196,135,197,247,209,125,168,162,167,115,211,228,9,64,242,218,163,29,
225,71,144,124,197,181,164,252,129,170,246,93,142,54,116,21,217,133,104,45,62,43,78,70,229,117,211,176,56,154,133,176,94,182,122,2,53,50,74,194,244,104,13,126,113,227,184,251,3,215,55,243,49,183,97,179,
228,49,17,141,223,139,103,185,38,121,2,144,156,110,192,1,168,228,233,108,41,143,37,150,97,252,125,227,47,218,230,190,198,156,12,156,145,246,32,26,113,4,233,205,4,244,66,71,21,231,49,142,187,7,218,111,
144,132,249,209,49,188,25,13,99,142,66,39,27,62,155,198,255,159,3,248,14,53,46,10,117,39,122,200,112,174,73,158,0,196,215,25,21,242,57,4,61,93,20,217,67,104,31,67,25,154,244,236,138,158,216,178,104,18,
42,35,251,112,74,215,159,19,245,108,232,101,24,115,48,240,15,146,75,44,55,70,155,232,44,203,99,247,67,39,27,26,235,196,121,62,170,132,24,106,18,176,40,106,43,238,92,147,60,1,136,167,21,90,223,63,159,226,
62,241,55,230,45,180,161,113,80,218,3,137,104,81,244,102,222,49,237,129,52,225,15,84,185,239,251,148,174,223,11,85,49,156,221,48,230,133,216,220,36,91,234,52,224,84,227,152,141,149,59,238,128,246,56,116,
51,136,255,40,113,58,30,186,2,242,4,32,142,117,129,139,176,95,71,204,139,239,209,231,224,155,180,7,18,65,91,224,93,242,241,181,125,29,21,163,73,171,140,176,117,145,157,177,192,34,104,170,60,9,173,208,
13,213,178,144,206,104,244,121,249,170,193,127,179,236,249,209,135,240,50,196,174,36,60,1,176,53,43,112,45,246,187,136,243,232,39,96,13,146,123,179,78,202,49,104,86,39,47,246,65,199,19,211,178,37,218,
89,111,117,66,226,30,212,113,47,41,93,209,126,128,249,12,99,190,130,126,54,234,19,179,119,80,233,224,80,239,19,191,95,131,43,16,79,0,236,108,141,110,254,49,235,164,231,205,143,192,234,168,124,109,17,204,
6,124,77,190,142,108,14,69,55,175,52,55,101,158,5,156,104,20,107,34,154,5,248,170,185,15,52,180,28,154,77,105,107,24,243,16,84,27,227,159,168,237,183,133,93,208,6,64,231,90,196,19,128,112,221,208,15,114,
146,79,37,121,242,13,122,147,43,66,29,128,172,29,249,107,169,19,81,161,158,180,180,65,79,189,22,229,109,65,125,16,246,50,138,213,82,199,162,242,206,86,254,68,203,72,167,99,115,244,111,0,48,47,213,245,
30,112,37,229,9,64,152,117,208,78,112,203,141,78,69,244,2,176,30,249,126,115,234,10,252,128,125,161,155,36,12,70,199,242,146,168,171,63,45,243,163,34,55,22,39,97,198,161,89,141,36,203,31,183,66,37,122,
251,24,198,124,21,205,46,76,103,16,235,56,242,181,52,229,50,192,19,128,234,29,129,90,216,198,40,127,90,68,215,163,98,40,121,21,163,86,124,146,118,36,189,198,65,245,142,98,234,29,240,213,58,29,237,210,
79,210,28,168,73,81,247,132,175,219,156,191,208,209,203,162,23,221,114,198,60,1,168,220,116,232,102,150,84,147,146,16,127,160,106,96,159,213,253,250,41,218,156,215,3,88,0,109,68,234,131,205,241,163,150,
200,194,77,168,90,86,29,218,234,77,68,45,95,31,65,103,182,135,162,253,35,139,162,99,148,235,97,123,6,253,41,96,3,195,120,213,104,139,102,1,22,49,136,245,51,154,242,158,96,16,171,18,91,0,15,38,124,205,
230,164,177,36,226,10,192,19,128,202,244,64,197,110,150,79,123,32,141,24,6,188,134,214,90,223,71,55,253,129,45,248,123,173,81,133,178,221,209,62,134,206,145,198,7,74,72,150,64,73,72,158,204,142,214,88,
173,118,178,191,128,42,66,78,171,42,28,232,168,216,53,192,138,70,215,156,128,18,189,145,70,241,170,181,30,74,70,44,108,2,60,102,20,171,18,215,3,251,166,112,221,105,89,25,109,82,116,174,34,158,0,180,220,
98,168,83,87,143,180,7,82,231,71,116,179,127,181,238,215,207,80,67,152,16,93,129,127,213,189,98,37,2,47,160,26,1,73,63,185,133,216,17,184,203,40,214,141,104,57,161,37,255,254,246,232,233,110,71,163,107,
111,140,102,29,210,246,42,54,45,147,239,66,197,182,146,214,9,248,24,251,114,199,213,248,28,155,25,21,87,66,158,0,180,204,50,232,230,159,246,17,191,119,209,244,227,67,196,109,244,49,59,170,37,31,171,155,
216,151,104,103,250,131,132,39,45,73,184,14,216,207,32,206,227,104,122,191,177,82,176,211,210,22,120,22,88,205,224,250,23,160,221,236,105,179,234,121,63,2,213,222,24,99,16,171,82,235,160,247,132,52,59,
64,130,90,49,95,148,242,24,92,78,121,2,208,188,127,162,41,75,203,198,32,45,53,9,77,235,63,132,110,150,63,36,124,253,173,81,133,178,88,179,1,111,161,27,210,75,145,226,91,121,5,88,37,48,198,104,180,239,
162,154,157,235,189,80,194,23,218,40,230,49,52,109,158,5,31,162,229,160,80,235,1,255,51,136,83,141,91,80,147,162,180,140,71,155,255,138,92,118,219,69,228,9,64,211,86,69,111,154,49,215,197,27,243,27,170,
222,118,29,233,175,151,47,136,154,202,44,20,241,26,79,160,29,226,89,109,95,58,8,152,37,48,198,149,192,161,1,127,223,162,85,236,215,40,9,201,130,125,105,190,61,110,75,92,76,122,181,25,186,162,141,181,105,
29,3,126,8,85,90,116,174,42,158,0,76,219,106,232,198,148,100,7,191,126,168,168,208,125,168,238,121,86,204,140,158,178,150,138,120,141,113,232,205,252,44,210,61,175,62,165,182,104,108,161,214,68,29,242,
170,181,25,225,221,253,70,145,157,142,148,157,128,95,9,31,207,71,192,146,225,195,169,218,230,232,70,156,134,180,54,65,186,130,240,4,160,113,11,161,169,247,36,142,199,77,2,254,139,214,241,250,37,112,189,
106,117,69,235,182,22,53,203,155,210,31,61,41,63,26,249,58,45,213,13,29,209,11,213,5,173,89,87,107,78,180,241,51,84,91,178,179,1,243,30,194,247,153,76,66,95,163,52,75,29,223,11,108,155,240,53,127,65,223,
19,149,236,39,113,110,50,158,0,76,109,22,84,155,123,222,4,174,213,23,56,5,61,197,228,193,236,40,73,233,153,192,181,250,2,7,161,227,119,105,234,73,248,50,204,24,212,242,53,68,59,108,102,133,102,36,221,
155,101,67,86,79,207,235,98,179,169,176,90,179,160,83,1,161,203,68,149,184,10,245,19,112,174,106,158,0,76,174,35,58,166,22,251,156,255,135,192,97,100,127,243,91,99,150,70,155,226,146,152,74,30,134,146,
128,123,18,184,214,180,204,66,248,38,171,90,244,189,21,178,91,125,102,180,55,36,212,116,100,103,121,105,6,244,53,110,19,24,231,100,180,116,148,38,139,37,154,74,132,46,41,57,231,9,64,3,173,80,219,210,152,
173,124,255,4,142,71,93,3,243,60,117,183,63,250,55,36,229,94,116,118,62,141,134,66,29,176,217,147,176,40,77,23,254,105,206,138,132,23,123,25,135,106,11,100,201,219,168,30,126,136,251,136,119,100,181,18,
55,3,123,38,112,157,65,168,44,113,158,223,67,92,6,120,2,240,183,227,137,219,49,237,25,180,243,185,127,196,107,36,165,6,157,129,94,39,193,107,14,68,229,78,173,170,200,85,226,79,194,103,60,142,33,172,14,
190,69,75,221,95,200,78,33,171,122,23,163,190,26,33,62,65,157,245,210,214,25,149,58,142,189,124,152,247,190,26,46,35,60,1,144,69,128,247,136,243,116,52,30,56,1,189,209,21,233,147,61,23,58,2,213,41,193,
107,214,162,36,237,84,146,125,250,121,159,240,19,16,223,3,11,83,221,244,123,39,224,43,194,143,155,189,136,166,142,179,196,98,31,192,56,180,196,146,133,39,226,213,208,50,162,101,31,135,41,173,131,138,67,
57,23,196,19,0,213,194,127,157,56,235,254,3,80,49,157,55,35,196,206,130,211,209,38,198,164,61,139,202,227,14,78,232,122,255,1,182,55,136,115,2,112,110,21,127,239,124,52,131,16,42,139,79,142,243,160,228,
40,84,79,210,223,48,90,239,2,84,161,47,134,33,40,17,204,202,73,14,151,99,158,0,168,18,221,121,17,226,126,136,206,233,166,93,200,39,166,78,192,183,36,187,251,185,222,0,116,244,42,137,38,40,135,1,151,25,
196,153,136,246,152,84,114,196,113,7,84,243,222,162,228,236,30,192,173,6,113,44,181,65,123,44,218,6,198,89,9,117,108,204,130,246,232,180,140,69,165,195,41,221,4,236,19,33,174,43,161,178,39,0,11,162,53,
187,233,140,227,62,142,110,78,89,42,104,19,203,17,104,121,35,13,227,208,230,192,155,35,95,103,9,148,208,89,152,128,158,230,47,71,103,216,167,165,13,112,28,154,101,177,154,78,158,27,155,90,2,214,190,69,
229,142,67,108,69,182,218,244,46,129,74,93,91,191,183,28,69,122,63,111,174,96,202,158,0,60,132,214,32,45,61,130,110,254,89,57,106,21,91,39,244,52,158,116,185,228,134,174,0,14,167,233,27,106,136,26,116,
227,180,172,127,240,17,122,35,127,156,201,11,13,205,2,108,138,222,232,23,52,188,222,167,168,163,101,22,61,7,244,9,140,177,43,112,135,193,88,44,29,8,92,109,28,115,28,234,234,152,102,221,3,87,16,101,78,
0,86,64,211,199,150,221,188,30,68,199,145,202,182,62,119,21,58,175,159,166,123,208,20,119,172,206,112,231,162,39,114,107,147,208,177,174,33,232,172,255,172,196,233,48,119,60,113,150,186,44,220,65,120,
91,223,253,177,233,45,96,237,126,180,15,200,210,8,96,13,180,57,213,185,170,149,57,1,120,1,253,16,89,121,30,216,144,242,60,249,55,180,56,217,168,102,248,26,154,209,25,18,33,246,194,232,41,58,237,246,175,
213,152,128,166,216,179,186,31,229,38,116,196,51,196,17,168,133,117,214,204,136,78,24,89,31,13,28,138,78,3,120,18,224,170,86,214,4,96,125,224,73,195,120,159,163,25,133,144,90,239,121,247,26,218,136,149,
182,207,208,27,227,192,8,177,31,69,211,175,121,115,7,225,157,4,99,186,6,56,32,48,198,73,192,217,6,99,137,225,159,168,122,102,232,70,199,41,253,142,202,32,191,99,28,215,149,68,89,19,128,119,129,101,140,
98,13,71,63,224,95,26,197,203,171,35,81,67,163,44,248,6,88,11,251,13,111,43,144,157,157,230,45,53,9,173,253,103,181,213,50,104,67,100,72,171,100,80,125,136,208,66,73,49,29,69,88,33,168,105,249,3,37,165,
175,69,136,237,10,174,140,9,192,106,216,214,224,223,26,117,243,43,187,5,200,86,18,244,3,176,54,74,6,44,89,213,4,72,202,181,104,51,90,150,89,84,3,60,23,213,89,200,170,26,212,186,119,195,8,177,255,2,182,
68,45,187,157,107,177,50,38,0,22,45,72,235,221,14,236,102,20,171,8,190,192,118,231,122,168,129,40,9,176,124,250,157,13,253,59,187,24,198,140,101,40,250,122,88,180,51,142,201,162,134,126,150,55,57,214,
235,142,138,130,205,31,33,246,88,84,28,43,75,71,33,93,198,149,45,1,152,29,61,25,90,172,197,253,130,54,134,101,165,181,106,22,92,136,166,58,179,100,32,176,42,240,157,97,204,237,209,76,64,150,213,162,167,
194,36,59,212,85,235,97,212,77,47,196,129,36,219,160,170,90,11,163,101,164,24,9,228,68,180,153,242,182,8,177,93,1,149,45,1,56,13,213,145,183,176,19,112,183,81,172,162,216,152,202,170,220,37,229,59,148,
4,88,110,12,76,170,243,91,181,46,65,251,50,242,224,85,96,229,192,24,121,250,121,92,23,213,127,8,109,131,220,152,90,244,117,207,226,137,8,151,49,101,74,0,90,163,77,97,22,221,208,94,1,86,167,88,205,125,
44,204,130,206,180,103,209,39,232,107,102,213,82,184,29,90,211,77,178,35,98,75,61,142,142,67,230,165,30,197,231,192,66,129,49,54,65,95,143,188,176,42,47,61,45,89,62,21,225,50,162,76,9,192,170,192,203,
134,177,94,53,138,85,52,223,163,6,47,89,244,22,218,19,240,167,81,188,46,168,158,196,210,70,241,44,188,134,158,48,243,82,134,186,53,250,122,132,150,204,93,29,187,159,239,164,92,143,90,132,199,114,1,234,
117,226,92,163,202,148,0,88,236,52,6,213,15,136,177,147,183,40,238,3,182,73,123,16,77,120,12,61,29,91,181,142,157,17,232,139,78,151,164,237,57,212,108,104,100,218,3,169,192,130,104,83,101,168,94,216,116,
21,76,82,91,244,126,178,86,196,107,228,105,41,200,37,172,76,9,192,55,192,124,6,113,250,160,167,62,215,184,163,209,147,71,136,9,196,89,31,173,119,49,182,155,21,59,160,106,118,59,26,198,172,212,245,192,
33,192,248,20,199,80,141,173,128,7,2,99,140,65,61,41,172,146,186,36,117,66,73,192,42,17,175,113,41,74,2,74,243,102,239,90,166,44,9,192,98,192,199,6,113,222,199,174,128,80,81,109,138,158,136,67,124,136,
158,212,99,22,118,217,27,251,46,130,251,160,162,54,29,140,227,54,101,4,170,131,159,245,83,9,211,114,26,225,27,115,63,65,229,168,243,106,6,116,134,127,133,136,215,184,28,53,204,42,197,27,190,107,153,178,
36,0,39,2,103,25,196,57,12,117,158,115,211,102,209,23,96,48,218,80,120,56,122,90,143,81,127,127,28,90,43,183,44,10,5,234,24,120,41,246,13,96,26,243,24,106,194,148,197,22,191,45,245,24,176,81,96,140,255,
146,204,231,59,166,46,168,195,95,239,136,215,184,2,248,23,158,4,184,58,101,73,0,158,65,155,191,66,76,66,111,238,191,132,15,167,208,58,17,190,6,93,139,158,162,199,2,187,3,55,18,103,73,96,8,154,209,137,
209,36,103,61,180,19,59,198,212,238,115,192,25,228,111,211,219,148,218,161,34,69,157,2,227,100,189,12,112,75,117,69,95,219,152,155,74,175,68,15,50,165,120,227,119,77,43,67,2,208,10,189,201,204,24,24,231,
69,96,205,224,209,148,195,111,168,181,109,136,134,155,186,54,71,83,220,161,59,197,27,243,58,234,10,25,107,237,124,101,84,47,96,107,160,115,64,156,97,104,131,229,45,192,219,6,227,202,2,171,178,220,187,
162,134,71,69,208,29,37,1,75,70,188,198,85,168,247,66,225,223,252,93,211,202,144,0,44,132,77,41,216,3,128,235,12,226,148,193,91,192,242,129,49,166,60,106,217,7,120,4,152,62,48,110,99,46,4,142,137,16,183,
161,14,232,223,212,7,37,5,11,163,55,251,105,25,140,58,27,190,138,90,77,191,70,241,90,77,159,1,156,108,16,231,31,216,247,124,72,83,87,224,9,226,238,9,240,36,192,149,34,1,216,149,240,210,152,147,80,13,248,
193,225,195,137,174,53,122,210,236,90,247,107,103,116,211,236,4,180,7,58,214,189,218,215,253,183,182,104,253,177,21,186,73,53,124,202,174,255,248,122,109,209,180,237,95,205,140,97,41,96,166,192,127,199,
246,192,189,83,252,183,245,209,6,195,118,129,177,167,84,139,54,47,38,93,72,166,59,218,235,208,9,125,13,134,163,229,147,65,168,213,107,209,245,35,124,205,123,0,90,154,43,154,78,232,123,189,79,196,107,120,
157,128,146,43,67,2,112,21,218,40,21,226,35,226,78,201,53,166,35,186,137,118,71,211,233,221,27,188,102,106,240,251,134,55,250,250,155,125,17,28,65,227,229,76,183,7,238,66,9,139,165,161,104,237,53,198,
126,0,55,53,171,238,145,119,163,50,192,69,52,29,74,130,55,141,120,13,175,24,88,98,101,72,0,94,33,124,35,214,213,192,193,6,99,1,232,134,202,17,247,64,179,10,179,215,189,102,5,230,64,79,132,115,16,190,49,
42,239,78,71,71,196,26,115,0,112,77,132,107,62,131,54,239,21,254,135,34,3,206,68,55,159,80,251,1,55,24,196,201,170,182,192,173,196,173,49,225,167,155,74,170,12,9,192,15,192,92,129,49,246,64,63,132,205,
105,7,204,89,247,154,11,152,187,145,63,23,229,9,61,182,230,214,229,79,66,55,17,107,69,191,161,100,65,13,240,45,48,175,65,172,133,177,169,36,152,101,173,80,194,187,95,164,248,181,168,139,224,191,35,197,
119,25,85,244,4,160,53,170,18,22,122,132,172,55,240,78,221,239,59,161,138,130,243,215,253,58,95,131,63,207,137,253,212,116,89,181,100,214,229,50,244,244,98,105,36,170,101,240,131,113,92,247,183,213,209,
169,154,80,63,163,196,186,208,111,98,117,106,128,243,81,165,205,24,38,162,89,134,251,34,197,119,25,84,244,4,96,78,108,138,164,60,132,166,230,231,71,83,245,46,190,91,208,83,73,83,90,161,141,123,27,24,95,
251,57,212,229,175,208,63,28,41,122,8,29,237,12,117,25,42,22,85,38,231,0,199,71,138,61,30,245,146,120,60,82,124,151,49,69,79,0,86,66,199,167,92,254,220,3,236,208,130,143,235,138,206,197,91,244,121,104,
200,151,2,226,88,16,29,111,180,152,41,91,17,120,211,32,78,222,156,69,188,194,71,163,81,101,70,239,119,82,2,69,79,0,182,101,234,163,100,46,31,30,1,54,107,225,199,46,1,188,193,228,71,22,67,13,69,55,171,
161,134,49,157,170,58,238,109,16,167,63,42,22,85,232,55,176,38,88,109,162,108,204,8,180,76,243,65,164,248,46,35,138,158,0,236,129,166,146,93,254,60,131,106,245,183,212,142,232,120,160,165,235,208,137,
3,103,99,118,84,221,177,189,65,172,243,129,227,12,226,228,217,233,192,41,145,98,15,68,51,168,190,23,166,192,138,158,0,236,135,87,239,203,171,231,169,188,79,250,165,168,217,137,149,73,104,154,185,159,97,
204,50,179,122,250,7,213,108,240,39,84,21,242,57,47,82,236,111,80,18,144,135,2,104,174,10,69,79,0,14,70,205,47,92,254,84,147,0,180,65,181,229,87,50,28,199,27,168,116,111,161,127,80,18,176,4,240,30,58,
153,19,234,61,96,89,131,56,69,113,10,154,13,136,225,85,180,33,118,76,164,248,46,69,69,79,0,14,7,46,73,123,16,174,42,213,36,0,160,10,115,239,99,187,31,96,103,236,151,23,202,230,89,170,251,122,54,166,72,
205,127,172,196,92,14,120,16,216,6,205,136,185,2,41,122,2,16,115,122,204,197,85,109,2,0,170,13,112,153,225,88,190,69,5,103,98,117,12,44,186,77,81,93,123,11,191,0,243,0,227,140,226,21,201,37,196,59,22,
121,21,112,72,164,216,46,37,69,79,0,142,66,21,229,92,254,132,36,0,173,234,254,254,234,118,195,241,110,144,85,234,2,124,140,106,114,88,56,25,29,131,115,83,171,1,174,7,246,137,20,255,88,212,64,200,21,68,
209,19,128,61,129,155,211,30,132,171,74,72,2,0,58,34,246,33,118,61,21,6,160,182,179,163,141,226,149,197,191,129,221,141,98,141,70,149,255,134,24,197,43,162,86,104,121,36,70,239,128,90,180,28,118,119,132,
216,46,5,69,79,0,54,3,30,78,123,16,174,42,161,9,0,216,55,13,58,26,184,200,48,94,209,109,12,60,106,24,239,122,96,127,195,120,69,213,6,120,128,150,215,209,168,196,24,212,162,248,141,8,177,93,194,138,158,
0,172,130,186,1,186,252,177,72,0,106,128,151,9,239,6,89,111,8,106,232,52,202,40,94,145,205,132,218,104,207,110,20,111,20,218,224,57,192,40,94,209,181,71,201,215,58,17,98,255,10,44,143,183,206,206,189,
162,39,0,139,0,159,166,61,136,12,26,5,140,5,254,68,27,219,70,2,19,80,5,176,137,192,112,180,227,119,28,240,87,131,191,247,23,147,111,190,170,255,56,234,254,222,136,186,223,255,19,45,191,132,176,72,0,0,
150,3,222,194,174,73,211,193,168,81,145,155,182,214,192,83,192,218,134,49,207,33,94,249,219,162,234,8,60,141,93,2,220,208,251,192,170,76,254,254,224,114,166,232,9,192,44,192,160,180,7,17,104,44,240,59,
186,73,143,64,55,221,145,232,230,61,178,238,207,35,26,252,249,207,6,31,255,23,186,217,143,65,235,167,163,73,230,60,239,206,132,31,211,178,74,0,0,110,67,71,199,44,124,139,74,4,79,52,138,87,68,23,162,13,
184,86,6,163,70,92,35,154,251,64,55,149,25,209,44,216,226,17,98,63,128,202,173,23,250,38,82,100,69,79,0,106,128,97,232,135,32,43,134,163,242,154,67,208,27,219,208,186,223,15,109,240,106,248,255,254,76,
103,152,65,178,150,0,204,1,124,9,76,111,20,111,27,244,230,231,166,182,29,240,31,244,179,103,229,80,188,160,87,136,158,192,235,216,157,196,104,232,12,224,212,8,113,93,2,138,158,0,128,222,168,183,74,123,
16,13,140,3,110,5,206,69,13,77,138,40,107,9,0,232,77,234,52,163,88,253,208,50,135,155,92,111,212,69,206,42,209,2,149,163,93,20,63,247,31,106,81,180,31,170,171,113,220,90,96,123,224,62,227,184,46,1,101,
72,0,214,1,254,151,246,32,26,49,30,184,19,37,2,95,167,60,22,107,89,76,0,58,162,89,128,158,70,241,86,193,91,77,55,180,48,154,106,158,201,48,102,45,176,30,106,12,229,194,173,138,222,11,167,51,142,59,10,
88,13,120,215,56,174,139,172,12,9,0,232,40,96,140,35,49,22,38,161,141,58,215,2,143,83,140,114,155,89,76,0,192,182,46,196,237,192,110,70,177,242,110,110,84,51,222,42,185,170,119,51,118,205,131,156,108,
133,158,214,173,54,197,214,251,25,157,12,248,197,56,174,139,168,44,9,64,87,244,116,178,88,11,63,126,4,240,25,176,66,180,17,53,174,63,112,19,42,180,241,125,194,215,182,148,213,4,160,45,218,196,103,177,
22,58,10,232,129,246,116,148,217,172,232,103,107,1,227,184,3,208,180,117,217,63,191,49,196,106,146,246,10,170,17,48,33,66,108,23,65,89,18,0,80,18,112,27,176,73,51,31,247,62,90,211,250,14,184,135,244,246,
15,244,67,153,250,253,192,143,41,141,161,90,89,77,0,192,182,79,192,65,216,22,26,202,155,185,209,236,213,130,17,98,111,2,60,22,33,174,147,115,129,227,34,196,189,8,21,204,114,57,80,166,4,160,222,122,168,
154,216,90,192,12,117,255,109,60,90,207,253,55,122,250,174,207,96,219,162,155,240,230,9,143,177,161,90,224,19,180,14,250,44,122,218,202,250,217,219,44,39,0,211,163,153,22,139,181,234,50,183,165,93,20,
221,252,231,136,16,251,78,96,151,8,113,221,223,106,208,123,221,246,198,113,107,129,45,241,10,172,185,80,198,4,160,161,30,168,104,201,64,166,125,174,187,29,58,73,208,220,204,65,82,198,162,217,129,151,209,
148,219,235,232,204,127,150,100,57,1,0,219,19,1,203,162,68,160,76,86,68,79,231,221,34,196,254,6,157,38,248,35,66,108,55,185,14,192,139,104,237,222,210,31,168,0,215,183,198,113,157,177,178,39,0,45,213,
30,184,133,56,13,54,66,77,0,62,64,201,192,75,104,51,214,208,84,71,148,253,4,160,59,154,5,176,104,20,116,33,112,140,65,156,188,216,17,184,17,157,170,176,54,10,37,23,31,69,136,237,26,55,59,122,160,176,222,
192,249,62,176,18,201,20,30,115,85,242,4,160,229,106,80,209,139,147,210,30,72,51,106,209,6,198,151,209,236,192,59,192,87,36,123,186,32,235,9,0,216,245,78,255,30,152,143,226,87,67,107,139,214,119,15,141,
120,141,93,208,244,191,75,214,50,232,1,194,58,169,187,137,120,173,137,157,1,79,0,42,183,27,112,3,90,26,200,139,145,232,169,234,221,6,175,207,136,119,211,202,67,2,176,0,240,5,54,21,235,122,163,68,171,168,
102,70,27,98,251,68,188,198,85,192,33,17,227,187,166,109,137,54,28,91,31,15,220,3,21,62,115,25,228,9,64,117,214,64,229,78,103,75,121,28,33,6,163,155,214,219,104,186,238,99,244,52,107,49,83,144,135,4,0,
180,92,178,178,65,156,243,137,179,163,58,11,54,71,53,42,98,126,175,191,129,126,166,188,218,95,186,78,70,179,156,150,70,161,227,212,31,27,199,117,6,60,1,168,222,172,40,179,93,63,229,113,88,26,5,124,142,
78,29,124,134,126,104,63,67,189,11,42,145,151,4,96,111,180,158,29,234,91,212,172,166,72,102,2,174,0,118,136,124,157,175,80,85,197,193,145,175,227,154,23,235,100,192,87,104,179,108,30,251,154,20,154,39,
0,97,106,208,58,242,185,228,107,73,160,82,245,133,145,62,69,55,187,111,81,157,132,111,81,231,193,41,229,37,1,232,140,78,128,88,212,174,95,28,37,78,69,176,53,154,146,159,53,242,117,6,160,25,152,74,19,76,
23,79,7,180,153,184,183,113,220,27,129,125,141,99,186,64,158,0,216,88,6,109,120,89,58,237,129,164,96,24,127,39,3,245,175,5,9,223,25,159,68,2,0,118,173,130,143,68,27,11,243,108,105,180,209,47,230,90,127,
189,97,168,126,252,167,9,92,203,85,102,46,180,79,200,178,175,3,168,28,251,35,198,49,93,0,79,0,236,180,66,79,190,151,160,99,102,46,76,82,9,192,154,117,215,10,245,36,176,161,65,156,52,204,1,156,2,236,133,
234,98,196,54,10,21,228,122,53,129,107,185,234,172,133,10,61,89,126,63,12,65,51,101,191,26,198,116,1,60,1,176,55,27,122,138,218,17,219,158,232,101,147,84,2,80,131,106,2,204,21,24,103,20,42,140,51,54,116,
64,9,234,1,28,1,28,136,166,126,147,48,26,216,2,221,92,92,182,157,2,156,110,28,243,49,96,83,138,127,108,54,23,60,1,136,103,9,84,51,96,107,60,17,168,70,82,9,0,192,213,232,38,24,106,45,108,102,19,98,235,
133,122,34,236,139,125,107,216,166,12,71,21,53,95,73,240,154,174,122,173,208,13,123,3,227,184,7,0,215,25,199,116,85,240,4,32,190,222,168,244,236,70,105,15,36,103,146,76,0,54,194,166,241,204,57,192,137,
6,113,98,89,6,29,87,220,10,251,243,222,205,25,132,78,204,124,144,240,117,93,152,238,104,63,192,220,134,49,255,66,223,139,95,25,198,116,85,240,4,32,57,203,160,167,204,237,177,217,117,94,116,73,38,0,29,
80,249,228,208,105,240,87,129,85,195,135,99,110,9,116,190,123,83,210,153,141,234,15,172,11,124,157,194,181,93,184,222,104,214,166,189,97,204,183,209,9,144,241,134,49,93,133,60,1,72,94,103,180,89,112,95,
96,201,148,199,146,101,73,38,0,0,143,2,27,7,198,24,135,246,1,100,165,91,227,194,168,233,209,214,36,255,196,95,239,19,244,228,63,32,165,235,59,27,7,96,223,250,250,76,180,207,192,165,196,19,128,116,45,133,
142,198,108,70,57,143,16,54,37,233,4,192,234,13,110,61,224,127,6,113,66,244,66,155,183,118,36,189,27,63,168,139,230,158,100,175,91,165,171,206,157,192,78,134,241,38,160,34,80,111,25,198,116,21,240,4,32,
59,230,66,83,180,235,0,255,36,126,17,150,172,75,58,1,152,11,155,130,52,105,150,5,238,138,54,158,30,132,237,116,109,165,38,2,39,160,78,137,254,6,83,28,51,160,61,28,189,12,99,126,140,170,4,250,82,64,10,
60,1,200,174,94,168,134,246,10,104,173,108,73,146,57,163,157,21,73,39,0,160,162,52,139,4,198,232,135,18,184,36,181,3,14,70,27,16,187,37,124,237,41,13,65,251,92,158,75,121,28,46,142,21,81,167,209,54,134,
49,79,2,206,54,140,231,90,200,19,128,252,232,140,166,203,86,65,21,212,122,83,236,242,195,183,163,206,139,73,186,18,221,72,67,76,64,79,226,73,213,61,223,10,184,0,219,167,178,106,245,3,182,1,126,76,123,
32,46,170,211,208,201,38,43,99,208,3,142,159,10,72,152,39,0,249,213,1,88,30,37,3,171,162,204,188,83,170,35,178,117,24,106,70,147,164,45,129,255,26,196,89,19,120,209,32,78,83,22,66,159,159,117,34,95,167,
37,198,162,83,6,23,160,4,200,21,91,27,52,11,176,162,97,204,23,81,9,106,191,33,37,200,19,128,226,104,141,110,10,203,54,120,45,71,186,107,193,33,150,32,249,22,162,221,80,87,186,208,141,115,39,160,6,81,49,
116,68,125,22,142,35,27,95,219,15,129,221,241,243,253,101,211,11,181,17,239,108,24,115,111,224,102,195,120,174,25,158,0,20,91,71,84,127,160,55,154,45,88,158,108,76,21,55,231,71,96,30,210,121,26,120,31,
157,206,8,209,23,216,220,96,44,83,218,22,245,154,152,35,66,236,74,141,69,83,193,23,225,79,253,101,181,59,240,111,195,120,191,163,61,56,222,43,32,33,158,0,148,79,23,212,144,99,9,180,238,182,36,176,24,217,
42,78,180,3,112,79,74,215,190,4,181,120,14,241,43,48,187,193,88,234,205,137,202,21,111,98,24,51,196,211,232,115,244,121,218,3,113,169,187,15,237,251,176,140,183,157,97,60,215,4,79,0,28,104,202,123,62,
254,78,8,22,65,203,9,243,147,252,70,195,199,72,247,70,183,13,122,19,10,53,47,170,128,23,162,21,170,30,121,14,58,130,149,182,143,128,163,73,191,206,129,203,142,174,232,251,162,167,97,204,77,176,41,205,
237,154,225,9,128,107,74,27,52,21,191,32,74,8,22,108,240,251,89,34,92,111,36,176,40,240,83,132,216,45,53,55,225,55,110,80,245,189,144,13,133,139,0,55,2,43,25,140,37,212,64,224,100,224,86,96,82,186,67,
113,25,180,62,106,135,109,229,39,244,62,224,5,164,34,243,4,192,85,99,38,84,247,126,65,227,184,7,163,169,238,180,253,74,120,33,166,51,168,238,168,84,43,52,189,126,22,201,118,234,107,204,112,224,98,180,
44,146,149,242,198,46,155,238,64,37,206,173,156,7,28,111,24,207,53,194,19,0,87,169,46,192,179,232,132,129,165,55,81,193,163,44,60,97,62,66,248,50,196,195,168,239,125,37,230,70,79,217,107,4,94,59,212,95,
104,55,246,217,192,111,41,143,197,229,67,119,224,51,236,102,6,199,161,89,128,111,140,226,185,70,120,2,224,42,209,9,109,0,179,158,150,30,133,142,45,126,97,28,183,90,39,162,39,240,16,223,161,125,21,45,181,
23,112,41,233,174,245,143,70,125,218,207,195,111,252,174,114,59,161,126,1,86,238,71,39,95,92,36,158,0,184,150,234,128,54,230,244,137,16,123,31,224,166,8,113,171,181,1,240,68,96,140,90,52,91,210,220,58,
102,119,244,180,189,89,224,245,66,140,67,159,255,115,240,174,125,46,204,227,192,134,70,177,106,81,161,179,87,141,226,185,41,120,2,224,90,162,29,240,16,118,63,216,13,101,241,216,207,156,216,148,179,93,
9,120,163,137,255,191,26,112,23,182,59,168,43,49,1,149,92,62,19,155,141,143,206,205,133,90,64,91,205,100,189,131,122,107,100,97,105,176,112,60,1,112,205,105,7,220,141,106,206,91,235,143,218,32,255,17,
33,118,168,223,129,25,3,99,236,129,214,244,167,212,26,45,51,156,66,58,13,158,38,161,58,11,167,227,245,215,157,189,67,176,45,227,189,27,74,84,157,49,79,0,92,83,166,71,61,221,215,143,16,123,2,122,2,110,
234,9,57,77,175,162,77,137,33,206,65,55,250,134,122,160,167,254,53,2,99,87,235,25,224,40,116,118,219,185,24,90,1,175,96,183,87,104,0,58,113,228,39,81,140,121,2,224,166,165,27,90,207,91,33,82,252,152,245,
242,45,92,7,236,23,24,99,202,229,141,213,128,123,129,217,2,227,86,227,83,84,196,199,242,188,182,115,211,178,8,234,15,209,214,40,94,181,199,106,93,19,60,1,112,141,153,3,237,246,95,52,82,252,7,208,238,222,
44,127,243,89,76,99,190,143,122,49,128,186,27,94,136,221,27,98,75,13,66,111,156,55,227,53,251,93,178,44,202,106,215,27,133,10,144,165,89,36,172,112,60,1,112,83,90,0,221,252,231,137,20,255,125,96,21,244,
3,157,101,235,1,79,5,198,24,137,122,2,220,0,236,24,60,162,202,140,70,199,10,207,195,43,170,185,116,204,136,246,152,204,108,20,239,78,96,23,163,88,14,79,0,220,228,150,69,199,223,98,148,249,5,85,216,91,
158,124,100,241,255,192,102,131,220,87,40,169,74,74,45,218,99,112,2,249,248,60,187,98,219,15,45,167,89,152,132,122,149,124,98,20,175,244,60,1,112,245,118,64,103,193,59,70,138,63,22,88,147,236,110,250,
155,82,59,52,75,145,198,46,253,106,125,4,236,79,126,62,199,174,248,90,3,239,162,27,183,133,135,128,45,141,98,149,158,39,0,174,53,218,140,119,116,228,235,228,241,40,207,247,196,91,10,177,244,39,112,26,
112,57,190,206,239,178,103,13,224,5,163,88,181,104,22,241,29,163,120,165,230,9,64,185,117,3,254,3,172,27,249,58,199,163,181,232,188,121,142,56,149,15,45,61,134,154,40,253,144,246,144,164,80,75,0,0,32,
0,73,68,65,84,64,156,107,194,3,216,213,18,121,146,56,69,201,74,199,19,128,242,90,12,53,172,169,164,94,125,53,46,34,254,236,66,44,55,2,123,167,61,136,105,248,17,157,84,120,36,237,129,56,215,2,243,162,102,
65,86,29,46,87,1,94,51,138,85,90,158,0,148,211,118,104,189,191,83,228,235,220,140,234,252,231,245,155,236,116,84,173,47,75,38,161,169,254,147,241,194,40,46,95,206,70,155,83,45,60,133,122,118,184,0,158,
0,148,75,103,224,74,96,215,4,174,245,0,176,61,48,49,129,107,197,178,63,112,109,218,131,104,224,103,180,151,226,249,180,7,226,92,21,58,1,95,99,87,8,107,57,180,193,208,85,201,19,128,242,88,5,109,194,155,
55,129,107,61,13,108,138,186,204,229,217,166,64,223,180,7,81,231,94,224,0,212,163,192,185,188,58,12,184,204,40,150,159,8,8,228,9,64,241,181,1,78,170,123,37,113,164,237,113,96,107,96,76,2,215,138,173,55,
208,47,229,49,140,64,123,40,110,72,121,28,206,89,152,14,248,6,85,27,13,85,11,44,129,215,5,168,154,39,0,197,182,0,170,158,213,59,161,235,221,131,150,23,198,39,116,189,216,122,146,110,49,157,55,80,125,6,
223,225,239,138,228,96,180,20,105,225,46,96,103,163,88,165,227,9,64,49,213,0,7,1,231,19,175,176,207,148,110,66,107,230,121,94,243,159,82,91,210,91,198,184,5,56,16,21,80,114,174,72,218,163,89,128,158,6,
177,38,0,189,240,170,151,85,241,4,160,120,230,66,55,143,181,18,188,230,213,192,161,104,135,122,209,140,36,254,105,137,134,38,162,22,194,231,39,120,77,231,146,118,0,112,141,81,172,11,129,99,140,98,149,
138,39,0,197,178,59,218,96,211,37,161,235,213,162,227,104,103,39,116,189,52,252,128,146,170,36,12,69,93,18,125,151,191,43,186,118,168,79,198,220,6,177,254,64,63,163,222,244,170,66,158,0,20,195,172,168,
104,205,38,9,94,115,52,58,146,118,127,130,215,76,195,7,216,213,49,111,202,247,192,58,192,183,9,92,203,185,44,216,7,187,205,173,255,66,245,49,92,5,60,1,200,191,245,128,219,80,18,144,148,95,128,205,128,
183,19,188,102,90,94,64,181,204,99,250,10,45,217,252,28,249,58,206,101,73,91,224,75,108,142,38,127,143,58,120,22,105,15,82,116,158,0,228,87,59,212,196,231,112,180,233,47,41,31,160,243,241,101,217,116,
243,32,176,69,196,248,159,1,107,163,164,202,185,178,217,19,85,12,181,176,25,94,26,187,34,158,0,228,211,130,192,221,192,50,9,95,247,65,52,237,255,103,194,215,77,211,173,232,223,28,195,135,104,218,127,112,
164,248,206,101,93,59,224,59,108,234,2,120,147,160,10,121,2,144,63,187,161,93,247,211,39,120,205,177,104,151,237,149,228,183,174,127,181,174,69,199,27,173,125,15,172,8,12,138,16,219,185,60,57,6,155,83,
47,147,208,50,192,119,6,177,74,193,19,128,252,152,14,253,144,28,154,240,117,127,64,53,253,223,76,248,186,89,113,41,218,96,100,105,24,176,50,240,133,113,92,231,242,168,51,234,110,105,113,122,233,124,224,
56,131,56,165,224,9,64,62,204,141,118,219,39,85,209,175,222,67,192,94,148,187,254,252,57,192,241,134,241,198,161,46,102,126,212,207,185,191,93,12,28,97,16,103,8,48,39,197,40,69,30,157,39,0,217,183,21,
42,236,211,57,193,107,254,9,28,5,92,159,224,53,179,234,36,224,76,195,120,59,163,242,165,206,185,191,205,133,142,192,182,49,136,181,61,106,158,229,154,225,9,64,118,181,70,79,159,71,147,236,46,255,103,209,
249,220,254,9,94,51,203,142,4,46,50,138,117,29,170,128,230,156,155,154,213,137,27,223,12,216,66,158,0,100,83,103,224,14,116,220,46,41,195,209,102,156,27,41,223,70,191,166,88,181,47,253,8,88,1,21,80,114,
206,77,109,109,224,25,131,56,19,129,121,240,186,26,205,242,4,32,123,22,0,30,6,22,78,240,154,79,2,251,81,158,179,253,149,56,4,184,34,48,198,159,192,114,168,232,137,115,110,218,62,1,22,53,136,115,44,112,
129,65,156,66,243,4,32,91,54,70,235,195,73,173,247,15,71,167,10,110,79,232,122,121,116,32,58,118,25,226,86,96,143,240,161,56,87,120,135,98,83,210,247,51,108,18,137,66,243,4,32,59,14,67,59,97,91,39,116,
189,103,81,21,46,127,234,111,218,254,168,22,64,136,155,208,190,10,231,92,211,186,0,3,177,105,99,222,27,120,199,32,78,97,121,2,144,190,214,232,172,249,33,9,93,111,52,112,58,106,161,89,196,246,189,214,246,
67,155,247,66,92,79,156,98,66,206,21,209,29,232,180,76,40,111,19,220,12,79,0,210,213,9,184,7,216,40,161,235,189,137,42,9,126,149,208,245,138,96,111,180,49,50,196,53,192,65,6,99,113,174,12,250,0,207,25,
196,249,1,53,26,242,155,220,52,120,2,144,158,217,208,230,187,165,18,184,214,68,116,150,253,108,96,66,2,215,43,18,139,25,128,43,73,190,130,163,115,121,85,131,106,2,88,116,9,92,1,120,203,32,78,33,121,2,
144,142,121,129,167,81,221,234,216,126,66,211,105,47,39,112,173,34,178,56,5,112,25,234,218,232,156,107,153,83,129,211,12,226,92,130,106,121,184,70,120,2,144,188,165,208,147,255,108,9,92,235,97,84,202,
119,88,2,215,42,170,35,208,230,204,16,23,163,202,138,206,185,150,153,23,205,2,132,22,65,251,9,149,82,247,27,93,35,60,1,72,214,106,168,95,181,69,211,139,166,140,65,13,49,174,192,191,241,67,29,143,42,50,
134,240,6,37,206,85,238,13,52,133,31,202,79,3,76,131,39,0,201,89,15,53,215,233,16,249,58,95,3,219,160,94,243,46,220,41,232,212,68,136,115,129,19,12,198,226,92,153,252,11,157,144,10,117,58,54,203,9,133,
227,9,64,50,54,2,254,11,180,143,124,157,190,104,151,255,240,200,215,41,147,51,81,67,160,16,103,1,39,27,140,197,185,50,233,129,166,240,91,5,198,121,23,85,226,116,83,240,4,32,190,36,110,254,19,209,77,230,
12,252,108,191,53,139,54,165,39,18,190,140,224,92,25,189,0,172,17,24,163,22,117,27,244,222,0,83,240,4,32,174,173,129,187,129,182,17,175,49,4,216,17,155,38,26,110,106,215,3,251,6,198,56,20,29,5,116,206,
85,230,96,108,126,118,246,3,110,48,136,83,40,158,0,196,179,17,106,111,217,46,226,53,222,67,237,51,127,140,120,141,178,187,11,37,88,33,246,64,253,0,156,115,149,153,27,155,214,228,125,129,205,13,226,20,
138,39,0,113,244,1,30,7,166,139,120,141,135,128,93,128,191,34,94,195,233,212,198,38,129,49,182,66,201,160,115,174,114,239,19,94,48,109,56,208,29,45,151,186,58,158,0,216,91,1,248,31,48,67,196,107,92,129,
10,203,248,122,127,124,207,3,107,6,198,88,23,95,162,113,174,90,167,163,211,56,161,254,9,244,51,136,83,24,158,0,216,90,12,120,5,152,49,82,252,113,104,45,235,214,72,241,221,212,250,161,115,196,33,86,68,
125,24,156,115,149,91,14,120,219,32,206,9,232,72,174,171,227,9,128,157,158,168,112,69,207,72,241,135,161,245,126,47,233,155,172,111,129,94,129,49,22,3,62,53,24,139,115,101,84,3,252,2,204,26,24,231,57,
96,237,240,225,20,135,39,0,54,102,68,79,254,139,69,138,255,19,176,62,240,89,164,248,110,218,70,162,174,141,33,230,66,95,67,231,92,117,44,54,227,142,6,186,161,74,169,14,79,0,44,180,67,107,254,171,71,138,
255,25,186,249,251,13,36,121,29,177,217,100,217,21,248,195,32,142,115,101,181,7,112,139,65,156,85,129,87,13,226,20,130,39,0,225,110,66,13,119,98,120,3,216,24,111,230,147,22,139,35,72,181,168,14,132,239,
62,118,174,122,115,98,115,220,249,104,224,34,131,56,133,224,9,64,152,195,80,171,215,24,158,64,53,253,71,69,138,239,154,215,155,240,93,195,191,163,105,71,231,92,152,47,128,5,3,99,60,136,142,229,58,60,1,
8,177,14,186,73,183,137,16,187,47,176,45,218,245,239,210,179,17,240,88,96,140,47,128,133,13,198,226,92,217,93,135,78,65,133,248,5,245,24,112,120,2,80,173,121,80,131,137,24,79,118,15,3,219,225,55,255,44,
176,88,119,124,137,240,90,230,206,57,21,62,187,221,32,206,60,192,15,6,113,114,207,19,128,202,181,71,59,254,67,207,134,55,230,65,96,123,96,124,132,216,174,114,199,0,231,7,198,184,15,37,116,206,185,48,243,
163,118,231,161,182,7,238,53,136,147,123,158,0,84,238,42,224,160,8,113,255,11,236,128,223,252,179,228,34,224,200,192,24,87,162,102,64,206,185,112,191,18,94,15,224,60,224,120,131,177,228,158,39,0,149,217,
150,56,153,227,211,192,166,248,180,127,214,220,142,166,29,67,156,4,156,109,48,22,231,156,122,160,132,54,245,121,18,216,208,96,44,185,231,9,64,203,245,4,62,66,103,186,45,189,137,170,83,121,83,159,236,121,
10,88,47,48,198,62,232,168,168,115,46,220,177,232,9,62,196,64,96,14,131,177,228,158,39,0,45,83,131,138,253,88,151,145,252,20,88,13,63,231,159,85,239,1,75,7,198,216,20,120,212,96,44,206,57,37,228,79,25,
196,153,5,24,108,16,39,215,60,1,104,153,127,1,151,26,199,236,15,172,2,12,48,142,235,236,12,37,252,164,135,119,32,115,206,206,172,104,31,64,168,117,128,103,13,226,228,154,39,0,205,155,31,77,253,119,48,
140,57,2,88,9,111,16,147,101,51,162,34,62,161,230,198,166,130,153,115,78,6,16,126,150,255,112,226,21,113,203,13,79,0,154,22,99,234,127,18,234,234,247,136,97,76,103,111,25,84,235,33,196,4,148,56,78,8,31,
142,115,174,206,227,132,111,226,187,134,56,167,185,114,197,19,128,166,89,53,160,104,232,88,224,2,227,152,206,222,86,192,3,129,49,190,39,188,149,176,115,110,114,231,2,199,5,198,120,6,88,215,96,44,185,230,
9,192,180,205,4,124,137,109,181,191,219,129,221,12,227,185,120,142,38,60,81,123,30,88,203,96,44,206,185,191,237,14,252,59,48,134,39,231,120,2,208,148,107,128,3,12,227,125,2,44,143,122,82,187,236,187,22,
216,63,48,198,205,192,222,6,99,113,206,253,109,101,194,91,250,78,66,237,190,199,134,15,39,191,60,1,104,220,34,192,135,216,53,250,249,11,149,14,254,220,40,158,139,239,105,194,167,8,79,6,206,50,24,139,115,
238,111,179,0,131,12,226,44,140,154,117,149,150,39,0,141,123,6,219,141,127,187,97,211,196,194,37,231,107,116,2,36,196,46,192,157,6,99,113,206,77,238,119,116,82,39,196,6,216,212,20,200,45,79,0,166,182,
54,74,0,172,220,134,214,172,92,126,180,70,75,53,109,3,227,172,74,248,84,165,115,110,106,253,8,111,200,182,55,90,166,43,45,79,0,166,246,6,176,130,81,172,31,129,197,128,145,70,241,92,50,230,5,190,51,136,
211,19,47,244,228,92,12,15,160,147,58,33,78,1,206,52,24,75,110,121,2,48,185,77,129,190,134,241,74,63,197,148,83,125,128,231,2,99,140,69,155,140,38,133,15,199,57,55,133,203,9,239,178,121,29,182,27,189,
115,199,19,128,201,89,76,43,213,243,35,127,249,181,15,112,67,96,140,47,129,133,12,198,226,156,155,154,197,49,221,71,209,67,95,105,121,2,240,183,53,209,185,109,11,131,208,73,2,111,242,147,79,22,79,23,15,
163,138,143,206,57,123,59,2,119,5,198,120,23,88,206,96,44,185,229,9,192,223,158,64,83,246,22,124,215,127,190,61,143,18,194,16,231,0,39,26,140,197,57,55,181,213,129,23,3,99,252,0,204,19,60,146,28,243,4,
64,22,70,141,121,106,12,98,189,135,150,17,124,237,55,191,6,163,74,144,33,118,38,252,9,197,57,215,184,133,129,207,2,99,12,39,252,40,97,174,121,2,32,22,83,190,245,214,38,124,3,153,75,79,15,108,118,238,47,
3,188,111,16,199,57,55,181,217,129,129,129,49,106,209,81,223,137,225,195,201,39,79,0,212,173,109,0,208,213,32,86,95,96,115,131,56,46,61,235,17,126,114,99,18,208,25,85,128,116,206,217,155,14,155,178,234,
221,176,105,251,157,75,158,0,216,52,150,0,101,147,75,160,154,255,46,191,142,2,46,12,140,225,141,70,156,139,111,52,74,4,66,244,66,63,175,165,228,9,0,252,15,88,199,32,206,99,192,38,6,113,92,186,110,37,252,
248,230,227,192,198,225,67,113,206,53,225,23,96,182,192,24,165,94,170,43,123,2,48,43,154,254,111,109,16,203,203,190,22,195,123,192,210,129,49,46,66,231,148,157,115,241,124,1,44,24,24,99,101,224,117,131,
177,228,82,217,19,128,131,129,43,13,226,188,6,172,98,16,199,165,171,13,42,219,28,58,173,184,39,54,203,74,206,185,105,251,8,88,60,48,198,26,192,75,225,67,201,167,178,39,0,86,211,255,219,2,247,27,196,113,
233,178,56,90,4,42,46,242,174,65,28,231,220,180,189,3,44,27,24,99,93,108,155,191,229,74,153,19,128,206,232,188,119,187,192,56,195,208,209,177,177,193,35,114,105,219,14,184,39,48,198,56,244,189,229,223,
15,206,197,101,209,184,109,35,84,4,174,148,202,156,0,108,9,252,215,32,206,85,192,33,6,113,92,250,206,3,142,13,140,241,62,218,88,228,156,139,235,37,96,181,192,24,155,99,219,0,46,87,202,156,0,92,137,246,
0,132,90,22,109,28,171,86,107,84,212,162,59,154,145,248,5,29,41,116,201,179,120,67,185,25,245,25,119,206,197,245,12,42,188,22,162,212,203,183,101,78,0,62,68,231,246,67,124,69,245,187,80,123,163,153,131,
13,209,205,191,222,80,148,145,94,4,124,30,52,58,87,137,54,168,52,104,199,192,56,7,1,215,132,15,199,57,215,140,23,81,79,128,16,155,1,143,132,15,37,159,202,154,0,116,5,134,0,173,2,227,92,1,28,86,225,223,
89,19,56,158,230,55,31,78,64,5,105,78,194,251,10,36,97,25,108,54,238,173,8,188,105,16,199,57,215,52,139,246,237,107,97,215,5,54,119,202,154,0,172,141,205,206,207,13,129,39,43,248,216,147,169,124,211,202,
189,192,14,248,178,64,108,7,161,253,28,33,38,0,93,128,81,225,195,113,206,53,227,19,96,209,192,24,203,3,111,27,140,37,151,202,154,0,28,13,92,16,24,99,52,154,186,111,174,30,245,124,168,217,208,70,1,215,
58,1,56,55,224,239,187,230,221,129,58,248,133,248,132,240,115,201,206,185,150,249,14,152,55,48,198,34,148,120,169,181,172,9,192,221,232,169,58,196,139,52,221,51,190,3,112,28,112,12,225,133,101,70,161,
68,226,215,192,56,110,218,190,65,159,227,16,183,19,94,70,216,57,215,50,191,162,106,174,33,230,2,126,50,24,75,46,149,53,1,120,151,240,163,90,151,0,71,78,227,255,245,1,110,34,60,59,109,232,84,224,12,195,
120,238,111,179,0,131,12,226,28,134,246,133,56,231,226,27,1,204,16,24,163,43,240,135,193,88,114,169,172,9,192,31,104,173,54,196,46,192,157,83,252,183,54,192,41,192,137,132,111,48,156,210,91,132,23,189,
112,141,219,4,155,157,192,189,81,117,50,231,92,124,19,8,239,227,210,182,46,78,41,149,49,1,152,9,157,183,15,181,24,240,105,131,63,247,68,75,11,171,26,196,110,204,239,168,119,181,179,119,14,58,153,17,226,
47,96,70,74,252,102,226,92,130,218,3,99,2,99,140,65,75,181,165,85,198,4,96,33,194,55,125,76,66,235,250,227,235,254,188,62,154,13,232,62,205,191,17,110,2,202,86,157,189,231,105,122,63,71,75,99,172,101,
48,22,231,92,243,186,162,50,236,33,6,163,229,191,210,42,99,2,176,34,225,237,31,7,241,119,31,234,61,129,235,209,244,127,76,3,208,44,131,179,213,22,205,174,76,31,24,231,76,180,252,227,156,139,111,46,224,
135,192,24,223,3,189,12,198,146,91,101,76,0,54,4,30,15,140,241,33,176,20,42,210,115,6,80,19,58,168,22,120,20,216,52,129,235,148,205,42,192,43,6,113,254,175,189,251,14,179,171,170,250,56,254,77,8,144,16,
164,19,1,67,81,122,239,189,131,64,144,142,116,94,165,137,32,130,190,244,42,4,233,189,26,122,21,1,41,74,151,242,74,135,208,133,208,36,72,135,8,8,132,4,18,72,127,255,248,205,200,16,38,51,247,222,189,78,
185,247,252,62,207,147,71,36,51,235,236,144,153,57,235,236,179,246,90,3,128,123,2,226,152,89,247,150,6,158,79,140,241,34,233,221,96,155,90,21,19,128,157,249,110,241,94,189,238,67,199,198,126,149,190,156,
154,237,10,92,149,227,245,170,98,32,58,97,145,98,34,170,207,24,145,188,26,51,171,197,58,192,3,137,49,30,67,15,0,149,85,197,4,96,95,52,8,40,197,120,178,223,242,239,232,95,168,227,213,216,28,175,89,21,143,
144,254,67,96,8,122,34,49,179,124,108,5,252,37,49,198,173,104,26,96,101,85,49,1,56,140,230,234,170,55,14,205,13,120,168,232,133,180,160,233,81,33,81,106,113,229,5,192,62,233,203,49,179,26,237,129,122,
173,164,168,252,228,206,42,38,0,7,0,103,20,189,136,26,141,69,69,134,127,42,122,33,45,42,162,30,4,212,66,216,127,71,102,249,57,8,13,75,75,113,42,112,104,192,90,154,86,21,19,128,136,161,47,121,120,1,213,
24,12,46,122,33,45,236,12,148,16,166,250,1,48,44,32,142,153,213,230,4,52,35,37,197,33,164,39,17,77,173,138,9,192,47,128,75,138,94,68,23,94,70,71,202,110,196,99,128,179,246,60,233,239,238,95,33,125,34,
153,153,213,103,16,233,69,216,187,3,87,4,172,165,105,85,49,1,248,25,26,218,82,54,47,161,27,255,77,248,198,159,135,126,104,152,72,234,17,206,243,129,253,210,151,99,102,117,184,14,216,33,49,198,230,232,
120,117,101,85,49,1,216,22,184,161,232,69,116,48,18,245,19,24,4,76,40,120,45,85,178,61,112,125,64,156,45,81,53,177,153,229,231,94,84,28,157,98,117,210,155,194,53,181,42,38,0,107,81,158,138,250,27,128,
253,241,251,227,34,92,66,122,5,240,4,52,91,162,178,211,196,204,10,50,4,88,50,49,198,194,192,208,128,181,52,173,42,38,0,243,2,111,23,188,134,47,209,251,171,212,134,68,214,184,183,209,215,66,10,79,104,52,
43,198,199,192,236,137,49,102,37,125,158,64,83,171,98,2,208,11,248,138,124,27,249,116,244,42,176,29,122,231,111,197,88,22,120,46,32,206,137,104,244,179,153,229,103,26,52,201,47,165,126,103,66,91,156,74,
215,91,85,49,1,128,152,167,191,70,220,10,236,136,18,16,43,206,209,192,177,1,113,214,71,83,0,205,44,63,253,129,247,18,99,84,126,18,32,84,55,1,120,8,213,2,228,233,18,180,237,239,66,191,226,61,3,44,159,24,
227,43,212,255,63,117,38,185,153,213,103,69,224,169,196,24,237,3,221,42,173,170,9,192,133,192,94,57,94,207,91,197,229,209,31,120,151,244,227,127,119,2,155,166,47,199,204,234,180,25,112,91,98,140,187,128,
77,2,214,210,212,170,154,0,68,244,145,174,149,207,137,151,75,84,39,200,189,129,139,2,226,152,89,125,246,66,15,113,41,46,66,223,195,149,86,213,4,96,73,116,140,36,107,215,0,187,80,241,66,147,146,185,7,216,
48,49,198,36,96,30,224,253,244,229,152,89,157,142,65,99,188,83,28,141,26,175,85,90,85,19,128,169,208,217,237,233,51,188,198,61,104,139,120,124,134,215,176,250,204,128,138,127,166,73,140,243,60,58,73,96,
102,249,187,128,244,167,247,95,160,105,128,149,86,213,4,0,224,65,96,237,140,98,191,7,44,7,124,146,81,124,107,76,84,247,191,223,163,167,16,51,203,223,93,192,198,137,49,54,66,221,4,43,173,202,9,192,177,
104,27,40,218,24,116,194,32,181,74,213,226,93,3,236,28,16,103,101,252,247,107,86,148,87,128,69,19,99,44,137,123,177,84,58,1,136,56,74,210,153,3,128,179,50,136,107,105,166,6,62,2,102,78,140,243,17,48,23,
174,235,48,43,66,15,212,73,117,186,196,56,51,227,22,222,149,78,0,122,160,34,174,185,2,99,62,13,172,138,207,250,151,209,166,196,76,254,186,140,244,25,2,102,214,152,126,40,9,79,49,138,108,235,191,154,70,
149,19,0,208,15,243,221,131,98,141,67,187,10,47,4,197,179,88,127,2,118,10,136,227,233,127,102,197,89,9,205,224,72,49,20,13,2,170,188,170,39,0,219,0,55,6,197,58,29,56,56,40,150,197,234,139,158,26,250,38,
198,249,2,61,129,184,251,159,89,49,34,198,185,223,143,218,120,87,94,213,19,128,223,0,231,4,196,25,9,252,8,248,52,32,150,197,219,9,237,0,164,186,142,152,93,4,51,107,204,193,192,169,137,49,174,4,118,75,
95,74,243,171,122,2,240,55,96,64,64,28,31,11,43,183,59,136,105,251,185,21,112,75,64,28,51,107,204,31,128,125,18,99,252,14,56,62,96,45,77,175,202,9,64,31,244,196,222,39,49,206,112,244,244,95,249,138,210,
146,154,13,24,134,78,1,164,248,2,248,62,158,228,104,86,164,136,100,126,39,180,155,87,121,85,78,0,6,160,29,128,84,39,0,71,5,196,177,108,252,10,24,20,16,199,219,255,102,197,27,10,44,152,24,195,125,60,218,
84,57,1,56,7,213,0,164,90,4,120,45,32,142,101,227,17,96,141,128,56,91,3,127,13,136,99,102,141,153,6,29,225,235,149,24,103,86,224,179,244,229,52,191,42,39,0,47,3,139,37,198,120,13,37,0,86,78,243,0,111,
147,62,250,247,75,84,253,239,237,127,179,226,44,138,186,0,166,248,156,244,102,96,45,163,170,9,64,95,96,4,26,10,148,226,20,224,176,244,229,88,70,14,7,78,12,136,115,61,176,99,64,28,51,107,220,150,164,239,
194,61,11,172,16,176,150,150,80,213,4,96,53,224,177,128,56,171,2,79,4,196,177,120,61,208,251,194,5,2,98,109,10,220,25,16,199,204,26,23,145,208,223,128,134,130,25,213,77,0,246,65,199,73,82,12,71,21,230,
238,9,95,78,27,162,145,204,169,62,2,250,227,177,206,102,69,187,2,216,53,49,198,73,192,17,233,75,105,13,85,77,0,46,5,246,72,140,113,15,49,61,4,44,27,55,163,194,189,84,103,2,7,6,196,49,179,52,131,129,85,
18,99,236,1,92,30,176,150,150,80,213,4,224,89,96,185,196,24,110,254,83,94,115,0,239,146,126,246,31,96,25,60,223,193,172,12,62,5,102,73,140,177,14,240,80,250,82,90,67,85,19,128,47,73,239,11,191,57,49,211,
229,44,222,145,196,116,250,122,1,37,0,102,86,172,136,41,128,0,115,163,41,176,70,53,19,128,153,208,251,251,84,115,16,243,5,105,177,122,2,111,0,243,5,196,58,16,189,2,48,179,98,173,139,134,248,164,24,137,
126,254,87,238,166,55,37,85,76,0,150,0,94,76,140,49,18,152,49,96,45,22,239,39,196,84,236,143,71,79,11,31,6,196,50,179,52,251,147,158,140,15,70,39,192,172,77,21,19,128,136,234,240,23,129,165,2,214,98,241,
110,1,182,8,136,115,39,58,254,103,102,197,139,56,1,112,41,176,103,250,82,90,71,21,19,128,221,72,175,2,189,3,216,44,96,45,22,107,110,224,77,210,91,133,130,154,142,220,26,16,199,204,210,69,20,110,239,15,
156,29,176,150,150,81,197,4,224,40,224,184,196,24,131,128,95,7,172,197,98,157,6,28,20,16,231,125,224,135,248,236,191,89,25,244,66,133,219,211,38,198,217,8,184,55,125,57,173,163,138,9,192,41,192,33,137,
49,60,79,186,124,102,68,71,255,102,8,136,117,12,58,230,105,102,197,91,28,120,41,32,78,127,224,131,128,56,45,163,138,9,192,153,104,43,40,197,65,192,25,1,107,177,56,135,2,39,7,196,25,143,78,16,248,7,133,
89,57,236,12,92,147,24,195,67,128,58,81,197,4,224,60,96,223,196,24,251,1,231,7,172,197,98,76,141,222,253,247,15,136,117,51,176,77,64,28,51,139,113,42,112,112,98,140,71,129,53,3,214,210,82,170,152,0,92,
8,236,149,24,227,151,192,37,1,107,177,24,187,3,151,5,197,218,16,184,47,40,150,153,165,187,27,189,191,79,113,17,176,119,192,90,90,74,21,19,128,136,57,0,187,2,87,165,47,197,2,244,64,199,50,23,15,136,245,
47,96,33,220,40,196,172,76,62,66,157,0,83,252,22,56,55,96,45,45,165,138,9,64,196,121,82,239,0,148,199,38,232,88,102,132,3,128,179,130,98,153,89,186,249,128,183,2,226,252,24,248,123,64,156,150,82,197,4,
32,162,6,224,96,224,244,128,181,88,186,7,129,181,3,226,140,0,230,65,93,30,205,172,28,182,7,174,15,136,51,27,26,38,100,29,84,49,1,56,14,245,2,72,113,60,58,10,104,197,90,19,120,56,40,214,169,232,36,129,
153,149,71,196,169,173,183,81,95,15,155,76,21,19,128,3,73,127,122,63,31,157,4,176,98,61,70,76,111,239,113,192,252,192,123,1,177,204,44,206,163,192,234,137,49,124,178,103,10,170,152,0,68,84,140,95,7,236,
20,176,22,107,220,102,192,109,65,177,254,8,252,60,40,150,153,197,232,133,94,205,77,151,24,231,72,224,196,244,229,180,158,42,38,0,91,163,140,48,197,83,192,202,1,107,177,198,244,68,189,193,151,9,138,183,
44,240,124,80,44,51,139,177,28,250,62,79,53,128,244,1,112,45,169,138,9,192,90,192,67,137,49,60,14,184,88,59,1,127,10,138,245,127,192,6,65,177,204,44,206,94,168,111,75,170,126,192,127,2,226,180,156,42,
38,0,115,2,195,2,226,204,5,252,59,32,142,213,103,106,224,21,96,129,160,120,110,252,99,22,163,55,26,197,189,46,122,122,159,29,61,40,125,142,58,117,62,5,220,14,60,65,109,189,54,46,71,211,91,83,188,135,78,
247,88,39,170,152,0,128,222,43,165,14,141,89,15,120,32,96,45,86,159,189,129,11,130,98,61,78,122,129,145,89,213,77,15,28,14,236,3,204,84,195,199,191,136,78,99,221,68,215,137,192,171,192,34,137,107,187,
5,216,42,49,70,203,170,106,2,240,52,176,66,98,12,15,4,202,223,247,128,127,162,221,151,8,30,15,106,150,102,93,244,58,110,206,6,62,247,14,212,149,245,227,78,126,175,31,240,33,234,244,153,226,104,210,199,
191,183,172,170,38,0,215,160,9,83,41,110,7,54,15,88,139,213,238,12,212,173,47,194,96,98,142,16,154,85,213,158,192,32,84,173,223,168,119,208,110,234,155,147,253,251,159,162,29,130,84,155,0,119,5,196,105,
73,85,77,0,142,6,142,77,140,241,57,48,43,48,49,125,57,86,131,37,129,231,72,251,97,211,145,43,131,205,26,183,3,122,242,239,25,16,235,125,116,170,170,99,109,214,217,168,127,127,170,57,208,44,1,235,68,85,
19,128,45,208,187,161,84,203,1,255,8,136,99,93,235,1,60,66,220,251,250,39,128,85,131,98,153,85,205,34,232,231,94,239,192,152,15,160,211,56,19,218,254,255,115,232,120,110,138,119,129,121,19,99,180,180,
170,38,0,179,162,99,33,169,239,151,92,7,144,143,221,80,69,112,148,141,209,136,81,51,171,79,15,116,140,122,205,12,98,239,5,92,140,78,14,124,10,76,149,24,207,13,219,186,81,213,4,0,224,101,96,177,196,24,
110,8,148,189,89,80,225,223,236,65,241,30,68,133,75,102,86,191,13,200,174,112,118,24,58,222,187,30,49,19,62,247,5,254,16,16,167,101,85,57,1,184,16,101,156,41,38,1,11,2,111,164,47,199,166,224,98,84,108,
20,97,34,176,18,49,221,197,204,170,232,86,178,45,126,222,21,88,148,152,193,92,126,69,219,141,42,39,0,59,163,211,0,169,142,2,78,8,136,99,223,181,39,74,0,162,92,13,236,18,24,207,172,74,166,1,134,147,222,
155,191,43,131,219,254,55,181,70,231,11,96,102,190,169,41,176,78,84,57,1,152,7,29,65,73,245,50,176,68,64,28,251,182,205,129,191,144,254,30,176,221,87,192,194,120,226,159,89,163,214,64,197,184,89,155,64,
250,247,189,91,124,215,160,202,9,0,104,123,40,98,160,204,194,192,208,128,56,38,43,1,247,3,125,3,99,158,128,118,107,204,172,49,251,3,103,22,189,136,26,13,36,253,168,119,203,171,122,2,112,4,49,219,247,7,
3,167,7,196,49,88,30,245,230,159,57,48,230,199,168,86,99,100,96,76,179,170,185,12,141,83,111,6,158,241,81,131,170,39,0,11,1,175,5,196,241,185,242,24,43,160,10,227,200,155,63,232,189,255,213,193,49,205,
170,38,162,133,122,30,38,160,211,67,78,248,187,81,245,4,0,224,5,96,169,128,56,203,180,197,178,198,44,135,50,246,89,130,227,62,132,142,253,85,254,11,221,44,193,84,168,176,174,79,209,11,169,193,243,164,
55,17,170,4,39,0,122,47,28,49,44,226,124,96,191,128,56,85,180,62,112,51,106,0,18,105,12,176,52,49,187,60,102,85,182,8,154,206,215,12,6,1,191,46,122,17,205,192,9,64,220,23,246,104,224,135,116,62,217,202,
166,236,103,192,165,232,136,81,180,129,184,16,200,44,194,78,168,247,127,51,216,17,184,190,232,69,52,3,39,0,242,34,49,71,249,78,37,166,129,69,85,28,137,118,95,82,91,50,119,230,53,244,244,63,38,131,216,
102,85,115,46,205,177,195,57,9,141,38,246,0,160,26,56,1,144,129,192,49,1,113,190,70,237,133,223,10,136,213,202,166,7,46,65,19,197,178,48,30,189,247,127,52,163,248,102,85,243,36,58,158,91,118,47,161,201,
161,86,3,39,0,178,4,218,5,136,240,87,96,235,160,88,173,104,33,212,224,103,241,12,175,113,24,112,74,134,241,205,170,164,55,48,130,108,94,211,69,59,151,152,49,194,149,224,4,224,27,79,16,55,216,103,7,224,
207,65,177,90,201,118,232,201,127,134,12,175,113,7,234,34,232,47,108,179,24,171,1,143,21,189,136,26,109,1,220,86,244,34,154,133,19,128,111,252,28,184,42,40,214,167,232,253,243,7,65,241,154,221,204,232,
148,68,214,163,57,95,69,253,24,70,100,124,29,179,42,57,8,56,173,232,69,212,96,2,26,245,238,239,255,26,57,1,248,70,111,212,39,126,182,160,120,79,2,107,227,34,180,13,81,7,177,254,25,95,231,83,96,21,224,
95,25,95,199,172,106,238,2,54,46,122,17,53,240,120,246,58,57,1,248,182,99,129,163,3,227,93,5,236,70,53,183,163,231,64,237,145,119,34,155,42,255,142,70,3,27,225,162,63,179,104,83,3,159,161,194,221,178,
59,9,181,119,183,26,57,1,248,182,25,81,5,127,100,43,218,243,128,223,4,198,43,187,158,192,255,160,161,33,179,230,112,189,177,192,150,192,223,114,184,150,89,213,228,53,1,48,194,6,104,10,160,213,200,9,192,
119,13,36,230,72,96,71,39,162,51,239,173,110,115,52,92,41,175,241,200,99,129,159,162,194,63,51,139,119,52,205,209,76,107,12,122,112,251,170,232,133,52,19,39,0,223,53,19,106,34,211,47,56,238,133,192,190,
168,80,165,213,172,131,146,156,60,7,34,141,71,29,191,110,202,241,154,102,85,243,48,176,102,209,139,168,193,3,192,122,69,47,162,217,56,1,232,220,174,192,21,25,196,189,15,221,180,62,205,32,118,222,122,0,
155,160,81,200,107,229,124,237,9,232,239,232,154,156,175,107,86,37,179,160,142,122,189,18,227,140,2,250,166,47,167,75,71,160,26,0,171,131,19,128,206,245,64,5,101,171,101,16,251,29,116,228,240,225,12,98,
231,161,55,74,98,14,36,219,102,62,83,242,21,42,44,188,165,128,107,155,85,73,84,255,255,67,208,14,97,106,34,209,149,133,129,161,25,198,111,73,78,0,166,108,41,116,172,100,218,12,98,79,4,206,65,181,6,95,
100,16,63,11,203,1,187,163,31,10,145,69,146,245,248,12,213,25,52,75,83,18,179,102,118,29,233,237,186,39,1,63,0,206,64,15,14,89,120,18,29,1,182,58,57,1,232,218,193,104,192,79,86,62,68,197,129,87,163,119,
218,101,179,16,106,107,188,61,176,76,193,107,121,21,117,249,122,189,224,117,152,85,193,212,104,178,233,76,137,113,94,68,15,83,203,1,207,144,205,145,224,1,192,61,25,196,109,121,78,0,186,214,19,29,43,89,
55,227,235,188,1,156,140,182,219,138,172,98,157,26,13,252,216,16,221,248,243,170,230,239,206,157,104,231,97,100,209,11,49,171,136,117,129,251,3,226,156,137,94,23,2,252,1,216,39,32,102,71,183,162,99,192,
214,0,39,0,221,235,143,50,215,239,231,112,173,225,40,9,184,22,109,107,77,204,248,122,223,67,79,246,171,160,111,248,53,41,87,195,143,49,192,225,192,217,84,179,153,146,89,81,46,0,246,14,136,179,49,112,119,
219,63,247,69,51,87,162,30,44,222,6,150,71,175,6,173,1,78,0,106,179,26,202,134,179,168,7,152,146,15,209,55,206,163,232,155,102,40,48,174,193,88,179,1,243,3,63,106,251,181,24,218,146,91,8,237,114,148,209,
75,192,206,192,144,162,23,98,86,49,189,128,97,192,236,137,113,190,66,63,123,70,119,248,119,115,162,198,66,243,39,198,126,23,29,251,123,35,49,78,165,57,1,168,221,30,192,165,5,94,127,28,234,82,56,12,61,
25,143,68,223,88,237,179,6,122,161,39,122,208,123,187,217,209,55,223,172,64,159,92,87,154,102,18,234,158,120,40,240,117,193,107,49,171,162,1,196,116,214,156,210,246,124,63,84,96,216,232,185,253,199,81,
65,225,187,13,126,190,181,113,2,80,159,99,80,167,64,203,206,94,192,197,69,47,194,172,194,174,64,125,54,82,237,206,148,251,169,76,133,94,49,28,77,237,77,215,254,3,156,130,94,9,182,98,67,181,220,57,1,168,
223,25,192,1,69,47,162,133,237,74,220,88,102,51,171,79,111,244,250,113,198,196,56,19,208,64,176,79,186,249,184,233,129,109,208,19,253,202,157,92,247,75,212,51,229,22,84,27,53,42,113,93,214,129,19,128,
250,245,64,179,237,163,171,89,77,170,50,55,193,172,140,118,64,219,243,169,30,66,45,194,235,213,159,111,10,174,255,141,94,121,90,70,156,0,52,238,80,116,116,207,98,221,128,250,14,152,89,254,238,3,126,28,
16,103,127,180,85,111,37,230,4,32,205,126,232,139,188,172,149,244,205,232,121,96,217,162,23,97,86,65,243,161,170,250,212,159,103,19,219,98,189,151,24,199,50,230,4,32,221,79,208,80,154,162,218,227,182,
154,81,148,171,23,129,89,85,12,36,102,20,122,163,219,255,150,51,39,0,49,230,7,254,130,90,94,90,186,153,129,207,139,94,132,89,133,76,133,158,254,231,13,136,229,147,60,77,194,9,64,156,62,168,38,96,95,252,
74,32,213,162,192,63,139,94,132,89,133,108,65,204,132,205,177,168,217,143,187,243,53,1,39,0,241,86,7,174,4,22,40,120,29,205,108,29,180,141,104,102,249,120,128,152,109,251,91,128,173,2,226,88,14,156,0,
100,163,47,112,4,234,23,208,187,224,181,228,229,21,96,16,146,2,102,15,0,0,16,199,73,68,65,84,26,215,187,97,98,172,29,128,63,39,175,200,204,106,177,36,113,45,183,183,5,110,10,138,101,25,115,2,144,173,31,
2,167,161,201,122,89,140,193,44,218,24,224,54,52,56,228,65,212,198,247,42,224,231,137,113,127,11,156,155,24,195,204,106,115,9,240,139,128,56,31,3,115,163,215,0,214,4,156,0,228,99,25,212,220,102,107,154,
191,62,96,18,26,80,244,39,116,102,127,248,100,191,127,62,240,235,196,107,28,3,252,62,49,134,153,117,111,54,212,83,63,98,94,200,105,192,33,1,113,44,39,78,0,242,181,40,234,29,176,51,48,67,193,107,169,199,
120,52,193,235,14,116,218,225,237,46,62,246,100,212,36,41,197,41,192,97,137,49,204,172,123,191,7,126,23,16,103,18,176,48,240,122,64,44,203,137,19,128,98,244,5,182,67,125,239,87,71,71,112,202,230,61,180,
173,127,55,154,12,54,249,147,254,148,28,5,28,151,120,237,243,128,223,36,198,48,179,174,205,128,146,249,136,30,38,247,3,235,7,196,177,28,57,1,40,222,236,168,112,110,115,96,109,210,135,112,52,98,60,58,118,
247,44,122,210,127,144,198,231,108,31,142,250,249,167,184,140,152,119,146,102,54,101,135,160,221,182,8,46,220,109,66,78,0,202,165,39,176,4,176,6,176,34,122,101,176,8,113,73,193,120,224,29,180,77,55,20,
221,244,255,1,188,0,124,21,116,141,136,25,9,215,1,59,5,172,197,204,58,215,27,120,11,77,236,75,53,12,21,60,187,248,175,201,56,1,104,14,115,160,222,218,223,7,230,106,251,255,179,2,83,3,211,1,211,182,125,
220,215,232,70,62,28,24,141,230,103,15,67,213,185,195,218,126,141,203,120,173,17,79,21,55,161,227,68,102,150,141,125,209,171,182,8,71,146,190,235,103,5,112,2,96,209,34,18,128,235,209,124,112,51,139,215,
7,237,2,254,32,32,214,104,96,30,224,211,128,88,150,51,39,0,22,237,48,224,164,196,24,215,162,147,18,102,205,104,110,96,121,180,45,62,13,154,142,247,14,240,18,106,152,85,180,136,58,157,118,131,72,63,246,
107,5,113,2,96,209,142,67,39,1,82,92,13,236,18,176,22,179,188,76,7,236,134,138,87,151,233,226,227,222,66,53,46,231,160,87,115,121,155,25,21,248,70,84,254,79,68,117,74,67,3,98,89,1,156,0,88,180,179,128,
255,77,140,113,5,176,123,192,90,204,242,176,53,106,128,53,103,29,159,51,26,157,193,63,29,152,144,197,162,166,224,4,212,166,60,130,251,254,55,57,39,0,22,237,98,96,207,196,24,23,1,123,7,172,197,44,75,83,
161,39,249,148,45,240,135,128,45,201,103,252,117,127,224,53,180,91,17,97,69,224,153,160,88,86,0,39,0,22,237,90,210,11,248,220,9,208,202,174,7,250,90,223,33,32,214,16,212,3,36,235,36,224,26,226,106,107,
238,2,54,9,138,101,5,113,2,96,209,238,5,54,72,140,113,24,113,13,74,204,178,112,60,58,254,22,229,30,116,67,205,234,117,192,170,192,99,196,13,37,91,5,120,50,40,150,21,196,9,128,69,27,130,198,139,166,248,
37,154,80,102,86,70,63,5,110,36,126,194,231,126,168,150,32,90,15,224,9,96,165,160,120,247,0,3,130,98,89,129,156,0,88,180,15,81,195,162,20,219,161,31,176,102,101,179,60,106,151,29,49,61,111,114,159,3,63,
162,246,185,27,181,218,5,184,50,48,222,26,104,55,193,154,156,19,0,139,52,21,48,134,244,225,70,63,6,254,158,190,28,179,80,115,0,79,163,98,186,172,28,8,156,25,24,111,22,224,85,160,95,80,188,59,128,205,130,
98,89,193,156,0,88,164,185,128,15,2,226,44,130,170,149,205,202,98,90,224,1,244,46,61,75,47,208,117,31,129,122,93,10,236,17,20,107,2,90,219,75,65,241,172,96,78,0,44,210,218,104,146,96,138,73,104,92,114,
212,112,34,179,8,151,144,207,132,202,73,232,21,218,127,2,98,173,137,142,25,70,213,42,92,78,92,50,97,37,224,4,192,34,237,142,70,249,166,248,152,244,26,2,179,72,17,237,173,235,177,33,112,95,98,140,105,209,
164,207,69,211,151,3,40,33,95,24,120,47,40,158,149,128,19,0,139,20,209,101,236,105,226,170,149,27,209,11,248,94,219,63,143,3,190,44,112,45,86,188,61,81,99,170,232,138,255,238,174,121,105,98,140,99,129,
163,3,214,210,238,84,52,234,219,90,136,19,0,139,116,3,233,99,124,111,6,182,9,88,75,173,122,2,171,161,194,166,85,81,149,119,199,78,105,111,1,207,1,183,163,41,133,99,114,92,155,21,107,91,212,183,63,181,
168,181,94,39,144,54,79,99,5,96,48,74,102,35,124,132,158,254,71,4,197,179,146,112,2,96,145,94,33,125,203,241,120,224,119,1,107,233,74,251,77,127,91,116,166,187,214,177,168,255,1,206,69,77,138,198,101,
179,180,166,213,23,189,186,25,143,142,130,142,45,118,57,201,54,2,110,67,211,252,242,118,13,240,179,6,63,183,55,240,44,176,88,220,114,216,29,205,231,176,22,227,4,192,162,244,1,190,32,253,105,105,7,224,
207,233,203,249,142,70,111,250,157,121,14,253,128,46,195,104,215,162,76,139,6,193,108,137,138,205,230,234,240,123,147,208,188,249,135,208,223,229,3,104,114,92,179,88,21,189,131,239,91,208,245,31,1,214,
106,240,115,79,71,71,9,163,60,137,190,111,154,233,239,207,106,228,4,192,162,172,8,60,21,16,103,9,224,229,128,56,16,123,211,159,220,72,96,125,170,55,12,101,42,84,13,63,16,157,139,175,197,203,104,6,253,
237,25,173,41,210,178,168,7,69,196,184,220,70,189,3,204,215,192,231,173,137,78,225,244,12,90,199,68,212,242,247,233,160,120,86,50,78,0,44,202,158,104,18,96,138,177,192,244,164,109,175,103,121,211,159,
220,167,232,232,99,84,194,82,118,115,161,237,233,117,27,252,252,171,209,148,199,178,30,241,92,13,184,19,152,169,224,117,124,1,204,80,231,231,204,130,170,254,231,9,92,199,101,228,115,244,209,10,226,4,192,
162,92,8,236,149,24,227,69,96,169,6,62,47,207,155,254,228,134,160,162,171,86,175,9,88,23,21,196,165,30,209,124,28,248,9,229,43,40,91,31,184,149,226,182,253,59,154,132,106,15,198,215,248,241,61,128,91,
128,205,3,215,240,49,176,56,240,73,96,76,43,25,39,0,22,229,69,180,125,159,226,10,84,112,84,139,34,111,250,147,59,20,29,147,106,69,61,208,159,239,120,226,170,225,255,14,108,76,121,146,166,205,208,9,150,
222,69,47,164,131,217,208,14,83,45,254,23,56,43,248,250,59,161,132,207,90,152,19,0,139,48,11,122,82,72,61,43,221,221,249,231,50,221,244,59,26,1,204,73,121,183,182,27,53,19,112,21,177,79,150,237,6,162,
179,234,69,219,1,189,154,152,186,232,133,76,102,126,224,205,26,62,110,5,52,152,39,242,180,194,237,100,243,119,110,37,227,4,192,34,108,134,142,76,165,90,156,239,86,214,119,188,233,111,195,183,171,205,203,
164,213,158,152,150,5,110,66,211,233,178,48,14,157,45,127,43,163,248,181,248,53,112,14,249,159,243,175,197,242,232,180,73,87,102,69,69,168,243,5,94,119,4,218,201,123,63,48,166,149,148,19,0,139,112,42,
112,112,98,140,207,208,182,231,36,154,231,166,223,81,43,77,73,251,5,112,30,217,111,137,95,76,122,221,72,35,122,161,45,243,125,11,184,118,173,214,4,30,237,226,247,167,2,238,70,147,51,35,253,10,213,243,
88,5,56,1,176,8,207,3,75,39,198,184,11,245,91,47,219,246,126,173,58,38,48,205,170,31,112,1,176,117,78,215,27,137,142,18,230,249,234,228,123,192,181,192,166,57,94,179,17,107,160,173,253,41,137,62,239,15,
234,125,176,17,205,253,53,108,117,112,2,96,169,230,66,219,133,169,239,255,39,18,119,126,185,40,181,190,183,45,163,29,128,243,209,182,114,158,54,70,79,178,121,88,0,189,223,94,36,195,107,60,142,18,193,133,
18,227,116,181,3,176,35,74,98,34,125,134,78,224,68,140,243,182,38,225,4,192,82,69,76,0,108,21,91,161,227,88,205,100,118,96,16,249,206,95,232,232,36,210,7,72,213,98,29,84,211,144,101,130,51,24,24,208,246,
191,169,173,120,167,180,3,176,2,234,176,56,93,39,191,151,98,59,224,198,224,152,86,114,78,0,44,213,141,20,119,243,40,155,253,129,179,139,94,68,29,54,69,239,225,231,44,112,13,143,162,167,221,172,244,0,126,
3,156,70,182,149,254,207,2,27,0,195,129,55,72,47,158,236,44,1,232,15,60,65,252,235,177,171,128,93,131,99,90,19,112,2,96,41,122,160,1,57,121,111,27,151,213,217,40,9,40,187,254,192,25,232,169,175,104,99,
80,219,221,44,234,0,230,0,254,72,124,161,220,228,158,2,54,228,155,230,70,239,147,126,147,94,29,189,78,104,55,19,74,150,22,79,140,59,185,183,129,101,40,95,99,38,203,129,19,0,75,177,32,48,180,232,69,148,
200,117,232,56,96,89,245,65,133,99,135,81,142,142,119,237,86,38,102,142,68,71,3,208,147,109,191,224,184,147,123,26,221,252,63,239,240,239,62,69,189,49,82,44,141,186,76,130,118,46,254,134,186,21,70,26,
139,134,14,61,25,28,215,154,132,19,0,75,241,99,84,57,108,114,11,170,3,40,163,109,208,54,248,124,5,175,163,51,63,67,51,6,34,76,13,156,136,18,157,212,194,212,238,60,139,190,7,58,222,252,123,160,27,107,175,
196,216,243,2,239,182,197,187,138,198,199,3,119,229,183,104,188,181,85,148,19,0,75,177,13,46,28,234,232,110,84,213,94,38,75,161,87,19,141,14,240,201,195,113,192,209,1,113,150,65,5,169,203,5,196,234,206,
83,104,151,97,248,100,255,126,6,98,182,211,103,68,199,36,207,65,53,12,209,110,66,71,110,173,194,156,0,88,138,77,80,3,156,102,54,9,109,227,190,79,250,249,247,187,208,127,147,50,248,1,112,20,106,175,92,
198,78,119,29,93,143,142,182,53,170,15,112,12,122,234,79,125,242,174,197,157,192,246,192,168,78,126,111,62,210,187,27,78,64,59,25,199,180,253,138,246,47,212,105,112,100,6,177,173,137,56,1,176,20,203,161,
109,208,102,211,126,211,191,17,61,9,189,141,142,162,157,144,24,247,70,138,47,172,235,143,134,247,236,9,76,91,240,90,106,53,24,117,126,108,196,58,232,36,195,130,97,171,233,218,165,168,91,222,148,38,245,
45,75,247,45,124,187,51,28,205,73,200,226,68,201,104,244,223,250,133,12,98,91,147,113,2,96,41,166,69,79,17,145,131,72,178,210,217,77,191,163,107,73,123,10,133,250,166,25,70,155,27,21,247,237,65,243,220,
248,219,189,74,253,231,230,103,66,53,13,123,144,253,187,126,208,215,207,64,224,247,221,124,220,134,192,61,137,215,26,143,118,109,162,255,92,147,80,195,167,27,130,227,90,147,114,2,96,169,238,69,231,159,
203,168,187,155,126,71,175,0,139,38,94,239,120,224,119,137,49,234,53,55,112,56,74,60,154,237,198,223,110,24,181,31,155,235,5,252,18,109,141,103,93,225,223,110,124,219,53,175,168,225,99,119,3,46,207,118,
57,13,139,170,181,176,22,225,4,192,82,237,2,92,89,244,34,58,168,231,166,223,110,62,98,166,210,237,65,126,63,252,87,70,211,236,182,167,216,29,152,123,209,83,111,138,81,192,244,53,124,220,230,192,41,100,
219,202,119,114,95,162,98,185,90,219,21,31,133,110,180,101,243,87,52,99,195,63,240,237,191,156,0,88,170,105,80,47,128,121,11,92,67,35,55,253,142,246,69,211,239,82,173,131,218,180,102,165,15,122,77,177,
15,42,226,42,210,151,168,58,253,62,224,189,196,88,237,19,32,167,100,121,52,252,102,157,196,235,212,235,3,96,11,234,171,115,185,0,216,59,155,229,52,108,8,106,44,244,101,209,11,177,114,113,2,96,17,138,56,
14,152,122,211,239,232,239,192,122,137,235,153,136,58,218,101,81,89,61,63,42,60,219,141,244,6,51,17,158,65,13,143,94,71,45,111,223,72,140,55,134,206,71,15,47,130,158,168,119,36,255,65,81,247,183,93,247,
227,58,63,239,54,202,53,22,250,3,84,244,247,110,209,11,177,242,113,2,96,81,174,68,175,3,178,246,52,42,98,74,189,233,183,91,28,120,145,244,130,171,151,129,37,210,151,243,95,51,0,91,162,27,237,6,148,99,
82,226,120,52,188,231,56,96,92,219,191,91,24,248,103,98,220,17,168,168,175,221,114,168,174,97,107,242,255,115,79,2,78,5,142,68,199,241,234,245,50,233,131,128,162,140,64,157,254,134,116,247,129,86,77,78,
0,44,202,52,168,39,64,22,5,129,237,79,250,55,18,115,211,239,232,98,116,100,46,34,206,94,137,49,166,67,79,143,219,163,134,66,157,61,21,23,229,37,52,48,102,242,237,240,21,73,111,227,251,17,234,219,191,22,
186,241,15,72,140,215,168,17,232,207,216,232,68,199,158,168,158,161,12,127,111,99,209,215,208,253,69,47,196,202,203,9,128,69,154,22,184,132,152,182,165,89,222,244,219,205,13,188,134,222,173,167,218,28,
205,154,175,215,180,232,134,183,125,91,140,50,245,232,7,61,245,159,138,142,191,141,233,228,247,183,37,253,88,217,72,244,148,186,70,98,156,20,67,208,171,172,215,19,98,204,3,188,19,179,156,36,147,128,157,
209,108,10,179,41,114,2,96,89,216,25,56,147,250,143,105,229,113,211,239,232,122,116,227,77,53,26,152,141,218,39,218,45,142,118,74,54,0,214,166,124,55,253,118,131,81,237,65,87,77,99,14,70,9,66,51,187,6,
237,222,140,78,140,179,30,170,39,41,218,1,192,89,69,47,194,202,207,9,128,101,165,47,170,9,216,21,85,113,119,246,46,119,2,42,40,187,153,252,110,250,237,214,6,30,12,138,213,93,43,219,126,104,104,76,251,
77,63,122,158,123,180,225,104,43,254,18,84,220,216,149,63,160,83,9,205,104,4,26,136,115,85,80,188,50,244,0,56,154,114,30,67,180,18,114,2,96,121,232,135,134,210,204,135,18,129,49,168,247,254,51,20,51,135,
188,103,219,181,151,13,138,183,62,223,188,107,237,131,134,210,172,208,246,107,121,84,20,150,71,183,186,84,19,129,171,81,71,193,143,106,252,156,71,40,118,235,190,81,247,161,190,13,169,71,24,59,58,20,56,
57,48,94,189,78,70,137,155,89,77,156,0,88,21,109,143,158,218,35,124,142,42,198,151,111,251,181,56,249,12,164,137,246,56,122,26,126,166,142,207,233,141,254,252,205,212,129,112,20,112,8,58,175,31,253,195,
239,72,212,13,178,8,231,162,191,63,179,154,57,1,176,42,186,159,114,143,199,205,211,187,232,169,241,58,234,191,33,174,9,60,28,190,162,236,60,138,94,73,165,246,45,152,146,189,81,98,145,183,139,219,174,237,
31,230,86,23,39,0,86,53,179,161,237,237,50,156,171,47,210,39,192,137,232,134,245,117,131,49,34,38,40,230,225,107,52,163,225,76,186,175,105,72,81,68,17,224,32,212,201,210,63,200,173,110,78,0,172,106,54,
165,177,227,122,173,226,11,116,35,60,163,237,159,83,60,67,241,45,137,187,115,31,106,89,156,218,172,168,22,211,163,2,202,188,94,1,157,129,78,97,248,135,184,53,196,9,128,85,205,254,232,6,88,53,95,160,105,
118,39,1,31,6,196,91,128,180,51,243,89,123,31,189,147,191,58,231,235,222,142,146,204,172,157,130,138,53,205,26,230,4,192,170,230,88,170,53,18,245,51,224,28,84,36,246,121,96,220,99,128,129,129,241,162,
140,70,55,199,211,168,189,47,67,164,159,0,119,102,124,141,35,80,34,103,150,196,9,128,85,77,145,149,218,121,122,19,221,244,47,39,125,171,127,114,61,80,7,197,5,131,227,166,186,17,56,136,226,7,223,60,64,
54,147,11,199,163,158,11,151,100,16,219,42,200,9,128,85,205,47,129,139,138,94,68,134,30,71,175,56,110,161,177,97,54,181,40,75,199,187,118,67,208,171,157,178,244,189,95,12,120,18,213,4,68,25,13,236,64,
181,235,87,44,152,19,0,171,154,149,208,15,231,86,50,10,29,227,187,144,250,102,215,55,170,44,51,239,95,70,51,10,110,34,219,234,254,70,108,141,118,36,34,78,155,124,130,134,68,61,17,16,203,236,191,156,0,
88,213,76,131,138,224,102,46,122,33,1,94,68,187,25,215,144,111,71,197,123,201,102,234,99,173,254,137,110,252,127,166,124,55,254,142,182,5,254,72,90,163,164,55,81,93,193,107,33,43,50,235,192,9,128,85,81,
212,8,224,34,124,136,158,246,255,8,252,163,160,53,60,71,92,27,229,122,12,69,125,238,175,35,187,215,27,209,86,70,117,24,139,53,240,185,55,160,33,69,145,197,155,102,255,229,4,192,170,104,97,180,125,60,85,
209,11,169,209,231,232,221,239,245,232,233,123,124,177,203,225,14,96,147,28,175,247,58,106,56,116,13,205,115,227,239,168,55,186,145,31,128,70,6,119,103,48,58,101,113,95,150,139,50,115,2,96,85,53,8,141,
186,45,171,207,128,219,208,251,237,251,128,177,197,46,231,91,206,64,55,179,44,77,66,201,206,121,192,223,40,247,86,127,173,122,161,246,201,3,128,37,128,31,162,215,3,35,81,146,243,44,42,222,244,118,191,
229,194,9,128,85,213,244,104,43,187,76,71,217,134,160,155,221,93,168,154,191,232,39,253,41,89,158,250,134,6,213,99,36,26,207,123,62,218,242,55,179,140,56,1,176,42,91,8,13,179,249,126,65,215,255,55,58,
186,246,0,122,218,141,28,77,155,181,135,209,211,108,148,215,208,77,255,42,226,251,22,152,89,39,156,0,88,213,45,6,220,138,90,219,102,237,117,116,148,107,48,186,233,231,209,159,62,43,11,0,207,3,125,19,98,
140,66,91,222,87,163,215,28,254,97,100,150,35,39,0,102,58,18,120,38,176,11,234,114,23,225,45,224,133,182,95,79,163,222,3,159,4,197,46,139,13,80,141,194,12,117,124,206,56,180,219,113,45,74,188,70,101,176,
46,51,171,129,19,0,179,111,172,136,58,202,109,77,109,103,183,199,161,27,253,208,182,95,175,163,211,5,67,200,247,92,126,145,150,70,13,136,86,233,226,99,38,1,143,161,155,254,141,180,94,34,100,214,148,156,
0,152,125,87,95,96,109,96,73,96,110,96,106,84,133,255,126,219,175,119,208,251,250,97,40,9,48,53,171,217,2,88,21,253,247,155,132,146,161,7,128,191,162,255,102,102,86,34,255,15,113,165,79,135,26,115,35,
172,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* PluginEditor::crestBianco_png = (const char*) resource_PluginEditor_crestBianco_png;
const int PluginEditor::crestBianco_pngSize = 31711;

// JUCER_RESOURCE: v_png, 7321, "../images/v.png"
static const unsigned char resource_PluginEditor_v_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,1,0,0,0,1,0,8,6,0,0,0,92,114,168,102,0,0,0,4,103,65,77,65,0,0,177,143,11,252,97,5,0,0,10,
55,105,67,67,80,115,82,71,66,32,73,69,67,54,49,57,54,54,45,50,46,49,0,0,72,137,157,150,119,84,83,217,22,135,207,189,55,189,80,146,16,138,148,208,107,104,82,2,72,13,189,72,145,46,42,49,9,16,74,192,144,
0,34,54,68,84,112,68,81,145,166,8,50,40,224,128,163,67,145,177,34,138,133,1,81,177,235,4,25,68,212,113,112,20,27,150,73,100,173,25,223,188,121,239,205,155,223,31,247,126,107,159,189,207,221,103,239,125,
214,186,0,144,252,131,5,194,76,88,9,128,12,161,88,20,225,231,197,136,141,139,103,96,7,1,12,240,0,3,108,0,224,112,179,179,66,22,248,70,2,153,2,124,216,140,108,153,19,248,23,189,186,14,32,249,251,42,211,
63,140,193,0,255,159,148,185,89,34,49,0,80,152,140,231,242,248,217,92,25,23,201,56,61,87,156,37,183,79,201,152,182,52,77,206,48,74,206,34,89,130,50,86,147,115,242,44,91,124,246,153,101,15,57,243,50,132,
60,25,203,115,206,226,101,240,228,220,39,227,141,57,18,190,140,145,96,25,23,231,8,248,185,50,190,38,99,131,116,73,134,64,198,111,228,177,25,124,78,54,0,40,146,220,46,230,115,83,100,108,45,99,146,40,50,
130,45,227,121,0,224,72,201,95,240,210,47,88,204,207,19,203,15,197,206,204,90,46,18,36,167,136,25,38,92,83,134,141,147,19,139,225,207,207,77,231,139,197,204,48,14,55,141,35,226,49,216,153,25,89,28,225,
114,0,102,207,252,89,20,121,109,25,178,34,59,216,56,57,56,48,109,45,109,190,40,212,127,93,252,155,146,247,118,150,94,132,127,238,25,68,31,248,195,246,87,126,153,13,0,176,166,101,181,217,250,135,109,105,
21,0,93,235,1,80,187,253,135,205,96,47,0,138,178,190,117,14,125,113,30,186,124,94,82,196,226,44,103,43,171,220,220,92,75,1,159,107,41,47,232,239,250,159,14,127,67,95,124,207,82,190,221,239,229,97,120,
243,147,56,146,116,49,67,94,55,110,102,122,166,68,196,200,206,226,112,249,12,230,159,135,248,31,7,254,117,30,22,17,252,36,190,136,47,148,69,68,203,166,76,32,76,150,181,91,200,19,136,5,153,66,134,64,248,
159,154,248,15,195,254,164,217,185,150,137,218,248,17,208,150,88,2,165,33,26,64,126,30,0,40,42,17,32,9,123,100,43,208,239,125,11,198,71,3,249,205,139,209,153,152,157,251,207,130,254,125,87,184,76,254,
200,22,36,127,142,99,71,68,50,184,18,81,206,236,154,252,90,2,52,32,0,69,64,3,234,64,27,232,3,19,192,4,182,192,17,184,0,15,224,3,2,65,40,136,4,113,96,49,224,130,20,144,1,68,32,23,20,128,181,160,24,148,
130,173,96,39,168,6,117,160,17,52,131,54,112,24,116,129,99,224,52,56,7,46,129,203,96,4,220,1,82,48,14,158,128,41,240,10,204,64,16,132,133,200,16,21,82,135,116,32,67,200,28,178,133,88,144,27,228,3,5,67,
17,80,28,148,8,37,67,66,72,2,21,64,235,160,82,168,28,170,134,234,161,102,232,91,232,40,116,26,186,0,13,67,183,160,81,104,18,250,21,122,7,35,48,9,166,193,90,176,17,108,5,179,96,79,56,8,142,132,23,193,201,
240,50,56,31,46,130,183,192,149,112,3,124,16,238,132,79,195,151,224,17,88,10,63,129,167,17,128,16,17,58,162,139,48,17,22,194,70,66,145,120,36,9,17,33,171,144,18,164,2,105,64,218,144,30,164,31,185,138,
72,145,167,200,91,20,6,69,69,49,80,76,148,11,202,31,21,133,226,162,150,161,86,161,54,163,170,81,7,80,157,168,62,212,85,212,40,106,10,245,17,77,70,107,162,205,209,206,232,0,116,44,58,25,157,139,46,70,87,
160,155,208,29,232,179,232,17,244,56,250,21,6,131,161,99,140,49,142,24,127,76,28,38,21,179,2,179,25,179,27,211,142,57,133,25,198,140,97,166,177,88,172,58,214,28,235,138,13,197,114,176,98,108,49,182,10,
123,16,123,18,123,5,59,142,125,131,35,226,116,112,182,56,95,92,60,78,136,43,196,85,224,90,112,39,112,87,112,19,184,25,188,18,222,16,239,140,15,197,243,240,203,241,101,248,70,124,15,126,8,63,142,159,33,
40,19,140,9,174,132,72,66,42,97,45,161,146,208,70,56,75,184,75,120,65,36,18,245,136,78,196,112,162,128,184,134,88,73,60,68,60,79,28,37,190,37,81,72,102,36,54,41,129,36,33,109,33,237,39,157,34,221,34,189,
32,147,201,70,100,15,114,60,89,76,222,66,110,38,159,33,223,39,191,81,160,42,88,42,4,40,240,20,86,43,212,40,116,42,92,81,120,166,136,87,52,84,244,84,92,172,152,175,88,161,120,68,113,72,241,169,18,94,201,
72,137,173,196,81,90,165,84,163,116,84,233,134,210,180,50,85,217,70,57,84,57,67,121,179,114,139,242,5,229,71,20,44,197,136,226,67,225,81,138,40,251,40,103,40,99,84,132,170,79,101,83,185,212,117,212,70,
234,89,234,56,13,67,51,166,5,208,82,105,165,180,111,104,131,180,41,21,138,138,157,74,180,74,158,74,141,202,113,21,41,29,161,27,209,3,232,233,244,50,250,97,250,117,250,59,85,45,85,79,85,190,234,38,213,
54,213,43,170,175,213,230,168,121,168,241,213,74,212,218,213,70,212,222,169,51,212,125,212,211,212,183,169,119,169,223,211,64,105,152,105,132,107,228,106,236,209,56,171,241,116,14,109,142,203,28,238,156,
146,57,135,231,220,214,132,53,205,52,35,52,87,104,238,211,28,208,156,214,210,214,242,211,202,210,170,210,58,163,245,84,155,174,237,161,157,170,189,67,251,132,246,164,14,85,199,77,71,160,179,67,231,164,
206,99,134,10,195,147,145,206,168,100,244,49,166,116,53,117,253,117,37,186,245,186,131,186,51,122,198,122,81,122,133,122,237,122,247,244,9,250,44,253,36,253,29,250,189,250,83,6,58,6,33,6,5,6,173,6,183,
13,241,134,44,195,20,195,93,134,253,134,175,141,140,141,98,140,54,24,117,25,61,50,86,51,14,48,206,55,110,53,190,107,66,54,113,55,89,102,210,96,114,205,20,99,202,50,77,51,221,109,122,217,12,54,179,55,75,
49,171,49,27,50,135,205,29,204,5,230,187,205,135,45,208,22,78,22,66,139,6,139,27,76,18,211,147,153,195,108,101,142,90,210,45,131,45,11,45,187,44,159,89,25,88,197,91,109,179,234,183,250,104,109,111,157,
110,221,104,125,199,134,98,19,104,83,104,211,99,243,171,173,153,45,215,182,198,246,218,92,242,92,223,185,171,231,118,207,125,110,103,110,199,183,219,99,119,211,158,106,31,98,191,193,190,215,254,131,131,
163,131,200,161,205,97,210,209,192,49,209,177,214,241,6,139,198,10,99,109,102,157,119,66,59,121,57,173,118,58,230,244,214,217,193,89,236,124,216,249,23,23,166,75,154,75,139,203,163,121,198,243,248,243,
26,231,141,185,234,185,114,92,235,93,165,110,12,183,68,183,189,110,82,119,93,119,142,123,131,251,3,15,125,15,158,71,147,199,132,167,169,103,170,231,65,207,103,94,214,94,34,175,14,175,215,108,103,246,74,
246,41,111,196,219,207,187,196,123,208,135,226,19,229,83,237,115,223,87,207,55,217,183,213,119,202,207,222,111,133,223,41,127,180,127,144,255,54,255,27,1,90,1,220,128,230,128,169,64,199,192,149,129,125,
65,164,160,5,65,213,65,15,130,205,130,69,193,61,33,112,72,96,200,246,144,187,243,13,231,11,231,119,133,130,208,128,208,237,161,247,194,140,195,150,133,125,31,142,9,15,11,175,9,127,24,97,19,81,16,209,191,
128,186,96,201,130,150,5,175,34,189,34,203,34,239,68,153,68,73,162,122,163,21,163,19,162,155,163,95,199,120,199,148,199,72,99,173,98,87,198,94,138,211,136,19,196,117,199,99,227,163,227,155,226,167,23,
250,44,220,185,112,60,193,62,161,56,225,250,34,227,69,121,139,46,44,214,88,156,190,248,248,18,197,37,156,37,71,18,209,137,49,137,45,137,239,57,161,156,6,206,244,210,128,165,181,75,167,184,108,238,46,238,
19,158,7,111,7,111,146,239,202,47,231,79,36,185,38,149,39,61,74,118,77,222,158,60,153,226,158,82,145,242,84,192,22,84,11,158,167,250,167,214,165,190,78,11,77,219,159,246,41,61,38,189,61,3,151,145,152,
113,84,72,17,166,9,251,50,181,51,243,50,135,179,204,179,138,179,164,203,156,151,237,92,54,37,10,18,53,101,67,217,139,178,187,197,52,217,207,212,128,196,68,178,94,50,154,227,150,83,147,243,38,55,58,247,
72,158,114,158,48,111,96,185,217,242,77,203,39,242,125,243,191,94,129,90,193,93,209,91,160,91,176,182,96,116,165,231,202,250,85,208,170,165,171,122,87,235,175,46,90,61,190,198,111,205,129,181,132,181,
105,107,127,40,180,46,44,47,124,185,46,102,93,79,145,86,209,154,162,177,245,126,235,91,139,21,138,69,197,55,54,184,108,168,219,136,218,40,216,56,184,105,238,166,170,77,31,75,120,37,23,75,173,75,43,74,
223,111,230,110,190,248,149,205,87,149,95,125,218,146,180,101,176,204,161,108,207,86,204,86,225,214,235,219,220,183,29,40,87,46,207,47,31,219,30,178,189,115,7,99,71,201,142,151,59,151,236,188,80,97,87,
81,183,139,176,75,178,75,90,25,92,217,93,101,80,181,181,234,125,117,74,245,72,141,87,77,123,173,102,237,166,218,215,187,121,187,175,236,241,216,211,86,167,85,87,90,247,110,175,96,239,205,122,191,250,206,
6,163,134,138,125,152,125,57,251,30,54,70,55,246,127,205,250,186,185,73,163,169,180,233,195,126,225,126,233,129,136,3,125,205,142,205,205,45,154,45,101,173,112,171,164,117,242,96,194,193,203,223,120,127,
211,221,198,108,171,111,167,183,151,30,2,135,36,135,30,127,155,248,237,245,195,65,135,123,143,176,142,180,125,103,248,93,109,7,181,163,164,19,234,92,222,57,213,149,210,37,237,142,235,30,62,26,120,180,
183,199,165,167,227,123,203,239,247,31,211,61,86,115,92,229,120,217,9,194,137,162,19,159,78,230,159,156,62,149,117,234,233,233,228,211,99,189,75,122,239,156,137,61,115,173,47,188,111,240,108,208,217,243,
231,124,207,157,233,247,236,63,121,222,245,252,177,11,206,23,142,94,100,93,236,186,228,112,169,115,192,126,160,227,7,251,31,58,6,29,6,59,135,28,135,186,47,59,93,238,25,158,55,124,226,138,251,149,211,87,
189,175,158,187,22,112,237,210,200,252,145,225,235,81,215,111,222,72,184,33,189,201,187,249,232,86,250,173,231,183,115,110,207,220,89,115,23,125,183,228,158,210,189,138,251,154,247,27,126,52,253,177,93,
234,32,61,62,234,61,58,240,96,193,131,59,99,220,177,39,63,101,255,244,126,188,232,33,249,97,197,132,206,68,243,35,219,71,199,38,125,39,47,63,94,248,120,252,73,214,147,153,167,197,63,43,255,92,251,204,
228,217,119,191,120,252,50,48,21,59,53,254,92,244,252,211,175,155,95,168,191,216,255,210,238,101,239,116,216,244,253,87,25,175,102,94,151,188,81,127,115,224,45,235,109,255,187,152,119,19,51,185,239,177,
239,43,63,152,126,232,249,24,244,241,238,167,140,79,159,126,3,247,132,243,251,199,209,59,120,0,0,0,32,99,72,82,77,0,0,122,38,0,0,128,132,0,0,250,0,0,0,128,232,0,0,117,48,0,0,234,96,0,0,58,152,0,0,23,112,
156,186,81,60,0,0,0,9,112,72,89,115,0,0,11,18,0,0,11,18,1,210,221,126,252,0,0,0,27,116,69,88,116,83,111,102,116,119,97,114,101,0,67,101,108,115,121,115,32,83,116,117,100,105,111,32,84,111,111,108,193,
167,225,124,0,0,17,165,73,68,65,84,120,156,237,221,121,180,85,117,25,198,241,239,65,64,80,25,84,80,52,81,115,32,19,194,150,186,74,113,8,173,180,140,34,43,211,50,154,204,210,178,129,210,108,192,210,165,
165,54,152,217,104,3,149,105,57,52,152,73,165,150,73,154,210,42,51,43,43,76,211,180,36,103,34,68,68,188,183,63,94,88,234,245,94,238,57,247,236,253,190,123,239,247,249,172,229,114,45,229,158,103,203,149,
231,158,179,247,239,247,123,91,189,189,189,136,72,78,45,21,128,72,94,42,0,145,196,84,0,34,137,169,0,68,18,83,1,136,36,166,2,16,73,76,5,32,146,152,10,64,36,49,21,128,72,98,42,0,145,196,84,0,34,137,169,
0,68,18,83,1,136,36,166,2,16,73,76,5,32,146,152,10,64,36,49,21,128,72,98,42,0,145,196,84,0,34,137,169,0,68,18,83,1,136,36,166,2,16,73,76,5,32,146,152,10,64,36,49,21,128,72,98,42,0,145,196,84,0,34,137,
169,0,68,18,83,1,136,36,166,2,16,73,76,5,32,146,152,10,64,36,49,21,128,72,98,42,0,145,196,84,0,34,137,169,0,68,18,83,1,136,36,166,2,16,73,76,5,32,146,152,10,64,36,49,21,128,72,98,42,0,145,196,84,0,34,
137,169,0,68,18,83,1,136,36,166,2,16,73,76,5,32,146,88,19,10,160,5,140,27,226,215,14,3,198,3,99,129,245,215,188,214,106,96,5,112,63,240,72,155,175,179,106,205,215,72,188,118,255,127,216,28,152,8,12,239,
243,207,123,128,255,1,255,198,190,175,157,234,1,150,13,225,235,66,52,161,0,0,22,3,83,2,243,31,0,38,0,141,248,205,172,185,131,128,5,129,249,239,3,206,8,204,239,72,83,10,32,250,155,14,240,12,224,230,224,
107,16,248,19,48,45,48,127,44,246,14,162,22,154,82,0,35,176,183,224,125,223,206,121,58,19,152,27,152,47,176,5,112,87,96,254,37,192,236,192,252,142,53,165,0,0,78,6,230,5,230,175,6,70,175,249,187,196,248,
8,112,82,96,254,142,192,45,129,249,29,107,82,1,76,2,150,4,95,195,12,224,186,224,107,200,106,61,96,57,48,42,40,255,54,96,187,160,236,33,107,82,1,0,44,2,158,27,152,191,0,152,21,152,159,217,12,224,215,129,
249,47,2,46,11,204,31,146,166,21,192,62,192,175,130,175,97,35,224,161,224,107,200,232,74,96,191,160,236,229,192,152,160,236,174,52,173,0,134,97,119,96,55,8,188,134,87,2,63,8,204,207,104,99,236,81,108,
148,90,61,250,123,162,166,21,0,216,55,227,83,129,249,127,1,166,6,230,103,116,52,240,197,160,236,30,236,41,84,79,80,126,87,154,88,0,155,96,171,248,34,77,2,238,14,190,134,44,90,192,125,216,247,61,194,124,
224,136,160,236,174,53,177,0,192,110,198,28,16,152,63,23,91,23,32,229,155,134,45,254,137,50,142,26,45,253,237,171,169,5,176,43,112,125,96,254,82,236,39,82,35,127,115,43,230,60,224,181,65,217,215,96,55,
158,107,171,169,5,16,253,182,16,180,52,216,195,104,98,55,97,61,19,248,91,96,126,215,154,90,0,96,159,203,190,22,152,127,22,240,238,192,252,12,94,13,92,16,148,125,7,176,77,80,118,97,154,92,0,27,17,187,41,
163,7,219,98,172,165,193,229,185,157,184,63,132,179,177,181,255,181,214,228,2,128,216,207,135,0,123,19,187,58,173,201,182,197,150,223,70,120,8,251,1,83,123,77,47,128,157,128,191,6,230,255,12,120,113,96,
126,147,157,65,220,238,203,15,1,167,6,101,23,170,233,5,0,246,89,109,114,96,190,150,6,23,111,4,176,18,91,249,233,237,49,108,195,81,35,62,218,101,40,128,67,128,11,3,243,95,13,92,20,152,223,68,47,4,46,15,
202,62,7,120,67,80,118,225,50,20,192,250,216,79,139,40,55,99,143,4,165,56,191,3,118,11,202,158,136,61,98,110,132,12,5,0,246,72,238,157,129,249,91,0,255,9,204,111,146,205,137,251,189,188,22,216,43,40,187,
20,89,10,96,27,236,145,81,148,247,2,159,9,204,111,146,227,129,211,130,178,119,3,126,31,148,93,138,44,5,0,112,19,176,115,80,246,50,236,248,241,52,191,217,37,137,220,238,125,39,176,117,64,110,169,50,21,
192,129,216,99,185,40,181,95,54,90,1,207,1,126,19,148,125,56,240,157,160,236,210,100,42,128,225,192,195,196,157,28,252,5,224,152,160,236,166,248,41,118,244,150,183,21,192,134,1,185,165,203,84,0,0,39,2,
31,13,202,214,210,224,238,140,5,254,27,148,125,10,112,66,80,118,169,178,21,64,228,29,100,128,125,129,171,3,243,235,44,106,115,87,15,118,222,95,35,71,191,101,43,0,176,181,249,51,130,178,175,32,246,160,
146,186,106,97,197,189,89,64,246,69,216,98,174,70,202,88,0,123,97,7,57,68,25,131,157,34,43,237,123,38,118,214,98,132,109,176,229,228,141,148,177,0,162,79,14,62,140,184,61,236,117,53,31,120,83,64,238,245,
192,238,1,185,110,50,22,0,192,123,136,91,152,243,119,98,39,25,215,205,40,236,233,77,132,153,192,194,160,108,23,89,11,96,60,240,96,96,190,150,6,183,239,96,98,230,44,44,1,182,12,200,117,149,181,0,192,198,
120,29,20,148,125,28,177,179,11,234,228,102,108,232,166,183,163,128,179,3,114,93,101,46,128,93,128,63,4,101,107,105,112,123,38,19,115,3,110,37,182,238,224,209,128,108,87,153,11,160,5,220,3,76,8,202,159,
74,220,157,237,186,248,56,240,193,128,220,51,137,59,109,200,85,230,2,0,187,179,60,63,40,251,203,216,72,43,233,95,212,210,237,94,108,207,127,244,116,41,23,217,11,96,67,98,159,201,143,36,193,219,204,33,
154,9,252,50,32,247,82,224,165,1,185,33,178,23,0,216,17,79,115,130,178,103,210,240,199,76,93,184,14,216,35,32,119,58,177,163,198,92,169,0,236,153,252,226,160,236,95,2,251,7,101,87,217,4,224,222,128,220,
155,176,89,131,105,168,0,204,237,196,13,152,24,75,236,0,147,42,154,139,29,251,237,237,21,192,15,3,114,195,168,0,76,212,98,19,128,215,0,231,7,101,87,209,48,108,219,175,247,224,141,251,177,205,70,61,206,
185,161,84,0,102,36,240,72,80,246,109,192,118,65,217,85,20,53,217,249,3,192,233,1,185,161,84,0,143,251,12,182,71,32,194,211,128,187,130,178,171,230,98,108,238,158,167,71,129,77,73,248,81,76,5,240,184,
168,85,103,144,244,167,79,63,162,6,186,126,29,120,75,64,110,56,21,192,147,221,136,61,6,242,182,28,187,25,152,253,155,241,122,224,91,206,153,189,192,246,196,13,26,13,165,2,120,178,23,96,167,246,68,152,
134,61,134,202,170,5,252,27,219,41,233,233,42,96,63,231,204,202,80,1,60,217,112,108,144,231,200,128,236,175,2,111,13,200,173,138,29,177,157,127,222,246,195,74,32,37,21,192,83,205,3,78,14,202,206,188,52,
248,75,216,22,92,79,233,159,192,168,0,158,106,34,182,75,48,194,254,196,172,127,143,22,245,24,246,8,226,54,131,85,130,10,160,127,11,177,35,188,35,114,103,6,228,70,155,5,252,216,57,115,57,182,228,56,106,
253,71,37,168,0,250,183,7,182,25,37,194,56,236,192,144,76,34,230,54,158,70,204,89,3,149,162,2,232,95,212,114,84,128,215,1,231,5,228,70,217,18,187,251,239,169,7,91,124,149,254,92,70,21,192,192,142,1,62,
23,144,155,237,198,212,137,248,143,107,251,30,112,136,115,102,37,169,0,6,54,14,88,26,148,189,21,254,63,21,35,172,135,141,220,242,126,236,186,59,49,251,13,42,71,5,176,110,17,235,210,1,62,140,157,135,215,
116,123,227,63,43,241,6,108,195,145,160,2,24,204,116,108,121,176,183,21,216,253,135,166,127,115,174,2,158,231,156,249,42,224,251,206,153,149,165,2,88,183,200,161,148,77,63,154,106,19,252,15,222,188,7,
187,249,167,17,237,107,168,0,6,55,7,59,55,208,219,124,108,161,74,83,69,220,100,125,63,240,73,231,204,74,83,1,12,110,3,108,127,64,132,245,129,85,65,217,101,106,1,15,96,195,81,188,60,2,76,34,238,198,110,
37,169,0,218,243,117,224,205,1,185,207,7,174,12,200,45,91,196,189,149,179,241,223,107,80,121,42,128,246,236,128,77,245,245,118,13,176,79,64,110,217,206,7,14,117,206,220,137,184,211,159,43,75,5,208,190,
127,0,79,15,200,29,143,173,74,108,138,136,143,84,191,192,206,122,144,62,84,0,237,155,141,173,11,240,246,122,224,219,1,185,101,57,12,248,174,115,230,139,128,203,156,51,107,65,5,208,190,168,45,171,255,4,
182,13,200,45,203,29,216,249,139,94,110,197,62,194,73,63,84,0,157,249,36,112,108,64,238,100,224,95,1,185,69,219,14,251,3,233,233,104,108,16,171,244,67,5,208,153,173,128,59,3,114,79,0,78,9,200,45,218,103,
129,119,57,230,45,195,206,24,92,225,152,89,43,42,128,206,221,0,60,219,57,115,5,48,134,122,79,173,25,129,255,154,134,79,0,199,59,103,214,138,10,160,115,251,99,119,149,189,61,155,152,125,9,69,57,16,248,
153,99,94,15,246,212,38,106,214,67,45,168,0,58,23,181,133,245,27,196,44,70,42,138,247,59,39,237,249,111,131,10,96,104,62,72,204,118,221,186,46,13,158,4,44,113,206,220,11,184,214,57,179,118,84,0,67,19,
53,191,254,133,192,207,3,114,187,229,93,152,218,243,223,38,21,192,208,93,137,255,68,153,107,177,159,108,117,50,12,91,249,55,202,49,51,219,185,138,67,166,2,24,186,231,2,139,2,114,55,166,94,59,218,188,79,
88,190,23,219,243,159,117,192,74,71,84,0,67,23,117,114,240,27,241,31,160,217,141,203,177,143,46,94,154,178,102,194,133,10,160,59,71,3,95,116,206,188,19,216,218,57,115,168,188,15,86,125,20,59,102,252,62,
199,204,90,83,1,116,103,44,49,59,245,182,161,30,207,183,223,138,237,195,247,210,244,83,148,10,167,2,232,222,247,129,87,56,103,158,8,156,228,156,217,169,22,118,6,223,4,199,204,93,128,63,58,230,213,158,
10,160,123,83,129,63,59,103,174,4,54,164,218,75,131,119,198,70,126,121,185,10,255,167,50,181,167,2,232,94,11,27,226,177,133,115,110,213,151,6,159,131,29,168,234,229,229,192,143,28,243,26,65,5,80,140,195,
129,115,157,51,191,141,29,22,82,69,163,241,221,129,119,27,182,231,191,202,239,136,42,73,5,80,12,239,255,225,215,26,69,53,199,91,191,10,184,200,49,239,61,216,86,99,233,144,10,160,56,95,1,142,116,206,60,
16,123,206,94,53,183,0,219,59,101,45,199,22,254,100,27,169,94,8,21,64,113,34,78,187,89,4,236,233,156,57,152,173,177,99,204,188,124,22,123,7,32,67,160,2,40,214,205,192,142,206,153,155,0,15,58,103,174,203,
233,216,4,30,15,61,192,20,252,139,183,49,84,0,197,154,5,252,216,57,243,8,108,1,76,21,12,199,238,73,12,115,202,187,132,152,233,205,141,161,2,40,214,8,236,25,189,215,31,0,176,71,144,91,57,230,173,139,247,
105,73,77,157,156,228,70,5,80,188,211,240,63,135,110,91,124,63,119,15,100,17,182,75,210,195,159,129,103,57,101,53,150,10,160,120,91,98,63,149,61,157,132,45,15,142,52,17,91,250,235,229,45,216,204,70,233,
130,10,160,28,191,3,118,115,204,171,194,210,224,99,241,27,189,125,63,246,177,103,165,83,94,99,169,0,202,241,60,108,109,186,167,93,177,163,176,34,12,3,254,135,205,253,243,240,49,96,158,83,86,163,169,0,
202,177,30,182,64,197,243,24,172,239,96,75,146,35,236,14,252,214,41,107,53,182,29,250,46,167,188,70,83,1,148,231,56,108,48,133,167,168,165,193,151,2,47,113,202,138,44,186,198,81,1,148,103,83,252,79,166,
57,8,248,169,115,230,24,124,151,225,62,7,191,119,27,141,167,2,40,215,207,177,103,213,94,126,139,253,1,241,244,38,252,22,34,213,241,84,228,74,83,1,148,203,243,179,241,90,155,2,15,56,101,181,176,129,31,
155,59,229,29,10,92,232,148,149,130,10,160,92,45,236,15,227,120,199,204,35,129,175,57,101,77,1,22,59,101,221,137,109,184,90,237,148,151,130,10,160,124,222,7,99,46,193,22,35,121,240,220,2,253,1,108,163,
145,20,72,5,80,62,239,155,100,96,83,113,111,47,57,99,125,252,22,226,172,0,38,227,247,209,38,13,21,128,143,243,177,207,175,94,78,193,6,100,148,233,101,248,157,193,119,54,112,148,83,86,42,42,0,31,222,39,
228,174,194,142,41,43,115,105,240,98,236,30,128,135,157,129,191,58,101,165,162,2,240,209,194,110,98,61,205,49,115,119,224,250,146,94,123,43,236,191,199,195,229,216,209,103,82,2,21,128,159,67,177,143,2,
94,46,0,14,43,233,181,79,198,111,45,254,225,216,234,63,41,129,10,192,207,40,224,97,231,204,209,20,127,163,110,61,236,166,220,200,130,95,183,63,43,176,93,142,82,18,21,128,175,47,0,111,119,204,155,5,44,
40,248,53,247,5,22,22,252,154,3,185,16,223,155,167,233,168,0,124,109,139,13,177,240,114,61,118,47,160,72,87,3,123,23,252,154,253,233,197,166,45,221,237,144,149,150,10,192,159,231,221,115,176,225,156,247,
23,244,90,158,27,156,34,246,53,164,163,2,240,119,16,197,191,45,95,151,183,97,43,246,138,240,78,224,172,130,94,107,48,251,0,215,56,101,165,165,2,240,55,2,187,185,53,220,41,239,110,96,82,1,175,211,2,150,
2,99,11,120,173,193,84,233,164,227,70,83,1,196,240,124,140,6,182,137,166,219,123,15,187,0,127,40,224,90,218,113,12,118,195,84,74,166,2,136,49,9,219,180,227,229,84,224,67,93,190,198,69,216,208,207,178,
233,209,159,35,21,64,28,207,51,244,87,97,7,118,62,54,196,175,223,16,59,227,208,195,87,176,251,22,226,64,5,16,103,31,224,87,142,121,221,28,165,117,56,112,110,129,215,50,144,30,96,28,126,101,147,158,10,
32,142,247,81,218,223,3,14,25,226,215,254,11,159,125,12,87,1,251,57,228,200,26,42,128,88,239,3,62,229,152,183,1,157,47,71,222,30,184,165,132,107,233,207,84,224,47,78,89,130,10,32,218,198,248,30,114,241,
50,58,159,94,252,121,224,29,37,92,75,95,183,2,59,56,228,200,19,168,0,226,93,6,28,224,148,117,3,54,65,168,93,35,241,155,51,240,90,224,187,78,89,178,134,10,32,222,174,148,183,111,191,63,157,44,13,246,90,
181,184,20,123,55,36,206,84,0,241,90,216,250,250,77,156,242,142,6,190,220,230,175,189,17,152,94,226,181,172,117,58,118,232,167,56,83,1,84,195,17,248,29,229,125,15,182,16,105,176,111,188,215,98,165,213,
216,58,131,85,14,89,210,135,10,160,26,60,23,218,128,221,108,187,117,144,95,51,15,91,178,92,182,75,128,217,14,57,210,15,21,64,117,156,135,221,8,243,240,9,224,248,117,252,123,175,233,198,189,216,164,95,
175,243,5,165,15,21,64,117,60,3,248,155,83,214,96,75,131,247,196,230,240,149,237,143,216,38,35,9,162,2,168,150,59,176,1,24,30,246,0,126,51,192,191,187,18,159,21,121,7,0,87,56,228,200,0,84,0,213,114,8,
126,195,47,47,6,14,238,231,159,143,7,30,116,200,191,7,191,161,162,50,0,21,64,181,120,142,219,130,254,151,6,31,5,124,201,33,91,179,254,42,64,5,80,61,103,97,71,111,121,152,141,221,133,95,203,107,77,194,
35,148,127,131,81,218,160,2,168,158,173,129,127,58,101,245,189,9,55,13,248,147,67,238,185,192,28,135,28,25,132,10,160,154,110,194,230,225,121,152,200,227,39,253,122,60,138,236,197,150,35,107,210,111,5,
168,0,170,233,0,108,147,144,135,181,231,239,141,198,142,227,42,219,34,236,49,163,84,128,10,160,154,134,99,55,231,60,78,14,190,15,216,12,123,2,113,129,67,94,55,39,19,73,193,84,0,213,117,34,240,81,167,172,
169,192,165,192,211,75,206,185,3,91,249,39,21,161,2,168,174,205,129,255,56,101,221,141,207,51,249,35,241,219,244,36,109,80,1,84,219,175,129,25,209,23,81,144,229,192,152,232,139,144,39,83,1,84,219,12,172,
4,154,224,243,248,173,111,144,54,169,0,170,205,251,228,224,178,60,134,141,20,243,120,202,32,29,80,1,84,223,187,129,51,163,47,162,75,87,224,119,238,161,116,64,5,80,125,94,155,115,202,52,5,248,123,244,69,
200,83,169,0,234,97,1,118,64,103,29,45,6,118,138,190,8,233,159,10,160,30,60,39,243,22,237,96,108,235,177,84,144,10,160,30,90,216,254,249,9,209,23,210,161,7,128,77,163,47,66,6,166,2,168,143,55,0,223,140,
190,136,14,157,2,156,16,125,17,50,48,21,64,125,120,159,28,220,173,71,177,199,151,171,163,47,68,6,166,2,168,151,111,98,239,4,234,160,155,105,196,226,68,5,80,47,83,176,187,234,85,215,139,141,19,247,24,44,
34,93,80,1,212,207,237,84,127,71,221,239,129,221,162,47,66,6,167,2,168,159,131,129,31,68,95,196,32,102,2,11,163,47,66,6,167,2,168,31,207,145,221,67,177,4,216,50,250,34,164,61,42,128,122,58,3,152,27,125,
17,3,152,75,253,247,46,164,161,2,168,167,201,216,233,58,85,243,48,245,223,185,152,138,10,160,190,110,4,166,71,95,68,31,243,177,81,231,82,19,42,128,250,122,1,213,154,171,215,3,108,12,44,139,190,16,105,
159,10,160,190,134,3,15,97,55,5,171,224,106,96,223,232,139,144,206,168,0,234,109,30,112,114,244,69,172,177,11,54,105,72,106,68,5,80,111,19,177,93,130,209,254,1,108,31,125,17,210,57,21,64,253,45,36,254,
173,247,28,108,222,159,212,140,10,160,254,246,0,174,11,204,95,6,140,11,204,151,46,168,0,234,111,24,240,95,96,163,160,252,79,3,199,6,101,75,151,84,0,205,112,12,240,185,128,220,213,216,176,143,149,1,217,
82,0,21,64,51,140,3,150,6,228,46,0,102,5,228,74,65,84,0,205,113,49,48,219,57,115,59,224,54,231,76,41,144,10,160,57,166,99,203,131,189,220,4,76,115,204,147,18,168,0,154,163,133,77,19,222,204,41,239,37,
192,79,156,178,164,36,42,128,102,153,3,156,227,144,115,31,182,8,73,106,78,5,208,44,59,224,51,130,235,4,236,200,111,169,57,21,64,243,236,138,77,226,125,162,61,177,67,58,193,102,13,142,199,54,19,173,213,
251,132,191,86,99,19,137,251,123,170,112,235,154,95,163,3,63,26,66,5,32,146,152,10,64,36,49,21,128,72,98,42,0,145,196,84,0,34,137,169,0,68,18,83,1,136,36,166,2,16,73,76,5,32,146,152,10,64,36,49,21,128,
72,98,42,0,145,196,84,0,34,137,169,0,68,18,83,1,136,36,166,2,16,73,76,5,32,146,152,10,64,36,49,21,128,72,98,42,0,145,196,84,0,34,137,169,0,68,18,83,1,136,36,166,2,16,73,76,5,32,146,152,10,64,36,49,21,
128,72,98,42,0,145,196,84,0,34,137,169,0,68,18,83,1,136,36,166,2,16,73,76,5,32,146,152,10,64,36,49,21,128,72,98,42,0,145,196,84,0,34,137,169,0,68,18,83,1,136,36,166,2,16,73,76,5,32,146,152,10,64,36,177,
255,3,161,112,146,76,116,55,191,172,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* PluginEditor::v_png = (const char*) resource_PluginEditor_v_png;
const int PluginEditor::v_pngSize = 7321;

// JUCER_RESOURCE: u_png, 8786, "../images/u.png"
static const unsigned char resource_PluginEditor_u_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,1,0,0,0,1,0,8,6,0,0,0,92,114,168,102,0,0,0,4,103,65,77,65,0,0,177,143,11,252,97,5,0,0,10,
55,105,67,67,80,115,82,71,66,32,73,69,67,54,49,57,54,54,45,50,46,49,0,0,72,137,157,150,119,84,83,217,22,135,207,189,55,189,80,146,16,138,148,208,107,104,82,2,72,13,189,72,145,46,42,49,9,16,74,192,144,
0,34,54,68,84,112,68,81,145,166,8,50,40,224,128,163,67,145,177,34,138,133,1,81,177,235,4,25,68,212,113,112,20,27,150,73,100,173,25,223,188,121,239,205,155,223,31,247,126,107,159,189,207,221,103,239,125,
214,186,0,144,252,131,5,194,76,88,9,128,12,161,88,20,225,231,197,136,141,139,103,96,7,1,12,240,0,3,108,0,224,112,179,179,66,22,248,70,2,153,2,124,216,140,108,153,19,248,23,189,186,14,32,249,251,42,211,
63,140,193,0,255,159,148,185,89,34,49,0,80,152,140,231,242,248,217,92,25,23,201,56,61,87,156,37,183,79,201,152,182,52,77,206,48,74,206,34,89,130,50,86,147,115,242,44,91,124,246,153,101,15,57,243,50,132,
60,25,203,115,206,226,101,240,228,220,39,227,141,57,18,190,140,145,96,25,23,231,8,248,185,50,190,38,99,131,116,73,134,64,198,111,228,177,25,124,78,54,0,40,146,220,46,230,115,83,100,108,45,99,146,40,50,
130,45,227,121,0,224,72,201,95,240,210,47,88,204,207,19,203,15,197,206,204,90,46,18,36,167,136,25,38,92,83,134,141,147,19,139,225,207,207,77,231,139,197,204,48,14,55,141,35,226,49,216,153,25,89,28,225,
114,0,102,207,252,89,20,121,109,25,178,34,59,216,56,57,56,48,109,45,109,190,40,212,127,93,252,155,146,247,118,150,94,132,127,238,25,68,31,248,195,246,87,126,153,13,0,176,166,101,181,217,250,135,109,105,
21,0,93,235,1,80,187,253,135,205,96,47,0,138,178,190,117,14,125,113,30,186,124,94,82,196,226,44,103,43,171,220,220,92,75,1,159,107,41,47,232,239,250,159,14,127,67,95,124,207,82,190,221,239,229,97,120,
243,147,56,146,116,49,67,94,55,110,102,122,166,68,196,200,206,226,112,249,12,230,159,135,248,31,7,254,117,30,22,17,252,36,190,136,47,148,69,68,203,166,76,32,76,150,181,91,200,19,136,5,153,66,134,64,248,
159,154,248,15,195,254,164,217,185,150,137,218,248,17,208,150,88,2,165,33,26,64,126,30,0,40,42,17,32,9,123,100,43,208,239,125,11,198,71,3,249,205,139,209,153,152,157,251,207,130,254,125,87,184,76,254,
200,22,36,127,142,99,71,68,50,184,18,81,206,236,154,252,90,2,52,32,0,69,64,3,234,64,27,232,3,19,192,4,182,192,17,184,0,15,224,3,2,65,40,136,4,113,96,49,224,130,20,144,1,68,32,23,20,128,181,160,24,148,
130,173,96,39,168,6,117,160,17,52,131,54,112,24,116,129,99,224,52,56,7,46,129,203,96,4,220,1,82,48,14,158,128,41,240,10,204,64,16,132,133,200,16,21,82,135,116,32,67,200,28,178,133,88,144,27,228,3,5,67,
17,80,28,148,8,37,67,66,72,2,21,64,235,160,82,168,28,170,134,234,161,102,232,91,232,40,116,26,186,0,13,67,183,160,81,104,18,250,21,122,7,35,48,9,166,193,90,176,17,108,5,179,96,79,56,8,142,132,23,193,201,
240,50,56,31,46,130,183,192,149,112,3,124,16,238,132,79,195,151,224,17,88,10,63,129,167,17,128,16,17,58,162,139,48,17,22,194,70,66,145,120,36,9,17,33,171,144,18,164,2,105,64,218,144,30,164,31,185,138,
72,145,167,200,91,20,6,69,69,49,80,76,148,11,202,31,21,133,226,162,150,161,86,161,54,163,170,81,7,80,157,168,62,212,85,212,40,106,10,245,17,77,70,107,162,205,209,206,232,0,116,44,58,25,157,139,46,70,87,
160,155,208,29,232,179,232,17,244,56,250,21,6,131,161,99,140,49,142,24,127,76,28,38,21,179,2,179,25,179,27,211,142,57,133,25,198,140,97,166,177,88,172,58,214,28,235,138,13,197,114,176,98,108,49,182,10,
123,16,123,18,123,5,59,142,125,131,35,226,116,112,182,56,95,92,60,78,136,43,196,85,224,90,112,39,112,87,112,19,184,25,188,18,222,16,239,140,15,197,243,240,203,241,101,248,70,124,15,126,8,63,142,159,33,
40,19,140,9,174,132,72,66,42,97,45,161,146,208,70,56,75,184,75,120,65,36,18,245,136,78,196,112,162,128,184,134,88,73,60,68,60,79,28,37,190,37,81,72,102,36,54,41,129,36,33,109,33,237,39,157,34,221,34,189,
32,147,201,70,100,15,114,60,89,76,222,66,110,38,159,33,223,39,191,81,160,42,88,42,4,40,240,20,86,43,212,40,116,42,92,81,120,166,136,87,52,84,244,84,92,172,152,175,88,161,120,68,113,72,241,169,18,94,201,
72,137,173,196,81,90,165,84,163,116,84,233,134,210,180,50,85,217,70,57,84,57,67,121,179,114,139,242,5,229,71,20,44,197,136,226,67,225,81,138,40,251,40,103,40,99,84,132,170,79,101,83,185,212,117,212,70,
234,89,234,56,13,67,51,166,5,208,82,105,165,180,111,104,131,180,41,21,138,138,157,74,180,74,158,74,141,202,113,21,41,29,161,27,209,3,232,233,244,50,250,97,250,117,250,59,85,45,85,79,85,190,234,38,213,
54,213,43,170,175,213,230,168,121,168,241,213,74,212,218,213,70,212,222,169,51,212,125,212,211,212,183,169,119,169,223,211,64,105,152,105,132,107,228,106,236,209,56,171,241,116,14,109,142,203,28,238,156,
146,57,135,231,220,214,132,53,205,52,35,52,87,104,238,211,28,208,156,214,210,214,242,211,202,210,170,210,58,163,245,84,155,174,237,161,157,170,189,67,251,132,246,164,14,85,199,77,71,160,179,67,231,164,
206,99,134,10,195,147,145,206,168,100,244,49,166,116,53,117,253,117,37,186,245,186,131,186,51,122,198,122,81,122,133,122,237,122,247,244,9,250,44,253,36,253,29,250,189,250,83,6,58,6,33,6,5,6,173,6,183,
13,241,134,44,195,20,195,93,134,253,134,175,141,140,141,98,140,54,24,117,25,61,50,86,51,14,48,206,55,110,53,190,107,66,54,113,55,89,102,210,96,114,205,20,99,202,50,77,51,221,109,122,217,12,54,179,55,75,
49,171,49,27,50,135,205,29,204,5,230,187,205,135,45,208,22,78,22,66,139,6,139,27,76,18,211,147,153,195,108,101,142,90,210,45,131,45,11,45,187,44,159,89,25,88,197,91,109,179,234,183,250,104,109,111,157,
110,221,104,125,199,134,98,19,104,83,104,211,99,243,171,173,153,45,215,182,198,246,218,92,242,92,223,185,171,231,118,207,125,110,103,110,199,183,219,99,119,211,158,106,31,98,191,193,190,215,254,131,131,
163,131,200,161,205,97,210,209,192,49,209,177,214,241,6,139,198,10,99,109,102,157,119,66,59,121,57,173,118,58,230,244,214,217,193,89,236,124,216,249,23,23,166,75,154,75,139,203,163,121,198,243,248,243,
26,231,141,185,234,185,114,92,235,93,165,110,12,183,68,183,189,110,82,119,93,119,142,123,131,251,3,15,125,15,158,71,147,199,132,167,169,103,170,231,65,207,103,94,214,94,34,175,14,175,215,108,103,246,74,
246,41,111,196,219,207,187,196,123,208,135,226,19,229,83,237,115,223,87,207,55,217,183,213,119,202,207,222,111,133,223,41,127,180,127,144,255,54,255,27,1,90,1,220,128,230,128,169,64,199,192,149,129,125,
65,164,160,5,65,213,65,15,130,205,130,69,193,61,33,112,72,96,200,246,144,187,243,13,231,11,231,119,133,130,208,128,208,237,161,247,194,140,195,150,133,125,31,142,9,15,11,175,9,127,24,97,19,81,16,209,191,
128,186,96,201,130,150,5,175,34,189,34,203,34,239,68,153,68,73,162,122,163,21,163,19,162,155,163,95,199,120,199,148,199,72,99,173,98,87,198,94,138,211,136,19,196,117,199,99,227,163,227,155,226,167,23,
250,44,220,185,112,60,193,62,161,56,225,250,34,227,69,121,139,46,44,214,88,156,190,248,248,18,197,37,156,37,71,18,209,137,49,137,45,137,239,57,161,156,6,206,244,210,128,165,181,75,167,184,108,238,46,238,
19,158,7,111,7,111,146,239,202,47,231,79,36,185,38,149,39,61,74,118,77,222,158,60,153,226,158,82,145,242,84,192,22,84,11,158,167,250,167,214,165,190,78,11,77,219,159,246,41,61,38,189,61,3,151,145,152,
113,84,72,17,166,9,251,50,181,51,243,50,135,179,204,179,138,179,164,203,156,151,237,92,54,37,10,18,53,101,67,217,139,178,187,197,52,217,207,212,128,196,68,178,94,50,154,227,150,83,147,243,38,55,58,247,
72,158,114,158,48,111,96,185,217,242,77,203,39,242,125,243,191,94,129,90,193,93,209,91,160,91,176,182,96,116,165,231,202,250,85,208,170,165,171,122,87,235,175,46,90,61,190,198,111,205,129,181,132,181,
105,107,127,40,180,46,44,47,124,185,46,102,93,79,145,86,209,154,162,177,245,126,235,91,139,21,138,69,197,55,54,184,108,168,219,136,218,40,216,56,184,105,238,166,170,77,31,75,120,37,23,75,173,75,43,74,
223,111,230,110,190,248,149,205,87,149,95,125,218,146,180,101,176,204,161,108,207,86,204,86,225,214,235,219,220,183,29,40,87,46,207,47,31,219,30,178,189,115,7,99,71,201,142,151,59,151,236,188,80,97,87,
81,183,139,176,75,178,75,90,25,92,217,93,101,80,181,181,234,125,117,74,245,72,141,87,77,123,173,102,237,166,218,215,187,121,187,175,236,241,216,211,86,167,85,87,90,247,110,175,96,239,205,122,191,250,206,
6,163,134,138,125,152,125,57,251,30,54,70,55,246,127,205,250,186,185,73,163,169,180,233,195,126,225,126,233,129,136,3,125,205,142,205,205,45,154,45,101,173,112,171,164,117,242,96,194,193,203,223,120,127,
211,221,198,108,171,111,167,183,151,30,2,135,36,135,30,127,155,248,237,245,195,65,135,123,143,176,142,180,125,103,248,93,109,7,181,163,164,19,234,92,222,57,213,149,210,37,237,142,235,30,62,26,120,180,
183,199,165,167,227,123,203,239,247,31,211,61,86,115,92,229,120,217,9,194,137,162,19,159,78,230,159,156,62,149,117,234,233,233,228,211,99,189,75,122,239,156,137,61,115,173,47,188,111,240,108,208,217,243,
231,124,207,157,233,247,236,63,121,222,245,252,177,11,206,23,142,94,100,93,236,186,228,112,169,115,192,126,160,227,7,251,31,58,6,29,6,59,135,28,135,186,47,59,93,238,25,158,55,124,226,138,251,149,211,87,
189,175,158,187,22,112,237,210,200,252,145,225,235,81,215,111,222,72,184,33,189,201,187,249,232,86,250,173,231,183,115,110,207,220,89,115,23,125,183,228,158,210,189,138,251,154,247,27,126,52,253,177,93,
234,32,61,62,234,61,58,240,96,193,131,59,99,220,177,39,63,101,255,244,126,188,232,33,249,97,197,132,206,68,243,35,219,71,199,38,125,39,47,63,94,248,120,252,73,214,147,153,167,197,63,43,255,92,251,204,
228,217,119,191,120,252,50,48,21,59,53,254,92,244,252,211,175,155,95,168,191,216,255,210,238,101,239,116,216,244,253,87,25,175,102,94,151,188,81,127,115,224,45,235,109,255,187,152,119,19,51,185,239,177,
239,43,63,152,126,232,249,24,244,241,238,167,140,79,159,126,3,247,132,243,251,199,209,59,120,0,0,0,32,99,72,82,77,0,0,122,38,0,0,128,132,0,0,250,0,0,0,128,232,0,0,117,48,0,0,234,96,0,0,58,152,0,0,23,112,
156,186,81,60,0,0,0,9,112,72,89,115,0,0,11,18,0,0,11,18,1,210,221,126,252,0,0,0,27,116,69,88,116,83,111,102,116,119,97,114,101,0,67,101,108,115,121,115,32,83,116,117,100,105,111,32,84,111,111,108,193,
167,225,124,0,0,23,94,73,68,65,84,120,156,237,157,119,180,221,85,153,134,159,132,16,154,148,208,2,72,199,136,32,140,160,72,9,69,18,74,168,10,24,197,72,113,6,97,70,101,41,3,86,80,80,16,4,69,70,41,138,202,
32,168,128,13,44,40,32,210,123,141,136,244,30,144,102,8,137,9,161,37,185,247,204,31,239,189,147,24,18,146,156,236,239,156,253,219,251,125,214,186,43,44,254,120,127,39,185,231,188,231,219,223,254,202,128,
86,171,133,49,166,78,6,216,0,140,169,23,27,128,49,21,99,3,48,166,98,108,0,198,84,140,13,192,152,138,177,1,24,83,49,54,0,99,42,198,6,96,76,197,216,0,140,169,24,27,128,49,21,99,3,48,166,98,108,0,198,84,
140,13,192,152,138,177,1,24,83,49,54,0,99,42,198,6,96,76,197,216,0,140,169,24,27,128,49,21,99,3,48,166,98,108,0,198,84,140,13,192,152,138,177,1,24,83,49,54,0,99,42,198,6,96,76,197,216,0,140,169,24,27,
128,49,21,99,3,48,166,98,108,0,198,84,140,13,192,152,138,177,1,24,83,49,54,0,99,42,198,6,96,76,197,216,0,140,169,24,27,128,49,21,99,3,48,166,98,108,0,198,84,140,13,192,152,138,177,1,24,83,49,54,0,99,42,
198,6,96,76,197,216,0,140,169,24,27,128,49,21,99,3,48,166,98,108,0,198,84,140,13,192,152,138,177,1,152,210,88,28,216,50,177,230,20,224,62,224,245,196,186,93,167,100,3,56,20,56,30,88,46,177,110,47,112,
21,48,26,189,49,76,30,236,12,156,11,172,26,160,253,80,159,254,83,1,218,93,165,100,3,56,2,56,14,88,42,177,110,11,184,3,216,21,152,152,88,219,180,207,104,224,76,96,197,0,237,113,192,78,192,163,1,218,93,
165,100,3,248,18,240,85,20,18,166,230,46,96,55,224,249,0,109,211,30,251,3,167,147,62,226,3,120,22,24,1,60,28,160,221,85,74,54,128,35,145,1,44,22,160,125,55,240,62,96,114,128,182,105,143,253,128,51,136,
49,128,231,209,239,219,6,208,32,190,134,76,96,112,128,246,223,128,173,128,87,2,180,77,123,236,10,156,15,12,9,208,30,15,236,8,220,19,160,221,85,74,54,128,99,128,47,19,99,0,119,3,239,1,122,2,180,77,123,
236,8,252,18,88,62,64,251,5,96,20,58,250,21,69,201,6,112,2,240,121,96,209,0,237,219,129,45,2,116,77,251,108,2,92,65,76,18,112,2,176,23,112,83,128,118,87,41,217,0,78,4,62,75,140,1,220,12,108,29,160,107,
218,103,125,224,90,96,149,0,237,137,192,251,177,1,52,138,83,128,79,147,222,0,90,192,53,192,14,137,117,205,194,177,58,112,27,176,90,128,246,68,96,12,240,231,0,237,174,82,178,1,156,12,28,70,140,1,92,141,
206,156,38,31,134,160,220,204,26,1,218,147,128,125,209,17,163,40,74,54,128,239,160,106,192,8,3,248,19,170,3,48,249,176,28,50,128,53,3,180,39,1,31,69,191,247,162,40,217,0,162,114,0,45,224,74,84,26,106,
242,97,5,96,44,176,86,128,182,143,0,13,228,155,192,225,216,0,106,97,121,116,77,23,17,1,188,136,74,141,175,13,208,238,42,37,27,192,49,192,81,164,175,4,108,161,55,194,200,196,186,102,225,88,19,101,233,87,
15,208,158,0,236,3,220,16,160,221,85,74,54,128,163,144,9,68,148,2,223,8,108,27,160,107,218,103,93,224,122,224,173,1,218,227,129,93,112,33,80,163,248,12,112,18,176,68,128,246,173,168,20,216,228,195,6,168,
77,59,162,29,248,57,116,235,115,127,128,118,87,41,217,0,14,6,78,5,150,12,208,30,11,188,23,29,7,76,30,108,10,92,6,12,13,208,126,26,216,14,120,34,64,187,171,148,108,0,99,128,31,2,75,7,104,255,21,245,2,244,
6,104,155,246,120,55,186,166,91,41,64,251,73,100,248,47,4,104,119,149,146,13,96,23,212,28,178,76,128,246,125,200,0,138,27,17,213,96,182,1,126,75,76,47,192,35,168,247,99,82,128,118,87,41,217,0,70,2,23,
18,211,30,250,0,176,25,110,7,206,137,173,128,63,18,211,13,248,32,58,98,188,22,160,221,85,74,54,128,119,3,151,19,243,141,240,112,159,254,203,1,218,166,61,118,0,126,69,140,1,220,131,12,160,184,246,239,146,
13,224,157,40,43,28,145,20,42,54,36,108,48,219,2,191,39,38,226,187,11,25,126,113,148,108,0,145,247,194,143,1,155,227,161,160,57,49,10,248,57,49,6,80,236,252,135,146,13,96,37,224,78,98,74,67,31,67,103,
206,226,178,194,13,102,123,148,4,140,152,9,120,19,74,50,22,71,201,6,176,2,114,238,117,3,180,159,64,223,8,54,128,124,216,5,184,128,244,17,64,11,149,0,191,47,177,110,22,148,108,0,75,162,246,208,183,5,104,
63,129,34,128,127,4,104,155,246,216,158,152,8,160,133,114,73,59,37,214,205,130,146,13,96,48,42,216,217,32,64,123,28,138,0,198,7,104,155,246,216,9,213,125,68,68,0,197,118,127,150,108,0,131,80,4,176,97,
128,182,35,128,252,216,6,184,152,24,3,40,118,0,76,201,6,176,8,138,0,54,10,208,30,135,110,1,156,3,200,135,145,192,175,73,95,7,208,66,245,36,187,38,214,205,130,146,13,96,0,50,128,127,11,208,126,2,109,160,
245,17,32,31,182,4,46,37,38,2,184,20,216,35,177,110,22,216,0,218,99,28,106,14,153,16,160,109,218,99,59,148,4,140,136,0,124,4,104,40,119,161,133,17,169,113,4,144,31,155,163,118,224,8,3,184,12,216,61,177,
110,22,148,108,0,3,144,1,188,43,64,123,28,234,6,116,37,96,62,108,141,74,129,87,72,172,235,28,64,131,25,75,76,13,247,227,192,112,124,11,144,19,155,161,111,234,212,205,95,62,2,52,148,129,200,0,162,142,0,
155,225,8,32,39,182,0,254,64,250,129,32,45,52,14,124,151,196,186,89,80,178,1,128,122,1,222,19,160,251,24,138,0,156,3,200,135,77,80,168,190,114,98,93,31,1,26,202,0,224,47,196,68,0,143,163,163,197,228,0,
109,211,30,155,160,80,61,117,251,183,43,1,27,204,29,40,84,79,205,35,232,22,192,71,128,124,216,16,213,236,167,222,14,220,66,59,1,71,37,214,205,130,146,13,32,50,2,120,4,77,136,241,68,160,124,24,134,22,182,
164,222,14,236,102,160,6,115,59,42,216,73,205,3,232,222,121,106,128,182,105,143,117,208,0,152,212,155,129,108,0,13,101,0,186,5,216,52,64,251,1,148,3,40,110,72,100,131,25,138,12,63,245,0,152,162,215,193,
151,108,0,16,23,1,252,13,221,46,204,8,208,54,237,49,20,184,5,69,2,41,105,1,215,160,161,163,197,81,186,1,68,21,2,21,59,37,182,193,44,141,42,63,215,75,172,107,3,104,48,81,17,192,88,98,110,23,76,251,188,
5,213,125,172,159,88,183,232,109,208,165,27,64,84,33,208,95,130,116,77,251,44,134,186,63,223,145,88,215,17,64,131,185,13,101,235,83,227,237,192,249,17,53,0,166,5,92,7,140,72,172,155,5,165,27,64,84,33,
80,177,115,226,27,204,64,148,3,72,61,255,193,17,64,131,185,149,152,15,106,177,115,226,27,78,196,252,7,71,0,13,38,234,8,112,51,234,63,55,121,17,145,243,113,4,208,96,162,34,128,27,208,8,42,147,23,81,6,224,
197,32,13,37,202,0,110,68,203,40,77,94,68,252,190,125,13,216,96,28,1,212,69,84,221,71,177,191,239,210,13,224,22,212,182,155,154,98,223,16,13,231,102,210,95,207,182,80,147,209,246,137,117,179,160,116,3,
240,45,64,93,68,37,125,139,253,125,151,110,0,81,17,128,115,0,121,18,17,1,64,193,17,95,233,6,16,21,1,184,18,48,79,162,114,0,183,160,25,144,197,81,186,1,68,125,35,184,14,32,79,124,4,88,64,74,55,128,168,
8,224,78,98,190,105,204,194,17,213,252,85,108,196,87,186,1,220,68,76,232,230,94,128,60,137,234,253,40,54,226,43,221,0,162,146,128,127,69,131,70,138,254,199,107,32,127,33,102,4,220,109,196,188,143,186,
78,233,6,112,3,49,103,55,207,3,200,147,40,3,112,18,176,161,68,29,1,238,65,17,128,103,2,230,195,64,100,0,17,203,96,157,3,104,40,215,161,251,250,1,137,117,239,69,109,167,158,9,152,15,3,209,209,108,227,0,
109,231,0,26,202,245,232,8,144,218,0,30,68,6,240,122,98,93,211,62,81,19,129,192,6,208,88,174,66,131,28,82,27,192,67,232,172,249,106,98,93,211,62,139,34,3,216,48,64,187,216,202,79,27,64,123,60,138,34,0,
175,6,203,135,193,200,0,54,72,172,219,66,6,224,82,224,6,242,39,180,213,53,181,1,60,134,10,129,38,37,214,53,237,179,56,112,55,240,246,196,186,158,7,208,96,46,65,123,221,83,27,192,56,84,114,250,66,98,93,
211,62,203,160,74,192,97,137,117,189,26,172,193,252,22,248,0,233,13,224,41,84,24,242,92,98,93,211,62,75,163,35,192,186,137,117,91,40,146,220,45,177,110,22,148,110,0,191,4,70,163,43,162,148,60,131,110,
23,198,37,214,53,237,179,50,186,175,143,216,13,120,9,176,103,98,221,44,40,221,0,206,3,198,144,222,0,158,67,19,98,30,78,172,107,218,103,37,116,4,72,189,29,184,23,248,29,240,193,196,186,89,80,186,1,252,
0,56,24,221,17,167,100,60,26,19,125,111,98,93,211,62,107,161,108,253,234,137,117,123,81,36,249,209,196,186,89,80,186,1,156,1,252,23,48,40,177,238,4,96,15,212,36,98,242,96,61,212,251,177,106,98,221,30,
224,124,224,99,137,117,179,160,116,3,56,30,248,2,42,18,73,201,36,96,119,212,36,98,242,96,3,116,93,183,114,98,221,30,224,44,224,147,137,117,179,160,116,3,248,42,112,20,42,18,73,201,100,148,91,184,44,177,
174,105,159,247,160,108,253,138,137,117,103,160,72,242,240,196,186,89,80,186,1,28,6,156,132,138,68,82,50,21,56,16,93,51,154,60,216,26,248,3,48,36,177,238,116,224,91,192,87,18,235,102,65,233,6,112,8,112,
42,176,68,98,221,87,80,72,248,211,196,186,166,125,118,6,126,141,10,130,82,50,13,56,22,248,70,98,221,44,40,221,0,62,2,252,8,21,137,164,228,53,148,91,56,61,177,174,105,159,209,192,57,192,91,18,235,22,253,
187,46,221,0,118,2,46,36,230,91,225,56,224,132,196,186,166,125,62,142,62,164,17,209,222,161,192,185,137,117,179,160,116,3,216,14,157,211,151,79,172,59,3,248,46,240,249,196,186,166,125,14,3,190,9,44,150,
88,119,42,240,31,232,139,164,56,74,55,128,141,129,43,137,185,26,58,7,229,24,76,30,124,29,248,34,233,175,124,39,3,251,161,114,224,226,40,221,0,214,65,213,97,171,37,214,237,69,223,8,251,38,214,53,237,115,
10,240,25,210,23,125,77,66,13,101,55,36,214,205,130,210,13,96,21,84,172,179,118,98,221,22,170,1,216,61,177,174,105,159,115,129,253,73,95,246,253,2,234,4,188,51,177,110,22,148,110,0,75,1,119,145,190,71,
28,10,94,23,213,80,46,2,246,34,166,241,107,4,26,3,87,28,165,27,192,32,100,0,17,131,34,199,18,179,133,198,180,71,212,244,167,191,163,217,15,207,38,214,205,130,210,13,0,226,246,197,121,48,104,94,68,237,
128,120,12,237,4,40,114,250,83,13,6,112,61,49,19,93,199,161,55,156,167,2,229,65,212,86,160,7,209,18,152,34,141,190,6,3,184,28,21,4,165,14,13,159,71,131,34,31,72,172,107,22,156,197,209,56,176,245,3,180,
239,66,71,189,222,0,237,174,83,131,1,68,37,135,38,162,129,163,183,39,214,53,11,206,202,104,54,195,218,1,218,197,46,6,133,58,12,224,28,224,0,210,95,15,77,65,67,34,126,151,88,215,44,56,195,208,81,111,149,
196,186,69,79,4,134,58,12,224,52,212,185,151,186,64,228,85,84,126,122,86,98,93,179,224,108,3,252,158,244,37,223,45,212,98,252,129,196,186,217,80,131,1,28,141,122,185,83,15,5,41,186,77,180,97,236,137,198,
118,165,238,250,236,5,126,142,10,140,138,164,6,3,56,20,56,153,244,93,98,51,128,239,163,40,192,116,151,168,185,15,197,255,142,107,48,128,125,81,152,238,111,135,114,137,26,253,54,13,117,24,30,147,88,55,
27,106,48,128,109,81,162,46,226,124,120,5,48,42,177,174,89,112,78,69,145,94,234,68,239,171,168,229,251,123,137,117,179,161,6,3,216,0,109,9,78,61,46,26,10,191,34,106,16,191,0,62,68,250,171,222,151,208,
44,128,139,18,235,102,67,13,6,176,50,42,19,125,91,128,246,67,104,77,248,107,1,218,102,254,137,90,3,255,34,218,8,116,93,98,221,108,168,193,0,22,5,238,0,222,21,160,253,44,154,70,59,46,64,219,204,63,81,253,
30,207,160,106,207,98,87,192,213,96,0,0,215,0,239,35,253,55,196,68,96,31,10,254,134,104,0,203,160,62,128,245,2,180,31,5,222,11,252,51,64,59,11,106,49,128,11,129,189,73,127,70,124,5,248,20,240,147,196,
186,102,254,217,16,85,235,13,13,208,30,139,12,160,216,15,73,45,6,112,38,90,18,154,186,26,112,58,112,34,186,134,50,221,97,87,148,4,76,61,249,185,133,34,199,29,18,235,102,69,45,6,112,36,250,144,166,158,
24,219,139,86,144,23,185,56,178,33,124,26,109,238,73,189,253,169,138,185,143,181,24,192,254,104,85,248,82,137,117,91,104,33,229,200,196,186,102,254,249,30,240,159,164,143,238,102,160,61,3,71,36,214,205,
138,90,12,96,4,90,27,181,66,128,246,253,104,96,196,235,1,218,102,222,252,17,13,237,76,157,224,125,29,85,0,126,43,177,110,86,212,98,0,235,162,111,234,53,2,180,159,3,182,167,224,171,162,204,185,29,37,234,
82,243,18,234,49,248,101,128,118,54,212,98,0,139,163,187,226,119,6,104,79,65,213,98,191,9,208,54,111,206,80,84,141,185,86,128,246,11,104,236,251,29,1,218,217,80,139,1,64,92,45,192,52,180,35,240,184,196,
186,102,222,108,143,140,55,245,74,112,128,39,208,204,199,231,3,180,179,161,38,3,56,15,24,67,250,90,128,94,20,38,126,52,177,174,153,55,135,1,39,145,254,6,0,84,3,176,5,90,3,87,44,53,25,192,73,40,163,155,
122,119,28,192,173,104,116,180,233,44,63,2,14,34,125,23,96,11,184,20,216,35,177,110,118,212,100,0,7,161,182,209,212,251,227,1,158,68,93,129,69,135,139,25,18,117,172,155,1,156,13,124,34,177,110,118,212,
100,0,155,163,249,110,169,55,5,131,18,129,251,161,43,41,211,25,150,65,35,187,215,13,208,126,21,141,145,251,159,0,237,172,168,201,0,150,69,25,221,136,61,129,211,129,111,163,169,52,166,51,236,128,250,244,
151,13,208,158,132,138,199,46,13,208,206,138,154,12,0,84,11,176,29,233,67,198,22,90,64,178,107,98,93,51,119,142,5,190,68,250,49,96,160,246,238,145,232,38,160,104,106,51,128,179,208,157,125,234,164,17,
192,35,168,39,253,165,0,109,243,70,46,5,118,33,189,153,131,138,139,182,162,208,109,64,179,82,155,1,124,22,248,58,233,167,199,2,76,70,87,129,197,135,141,25,48,4,125,72,35,166,60,245,162,178,241,143,4,104,
103,71,109,6,48,2,248,21,176,98,128,246,12,212,152,242,223,1,218,230,95,217,27,56,151,244,45,192,160,241,110,199,161,54,239,226,169,205,0,134,0,55,16,83,18,12,174,7,232,20,81,243,29,64,115,0,63,140,134,
140,20,79,109,6,0,186,10,220,141,244,21,129,0,227,81,253,248,157,1,218,102,38,81,171,192,65,77,93,91,80,240,24,176,89,169,209,0,78,0,62,71,76,246,120,26,112,10,190,14,140,100,103,52,1,40,162,254,191,186,
219,156,26,13,96,55,224,103,164,95,20,210,143,143,1,177,252,16,85,117,70,132,255,175,163,53,114,71,7,104,103,73,141,6,176,28,112,35,113,121,128,23,81,85,224,229,65,250,53,243,22,100,176,81,191,187,137,
40,251,127,69,144,126,118,212,104,0,16,55,37,24,116,27,240,19,148,164,50,105,57,0,221,180,164,222,243,216,207,3,232,252,95,77,45,71,173,6,112,56,202,5,68,212,3,0,60,136,154,84,198,7,233,215,202,69,192,
94,196,24,119,47,240,91,96,116,128,118,182,212,106,0,27,1,127,2,222,26,164,255,50,90,42,121,102,144,126,141,172,15,252,25,88,51,72,255,21,52,61,250,180,32,253,44,169,213,0,64,219,124,182,37,166,148,180,
5,92,137,50,214,38,13,199,163,219,155,212,163,221,251,121,10,101,255,239,15,210,207,146,154,13,224,91,104,162,76,196,117,32,104,166,220,135,81,3,146,89,56,6,162,78,206,119,7,233,87,177,4,100,78,212,108,
0,59,0,23,16,51,31,0,52,74,234,231,40,113,101,22,142,253,209,113,42,98,152,11,232,250,239,219,104,6,64,85,212,108,0,139,160,178,224,45,137,57,6,0,60,141,218,74,31,9,210,175,133,171,209,0,208,168,223,211,
115,40,249,119,115,144,126,182,212,108,0,16,127,12,152,129,154,86,14,9,210,175,129,49,192,247,81,253,70,4,45,148,15,26,73,193,75,64,231,70,237,6,176,53,106,253,92,53,240,25,79,163,154,3,247,7,180,71,100,
178,22,52,254,235,68,212,38,94,29,181,27,0,192,85,168,77,56,234,13,54,3,21,30,141,9,210,47,153,79,2,223,36,174,240,7,52,253,103,79,224,222,192,103,100,139,13,0,190,136,106,191,83,47,14,157,149,241,168,
50,240,15,129,207,40,141,33,232,42,117,83,226,204,185,7,184,24,216,39,72,63,123,108,0,218,23,120,37,240,246,192,103,244,2,215,163,155,135,226,199,76,37,226,4,180,199,33,98,233,71,63,147,209,0,151,115,
3,159,145,53,54,0,113,14,106,224,137,88,26,210,207,84,244,166,62,41,240,25,165,176,9,42,203,93,59,240,25,45,52,87,96,4,21,213,254,207,142,13,64,140,66,13,60,67,131,159,243,48,170,54,123,60,248,57,77,231,
34,224,253,196,180,252,246,243,26,154,251,255,229,192,103,100,143,13,96,38,151,161,210,221,136,70,147,126,166,163,55,183,19,130,115,231,16,116,61,27,117,237,215,207,227,104,122,211,131,193,207,201,26,
27,192,76,14,66,211,124,162,223,120,19,81,226,241,127,131,159,211,68,214,68,137,210,141,137,75,252,129,140,248,124,52,34,190,106,108,0,51,25,140,42,206,134,19,251,230,107,1,247,161,182,214,199,2,159,211,
68,126,134,250,39,162,10,179,250,121,22,69,97,215,7,63,39,123,108,0,255,202,225,104,227,76,228,189,51,104,118,224,175,112,159,192,172,28,140,10,114,34,70,182,207,74,15,74,48,126,40,248,57,141,192,6,240,
175,12,65,185,128,205,137,141,2,64,163,195,142,68,219,138,106,103,109,148,27,137,188,243,239,231,31,40,244,191,44,248,57,141,192,6,240,70,62,7,28,67,124,20,208,127,20,216,3,173,23,175,153,31,163,107,216,
232,208,191,250,194,159,217,177,1,188,145,101,209,183,67,100,151,96,63,211,129,223,80,201,26,170,185,112,32,240,29,226,166,52,207,202,115,232,219,223,3,91,251,176,1,204,153,67,209,4,154,232,27,1,128,41,
104,21,213,41,29,120,86,110,172,141,204,118,125,58,99,182,191,70,145,134,233,195,6,48,103,22,65,111,204,145,196,108,18,158,157,191,163,172,244,77,29,120,86,46,12,64,255,198,59,210,153,127,227,113,40,210,
186,173,3,207,106,12,54,128,185,243,65,224,12,96,149,14,60,171,133,186,209,246,164,158,124,192,143,209,54,229,168,25,127,179,242,26,90,40,226,197,173,179,97,3,120,115,58,117,47,13,106,18,26,219,247,188,
113,29,120,94,55,249,1,186,2,93,178,3,207,106,1,119,163,186,139,90,204,117,190,177,1,188,57,239,68,189,252,157,56,163,130,178,212,127,3,62,133,54,224,148,198,96,84,1,57,154,184,157,12,179,51,9,221,234,
156,209,161,231,53,10,27,192,188,57,18,149,238,46,219,161,231,245,2,143,162,130,164,11,58,244,204,78,48,12,205,220,31,65,103,194,126,208,48,150,75,208,183,191,153,3,54,128,121,51,24,85,142,141,162,51,
201,42,80,216,250,15,212,167,126,100,135,158,25,201,222,192,215,128,13,137,237,240,155,157,71,129,127,167,174,228,234,2,97,3,152,63,134,3,231,1,235,116,248,185,47,163,97,37,159,167,185,147,133,191,129,
238,222,135,210,153,99,84,63,47,161,171,213,99,59,248,204,198,97,3,152,127,142,69,19,106,162,102,211,207,141,30,224,9,224,84,154,117,142,221,26,13,218,220,146,206,157,247,251,233,65,141,93,123,162,153,
255,102,46,216,0,230,159,78,215,6,204,206,84,148,24,60,17,189,185,115,101,53,180,96,99,111,180,116,37,114,190,194,220,120,18,69,29,215,116,225,217,141,194,6,176,96,12,71,87,131,235,118,233,249,189,168,
137,232,106,20,17,220,210,165,215,49,39,134,160,163,202,7,81,133,95,39,174,78,231,196,84,224,116,224,168,46,61,191,81,216,0,22,156,47,163,91,129,232,102,161,55,163,7,77,26,190,14,117,19,118,51,34,88,29,
141,239,222,27,229,72,34,135,120,206,139,30,180,139,113,55,212,114,109,230,129,13,160,61,46,65,227,195,58,153,209,158,19,61,192,63,129,123,80,59,237,47,128,9,29,120,238,32,116,43,242,17,96,27,20,246,119,
235,27,127,86,198,1,31,39,239,35,82,86,216,0,218,99,56,154,36,60,140,206,102,182,231,70,11,125,227,77,64,9,195,123,208,21,216,211,40,36,126,13,221,40,76,233,251,153,136,54,226,204,206,96,96,25,20,206,
175,136,42,245,150,235,251,115,37,116,244,89,15,253,189,135,246,253,255,110,156,241,231,196,20,116,44,58,166,219,47,164,73,216,0,218,231,112,116,28,88,161,219,47,100,14,244,162,232,96,70,223,79,15,50,
137,126,179,234,255,208,206,106,94,3,152,185,27,111,214,55,197,64,148,244,236,255,25,72,30,166,55,43,211,80,84,54,6,103,253,23,8,27,64,251,12,0,206,6,246,165,51,53,237,102,206,244,162,90,255,131,128,191,
118,249,181,52,14,27,192,194,177,22,50,129,237,136,93,42,98,230,76,11,120,10,101,252,75,42,155,238,24,54,128,133,103,56,170,113,223,132,238,212,7,212,204,243,192,119,209,2,81,211,6,54,128,52,236,6,156,
12,188,131,124,146,98,165,51,17,93,129,126,169,219,47,164,201,216,0,210,113,0,74,10,14,195,38,16,205,68,212,155,113,4,74,112,154,54,177,1,164,101,52,170,127,31,134,143,3,81,188,136,246,56,126,182,219,
47,164,4,108,0,233,217,7,56,26,216,136,238,23,10,149,68,11,157,249,207,70,255,190,38,1,54,128,24,182,66,107,192,183,160,115,195,47,74,166,23,85,249,157,134,138,125,76,34,108,0,113,172,137,214,79,239,76,
119,251,6,154,206,116,84,217,248,21,188,205,39,57,54,128,88,22,69,57,129,3,128,85,201,175,130,46,119,166,162,134,167,47,0,247,119,249,181,20,137,13,160,51,28,136,90,101,215,199,5,67,243,67,255,121,255,
124,116,179,226,206,190,32,108,0,157,99,99,180,109,104,123,212,112,99,230,204,52,224,1,116,124,250,105,151,95,75,241,216,0,58,203,98,104,150,192,254,168,119,222,183,4,51,105,161,251,253,171,208,177,233,
222,238,190,156,58,176,1,116,135,17,104,75,205,54,168,245,182,246,220,192,171,232,91,255,92,224,251,184,184,167,99,216,0,186,199,32,52,73,231,99,192,6,212,217,81,56,29,205,44,184,24,13,60,125,180,187,
47,167,62,108,0,221,103,53,224,51,104,164,214,90,212,81,55,208,3,188,128,50,252,167,1,55,119,247,229,212,139,13,32,31,134,161,99,193,40,52,103,175,68,35,232,65,165,188,183,162,101,157,151,118,247,229,
24,27,64,126,108,4,124,2,173,205,94,19,13,217,108,122,142,96,58,26,87,118,43,58,231,95,220,213,87,99,254,31,27,64,190,12,67,107,173,118,6,222,134,170,9,155,212,96,212,66,201,189,103,209,106,174,243,208,
150,35,147,17,54,128,252,89,6,229,7,246,68,67,71,134,162,77,59,57,154,65,47,186,199,127,17,173,50,187,22,77,43,246,149,94,166,216,0,154,197,70,104,51,209,240,190,255,30,138,86,149,45,74,231,135,117,182,
250,126,166,163,169,195,19,80,195,206,237,192,21,232,91,223,21,124,153,99,3,104,46,111,5,54,71,81,193,59,128,85,208,40,239,165,81,132,48,184,239,103,16,138,22,218,49,135,22,51,39,12,79,67,31,244,215,209,
226,205,23,209,114,146,199,129,251,208,150,162,7,219,254,219,152,174,96,3,40,135,37,144,1,172,2,44,15,44,133,70,150,175,134,110,21,214,64,187,250,134,160,154,131,193,204,28,243,13,250,144,79,71,31,240,
201,168,42,239,73,224,25,244,193,254,39,48,169,239,103,10,90,95,254,114,252,95,203,68,98,3,168,143,69,81,52,208,131,62,252,253,59,3,22,65,59,4,6,245,253,105,42,192,6,96,76,197,216,0,140,169,24,27,128,
49,21,99,3,48,166,98,108,0,198,84,140,13,192,152,138,177,1,24,83,49,54,0,99,42,198,6,96,76,197,216,0,140,169,24,27,128,49,21,99,3,48,166,98,108,0,198,84,140,13,192,152,138,177,1,24,83,49,54,0,99,42,198,
6,96,76,197,216,0,140,169,24,27,128,49,21,99,3,48,166,98,108,0,198,84,140,13,192,152,138,177,1,24,83,49,54,0,99,42,198,6,96,76,197,216,0,140,169,24,27,128,49,21,99,3,48,166,98,254,15,187,91,48,106,115,
103,12,160,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* PluginEditor::u_png = (const char*) resource_PluginEditor_u_png;
const int PluginEditor::u_pngSize = 8786;


//[EndFile] You can add extra defines here...
//[/EndFile]

