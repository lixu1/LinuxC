#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#define NEW_MOD S_IRUSR|S_IRGRP|S_IROTH
int main(void)
{
	int fd;
	struct stat statbuf;
	mode_t mode;
	if(chmod("test.txt",NEW_MOD)==-1)
	{
		perror("fail to change model test.txt");
		exit(1);
	}
	if(stat("test2.txt",&statbuf)==-1)
	{
		perror("fail to stat");
		exit(1);
	}
	mode=statbuf.st_mode;//get permission mode
	mode&=(~S_IRWXU & ~S_IRWXG & ~S_IRWXO);//close file all permission
	mode|=(NEW_MOD);//open all users read permission
	if(chmod("test2.txt",mode)==-1)//change file permission
	{
		perror("fail to change model test2.txt");
		exit(1);
	}
	return 0;
}
