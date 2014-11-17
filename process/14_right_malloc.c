#include <stdio.h>
#include <stdlib.h>
void f1(int **p)
{
	*p=(int *)malloc(sizeof(int));
}
int main(void)
{
	int *p;
	f1(&p);
	printf("set heap\n");
	printf("the heap:%d\n",*p);
	*p=4;
	printf("the heap:%d\n",*p);
	free(p);
	return 0;
}
