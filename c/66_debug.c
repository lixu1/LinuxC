#include <stdio.h>

#define DEBUG 0
#ifdef DEBUG
#define PRINT(str) printf(str);
#define PRINT1(str,arg); printf(str,arg);
#else
#define PRINT (str);
#define PRINT1 (str,arg);;
#endif
int main(void)
{
	int array[5]={1,2,4,3,0};
	int i;
	PRINT("before sort\n");
	//buddle_sort(array,5);
	PRINT("after sort\n");
	for(i=0;i<5;i++)
		PRINT1("%d\n",array[i]);
	return 0;
}
