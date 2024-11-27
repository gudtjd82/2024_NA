#include <stdio.h>
#include <stdlib.h>
#include "nrutil.h"
#include "my_function.h"

int main()
{
    float **a1, **a2, **a3;
    float **b1, **b2, **b3;
    int n1, n2, n3;

    char *path1 = "./lineq_dat/lineq1.dat";
    char *path2 = "./lineq_dat/lineq2.dat";
    char *path3 = "./lineq_dat/lineq3.dat";

    parsing_lineq(path1, &n1, &a1, &b1);
    parsing_lineq(path2, &n2, &a2, &b2);
    parsing_lineq(path3, &n3, &a3, &b3);

    printf("========Gauss-Jordan Elimination========\n");

    printf("Solving %s\n", path1);
    if (gaussj(a1, n1, b1, 1) == 0)
    {
        printf("Solution of %s:\n\t", path1);
        print_vector(b1, n1);
    }
    printf("=======================================\n");

    printf("Solving %s\n", path2);
    if (gaussj(a2, n2, b2, 1) == 0)
    {
        printf("Solution of %s:\n\t", path2);
        print_vector(b2, n2);
    }
    printf("=======================================\n");

    printf("Solving %s\n", path3);
    if (gaussj(a3, n3, b3, 1) == 0)
    {
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
    return 0;
}