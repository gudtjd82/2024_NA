
#define NRANSI
#include "nrutil.h"

void lfit(float **input, float **output, float **sig, int ndat, float **a, int **ia,
	int ma, float **covar, void (*funcs)(float*, float**, int))
{
	void covsrt(float **covar, int ma, int ia[], int mfit);
	void gaussj(float **a, int n, float **b, int m);
	int i,j,k,l,m,*mfit;
	float *ym,wt,sum,*sig2i,**beta,*afunc;
	
	mfit = ivector(1, 2);
	mfit[1] = 0;
	mfit[2] = 0;

	beta=matrix(1,ma,1,2);
	afunc=vector(1,ma);
	ym = vector(1, 2);		// for output
	sig2i = vector(1, 2);
	for (j=1;j<=ma;j++)
	{
		if (ia[j][1]) mfit[1]++;	// for x'
		if (ia[j][2]) mfit[2]++;	// for y'
	}
	if (mfit[1] == 0 && mfit[2] == 0) nrerror("lfit: no parameters to be fitted");
	for (j=1;j<=mfit[1];j++) {
		for (k=1;k<=mfit[1];k++) covar[j][k]=0.0;
		beta[j][1]=0.0;
		beta[j][2]=0.0;
	}
	for (j=1;j<=mfit[1];j++) {
		for (k=1;k<=mfit;k++) covar[j][k]=0.0;
		beta[j][1]=0.0;
	}
	for (i=1;i<=ndat;i++) {
		(*funcs)(input[i],afunc,ma);
		ym[1]=output[i][1];		// x'
		ym[2]=output[i][2];		// y'
		if (mfit < ma) {
			for (j=1;j<=ma/2;j++)
			{
				if (!ia[j]) ym[1] -= a[j]*afunc[j];
				if (!ia[j+3]) ym[2] -= a[j+3]*afunc[j];
			}
		}
		// weighted least-square (Chi-Square Fitting)
		sig2i[1]=1.0/SQR(sig[i][1]);
		sig2i[2]=1.0/SQR(sig[i][2]);
		for (j=0,l=1;l<=ma;l++) {
			if (ia[l]) {
				wt=afunc[l]*sig2i;
				for (j++,k=0,m=1;m<=l;m++)
					if (ia[m]) covar[j][++k] += wt*afunc[m];
				beta[j][1] += ym*wt;
			}
		}
	}
	for (j=2;j<=mfit;j++)
		for (k=1;k<j;k++)
			covar[k][j]=covar[j][k];
	gaussj(covar,mfit,beta,1);
	for (j=0,l=1;l<=ma;l++)
		if (ia[l]) a[l]=beta[++j][1];
	
	free_vector(afunc,1,ma);
	free_matrix(beta,1,ma,1,1);
}
#undef NRANSI
