#include <math.h>

#define MAXIT 100  // 최대 반복 횟수

float my_muller(float (*func)(float), float x0, float x1, float x2, float xacc, int* it)
{
    void nrerror(char error_text[]);
    
    int iter;
    float h1, h2, d1, d2, a, b, c, rad, den, dxr, x3;
    float f0, f1, f2, xacc_squared;

    // 함수 값 계산
    f0 = (*func)(x0);
    f1 = (*func)(x1);
    f2 = (*func)(x2);

    xacc_squared = xacc * xacc;

    *it = 0;
    for (iter = 0; iter < MAXIT; iter++) {
        (*it)++;
        h1 = x1 - x0;
        h2 = x2 - x1;
        d1 = (f1 - f0) / h1;
        d2 = (f2 - f1) / h2;

        a = (d2 - d1) / (h2 + h1);
        b = a * h2 + d2;
        c = f2;

        rad = sqrt(b * b - 4 * a * c);

        if (fabs(b + rad) > fabs(b - rad)) {
            den = b + rad;
        } else {
            den = b - rad;
        }

        dxr = -2 * c / den;
        x3 = x2 + dxr;

        if (fabs(dxr) < xacc) return x3;

        // 함수 값 업데이트
        x0 = x1;
        x1 = x2;
        x2 = x3;
        f0 = f1;
        f1 = f2;
        f2 = (*func)(x2);
    }

    nrerror("Maximum number of iterations exceeded in Muller method");
    return 0.0;
}