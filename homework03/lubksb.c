
void lubksb(float **a, int n, int *indx, float** b)
{
	int i,ii=0,ip,j;
	float sum, temp;

	for (i=1;i<=n;i++) {
		ip=indx[i];
		sum=b[ip][1];
		if (ip != i) {
            float temp = b[ip][1];
            b[ip][1] = b[i][1];
            b[i][1] = temp;
        }
		if (ii)
			for (j=ii;j<=i-1;j++) sum -= a[i][j]*b[j][1];
		else if (sum) ii=i;
		b[i][1]=sum;
	}
	for (i=n;i>=1;i--) {
		sum=b[i][1];
		for (j=i+1;j<=n;j++) sum -= a[i][j]*b[j][1];
		b[i][1]=sum/a[i][i];
	}
}
