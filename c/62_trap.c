#include <stdio.h>
int main(void)
{
	int a=32;
	int x=0xFFFFFFFF;
	printf("%d\n",0xFFFFFFFF>>32);
	printf("%d\n",x>>32);
	printf("%d\n",0xFFFFFFFF>>a);
	return 0;
}
