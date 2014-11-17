#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>
#define BUFES PIPE_BUF
int main(void)
{
	FILE *fp;
	char * cmd="cat 4_recat.c";
	char * buf[BUFES];
	if((fp=popen(cmd,"r"))==NULL)
	{
		perror("failed to popen");
		exit(1);
	}
	while((fgets(buf,BUFES,fp))!=NULL)
	{
		printf("%s",buf);
	}
	pclose(fp);
	exit(0);
}
