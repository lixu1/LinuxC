//父进程关闭管道两端，子进程之间进行通信
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <limits.h>
#define BUFES PIPE_BUF
void err_quit(char * msg)
{
	perror(msg);
	exit(1);
}
int main(void)
{
	int fd[2];
	char buf[BUFES];
	pid_t pid;
	int len;
	if((pipe(fd))<0)
	{
		err_quit("pipe");
	}
	if((pid=fork())<0)
		err_quit("fork");
	else if(pid==0)
	{
		close(fd[0]);
		write(fd[1],"hello brother\n",14);
		exit(0);
	}
	
	if((pid=fork())<0)
		err_quit("fork");
	else if(pid>0)
	{
		close(fd[0]);
		close(fd[1]);
		exit(0);
	}
	else
	{
		close(fd[1]);
		len=read(fd[0],buf,BUFES);
		write(STDOUT_FILENO,buf,len);
		exit(0);
	}
}