#include <stdio.h>
#include <stdlib.h>
void f1(int **p)
{
	*p=(int *)malloc(sizeof(int));
}
int f2(int *p)
{
	printf("the heap is %d\n",*p);
}
int main(void)
{
	int *p;
	f1(&p);
	f2(p);
	*p=4;
	f2(p);
	free(p);
	f2(p);
	return 0;
}
