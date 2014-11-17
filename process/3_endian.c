#include <stdio.h>
int main(void)
{
	int a=0x12345678;
	char *p;
	p=(char *)(&a);
	if(*p==0x78)
		printf("the little endian\n");
	else
		printf("the big endian\n");
	return 0;
}
