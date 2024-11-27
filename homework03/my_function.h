int gaussj(float **a, int n, float **b, int m);
int ludcmp(float **a, int n, int *indx, float *d);
void lubksb(float **a, int n, int *indx, float **b);
int svdcmp(float **a, int m, int n, float w[], float **v);
void svbksb(float **u, float w[], float **v, int m, int n, float **b, float **x);
void mprove(float **a, float **alud, int n, int indx[], float **b, float **x);
int parsing_lineq(char* path, int* n, float*** a, float*** b);
void print_matrix(float **a, int n);
void print_vector(float **b, int n);