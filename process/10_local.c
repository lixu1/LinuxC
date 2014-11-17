#include <stdio.h>
#include <string.h>
char * combine(char *str1,char *str2)
{
	char str[1024];
	char *p=str;
	strcpy(str,str1);
	strcat(str,str2);
	return p;
}
int main(void)
{
	char *p;
	p=combine("hello","world");
	combine("q","w");
	printf("%s\n",p);
	return 0;
}
