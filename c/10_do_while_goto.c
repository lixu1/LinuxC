#include <stdio.h>
int main(void)
{
int n;
int mul=1;
int i;
scanf("%d",&n);
i=1;
loop:
mul*=i;
i++;
if(i<=n)
goto loop;
printf("the result is %d\n",mul);
return 0;
}
