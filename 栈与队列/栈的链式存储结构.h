
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
#define MAXSIZE 100
typedef int status;
#define OK 1
#define ERROR 0
typedef struct StackNode {
	ElemType data;
	struct StackNode* next;
}StackNode, * LinkStackPtr;
typedef struct LinKStack {
	LinkStackPtr top;
	int count;
}LinkStack;
status Initstack(LinkStack* l)
{
	if (!l)
	{
		return ERROR;
	}
	l->top = NULL;
	l->count = 0;
	return OK;
}

status Pushstack(LinkStack* l, ElemType e)
{
	LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
	if (!s) {
		return ERROR;
	}
	s->data = e;
	s->next = l->top;
	l->top = s;
	l->count++;
	return OK;
}
status Popstack(LinkStack* l, ElemType* e)
{
	LinkStackPtr p;
	if (!l->top)
	{
		return ERROR;
	}
	*e = l->top->data;
	p = l->top;
	l->top = p->next;
	free(p);
	l->count--;
	return OK;
}
