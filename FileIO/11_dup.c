#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{
	int fd;
	fd=open("test.txt",O_RDONLY);
	close(fd);
	return fd;
}
