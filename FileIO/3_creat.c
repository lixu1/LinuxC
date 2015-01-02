#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
int main(void)
{
	int fd;
	fd=creat("test.txt",0700);
	if(fd==-1)
	{
		perror("fail to creat\n");
		exit(1);
	}
	else
		printf("creat OK\n");
	return 0;
}
