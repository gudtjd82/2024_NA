#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "nrutil.h"
#include "my_function.h"

float uniform_random(float a, float b, long *idum)
{
    return ran1(idum) * (b-a) + a;
}

float gaussian_random(float m, float s, long *idum)
{
    return gasdev(idum) * s + m;
}

int main(int argc, char *argv[])
{
    float uniform_num, gaussian_num;
    long idum = -time(NULL);
    float a = -3, b = 4, m=0.5, s=1.5;
    int num_of_samples;

    char* uniform_file_name = "./uniform_nums.txt";
    char* gaussian_file_name = "./gaussian_nums.txt";
    
    if (argc < 2)
    {
        printf("Error: No sample numbers!\n");
        return 0;
    }

    num_of_samples = atoi(argv[1]);

    // generate uniform random numbers
    FILE *fp_uniform;

    fp_uniform = fopen(uniform_file_name, "w");
    if (fp_uniform == NULL)
    {
        printf("Error: opening file\n");
        return 1;
    }

    for (int i = 0; i < num_of_samples; i++)
    {
        uniform_num = uniform_random(a, b, &idum);
        if (uniform_num < a || uniform_num >b)
        {
            printf("Error: Uniform num is out of range!\n");
            fclose(fp_uniform);
            return 1;
        }
        if (i == num_of_samples-1)
            fprintf(fp_uniform, "%f", uniform_num);
        else
            fprintf(fp_uniform, "%f\n", uniform_num);
    }
    fflush(fp_uniform);
    fclose(fp_uniform);

    // generate Gaussian random numbers
    FILE *fp_gaussian;

    fp_gaussian = fopen(gaussian_file_name, "w");
    if (fp_gaussian == NULL)
    {
        printf("Error: opening file\n");
        return 1;
    }

    for (int i = 0; i < num_of_samples; i++)
    {
        gaussian_num = gaussian_random(m, s, &idum);
        if (i == num_of_samples-1)
            fprintf(fp_gaussian, "%f", gaussian_num);
        else
            fprintf(fp_gaussian, "%f\n", gaussian_num);
    }
    fflush(fp_gaussian);
    fclose(fp_gaussian);

    return 0;
}