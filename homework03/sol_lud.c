#include <stdio.h>
#include <stdlib.h>
#include "nrutil.h"
#include "my_function.h"

int main()
{
    float **a1, **a2, **a3;
    float **b1, **b2, **b3;
    int n1, n2, n3;
    int *indx1, *indx2, *indx3;
    float d1, d2, d3, det1, det2, det3;

    char *path1 = "./lineq_dat/lineq1.dat";
    char *path2 = "./lineq_dat/lineq2.dat";
    char *path3 = "./lineq_dat/lineq3.dat";

    parsing_lineq(path1, &n1, &a1, &b1);
    parsing_lineq(path2, &n2, &a2, &b2);
    parsing_lineq(path3, &n3, &a3, &b3);

    indx1 = ivector(1, n1);
    indx2 = ivector(1, n2);
    indx3 = ivector(1, n3);

    printf("========LU Decomposition========\n");

    printf("Solving %s\n", path1);
    if (ludcmp(a1, n1, indx1, &d1) == 0)
    {
        det1 = d1;
        for(int i =1; i <= n1; i++)
        {
            det1 *= a1[i][i];
        }

        lubksb(a1, n1, indx1, b1);
        printf("Solution of %s:\n\t", path1);
        print_vector(b1, n1);

        printf("Determinant = %f\n", det1);
    }
    else
        printf("Determinant = 0\n");
    printf("=======================================\n");

    printf("Solving %s\n", path2);
    if (ludcmp(a2, n2, indx2, &d2) == 0)
    {
        det2 = d2;
        for(int i =1; i <= n2; i++)
        {
            det2 *= a2[i][i];
        }

        lubksb(a2, n2, indx2, b2);
        printf("Solution of %s:\n\t", path2);
        print_vector(b2, n2);

        printf("Determinant = %f\n", det2);
    }
    else
        printf("Determinant = 0\n");
    printf("=======================================\n");

    printf("Solving %s\n", path3);
    if (ludcmp(a3, n3, indx3, &d3) == 0)
    {
        det3 = d3;
        for(int i =1; i <= n3; i++)
        {
            det3 *= a3[i][i];
        }

        lubksb(a3, n3, indx3, b3);
        printf("Solution of %s:\n\t", path3);
        print_vector(b3, n3);

        printf("Determinant = %f\n", det3);
    }
    else
        printf("Determinant = 0\n");
    printf("=======================================\n");
    
    free_matrix(a1, 1, n1, 1, n1);
    free_matrix(a2, 1, n2, 1, n2);
    free_matrix(a3, 1, n3, 1, n3);

    free_matrix(b1, 1, n1, 1, 1);
    free_matrix(b2, 1, n2, 1, 1);
    free_matrix(b3, 1, n3, 1, 1);

    free_ivector(indx1, 1, n1);
    free_ivector(indx2, 1, n2);
    free_ivector(indx3, 1, n3);
    return 0;
}