#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/resource.h>
int main(void)
{
	pid_t pid;
	struct rusage rusage;
	pid=fork();
	if(pid<0)
	{
		printf("fail to fork\n");
		exit(0);
	}
	else if(pid==0)
	{
		printf("the child\n");
		exit(0);
	}
	else
		printf("the parent\n");
	if(wait3(NULL,0,&rusage)==-1)
	{
		perror("fail to wait");
		exit(1);
	}
	printf("%d\n%d\n%d\n",rusage.ru_utime,rusage.ru_stime,rusage.ru_maxrss);
	return 0;
}
