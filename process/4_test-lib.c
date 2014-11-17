#include <stdio.h>
int test_endian(void)
{
	int a=0x12345678;
	char *p;
	p=(char *)(&a);
	if(*p==0x78)
		return 1;
	return 0;
}
int main(void)
{
	if(test_endian()==1)
		printf("the little endian\n");
	else
		printf("the big endian\n");
}
