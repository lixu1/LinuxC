#include <stdio.h>
#include <stdlib.h>
void alter(int *p)
{
	p=(int *)malloc(sizeof(int));
	*p=100;
}
int main(void)
{
	int a;
	int *p;
	a=10;
	p=&a;
	printf("p: 0x%x,*p: %d\n",p,*p);
	alter(p);
	printf("p: 0x%x,*p: %d\n",p,*p);
	return 0;
}
