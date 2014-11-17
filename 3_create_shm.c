#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#define BUFES 4096
int main(void)
{
	system("ipcs -m");
	int shm_id;
	shm_id=shmget(IPC_PRIVATE,BUFES,0666);
	if(shm_id<0)
	{
		perror("shmget");
		exit(1);
	}
	printf("successfully created segment :%d\n",shm_id);
	system("ipcs -m");
	exit(0);
}
