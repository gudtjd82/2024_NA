
#include <math.h>
#define MAXIT 100

float my_rtsafe(float (*func)(float), float (*dfunc)(float), float x1, float x2, float xacc, int* it)
{
	void nrerror(char error_text[]);
	int j;
	float df,dx,dxold,f,fh,fl;
	float temp,xh,xl,rts;

	// hw2
	fl = (*func)(x1);
	df = (*dfunc)(x1);

	fh = (*func)(x2);
	df = (*dfunc)(x2);
	if ((fl > 0.0 && fh > 0.0) || (fl < 0.0 && fh < 0.0))
		nrerror("Root must be bracketed in rtsafe");
	if (fl == 0.0) return x1;
	if (fh == 0.0) return x2;
	if (fl < 0.0) {
		xl=x1;
		xh=x2;
	} else {
		xh=x1;
		xl=x2;
	}
	rts=0.5*(x1+x2);
	dxold=fabs(x2-x1);
	dx=dxold;
	// hw2
	f = (*func)(rts);
	df = (*dfunc)(rts);
	*it = 0;
	for (j=1;j<=MAXIT;j++) {
		(*it)++;
		if ((((rts-xh)*df-f)*((rts-xl)*df-f) > 0.0)
			|| (fabs(2.0*f) > fabs(dxold*df))) {
			dxold=dx;
			dx=0.5*(xh-xl);
			rts=xl+dx;
			if (xl == rts) return rts;
		} else {
			dxold=dx;
			dx=f/df;
			temp=rts;
			rts -= dx;
			if (temp == rts) return rts;
		}
		if (fabs(dx) < xacc) return rts;
		// hw2
		f = (*func)(rts);
		df = (*dfunc)(rts);
		if (f < 0.0)
			xl=rts;
		else
			xh=rts;
	}
	nrerror("Maximum number of iterations exceeded in rtsafe");
	return 0.0;
}
#undef MAXIT
