#include <stdio.h>
int main(void)
{
	int flags=0xfffffff7;
	int mask=0x08;
	flags=flags^mask;
	printf("the first 0x%x\n",flags);
	flags=flags^mask;	
	printf("the second 0x%x\n",flags);
	return 0;
}
