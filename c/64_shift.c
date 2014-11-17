#include <stdio.h>
int right_shift(int a,int n)
{
	int b,c;
	b = a<< (32-n);
	c = a >> n;
	c = c & ~( ~0 <<(32-n) );
	c = c | b;
	return c;
}
int main(void)
{
	int a,b;
	printf("please input a interger\n");
	scanf("%d",&a);
	printf("the original : 0x%x\n",a);
	b=right_shift(a,4);
	printf("the result : 0x%x\n",b);
	return 0;
}
