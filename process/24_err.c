#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
int main(void)
{
	printf("errno :%d\n",errno);
	int fd;
	errno=0;
	fd=fopen("/home/admin/nothing.txt",O_RDWR);
	if(errno==0)
		printf("Successful\n");
	else
	{
		int i=errno;
		printf("Fail to open errno is:%d\n",i);
		exit(1);
	}
	close(fd);
	printf("over");
}
