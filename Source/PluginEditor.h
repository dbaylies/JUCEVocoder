#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "SynthVoice.h"

//==============================================================================
/**
*/
class VocoderEditor  : public AudioProcessorEditor,
											   public Button::Listener
{
public:
	VocoderEditor(VocoderProcessor&);
    ~VocoderEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

	void buttonClicked(Button* button) override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    VocoderProcessor& processor;

	TextButton squareWaveButton;
	TextButton sawWaveButton;
	TextButton noiseButton;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (VocoderEditor)
};
