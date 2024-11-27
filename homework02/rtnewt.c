
#include <math.h>
#define JMAX 20

float my_rtnewt(float (*func)(float), float (*dfunc)(float), float x1, float x2, float xacc, int* it)
{
	void nrerror(char error_text[]);
	int j;
	float df,dx,f,rtn;

	rtn=0.5*(x1+x2);
	*it = 0;
	for (j=1;j<=JMAX;j++) {
		(*it)++;
		f = (*func)(rtn);
		df = -(*dfunc)(rtn);
		dx=f/df;
		rtn -= dx;
		if ((x1-rtn)*(rtn-x2) < 0.0)
			nrerror("Jumped out of brackets in rtnewt");
		if (fabs(dx) < xacc) return rtn;
	}
	nrerror("Maximum number of iterations exceeded in rtnewt");
	return 0.0;
}
#undef JMAX
