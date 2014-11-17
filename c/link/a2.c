#include <stdio.h>
void f(void);
int a;
int main(void)
{
	a=123;
	f();
	printf("a=%d\n",a);
	return 0;
}
