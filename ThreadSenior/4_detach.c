#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void *tfn1(void *arg)
{
	printf("the thread\n");
	sleep(1);
	return NULL;
}
int main(void)
{
	int err;
	pthread_t tid;
	pthread_attr_t attr;
	err=pthread_attr_init(&attr);
	if(err!=0)
	{
		printf("can't init attr %d\n",strerror(err));
		exit(1);
	}
	err=pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
	if(err!=0)
	{
		printf("can't set attr %d\n",strerror(err));
		exit(1);
	}
	err=pthread_create(&tid,&attr,tfn1,NULL);
	if(err!=0)
	{
		printf("can't create thread %d\n",strerror(err));
		exit(1);
	}
	err=pthread_join(tid,NULL);
	if(err!=0)
		printf("thread has been detached\n");
	return 0;
}
