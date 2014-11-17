#include <stdio.h>
char * replace(char *str)
{
	char *p;
	if(str == NULL) return NULL;
	p=str;
	while( *p != '\0')
	{
		if( *p == ' ') *p = '_';
		p++;
	}
	return p;
}
int main(void)
{
	const char *p="hello world and China!";
	printf("%s\n",p);
	if( replace(p) != NULL )
		printf("the string :%s\n",p);
	return 0;
}
