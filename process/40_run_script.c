#include <stdio.h>
#include <unistd.h>
int main()
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
		execl("/home/lixu/lixu/1_interp.sh","interp","arg1","arg2",NULL);
		exit(0);
	}
	exit(0);
}
