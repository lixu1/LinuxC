#include <stdio.h>
#define MAX 10
int main(void)
{
	int array[MAX];
	int i;
	int max;
	for(i=0;i<MAX;i++)
		scanf("%d",&array[i]);
	max==array[0];
	for(i=0;i<MAX;i++)
		if(max<array[i])
			max=array[i];
	printf("the result is %d\n",max);
	return 0;
}
// ./getMax < input.txt > max.txt
