#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "SynthVoice.h"

//==============================================================================
VocoderEditor::VocoderEditor (VocoderProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
	// Initialize colour
	picColor.fromRGB(0, 0, 0);

	// Load in images
	chooseYourWeapon = ImageCache::getFromMemory(BinaryData::ChooseYourWeapon_png, BinaryData::ChooseYourWeapon_pngSize);
	sawPic = ImageCache::getFromMemory(BinaryData::Saw_png, BinaryData::Saw_pngSize);
	squarePic = ImageCache::getFromMemory(BinaryData::Square_png, BinaryData::Square_pngSize);
	noisePic = ImageCache::getFromMemory(BinaryData::Noise_png, BinaryData::Noise_pngSize);
	sawOver = ImageCache::getFromMemory(BinaryData::SawOver_png, BinaryData::SawOver_pngSize);
	squareOver = ImageCache::getFromMemory(BinaryData::SquareOver_png, BinaryData::SquareOver_pngSize);
	noiseOver = ImageCache::getFromMemory(BinaryData::NoiseOver_png, BinaryData::NoiseOver_pngSize);
	sawDown = ImageCache::getFromMemory(BinaryData::SawDown_png, BinaryData::SawDown_pngSize);
	squareDown = ImageCache::getFromMemory(BinaryData::SquareDown_png, BinaryData::SquareDown_pngSize);
	noiseDown = ImageCache::getFromMemory(BinaryData::NoiseDown_png, BinaryData::NoiseDown_pngSize);


	squareWaveButton.setImages(false, true, true, squarePic, 1.0f, picColor, squareOver, 1.0f, picColor, squareDown, 1.0f, picColor);
	addAndMakeVisible(squareWaveButton);

	sawWaveButton.setImages(false, true, true, sawPic, 1.0f, picColor, sawOver, 1.0f, picColor, sawDown, 1.0f, picColor);
	addAndMakeVisible(sawWaveButton);

	noiseButton.setImages(false, true, true, noisePic, 1.0f, picColor, noiseOver, 1.0f, picColor, noiseDown, 1.0f, picColor);
	addAndMakeVisible(noiseButton);

	squareWaveButton.addListener(this);
	sawWaveButton.addListener(this);
	noiseButton.addListener(this);

    setSize (534, 321);
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
	squareWaveButton.setBounds(10, 216, (getWidth() / 3) - 20, getHeight() - 233);
	sawWaveButton.setBounds(30 + ((getWidth() / 3) - 20), 216, (getWidth() / 3) - 20, getHeight() - 233);
	noiseButton.setBounds(50 + 2*(((getWidth() / 3) - 20)), 216, (getWidth() / 3) - 20, getHeight() - 233);
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