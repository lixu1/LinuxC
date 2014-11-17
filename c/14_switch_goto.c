#include <stdio.h>
int main(void)
{
code *lab[]={lab_a,lab_b,lab_c};
char score;
scanf("%d",&score);
if(score>'C') goto lab_default;
score-='A';
goto lab[score];
lab_a:
printf("excellent\n");
goto done;
lab_b:
printf("good\n");
goto done;
lab_c:
printf("pass\n");
goto done;
lab_default:
printf("fail\n");
done:
return 0;
}
