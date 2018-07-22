/*
==============================================================================

SynthSound.h
Created: 13 Jun 2018 7:56:37pm
Author:  dbayl

==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "SynthSound.h"

bool SynthSound::appliesToNote(int midiNoteNumber)
{
	// Test Change
	return true;
}

bool SynthSound::appliesToChannel(int midiChannel)
{
	return true;
}
