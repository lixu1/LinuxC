#include "common.h"
int main(void)
{
	int a,b,res;
	p1=add;
	p2=sub;
	p3=mul;
	p4=div;
	a=2;
	b=1;
	res=(*p1)(a,b);
	printf("%d\n",res);
	res=(*p2)(a,b);
	printf("%d\n",res);
	res=(*p3)(a,b);
	printf("%d\n",res);
	res=(*p4)(a,b);
	printf("%d\n",res);
	return 0;
}
