#include <sys/wait.h>
#include <unistd.h>
int system(const char * cmdstring)
{
	pid_t pid;
	int status;
	if(cmdstring==NULL)return 1;
	pid=fork();
	if(pid<0)
	{
		status=-1;
	}
	else if(pid==0)
	{
		execl("/bin/sh","sh","-c",cmdstring,NULL);
		_exit(127);
	}
	if(waitpid(pid,&status,0)==-1)
		status=-1;
	return status;
}
