#include <stdio.h>
#include <unistd.h>
int f1()
{
	vfork();
	return 0;
}
int f2(int a,int b)
{
	return a+b;
}
int main()
{
	int c;
	f1();
	//c=f2(1,2);
	printf("%d\n",c);
	return 0;
}
