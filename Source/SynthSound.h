/*
  ==============================================================================

    SynthSound.h
    Created: 13 Jun 2018 7:56:37pm
    Author:  dbayl

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class SynthSound : public SynthesiserSound
{
public:
	bool appliesToNote(int midiNoteNumber);
    
	bool appliesToChannel(int midiChannel);
};