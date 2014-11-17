#include <stdio.h>
int main(void)
{
int n;
int add=0;
int i;
int t;
scanf("%d",&n);
i=1;
t=i<=n;
if(t==0)
goto done;
loop:
add+=i;
i++;
t=i<=n;
if(t==1) goto loop;
done:
printf("the result is %d\n",add);
return 0;
}
