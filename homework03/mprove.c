
#define NRANSI
#include "nrutil.h"

void mprove(float **a, float **alud, int n, int indx[], float **b, float **x)
{
	void lubksb(float **a, int n, int *indx, float **b);
	int j,i;
	double sdp;
	float **r;

	r=matrix(1,n, 1,1);
	for (i=1;i<=n;i++) {
		sdp = b[i][1];
		for (j=1;j<=n;j++) sdp -= a[i][j]*x[j][1];
		r[i][1]=sdp;
	}
	lubksb(alud,n,indx,r);
	for (i=1;i<=n;i++) x[i][1] += r[i][1];
	free_matrix(r, 1,n, 1,1);
}
#undef NRANSI
