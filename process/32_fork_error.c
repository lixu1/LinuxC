#include <unistd.h>
#include <stdio.h>
int main()
{
	while(1)
	{
		pid_t pid;
		pid=fork();
		printf("pid:%d\n",pid);
	}
	return 0;
}
