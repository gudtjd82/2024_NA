#include <stdio.h>
#include "nr.h"
#include "my_function.h"

int main()
{
    int nb = 5, n = 100, i, it = 0;
    float x1 = 1.0, x2 = 10.0, x_mid; 
    float rt, xacc = 0.000001;
    float xb1[nb+1], xb2[nb+1];

    // 근이 포함된 구간 찾기
    zbrak(bessj0, x1, x2, n, xb1, xb2, &nb);
    printf("구간의 수: %d\n", nb);
    for(i=1; i <= nb; i++)
    {
        printf("%d번째 구간: [%f, %f]\n", i, xb1[i], xb2[i]);
    }

    // Bisection Method
    printf("=====Bisection Method===================================\n");
    for(i=1; i<=nb; i++)
    {
        rt = my_rtbis(bessj0, xb1[i], xb2[i], xacc, &it);
        printf("root found by Bisection: %f, iteration:%d\n", rt, it);
        it = 0;
    }
    printf("========================================================\n");

    // Linear interpolation method
    printf("====Linear interpolation Method=========================\n");
    for(i=1; i<=nb; i++)
    {
        rt = my_rtflsp(bessj0, xb1[i], xb2[i], xacc, &it);
        printf("root found by Linear interpolation: %f, iteration:%d\n", rt, it);
        it = 0;
    }
    printf("========================================================\n");

    // Secant method
    printf("====Secant Method=======================================\n");
    for(i=1; i<=nb; i++)
    {
        rt = my_rtsec(bessj0, xb1[i], xb2[i], xacc, &it);
        printf("root found by Secant: %f, iteration:%d\n", rt, it);
        it = 0;
    }
    printf("========================================================\n");
    
    // Newton-Raphson method
    printf("====Newton-Raphson Method===============================\n");
    for(i=1; i<=nb; i++)
    {
        rt = my_rtnewt(bessj0, bessj1, xb1[i], xb2[i], xacc, &it);
        printf("root found by Newton-Raphson: %f, iteration:%d\n", rt, it);
        it = 0;
    }
    printf("========================================================\n");

    // Newton with braketing
    printf("====Newton with braketing Method===============================\n");
    for(i=1; i<=nb; i++)
    {
        rt = my_rtsafe(bessj0, bessj1, xb1[i], xb2[i], xacc, &it);
        printf("root found by Newton with braketing: %f, iteration:%d\n", rt, it);
        it = 0;
    }
    printf("========================================================\n");
    
    // Muller method
    printf("====Muller Method===============================\n");
    for(i=1; i<=nb; i++)
    {
        x_mid = (xb1[i] + xb2[i]) / 2.0 ;
        rt = my_muller(bessj0, xb1[i], x_mid, xb2[i], xacc, &it);
        printf("root found by muller: %f, iteration:%d\n", rt, it);
        it = 0;
    }
    printf("========================================================\n");

    printf("\n");
    // Newton with braketing for kepler eq.
    zbrak(kepler, x1, x2, n, xb1, xb2, &nb);
    printf("구간의 수: %d\n", nb);
    for(i=1; i <= nb; i++)
    {
        printf("%d번째 구간: [%f, %f]\n", i, xb1[i], xb2[i]);
    }
    printf("====Nonlinear Equation ===============================\n");
    // x1 = 0.0;
    // x2 = 2.0;
    for(i=1; i<=nb; i++)
    {
        rt = rtsafe(kepler_funcd, xb1[i], xb2[i], xacc);
        printf("root found by rtsafe: %f\n", rt);
    }
    printf("========================================================\n");

    return 0;
}