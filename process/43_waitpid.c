#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main(void)
{
	pid_t pid;
	pid=fork();
	if(pid<0)
	{
		printf("fail to fork\n");
		exit(1);
	}
	else if(pid==0)
	{
		sleep(5);
		printf("the child\n");
		exit(0);
	}
	else
	{
		printf("the parent\n");
		if(waitpid(pid,NULL,WNOHANG)==-1)
			printf("the child is not available now\n");
	}
	printf("no waiting,parent done\n");
	return 0;
}
