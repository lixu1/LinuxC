#include <stdio.h>
int main(void)
{
	int a=0x1234567f;
	int b=~1;
	printf("the result is : 0x%x\n",a&b);
	return 0;
}
