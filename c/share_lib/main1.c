#include <stdio.h>
#include "share_lib.h"
int main(void)
{
	int array[5]={5,4,3,2,1};
	int item;
	int pos;
	insert_sort(array,5);
	printf("please input a number\n");
	scanf("%d",&item);
	pos=binary_search(array,item,5);
	if(pos==-1)
		printf("can't find\n");
	else 
		printf("the position is %d\n",pos+1);
	return 0;
}
