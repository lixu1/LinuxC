#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(void)
{
	uid_t uid;
	uid_t euid;
	uid=getuid();
	euid=geteuid();
	printf("uid is %d\teuid is %d\n",uid,euid);
	if(setuid(1200)==-1)
	{
		perror("fail to set uid\n");
		exit(1);
	}
	printf("after changing\n");
	uid=getuid();
	euid=geteuid();
	printf("uid is %d\teuid is %d\n",uid,euid);
	return 0;
}
