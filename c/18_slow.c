#include <stdio.h>
#include <stdlib.h>
#define MAX 1024

int main(void)
{
FILE *fp;
char buf[ MAX ];
int n;
int letter=0,blank=0,number=0;
fp=fopen("article.txt","r");
if(fp==NULL)
{
perror("fail to open");
exit(1);
}
while((n=fread(buf,sizeof(char),MAX,fp))>0)
{
int i;
for(i=0;i<n;i++)
{
if(buf[i]>='0'&&buf[i]<='9')number++;
else if(buf[i]==' ')blank++;
else if((buf[i]>='a'&&buf[i]<='z')||(buf[i]>='A'&&buf[i]<='Z'))letter++;
}
}
printf("letter %d,number %d,blank %d\n",letter,number,blank);
fclose(fp);
return 0;
}
