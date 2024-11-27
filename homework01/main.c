#include <stdio.h>
#include "nr.h"

#define CONV(i) ((double)(i))

void get_eps(double *eps){
	// *eps = 0.f;
	double one, two, a, temp;

	one = CONV(1);
	two = one + one;

	a = one;
	do
	{
		a = a/two;
		temp = one + a;
	} while (temp != one);
	a *= two;
	*eps = a;
	
}

void machar_double(int *ibeta, int *it, int *irnd, int *ngrd, int *machep, int *negep,
	int *iexp, int *minexp, int *maxexp, double *eps, double *epsneg,
	double *xmin, double *xmax)
{
	int i,itemp,iz,j,k,mx,nxres;
	double a,b,beta,betah,betain,one,t,temp,temp1,tempa,two,y,z,zero;

	one=CONV(1);
	two=one+one;
	zero=one-one;
	a=one;
	do {
		a += a;
		temp=a+one;
		temp1=temp-a;
	} while (temp1-one == zero);
	b=one;
	do {
		b += b;
		temp=a+b;
		itemp=(int)(temp-a);
	} while (itemp == 0);
	*ibeta=itemp;
	beta=CONV(*ibeta);
	*it=0;
	b=one;
	do {
		++(*it);
		b *= beta;
		temp=b+one;
		temp1=temp-b;
	} while (temp1-one == zero);
	*irnd=0;
	betah=beta/two;
	temp=a+betah;
	if (temp-a != zero) *irnd=1;
	tempa=a+beta;
	temp=tempa+betah;
	if (*irnd == 0 && temp-tempa != zero) *irnd=2;
	*negep=(*it)+3;
	betain=one/beta;
	a=one;
	for (i=1;i<=(*negep);i++) a *= betain;
	b=a;
	for (;;) {
		temp=one-a;
		if (temp-one != zero) break;
		a *= beta;
		--(*negep);
	}
	*negep = -(*negep);
	*epsneg=a;
	*machep = -(*it)-3;
	a=b;
	for (;;) {
		temp=one+a;
		if (temp-one != zero) break;
		a *= beta;
		++(*machep);
	}
	*eps=a;
}

int main(){
	int ibeta, it, irnd, ngrd, machep, negep, iexp, minexp, maxexp;
	float eps_f, epsneg, xmin, xmax;
	double eps_d;

	machar(&ibeta, &it, &irnd, &ngrd, &machep, &negep, &iexp, &minexp, &maxexp,
			&eps_f, &epsneg, &xmin, &xmax);
	printf("Machine Accuracy of float (machar): \t%0.20f\n", eps_f);

	machar_double(&ibeta, &it, &irnd, &ngrd, &machep, &negep, &iexp, &minexp, &maxexp,
			&eps_d, &epsneg, &xmin, &xmax);
	printf("Machine Accuracy of double (machar): \t%0.20f\n", eps_d);

	get_eps(&eps_d);
	printf("Machine Accuracy of double (get_eps): \t%0.20f\n", eps_d);

	return 0;
}