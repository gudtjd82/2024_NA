#include <math.h>

// 케플러 방정식과 도함수 계산
// 케플러 방정식: E - e*sin(E) = M
// f(E) = E - e*sin(E) - M
// f'(E) = 1 - e*cos(E)
void kepler_funcd(float E, float *f, float *df) {
    float e = 0.7;  
    float M = 1.0; 

    *f = E - e * sin(E) - M;
    *df = 1 - e * cos(E);      // 도함수
}

float kepler(float E) {
    float e = 0.7;
    float M = 1.0;
    return E - e * sin(E) - M;
}