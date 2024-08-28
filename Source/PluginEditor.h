/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class TubeSaturationAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    TubeSaturationAudioProcessorEditor (TubeSaturationAudioProcessor&);
    ~TubeSaturationAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    TubeSaturationAudioProcessor& audioProcessor;
    juce::Slider gainSlider;
    juce::Slider toneSlider;
    juce::Slider volumeSlider;

    juce::Label gainLabel;
    juce::Label toneLabel;
    juce::Label volumeLabel;

    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> gainAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> toneAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> volumeAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TubeSaturationAudioProcessorEditor)
};
