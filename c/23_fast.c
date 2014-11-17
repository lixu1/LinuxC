#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1024
void lower2(char *p)
{
	int i,len;
	len=strlen(p);
	for(i=0;i<len;i++) if(p[i]>='A' && p[i]<='Z') p[i]-=32;
}
int main(void)
{
	FILE *fp;
	char buf[MAX];
	fp=fopen("article.txt","r");
	if(fp==NULL)
	{
		perror("fail to open");
		exit(1);
	}
	int n;
	while( ( n=fread(buf,sizeof(char),MAX-1,fp) )>0)
	{
		printf("%s\n",buf);
		buf[n]='\0';
		lower2(buf);
		printf("%s\n",buf);
	}
	if(n<0)
	{
		perror("fail to read\n");
		exit(1);
	}
	fclose(fp);
	return 0;
}
