#include <stdio.h>
int main(void)
{
	int a=100;
	int *p;
	p=&a;
	p=(void *)p;
	printf("%d\n",*p);
	return 0;
}
