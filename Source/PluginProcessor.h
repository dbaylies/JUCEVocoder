#pragma once
// For debugging in Visual Studio
#include <iostream>
// To recognize "PRId64" for timing; example found here: https://stackoverflow.com/questions/45980608/using-stdchronodurationrep-with-printf-in-32bit-and-64bit-programs
#include <cinttypes>
// For timing
#include <chrono>
// for OutputDebugString()
#include <windows.h>
#include <stdio.h>
// For sin(), pow(), sqrt() - maybe only need cmath
#include <math.h>
#include <cmath>
#define PI 3.14159265
#include "../JuceLibraryCode/JuceHeader.h"
#include "SynthSound.h"
#include "SynthVoice.h"


//==============================================================================
/**
*/
class VocoderProcessor  : public AudioProcessor
					
{
public:
    //==============================================================================
    VocoderProcessor();
    ~VocoderProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

	float* vocode(float* modulator, float* carrier);

	void smoothSpectrum();

	void getMagnitudeOfInterleavedComplexArray(float* array);

	void multiplyBySineEnvelope(float* carrier);

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

	enum
	{
		// Change order to lower the latency
		fftOrder = 10,
		fftSize = 1 << fftOrder
	};

private:
	// Synthesizer objects
    Synthesiser mySynth;
    SynthVoice* myVoice;
    
    double lastSampleRate;
	// Stores output of synthesizer
	AudioBuffer<float> tempBuf;
	// The actual FFT objects
	dsp::FFT fftAudio, fftMIDI, fftInverse;
	// Gets passed through FFT and stores output
	float fftAudioTemp[fftSize], fftMIDITemp[fftSize];
	float fftAudioOut[fftSize * 2], fftMIDIOut[fftSize * 2];
	float outStore[fftSize];
	float signalMag[fftSize];
	float fftAudioEnv[fftSize];
	// Experimenting with queues (adapting deque containers by default)
	std::queue<float> audioInputQueue, midiInputQueue, fftOutputQueue;
	// 1024-point sine envelope
	double sinenv[fftSize];
	// OLA output
	float sendOut;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (VocoderProcessor)
};
