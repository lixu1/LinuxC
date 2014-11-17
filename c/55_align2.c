#include <stdio.h>
struct test
{
	char ch;
	int i;
	short s;
};
int main(void)
{
	struct test var;
	printf("sizeof var :%d\n",sizeof(var));
	return 0;
}
