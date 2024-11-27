#include <stdio.h>
#include <stdlib.h>
#include "nrutil.h"

int parsing_data(char* path, float*** input, float*** output, int rows)
{
    FILE *file;

    file = fopen(path, "r");
    if (file == NULL)
    {
        printf("Error: Could not open file\n");
        return -1;
    }

    *input = matrix(1, rows, 1, 2);
    *output = matrix(1, rows, 1, 2);

    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= 2; j++)
            fscanf(file, "%f", &(*input)[i][j]);
        for (int j = 3; j <= 4; j++)
            fscanf(file, "%f", &(*output)[i][j-2]);
    }
    fclose(file);

    return 1;
}

void print_matrix(float **a, int rows, int cols)
{
    printf("===================Matrix===================\n");
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            printf("%f ", a[i][j]);
        }
        printf("\n");
    }
}

void print_vector(float **b, int n)
{
    // printf("===================Vector===================\n");
    for (int i = 1; i <= n; i++) {
        printf("%f ", b[i][1]);
    }
    printf("\n");
}
