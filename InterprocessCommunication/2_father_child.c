///父进程 到 子进程 通信
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#define BUFES 100
int main(void)
{
	int fd[2];
	char buf[BUFES];
	pid_t pid;
	int len;
	if((pipe(fd))<0)
	{
		perror("fail to pipe");
		exit(1);
	}
	if((pid=fork())<0)
	{
		perror("fail to fork");
		exit(1);
	}
	else if(pid>0)
	{
		//father process
		close(fd[0]);
		write(fd[1],"hello my son\n",14);
		exit(0);
	}
	else
	{
		//child process
		close(fd[1]);
		len=read(fd[0],buf,BUFES);
		if(len<0)
		{
			perror("process failed when read a pipe");
			exit(1);
		}
		else
			write(STDOUT_FILENO,buf,len);
		exit(0);
	}
}
