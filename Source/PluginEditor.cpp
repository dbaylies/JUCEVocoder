#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "SynthVoice.h"

//==============================================================================
VocoderEditor::VocoderEditor (VocoderProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
	addAndMakeVisible(squareWaveButton);
	squareWaveButton.setButtonText("Square Wave");

	addAndMakeVisible(sawWaveButton);
	sawWaveButton.setButtonText("Saw Wave");

	addAndMakeVisible(noiseButton);
	noiseButton.setButtonText("NoisyBoy");

	squareWaveButton.addListener(this);
	sawWaveButton.addListener(this);
	noiseButton.addListener(this);

    setSize (400, 300);

}

VocoderEditor::~VocoderEditor()
{
}

//==============================================================================
void VocoderEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (15.0f);
}

void VocoderEditor::resized()
{
	squareWaveButton.setBounds(10, 10, getWidth() - 20, 40);
	sawWaveButton.setBounds(10, 60, getWidth() - 20, 40);
	noiseButton.setBounds(10, 110, getWidth() - 20, 40);
}

void VocoderEditor::buttonClicked(Button* button)
{
	if (button == &squareWaveButton)
		SynthVoice::setWaveType(SynthVoice::square);
	else if (button == &sawWaveButton)
		SynthVoice::setWaveType(SynthVoice::saw);
	else if (button == &noiseButton)
		SynthVoice::setWaveType(SynthVoice::noise);
	else
		SynthVoice::setWaveType(SynthVoice::square);
}