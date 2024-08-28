/*
  ==============================================================================

    twelveax7.h
    Created: 2 Aug 2024 4:30:12pm
    Author:  LENOVO

  ==============================================================================
*/

#pragma once
class twelveax7 {
public:
   
    float get_Ip(float ip,float v1);
    float get_Dip();
    float Ip_prev = 0.;
    float Vc_prev = 214.57;
    float R1 = 100000.;

private:
    float Mu = 100.;
    float Ex = 1.45;
    float Kg = 1.695 * 10000.; //1060. * 1000;
    float Kp = 700.;
    float Kvb = 750.;
    float kvb2 = -5.;
    float Vct = 0.525;
    //circuit parameters
    float Vs = 250.;
    float R2 = 1500.;
    float R3 = 1000000.;
    

    //constants
    float Req = R1 + R2;
    float a1 = Req * Req;
    float a2 = 2. * Vs * Req + kvb2 * Req;
    float a3 = Kvb + Vs * Vs + kvb2 * Vs;

    //temporary 
    float Ip, sec1, sec2, sec3, sec4, E1, DE1, DIp,V1;
    
};
