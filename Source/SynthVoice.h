/*
==============================================================================

SynthVoice.h
Created: 13 Jun 2018 7:56:44pm
Author:  dbayl

==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "SynthSound.h"
#include "maximilian.h"

class SynthVoice : public SynthesiserVoice

{

public:

	bool canPlaySound(SynthesiserSound * sound);

	//=======================================================

	void startNote(int midiNoteNumber, float velocity, SynthesiserSound *sound, int currentPitchWheelPosition);

	//=======================================================

	void stopNote(float velocity, bool allowTailOff);

	//=======================================================
	/*
	bool isVoiceActive();
	*/

	//=======================================================

	void pitchWheelMoved(int newPitchWheelValue);

	//=======================================================

	void controllerMoved(int controllerNumber, int newControllerValue);

	//=======================================================

	void aftertouchChanged(int newAftertouchValue);

	//=======================================================

	void channelPressureChanged(int newChannelPressureValue);

	//=======================================================

	void renderNextBlock(AudioBuffer< float > &outputBuffer, int startSample, int numSamples);

	//=======================================================

	void renderNextBlock(AudioBuffer< double > &outputBuffer, int startSample, int numSamples);

	//=======================================================

	void setCurrentPlaybackSampleRate(double newRate);

	//=======================================================

	/*
	bool isPlayingChannel (int midiChannel) const;
	*/

	//=======================================================

	enum waveType 
	{
		square,
		saw,
		noise
	};

	static void setWaveType(int waveform);


private:

	double level;
	double frequency;
	double theWave;

	maxiOsc osc1;
	maxiEnv env1;

	static int waveShape;

};