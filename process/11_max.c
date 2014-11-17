#include <stdio.h>
int a=1;
int main(void)
{
	int b;
	printf("stack %x\n",&b+4);
	printf("data %x\n",&a+4);
	printf("process space %u\n",(&b+4)-(&a+4));
	return 0;
}
