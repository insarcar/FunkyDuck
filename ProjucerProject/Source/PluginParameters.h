#pragma once
#include<JuceHeader.h>

#define MS2SEC 0.001f
#define PARAM_SCALE 12.0f
//==============COMPRESSION============================
#define NAME_COMPRESSION "compression"
#define MIN_COMPRESSION 0.0f
#define MAX_COMPRESSION 1.0f
#define DEFAULT_COMPRESSION 0.0f
#define DEFAULT_THRESHOLD 1.0f
#define COEFF_A -0.999999f
#define COEFF_B -15.0f
#define COEFF_C -0.55f
#define RATIO_CONVERSION 0.75f
//==============LEVEL==================================
#define NAME_LEVEL "level"
#define MIN_LEVEL 0.0f
#define MAX_LEVEL 1.0f
#define DEFAULT_LEVEL 0.0f
//==============FACTOR SWITCH==========================
#define NAME_FACTORSWITCH "facswitch"
#define DEFAULT_FACTORSWITCH 0
//==============TIME SCALE=============================
#define NAME_TIMESCALE "timescale"
#define MIN_TIMESCALE -0.5f
#define MAX_TIMESCALE 0.5f
#define DEFAULT_TIMESCALE 0.0f
//==============INSTRUMENT=============================
#define NAME_INSTRUMENT "instrument"
#define DEFAULT_INSTRUMENT 0
//==============KNEE===================================
#define NAME_KNEE "knee"
#define DEFAULT_KNEE 0
#define SOFT_KNEE 12.0f
#define ALPHA_TIME 0.04f
//==============ACTIVE=================================
#define NAME_ACTIVE "active"
#define DEFAULT_ACTIVE 1
//==============FACTOR SCALING=========================
#define CREST_SCALE 3.0f
#define COBE_RMS_SCALE 10.0f
#define COBE_PEAK_SCALE 5.0f
//==============FOLLOWER===============================
#define RESOLUTION 10.0f
//==============AUTO AR FILTER=========================
#define GUITAR_MIN_ATK 40.0f
#define GUITAR_MIN_REL 80.0f
#define GUITAR_MAX_ATK 100.0f
#define GUITAR_MAX_REL 240.0f
#define BASS_MIN_ATK 60.0f
#define BASS_MIN_REL 120.0f
#define BASS_MAX_ATK 120.0f
#define BASS_MAX_REL 280.0f
//==============SOFT CLIP==============================
#define LENGTH 1
#define HARDNESS 2
//==============HPF====================================
#define QUALITY 0.7071f
#define DEFAULT_FREQ 25.0 //frequenza di taglio del butter
//==============PARAMETER SMOOTHING====================
#define SMOOTHING_RAMP 0.03f
//==============VU METER===============================
#define TIMER 50.0f //ms
#define DB_MAX 12.0f
#define DB_FLOOR -48.0f
#define DECAY_TARGET 0.267f
#define DEFAULT_RELEASE 0.5f

const auto factorChoices = StringArray{ "crest", "cobe_rms","cobe_peak" };
const auto instrumentChoices = StringArray{ "guitar", "bass" };
const auto kneeChoices = StringArray{ "hard", "soft", "auto" };

static AudioProcessorValueTreeState::ParameterLayout  createParameterLayout()
{
	std::vector<std::unique_ptr<RangedAudioParameter>> params;

    params.push_back(std::make_unique<AudioParameterFloat>(NAME_COMPRESSION, "Compression", NormalisableRange<float>(MIN_COMPRESSION, MAX_COMPRESSION, 0.001f, 0.9f), DEFAULT_COMPRESSION));
    params.push_back(std::make_unique<AudioParameterFloat>(NAME_LEVEL, "Makeup Level", NormalisableRange<float>(MIN_LEVEL, MAX_LEVEL, 0.001f), DEFAULT_LEVEL));
    params.push_back(std::make_unique<AudioParameterFloat>(NAME_TIMESCALE, "Time scale", NormalisableRange<float>(MIN_TIMESCALE, MAX_TIMESCALE, 0.01f), DEFAULT_TIMESCALE));
    params.push_back(std::make_unique<AudioParameterChoice>(NAME_FACTORSWITCH, "Factor Switch", factorChoices, DEFAULT_FACTORSWITCH));
    params.push_back(std::make_unique<AudioParameterChoice>(NAME_INSTRUMENT, "Instrument Switch", instrumentChoices, DEFAULT_INSTRUMENT));
    params.push_back(std::make_unique<AudioParameterChoice>(NAME_KNEE, "Knee Switch", kneeChoices, DEFAULT_KNEE));
    params.push_back(std::make_unique<AudioParameterBool>(NAME_ACTIVE, "Active Switch", DEFAULT_ACTIVE));


	return { params.begin(), params.end() };
};