// xb1, xb2 = 근이 존재하는 구간의 시작점과 끝점
// nb = 찾는 구간의 최대 개수 -> 실제 근의 개수
// [x1, x2]구간을 n개로 나누고 그 구간들 중에서 근이 포함된 구간을 찾아 그 구간의 개수를 nb에 저장
void zbrak(fx,x1,x2,n,xb1,xb2,nb)
float (*fx)(),x1,x2,xb1[],xb2[];
int *nb,n;
{
	int nbb,i;
	float x,fp,fc,dx;

	nbb=0;
	dx=(x2-x1)/n;
	fp=(*fx)(x=x1);
	for (i=1;i<=n;i++) {
		fc=(*fx)(x += dx);
		if (fc*fp <= 0.0) {
			xb1[++nbb]=x-dx;
			xb2[nbb]=x;
			if(*nb == nbb) return;

		}
		fp=fc;
	}
	*nb = nbb;
}
