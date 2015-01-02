#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#define MAX 1024
int main(void)
{
	int fd;
	struct stat statbuf;
	char buf[MAX];
	int n;
	if(stat("test.txt",&statbuf)==-1)
	{
		perror("fail to get status");
		exit(1);
	}
	printf("test.txt,the number of links is :%d\n",statbuf.st_nlink);
	if(link("test.txt","test100.txt")==-1)//create a hard link
	{
		perror("fail to link");
		exit(1);
	}
	if(stat("test.txt",&statbuf)==-1)
	{
		perror("fail to get status");
		exit(1);
	}
	printf("test.txt, the number of links is :%d\n",statbuf.st_nlink);
	if(stat("test100.txt",&statbuf)==-1)
	{
		perror("fail to get status");
		exit(1);
	}
	printf("test100.txt,the number of links is %d\n",statbuf.st_nlink);
	if((fd=open("test.txt",O_RDWR))==-1)
	{
		perror("fail to open");
		exit(1);
	}
	strcpy(buf,"hello world");
	if((n=write(fd,buf,strlen(buf)))==-1)
	{
		perror("fail to write");
		exit(1);
	}
	close(fd);
	if((fd=open("test100.txt",O_RDWR))==-1)
	{
		perror("fail to open");
		exit(1);
	}
	buf[n]='\0';
	printf("content of test100.txt is %s\n",buf);
	close(fd);
	if(unlink("test100.txt")==-1)
	{
		perror("fail to unlink");
		exit(1);
	}
	if(stat("test.txt",&statbuf)==-1)
	{
		perror("fail to get status");
		exit(1);
	}
	printf("test.txt,the number of links is :%d\n",statbuf.st_nlink);
	if((fd=open("test.txt",O_RDWR))==-1)
	{
		perror("fail to open");
		exit(1);
	}
	if(unlink("test.txt")==-1)
	{
		perror("fail to unlink");
		exit(1);
	}
	if(fstat(fd,&statbuf)==-1)
	{
		perror("fail to get status");
		exit(1);
	}
	printf("test.txt the number of links is %d\n",statbuf.st_nlink);
	if((n=read(fd,buf,n))==-1)
	{
		perror("fail to read");
		exit(1);
	}
	buf[n]='\0';
	printf("content of test.txt is %s\n",buf);
	close(fd);
	return 0;
}
