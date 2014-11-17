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
		int err=errno;
		printf("Fail to open errno , the reason is:%s\n",strerror(err));
	}
	close(fd);
	return 0;
}
