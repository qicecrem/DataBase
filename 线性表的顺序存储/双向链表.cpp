#include<stdio.h>
#include<stdlib.h>
#define ElemType int
#define status int
#define OK 1
#define ERROR 0
typedef struct DulNode {
	ElemType data;
	struct DulNode* next;
	struct DulNode* prior;
}DoulNode,*DuLinklist;
int GetLength(DuLinklist l)
{
	DuLinklist p;
	p = l->next;
	int count = 0;
	while (l != p)
	{
		p = p->next;
		count++;
	}
	return count;
}
status GetEle(DuLinklist l,int i,ElemType* e)
{
	if (i > GetLength(l))
	{
		return ERROR;
	}
	DuLinklist p;
	p = l->next;
	int j = 1;
	while (j<i)
	{
		p =p->next;
		j++;
	}
	*e = p->data;
	return OK;
}
status InitList(DuLinklist* l)
{
	if ((*l))
	{
		return ERROR;
	}
	*l = (DuLinklist)malloc(sizeof(DulNode));
	(*l)->next = *l;
	(*l)->prior = *l;
	return OK;
}
status ListInsert(DuLinklist* l, int i, ElemType e)
{
	int j = 1;
	DuLinklist p,s;
	p = *l;
	if (i > GetLength(*l) + 1)
	{
		return ERROR;
	}
	while (j < i)
	{
		p = p->next;
		j++;
	}
	s = (DuLinklist)malloc(sizeof(DoulNode));
	s->data = e;
	s->next = p->next;
	s->prior = p;
	p->next->prior = s;
	p->next = s;
	return OK;
}
status ListPush_back(DuLinklist* l, ElemType e)
{
	DuLinklist p, s;
	p = *l;
	s = (DuLinklist)malloc(sizeof(DulNode));
	s->data = e;
	s->next = p;
	s->prior = p->prior;
	p->prior->next = s;
	p->prior = s;
	return OK;
}
status ListDelete(DuLinklist* l, int i, ElemType* e)
{
	DuLinklist p, q;
	p = *l;
	int j = 1;
	while (j < i)
	{
		j++;
		p = p->next;
	}
	if (j > i)
	{
		return ERROR;
	}
	q = p->next;
	p->next = q->next;
	q->next->prior = p;
	free(q);
	return OK;
}
status Assignment(DuLinklist* l, int i, ElemType e)
{
	DuLinklist p;
	int k = 1;
	p = (*l)->next;
	while (p != *l&&k<i)
	{
		p = p->next;
		k++;
	}
	if (k < i)
	{
		return ERROR;
	}
	p->data = e;
	return OK;
}
status ClearList(DuLinklist* l)
{
	DuLinklist p, q;
	p = (*l)->next;
	while (p!=*l)
	{
		q = p->next;
		free(p);
		p = q;
	}
	free(*l);
	*l = NULL;
	return OK;
}
