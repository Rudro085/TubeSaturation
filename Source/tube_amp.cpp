/*
  ==============================================================================

    tube_amp.cpp
    Created: 2 Aug 2024 4:30:54pm
    Author:  LENOVO

  ==============================================================================
*/

#include "tube_amp.h"

void tube_amp::setParam(float Gain, float Vol) {
    gain = powf(10.,-.1/Gain);
    Volume = Vol;
}

void tube_amp::prepare(double SampleRate, int SamplePerBlock) {
    sampleRate = SampleRate;
    T = 1. / sampleRate;
}

float tube_amp::solve(float Vin,twelveax7& tube) {
    Ip = tube.Ip_prev;
    
    int j = 0;
    while (j <= 20) {
        j++;
        Ip = tube.get_Ip(Ip, Vin);

        gip = tube.get_Dip();
        Ipeq = Ip - gip * Ip;
        Ip = gip * Ip + Ipeq;
        if (Ip >= 250. / 100000.) Ip = 250. / 100000.;
        if (abs(Ip - tube.Ip_prev) <= 0.000001) break;
        tube.Ip_prev = Ip;
    }
    tube.Ip_prev = Ip;
    float Vout1 = Ids - tube.R1 * Ip;
    float Vout2 = (gc2 * Vout1 - gc2 * tube.Vc_prev) / (gr3 + gc2);
    //if (abs(Vout2) >= 20) Vout2 = 20. * Vout2 / abs(Vout2);
    tube.Vc_prev = Vout1 - Vout2;
    return Vout2;
}

void tube_amp::process(juce::dsp::AudioBlock<float>& block) {
    for (int sample = 0;sample < block.getNumSamples();++sample) {
        x = (block.getSample(0, sample) + block.getSample(1, sample)) / 2.;
        x =  4.2*x;
        temp = solve(x, tube1)*0.02*6.*gain;
        y = solve(temp, tube2)*Volume/50;
        //y = temp;
        block.setSample(0, sample, y);
        block.setSample(1, sample, y);
    }
}