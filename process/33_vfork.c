#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int global;
int main()
{
	pid_t pid;
	int stack=1;
	int *heap;
	heap=(int *)malloc(sizeof(int));
	*heap=2;
	pid=vfork();
	if(pid<0)
	{
		printf("fail to fork\n");
		exit(1);
	}
	else if(pid==0)
	{
		global++;
		stack++;
		(*heap)++;
		printf("this is child,data is :%d ,stack is %d, heap is %d\n",global,stack,*heap);
		printf("the child termenate\n");
		exit(0);
	}
	printf("the parent, data is %d,stack is %d,heap is %d\n",global,stack,*heap);
	printf("the parent termenate\n");
	return 0;
}
