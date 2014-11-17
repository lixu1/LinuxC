#include <stdio.h>
#include <unistd.h>
int main(void)
{
	pid_t pid,ppid,uid,euid,gid,egid;
	pid=getpid();
	ppid=getppid();
	uid=getuid();
	euid=geteuid();
	gid=getgid();
	egid=getegid();
	printf("pid:%u\tppid:%u\tuid:%u\teuid:%u\tgid:%u\tegid:%u\n",pid,ppid,uid,euid,gid,egid);
	return 0;
}
