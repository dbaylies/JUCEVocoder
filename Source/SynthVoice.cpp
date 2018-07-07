/*
==============================================================================

SynthVoice.cpp
Created: 2 July 2018
Author:  dbayl

==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "SynthSound.h"
#include "SynthVoice.h"
#include "maximilian.h"


// Must initialize static variable outside of class definition
int SynthVoice::waveShape = square;

bool SynthVoice::canPlaySound(SynthesiserSound * sound)
{
	return dynamic_cast<SynthSound*>(sound) != nullptr;
}

//=======================================================

void SynthVoice::startNote(int midiNoteNumber, float velocity, SynthesiserSound *sound, int currentPitchWheelPosition)
{
	env1.trigger = 1;
	// velocity is between 0.0 and 1.0
	level = velocity;
	frequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
}

//=======================================================

void SynthVoice::stopNote(float velocity, bool allowTailOff)
{
	env1.trigger = 0;
	allowTailOff = true;
	if (velocity == 0)
		clearCurrentNote();

}

//=======================================================
/*
bool SynthVoice::isVoiceActive()
{
}
*/

//=======================================================

void SynthVoice::pitchWheelMoved(int newPitchWheelValue)
{
}

//=======================================================

void SynthVoice::controllerMoved(int controllerNumber, int newControllerValue)
{
}

//=======================================================

void SynthVoice::aftertouchChanged(int newAftertouchValue)
{
}

//=======================================================

void SynthVoice::channelPressureChanged(int newChannelPressureValue)
{
}

//=======================================================

void SynthVoice::renderNextBlock(AudioBuffer< float > &outputBuffer, int startSample, int numSamples)
{

	env1.setAttack(200);
	env1.setDecay(500);
	env1.setSustain(0.8);
	env1.setRelease(200);

	for (int sample = 0; sample < numSamples; ++sample)
	{
		switch (waveShape) {
			case square: 
				theWave = osc1.square(frequency);
				break;
			case saw: 
				// Would like to use bandlimited sawn() but it throws an exception
				theWave = osc1.saw(frequency);
				break;
			case noise:
				theWave = osc1.noise();
				break;
			default:
				square: theWave = osc1.square(frequency);
		}

		double theSound = env1.adsr(theWave, env1.trigger) * level;

		for (int channel = 0; channel < outputBuffer.getNumChannels(); ++channel)
		{
			outputBuffer.addSample(channel, startSample, theSound);

		}
		++startSample;
	}

}

//=======================================================

void SynthVoice::renderNextBlock(AudioBuffer< double > &outputBuffer, int startSample, int numSamples)
{
}

//=======================================================

void SynthVoice::setCurrentPlaybackSampleRate(double newRate)
{
}

//=======================================================

/*
bool SynthVoice::isPlayingChannel (int midiChannel) const
{
}
*/

//=======================================================

void SynthVoice::setWaveType(int waveform)
{
	waveShape = waveform;
}