#include <unistd.h>
int main()
{
	int fd,number;
	fd=dup(0);
	close(fd);
	printf("fd:%d\n",fd);
	scanf("read a number %d",&number);
	return fd;
}
