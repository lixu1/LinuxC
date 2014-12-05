#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <time.h>
typedef struct job *Job;
struct job{
	pthread_t tid;
	Job next;
	int val;
};
pthread_mutex_t q_lock=PTHREAD_MUTEX_INITIALIZER;
int insert(Job head,int val,pthread_t tid)
{
	Job p,q;
	p=head;
	if(p!=NULL)
	{
		while(p->next!=NULL)
		{
			p=p->next;
		}
	}
	q=(struct job *)malloc(sizeof(struct job));
	if(q==NULL)
	{
		perror("fail to malloc");
		return -1;
	}
	q->next=NULL;
	q->val=val;
	q->tid=tid;
	if(p==NULL)
	{
		head=q;
		return 0;
	}
	p->next=q;
	return 0;
}
int free_job(Job head)
{
	struct job * p, *q;
	for(p=head;p!=NULL;p=p->next)
	{
		q=p;
		p=p->next;
		free(q);
	}
	return 0;
}
void print(Job head)
{
	Job p;
	for(p=head;p!=NULL;p=p->next)
		printf("thread %u: val  %d\n",(unsigned int)p->tid,p->val);
}
void * tf9(void *arg)
{
	long long count;
	struct job *p,*q;
	struct job *task=NULL;
	pthread_t tid;
	struct timeval begintime,endtime;
	float elapsed_time;
	tid=pthread_self();
	count=0;
	while(count<100000000)
	{
		if(pthread_mutex_trylock(&q_lock)==0)
		{
			q=(struct job *)arg;
			p=q->next;
			while(p!=NULL)
			{
				if(tid==p->tid)
					count++;
				p=p->next;
			}
			pthread_mutex_unlock(&q_lock);
		}
	}
	gettimeofday(&endtime,NULL);
	elapsed_time=1000000*(endtime.tv_sec-begintime.tv_sec)+endtime.tv_usec-begintime.tv_usec;
	elapsed_time/=1000000;
	printf("This total used time is:%f secons.\n",elapsed_time);
	return (void *)0;
}
int main(void)
{
	struct job *item;
	struct job *p,*q;
	pthread_t tid1,tid2;
	int i,err;
	struct timeval begintime;
	gettimeofday(&begintime,NULL);
	item=(struct job *)malloc(sizeof(struct job));
	item->next=NULL;
	item->val=0;
	item->tid=-1;
	err=pthread_create(&tid1,NULL,tf9,item)!=0;
	if(err!=0)
	{
		printf("fail to create thread %d\n",strerror(err));
		exit(1);
	}
	if(pthread_create(&tid2,NULL,tf9,item)!=0)
	{
		printf("fail to create thread %d\n",strerror(err));
		exit(1);
	}
	printf("===the 1st put===\n");
	pthread_mutex_lock(&q_lock);
	for(i=0;i<2;i++)
	{
		if(insert(item,i,tid1)==-1)
			exit(1);
		if(insert(item,i+1,tid2)==-1)
			exit(1);
	}
	if(insert(item,10,tid1)==-1)
		exit(1);
	pthread_mutex_unlock(&q_lock);
	printf("===the 2nd put===\n");
	pthread_mutex_lock(&q_lock);
	if(insert(item,9,tid2)==-1)
		exit(1);
	pthread_mutex_lock(&q_lock);
	err=pthread_join(tid1,NULL);
	if(err!=0)
	{
		printf("can't join thread %d\n",strerror(err));
		exit(1);
	}
	pthread_join(tid2,NULL);
	if(err!=0)
	{
		printf("can't join thread %d\n",strerror(err));
		exit(1);
	}
	printf("main thread done\n");
	return 0;
}
