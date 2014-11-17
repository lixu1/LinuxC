#include "common.h"
int (*p1)(int,int)=NULL;
int (*p2)(int,int)=NULL;
int (*p3)(int,int)=NULL;
int (*p4)(int,int)=NULL;

int add(int a,int b)
{
	return a+b;
}
int sub(int a,int b)
{
	return a-b;
}
int mul(int a,int b)
{
	return a*b;
}
int div(int a,int b)
{
	return a/b;
}
