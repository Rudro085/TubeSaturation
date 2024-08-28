/*
  ==============================================================================

    tube_amp.h
    Created: 2 Aug 2024 4:30:54pm
    Author:  LENOVO

  ==============================================================================
*/

#pragma once
#include<JuceHeader.h>
#include "twelveax7.h"

class tube_amp {
public:
    void prepare(double SampleRate, int SamplePerBlock);
    void process(juce::dsp::AudioBlock<float>& block);
    void setParam(float Gain, float Vol);
private:
    float sampleRate = 48000;
    float T = 1. / sampleRate;
    float C2 = .02 / 1000000.;
    float R3 = 1000000.;
    float gr3 = 1. / R3;
    float gc2 = C2 / T;
    float Ids = 250.;
    float solve(float Vin,twelveax7& tube);
    twelveax7 tube1,tube2;
    float Ip,gip,Ipeq,x,y,temp;
    float gain = 0.8; 
    float Volume = .5;

};