#include <stdio.h>
int func(int n)
{
	int sum=0,i;
	for(i=1;i<=n;i++)
		sum+=i;
	return sum;
}
int main(void)
{
	int i;
	long result=0;
	for(i=1;i<=100;i++)
		result+=i;
	printf("%d\n",result);
	printf("%d\n",func(250));
	return 0;
}
