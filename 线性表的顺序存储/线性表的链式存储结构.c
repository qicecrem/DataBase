#include<stdio.h>
#include<stdlib.h>
#define  ElemType int 
#define OK 1
#define ERROR 0
#define status int
typedef struct Node
{
	ElemType data;
	struct Node* next;
}Node;
status GetEle(Node* n, int i, ElemType* e)
{
	Node* p;
	p = n->next;
	int j = 1;
	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	if (!p )
	{
		return ERROR;
	}
	*e = p->data;
	return OK;
}
status ListInsert(Node** n, int i, ElemType e)
{
	int j = 1;
	Node* p,*s;
	p = *n;
	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i)
		return ERROR;
	s = (Node*)malloc(sizeof(Node));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}
status ListPush_back(Node** n, ElemType e)
{
	Node* p, *s;
	p = *n;
	while (p->next)
	{
		p=p->next;
	}
	s = (Node*)malloc(sizeof(Node));
	s->data = e;
	s->next = NULL;
	p->next = s;
	return OK;
}

status ListDelete(Node** n, int i, ElemType* e)
{
	Node* p, * q;
	p = *n;
	int j = 1;
		while (p->next&& j < i)
		{
			j++;
			p=p->next;

	}
		if (!(p->next) || j > i)
		{
			return ERROR;
		}
		q = p->next;
		p->next = q->next;
		*e = q->data;
		free(q);
		return OK;
}
void CreateListHead(Node** l, int n)
{
	Node* p;
	int i = 0;
	*l = (Node*)malloc(sizeof(Node));
	(*l)->next = NULL;
	for (; i < n; i++)
	{
		p = (Node*)malloc(sizeof(Node));
		p->data = 0;
		p->next = (*l)->next;
		(*l)->next = p;
	}
}
status Assignment(Node** l, int i, ElemType e)
{
	Node* p;
	int k = 1;
	while (p->next && k < i)
	{
		p = p->next;
		k++;
	}
	if (p || k <i)
	{
		return ERROR;
	}
	p->data = e;
	return OK;
}

void CreateListTail(Node** l, int n)
{
	Node* p,*s;
	int i = 0;
	*l = (Node*)malloc(sizeof(Node));
	s= *l;
	for (; i < n; i++)
	{
		p = (Node*)malloc(sizeof(Node));
		p->data = 0;
		s->next = p;
		s = p;
	}
	s->next = NULL;
}
status ClearList(Node** l)
{
	Node* p, *q;
	p = (*l)->next;
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	free(*l);
	*l = NULL;
	return OK;
}
