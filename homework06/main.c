#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "nrutil.h"
#include "my_function.h"

#define NPT 77  // Num of Points
#define SPREAD 0.1      // for sigma
#define NTERM 3  // Num of Terms

void funcs(float *input, float *afunc, int ma)
{
    afunc[1] = input[1];    // x
    afunc[2] = input[2];    // y
    afunc[3] = 1.0;    
}

int main(int argc, char *argv[])
{
    char* path;
    float **input, **output, **a, **sig, **covar, chisq;
    int **ia, i, j, t=0;

    ia = imatrix(1, NTERM, 1, 2);
    a = matrix(1, NTERM, 1, 2);
    sig = matrix(1, NPT, 1, 2);
    covar = matrix(1, NTERM, 1, NTERM);

    // parsing data file
    if (argc < 2)
    {
        printf("ERROR: No data file!\n");
        return 0;
    }
    path = argv[1];
    parsing_data(path, &input, &output, NPT);
    // print_matrix(input, NPT, 2);
    for(i=1; i <= NPT; i++)
    {
        sig[i][1] = SPREAD;
        sig[i][2] = SPREAD;
    }
    for (i = 1; i <= NTERM; i++)
    {
        ia[i][1] = 1;
        ia[i][2] = 1;
    }

    lfit(input, output, sig, NPT, a, ia, NTERM, covar, &chisq, funcs);

    printf("\n%11s %21s\n","parameter","uncertainty");
	for (i=1;i<=NTERM;i++)
		printf("  a[%1d] = %8.6f %12.6f\n",
			i,a[i][1],sqrt(covar[i][i]));
	for (i=1;i<=NTERM;i++)
		printf("  a[%1d] = %8.6f %12.6f\n",
			i+3,a[i][2],sqrt(covar[i][i]));

    free_imatrix(ia, 1, NTERM, 1, 2);
    free_matrix(a, 1, NTERM, 1, 2);
    free_matrix(sig, 1, NPT, 1, 2);
    free_matrix(covar, 1, NTERM, 1, NTERM);

    return 0;

}