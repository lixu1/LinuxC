#include <stdio.h>
int main(void)
{
	char *str1="hello";
	char str2[]="hello";
	char *str3="hello";
	if(str1==str2) printf("1 OK\n");
	if(str1==str3) printf("2 OK\n");
	return 0;
}
