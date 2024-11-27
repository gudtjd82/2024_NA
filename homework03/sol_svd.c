#include <stdio.h>
#include <stdlib.h>
#include "nrutil.h"
#include "my_function.h"

int main()
{
    float **a1, **a2, **a3;
    float **b1, **b2, **b3;
    int n1, n2, n3;
    float *w1, *w2, *w3, **v1, **v2, **v3;

    char *path1 = "./lineq_dat/lineq1.dat";
    char *path2 = "./lineq_dat/lineq2.dat";
    char *path3 = "./lineq_dat/lineq3.dat";

    parsing_lineq(path1, &n1, &a1, &b1);
    parsing_lineq(path2, &n2, &a2, &b2);
    parsing_lineq(path3, &n3, &a3, &b3);

    w1 = vector(1, n1);
    v1 = matrix(1, n1, 1, n1);

    w2 = vector(1, n2);
    v2 = matrix(1, n2, 1, n2);

    w3 = vector(1, n3);
    v3 = matrix(1, n3, 1, n3);

    printf("========Singular Value Decomposition========\n");

    printf("Solving %s\n", path1);
    if (svdcmp(a1, n1, n1, w1, v1) == 0)
    {
        svbksb(a1, w1, v1, n1, n1, b1, b1);
        printf("Solution of %s:\n\t", path1);
        print_vector(b1, n1);
    }
    printf("=======================================\n");

    printf("Solving %s\n", path2);
    if (svdcmp(a2, n2, n2, w2, v2) == 0)
    {
        svbksb(a2, w2, v2, n2, n2, b2, b2);
        printf("Solution of %s:\n\t", path2);
        print_vector(b2, n2);
    }
    printf("=======================================\n");

    printf("Solving %s\n", path3);
    if (svdcmp(a3, n3, n3, w3, v3) == 0)
    {
        svbksb(a3, w3, v3, n3, n3, b3, b3);
        printf("Solution of %s:\n\t", path3);
        print_vector(b3, n3);
    }
    printf("=======================================\n");

    free_matrix(a1, 1, n1, 1, n1);
    free_matrix(a2, 1, n2, 1, n2);
    free_matrix(a3, 1, n3, 1, n3);

    free_matrix(b1, 1, n1, 1, 1);
    free_matrix(b2, 1, n2, 1, 1);
    free_matrix(b3, 1, n3, 1, 1);

    free_vector(w1, 1, n1);
    free_vector(w2, 1, n2);
    free_vector(w3, 1, n3);
    
    free_matrix(v1, 1, n1, 1, n1);
    free_matrix(v2, 1, n2, 1, n2);
    free_matrix(v3, 1, n3, 1, n3);
    return 0;
}