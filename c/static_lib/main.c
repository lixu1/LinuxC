#include <stdio.h>
#include "static_lib.h"
int main(void)
{
	int a,b;
	printf("input a and b\n");
	scanf("%d%d",&a,&b);
	printf("the add:%d\n",add(a,b));
	printf("the sub:%d\n",sub(a,b));
	return 0;
}
