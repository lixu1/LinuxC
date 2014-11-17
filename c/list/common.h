#include <stdio.h>
#include <stdlib.h>
typedef struct node * Node;

struct node
{
	int val;
	Node next;
};

extern Node head;
extern int insert(int val);
extern int del(int val,Node *res);
extern void print();
extern void destroy();
