
#define NRANSI
#include "nrutil.h"

void lfit(float **input, float **output, float **sig, int ndat, float **a, int **ia,
	int ma, float **covar, float* chisq, void (*funcs)(float*, float*, int))
{
	void gaussj(float **a, int n, float **b, int m);
	int i,j,k,l,m,*mfit, max_mfit;
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
	max_mfit = (mfit[1] > mfit[2]) ? mfit[1] : mfit[2];
	if (mfit[1] == 0 && mfit[2] == 0) nrerror("lfit: no parameters to be fitted");
	for (j=1;j<=mfit[1];j++) {
		for (k=1;k<=mfit[1];k++) covar[j][k]=0.0;
		beta[j][1]=0.0;
	}
	for (j=1;j<=mfit[2];j++) {
		for (k=1;k<=mfit[2];k++) covar[j][k]=0.0;
		beta[j][2]=0.0;
	}
	for (i=1;i<=ndat;i++) {
		(*funcs)(input[i],afunc,ma);
		ym[1]=output[i][1];		// x'
		ym[2]=output[i][2];		// y'
		if (max_mfit < ma) {
			for (j=1;j<=ma;j++)
			{
				if (!ia[j][1]) ym[1] -= a[j][1]*afunc[j];
				if (!ia[j][2]) ym[2] -= a[j][2]*afunc[j];
			}
		}
		// weighted least-square (Chi-Square Fitting)
		sig2i[1]=1.0/SQR(sig[i][1]);
		sig2i[2]=1.0/SQR(sig[i][2]);
		for (j=0,l=1;l<=ma;l++) {
			if (ia[l][1]) {
				wt=afunc[l]*sig2i[1];
				for (j++,k=0,m=1;m<=l;m++)
					if (ia[m][1]) covar[j][++k] += wt*afunc[m];
				beta[j][1] += ym[1]*wt;
			}
		}
		for (j=0,l=1;l<=ma;l++) {
			if (ia[l][2]) {
				wt=afunc[l]*sig2i[2];
				for (j++,k=0,m=1;m<=l;m++)
					if (ia[m][2]) covar[j][++k] += wt*afunc[m];
				beta[j][2] += ym[2]*wt;
			}
		}
	}
	for (j=2;j<=max_mfit;j++)
		for (k=1;k<j;k++)
			covar[k][j]=covar[j][k];
	gaussj(covar,max_mfit,beta,2);
	int j_x = 0;
	int j_y = 0;
	for (l=1;l<=ma;l++)
	{
		if (ia[l][1]) a[l][1]=beta[++j_x][1];
		if (ia[l][2]) a[l][2]=beta[++j_y][2];
	}

	*chisq = 0.0;
    for (i = 1; i <= ndat; i++) {
        (*funcs)(input[i], afunc, ma);
        float fitted_x = 0.0, fitted_y = 0.0;
        for (j = 1; j <= ma; j++) {
            fitted_x += a[j][1] * afunc[j];
            fitted_y += a[j][2] * afunc[j];
        }
        *chisq += SQR((output[i][1] - fitted_x) / sig[i][1]) + SQR((output[i][2] - fitted_y) / sig[i][2]);
    }

	free_vector(afunc,1,ma);
	free_ivector(mfit, 1, 2);
	free_vector(ym, 1, 2);
	free_vector(sig2i, 1, 2);
	free_matrix(beta,1,ma,1,2);
}
#undef NRANSI
