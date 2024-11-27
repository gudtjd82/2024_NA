float my_rtbis(float (*func)(float), float x1, float x2, float xacc, int* it);
float my_rtflsp(float (*func)(float), float x1, float x2, float xacc, int* it);
float my_rtsec(float (*func)(float), float x1, float x2, float xacc, int* it);
float my_rtnewt(float (*func)(float), float (*funcd)(float), float x1, float x2, float xacc, int* it);
float my_rtsafe(float (*func)(float), float (*dfunc)(float), float x1, float x2, float xacc, int* it);
float my_muller(float (*func)(float), float x0, float x1, float x2, float xacc, int* it);
void kepler_funcd(float E, float *f, float *df);
float kepler(float E);