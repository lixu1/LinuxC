#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
int main(void)
{
	int fd;
	int len=strlen("hello world\n");
	char *p="hello world\n";
	if((fd=open("test.txt",O_RDWR|O_CREAT))==-1)
	{
		perror("fail to open");
		exit(1);
	}
	while(1)
	{
		if(write(fd,p,len)==-1)//now move test.txt to test.out ,
		{
			perror("fail to write");
			exit(1);
		}
	}
	close(fd);
	return 0;
}
