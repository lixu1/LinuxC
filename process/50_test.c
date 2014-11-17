#include <signal.h>
sig_atomic_t a;
void sigusrl_handler(int signo)
{
	a=1;
}
int main(void)
{
	while(a==0);
	return 0;
}
