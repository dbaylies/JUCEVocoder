#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "SynthVoice.h"

//==============================================================================
VocoderEditor::VocoderEditor (VocoderProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
	picColor.fromRGB(0, 0, 0);

	chooseYourWeapon = ImageCache::getFromMemory(BinaryData::ChooseYourWeapon_png, BinaryData::ChooseYourWeapon_pngSize);
	sawPic = ImageCache::getFromMemory(BinaryData::Saw_png, BinaryData::Saw_pngSize);
	squarePic = ImageCache::getFromMemory(BinaryData::Square_png, BinaryData::Square_pngSize);
	noisePic = ImageCache::getFromMemory(BinaryData::Noise_png, BinaryData::Noise_pngSize);

	addAndMakeVisible(squareWaveButton);
	squareWaveButton.setImages(false, true, true, squarePic, 1.0f, picColor, squarePic, 1.0f, picColor, squarePic, 1.0f, picColor);

	addAndMakeVisible(sawWaveButton);
	sawWaveButton.setImages(false, true, true, sawPic, 1.0f, picColor, sawPic, 1.0f, picColor, sawPic, 1.0f, picColor);

	addAndMakeVisible(noiseButton);
	noiseButton.setImages(false, true, true, noisePic, 1.0f, picColor, noisePic, 1.0f, picColor, noisePic, 1.0f, picColor);

	squareWaveButton.addListener(this);
	sawWaveButton.addListener(this);
	noiseButton.addListener(this);

    setSize (495, 450);
}

VocoderEditor::~VocoderEditor()
{
}

//==============================================================================
void VocoderEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
	g.drawImageAt(chooseYourWeapon, 0, 0);
    g.setColour (Colours::white);
    g.setFont (15.0f);
}

void VocoderEditor::resized()
{
	squareWaveButton.setBounds(10, 286, (getWidth() / 3) - 20, getHeight() - 296);
	sawWaveButton.setBounds(30 + ((getWidth() / 3) - 20), 286, (getWidth() / 3) - 20, getHeight() - 296);
	noiseButton.setBounds(50 + 2*(((getWidth() / 3) - 20)), 286, (getWidth() / 3) - 20, getHeight() - 296);
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