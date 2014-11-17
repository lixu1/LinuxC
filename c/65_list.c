#include <stdio.h>
#include <stdlib.h>
typedef struct node * Node;
Node head;

struct node
{
	int val;
	Node next;
};
int insert(int val)
{
	Node p,q;
	p=head;
	if(p!=NULL)
	{
		while(p->next!=NULL)
		{
			p=p->next;
		}
	}
	q=(Node)malloc(sizeof(struct node));
	if(q==NULL) return -1;
	q->next=NULL;
	q->val=val;
	if(p==NULL)
	{
		head=q;
		return 1;
	}
	p->next=q;
	return 1;
}
int del(int val,Node *res)
{
	Node p,q;
	p=head;
	if(p==NULL)return -1;
	if(p->val==val)
	{
		*res=p;
		head=p->next;
		return 1;
	}
	else if(p->next==NULL)
		return -1;
	q=p;
	p=p->next;
	while(p!=NULL)
	{
		if(p->val!=val)
		{
			q=p;
			p=p->next;
		}
		else
		{
			q->next=p->next;
			p->next=NULL;
			*res=p;
			return 1;
		}
	}
	return -1;
}
void print()
{
	Node p=head;
	while(p!=NULL)
	{
		printf("%d\n",p->val);
		p=p->next;
	}
}

void destroy()
{
		Node p=head;
		while(p!=NULL)
		{
			Node q;
			q=p;
			p=p->next;
			free(q);
		}
		head=NULL;
	}
	int main(void)
	{
		Node p;
		int i;
		printf("insert\n");
		for(i=1;i<8;i++) insert(i);
		print();
		printf("destory\n");
		destroy();
		print();
		return 0;
}
