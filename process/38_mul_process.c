#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(void)
{
	pid_t pid;
	pid=fork();
	if(pid<0)
	{
		perror("fail to fork");
		exit(1);
	}
	else if(pid==0)
	{
		int check=1;
		pid=getpid();
		while(check==1)
			sleep(1);
		printf("the child done\n");
		exit(0);
	}
	else
	{
		if(wait(NULL)==-1)
		{
			perror("fail to wait\n");
			exit(1);
		}
		printf("the parent done\n");
		exit(1);
	}
	return 0;
}
