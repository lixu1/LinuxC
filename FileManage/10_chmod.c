#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
int main(void)
{
	struct stat statbuf;
	if(stat("test.txt",&statbuf)==-1)
	{
		perror("fail to get status");
		exit(1);
	}
	printf("before changing owner\nthe owner of test.txt is %d\n,the group of test.txt is %d\n",(unsigned int)statbuf.st_uid,(unsigned int)statbuf.st_gid);
	if(chown("test.txt",0,-1)==-1)
	{
		perror("fail to change owner");
		exit(1);
	}
	if(stat("test.txt",&statbuf)==-1)
	{
		perror("fail to get status");
		exit(1);
	}
	printf("after changing owner\nthe owner of test.txt is %d\nthe group of test.txt is %d\n",(unsigned int)statbuf.st_uid,(unsigned int)statbuf.st_gid);
	if(chown("test.txt",100,-1)==-1)
	{
		perror("fail to change owner");
		exit(1);
	}
	if(stat("test.txt",&statbuf)==-1)
	{
		perror("fail to get status");
		exit(1);
	}
	printf("non exist owner\nthe owner of test.txt is %d\nthe group of test.txt is %d\n",(unsigned int)statbuf.st_uid,(unsigned int)statbuf.st_gid);
	return 0;
}
