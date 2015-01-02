#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
int main(void)
{
	struct stat buf;
	if(stat("./test.txt",&buf)==-1)
	{
		printf("stat error\n");
		exit(0);
	}
	if((buf.st_mode & S_IRGRP )==S_IRGRP) //group user read permission
		printf("user of the group can read\n");
	else
		printf("user of the group can not read\n");
	
	if((buf.st_mode&S_IXGRP)==S_IXGRP)
		printf("user of the group can execute\n");
	else
		printf("user of the group can not execute\n");
	return 0;
}
