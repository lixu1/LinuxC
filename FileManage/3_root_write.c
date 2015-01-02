#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define MAX 1024
int main(int argc ,char *argv[])
{
	int sfd,dfd;
	struct stat statbuf;
	char buf[MAX];
	int n;
	if(stat(argv[0],&statbuf)==-1)
	{
		perror("fail to stat");
		exit(1);
	}
	if((statbuf.st_mode & S_ISUID )== S_ISUID)
		printf("set user id\n");
	else
	{
		printf("can't write to root.txt\n");
	//```:	exit(1);
	}
	if((sfd=open("test.txt",O_RDONLY))==-1)
	{
		perror("fail to open\n");
		exit(1);
	}
	if((dfd=open("root.txt",O_WRONLY))==-1)
	{
		perror("fail to write\n");
		exit(1);
	}
	while((n=read(sfd,buf,MAX))>0)
	{
		if(write(dfd,buf,n)==-1)
		{
			perror("fail to write\n");
			exit(1);
		}
	}
	if(n>0)
	{
		perror("fail to read");
		exit(1);
	}
	printf("done\n");
	return 0;
}
