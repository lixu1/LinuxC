#include "common.h"
int main(void)
{
	Node p;
	int i;
	printf("insert\n");
	for(i=1;i<8;i++) insert(i);
	print();
	printf("destory\n");
	destroy();
	print();
	return 0;
}
