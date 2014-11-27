#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
void * tfn1(void *arg)
{
	printf("the first\n");
	return (void *)1;
}
void * tfn2(void *arg)
{
	printf("the second\n");
	pthread_exit((void *)3);
	printf("should not be here\n");
}
void * tfn3(void *arg)
{
	printf("the third,sleep 10 seconds\n");
	sleep(5);
	return NULL;
}
int main(void)
{
	pthread_t tid1,tid2,tid3;
	void * res1;
	void * res2;
	void * res3;
	int err1,err2,err3,err4,err5,err6;

	err1=pthread_create(&tid1,NULL,tfn1,NULL);
	err2=pthread_create(&tid2,NULL,tfn2,NULL);
	err3=pthread_create(&tid3,NULL,tfn3,NULL);

	if(err1!=0)
	{
		printf("can't create thread %d\n",strerror(err1));
		exit(1);
	}
	if(err2!=0)
	{
		printf("can't create thread %d\n",strerror(err2));
		exit(1);
	}
	if(err3!=0)
	{
		printf("can't create thread %d\n",strerror(err3));
		exit(1);
	}


	err4=pthread_join(tid1,&res1);
	err5=pthread_join(tid2,&res2);
	err6=pthread_join(tid3,NULL);

	if(err4!=0)
	{
		printf("can't join thread %d\n",strerror(err4));
	}
	printf("result from thd1: %d\n",(unsigned int)(res1));
	if(err5!=0)
	{
		printf("can't join thread %d\n",strerror(err5));
		exit(1);
	}
	printf("result from thd2:%d\n",(unsigned int)(res2));
	if(err6!=0)
	{
		printf("can't join thread %d\n",strerror(err6));
		exit(1);
	}
	printf("the third thread has done\n");
	return 0;
}
