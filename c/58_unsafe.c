#include <stdio.h>
int main(void)
{
	int a=0x3;
	int b=0xfffe;
	printf("the result is : 0x%x\n",a&b);
	return 0;
}
