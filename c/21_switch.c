#include <stdio.h>
int main(void)
{
	char score;
	scanf("%c",&score);
	switch(score)
	{
		case 'A':printf("90-100\n");break;
		case 'B':printf("80-90\n");break;
		case 'C':printf("70-80\n");break;
		case 'D':printf("60-70\n");break;
		case 'E':printf("0-60\n");break;
		default:printf("wrong input\n");
	}
	return 0;
}
