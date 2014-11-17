#include <stdio.h>
inline int f(int a,int b)
{
	return a+b;
}
int main(void)
{
	int c;
	c=f(1,2);
	printf("%d\n",c);
	return 1;
}
