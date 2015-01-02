#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#define MASK S_IRUSR|S_IRGRP|S_IROTH
int main(void)
{
	int fd;
	mode_t mask;
	mask=umask(MASK);
	printf("the original mask is %x\n",(unsigned int)mask);
	if((fd=open("test3.txt",O_CREAT,0777))==NULL)
	{
		perror("fail to crrate");
		exit(1);
	}
	close(fd);
	return 0;
}
