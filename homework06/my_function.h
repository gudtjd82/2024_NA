void lfit(float x[], float y[], float sig[], int ndat, float a[], int ia[],
	int ma, float **covar, float *chisq, void (*funcs)(float, float [], int));
int parsing_data(char* path, float*** input, float*** output);
void print_matrix(float **a, int rows, int cols);