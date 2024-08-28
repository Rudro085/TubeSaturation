

#include "twelveax7.h"
#include "math.h"

float twelveax7::get_Ip(float ip,float v1) {
    Ip = ip;
    V1 = v1;
    sec1 = sqrt(a1 * Ip * Ip - a2 * Ip + a3);
    sec2 = (V1 - R2 * Ip + Vct) / sec1;
    sec3 = exp(Kp * ((1. / Mu) + sec2));
    sec4 = log(1. + sec3);
    E1 = ((Vs - Req * Ip) / Kp) * sec4;
    ip = 0.;
    if (E1 >= 0) {
        ip = (2. / Kg) * powf(E1 ,Ex);
    }
    return ip;
    
}



float twelveax7::get_Dip() {
    DE1 = -Req * sec4 / Kp + (Vs - Req * Ip) * (sec3 / (1. + sec3)) * (-(R2 / sec1) - (V1 - R2 * Ip + Vct) * (2. * a1 * Ip - a2) / (2. * powf(sec1 ,3.)));
    DIp = 0.;
    if (E1 >= 0)  {
        DIp = (2. * Ex / Kg) * powf(E1 ,(Ex - 1.)) * DE1;
    }
    return DIp;
}