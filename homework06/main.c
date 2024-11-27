#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "nrutil.h"
#include "my_function.h"

#define NPT 77  // Num of Points
#define SPREAD 0.1      // sigma

void funcs(float *input, float *afunc, int ma)
{
    afunc[1] = input[0];    // x
    afunc[2] = input[1];    // y
    afunc[3] = 1.0;    
}

int main(int argc, char *argv[])
{
    char* path;
    float **input, **output, **sig, **a, **covar;
    int **ia, ma=3;

    a = matrix(1, ma, 1, 2);
    ia = imatrix(1, ma, 1, 2);

    // parsing data file
    if (argc < 2)
    {
        printf("ERROR: No data file!\n");
        return 0;
    }
    path = argv[1];
    parsing_data(path, &input, &output);
    sig = matrix(1, NPT, 1, 2);

    for(int i=1; i < NPT; i++)
    {
        sig[i][1] = SPREAD;
        sig[i][2] = SPREAD;
    }

    // print_matrix(input, 77, 2);s

    return 0;

}