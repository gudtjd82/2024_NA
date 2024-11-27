#include <stdio.h>
#include <stdlib.h>
#include "nrutil.h"

int parsing_lineq(char* path, int* n, float*** a, float*** b)
{
    FILE *file;
    int size;

    file = fopen(path, "r");
    if (file == NULL)
    {
        printf("Error: Could not open file\n");
        return -1;
    }

    fscanf(file, "%d", n);
    fscanf(file, "%d", n);
    size = *n;

    *a = matrix(1, size, 1, size);
    *b = matrix(1, size, 1, 1);

    for (int i = 1; i <= size; i++)
        for (int j = 1; j <= size; j++)
            fscanf(file, "%f", &(*a)[i][j]);

    for (int i =1; i <= size; i++)
        fscanf(file, "%f", &(*b)[i][1]);

    fclose(file);

    return 1;
}

void print_matrix(float **a, int n)
{
    // printf("===================Matrix===================\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
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
