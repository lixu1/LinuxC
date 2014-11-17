#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
int main(void)
{
	int f=0;
	char buffer[80]="";
	char buf[2][10];
	float seconds=0;
	float secondr=0;
	char *file="/proc/uptime";
	f = open(file, O_RDONLY);
	if (f == 0)
	{
		printf("error to open: %s\n", file);
		exit(1);
	}
	read(f, (void *)buffer, 80);
	sscanf(buffer, "%s %s", &buf[0], &buf[1]);
	close(f);
	printf("系统运行时间：\t%s秒\n", buf[0]);
	printf("系统空闲时间：\t%s秒\n", buf[1]);
	close(f);
	seconds=strtof(buf[0],NULL);
	secondr=strtof(buf[1],NULL);
	printf("系统运行时间：\t%03d天%02d时%02d分%02.6f秒\n", 
              (int)seconds/(24*3600),             /* 天 */
              ((int)seconds/(3600))%(24),         /* 时 */
              ((int)seconds/60)%60,               /* 分 */
              ((int)seconds%60)+(seconds-(int)seconds)); /* 秒(精确至毫秒) */
     printf("系统空闲时间：\t%03d天%02d时%02d分%02.6f秒\n", 
              (int)secondr/(24*3600),             /* 天 */
              ((int)secondr/(3600))%(24),         /* 时 */
              ((int)secondr/60)%60,               /* 分 */
              ((int)secondr%60)+(secondr-(int)secondr)); /* 秒(精确至毫秒) */
	return 0;
}
