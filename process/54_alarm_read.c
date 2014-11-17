#include <fcntl.h>
#include <signal.h>
void alarm_handler(int signo)
{
	
}
size_t sig_read(int filefds,void *buf,size_t nbytes)
{
	size_t n;
	if(signal(SIGALRM,alarm_handler)==SIG_ERR)
	{
		perror("fail to set handler for SIGALRM");
		exit(1);
	}
	alarm(5);
	if((n==read(filefds,buf,nbytes))==-1)
		return -1;
	alarm(0);
	return n;
}
