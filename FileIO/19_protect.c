#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
void sigbus_handler(int signo)
{
	printf("permission denied ---\n");
}
int main(void)
{
	int fd;
	char *buf;
	struct stat statbuf;
	if(signal(SIGBUS,sigbus_handler)==SIG_ERR)
	{
		perror("can't set handler for SIGALRM");
		exit(0);
	}
	if(stat("test.txt",&statbuf)==-1)
	{
		perror("fail to get stat");
		exit(1);
	}
	fd=open("test.txt",O_WRONLY);
	if(fd==-1)
	{
		perror("fail to open");
		exit(1);
	}
	buf=(char *)mmap(NULL,statbuf.st_size,PROT_READ,MAP_SHARED,fd,0);
	if(buf==MAP_FAILED)
	{
		perror("fail to mmap--buf");
		exit(1);
	}
	printf("try to mmap");
	strcpy(buf,"China\n");
	if(mprotect(buf,statbuf.st_size,PROT_READ|PROT_WRITE)==-1)
	{
		perror("fail to alter permission---");
		exit(1);
	}
	printf("try again\n");
	strcpy(buf,"China\n");
	if(munmap(buf,statbuf.st_size)==-1)
	{
		perror("fail to munmap");
		exit(1);
	}
	close(fd);
	return 0;
}
