#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
int main(void)
{
	int fd;
	struct stat statbuf;
	pid_t pid;
	uid_t ruid,euid;
	if(stat("test.txt",&statbuf)==-1)
	{
		perror("fail to stat");
		exit(1);
	}
//	if(getuid(&ruid,&euid)==-1)//get process read user id and effective user id
//	{
//		perror("fail to get uid");
//		exit(1);
//	}
	ruid=getuid();
	euid=geteuid();
	printf("real id is :%u,effective id is %u \n",(unsigned int)ruid,(unsigned int)euid);
	printf("file owner is %u\n",statbuf.st_uid);
	if(access("test.txt",R_OK)==-1)//test read
	{
		perror("fail to access");
		exit(1);
	}
	printf("access successfully\n");
	if((fd=open("test.txt",O_RDONLY))==-1)//open file
	{
		perror("fail to open");
		exit(1);
	}
	printf("ready to read\n");
	close(fd);
	return 0;
}
