#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
void sigusr1_handler(int signo)
{
	printf("catch SIGUSR1\n");
}
