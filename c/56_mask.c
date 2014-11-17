#include <stdio.h>
int main(void)
{
	unsigned char a,b;
	unsigned char mask=0x38;
	a=0xff;
	b=a&mask;
	printf("the flag b is : 0x%x\n",b);
	return 0;
}
