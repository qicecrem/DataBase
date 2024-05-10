#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
#define MAXSIZE 100
typedef int status;
#define OK 1
#define ERROR 0
typedef struct {
	ElemType data[MAXSIZE];
	int top1;
	int top2;
}sqDoubleStack;
status pushstack(sqDoubleStack* s, ElemType e, int stackNumber)
{
	if (s->top1 + 1 == s->top2)
	{
		return ERROR;
	}
	if (stackNumber == 1)
	{
		s->data[++s->top1] = e;
	}
	else if (stackNumber == 2)
	{
		s->data[--s->top2] = e;
	}
	return OK;
}
status popstack(sqDoubleStack* s, ElemType* e, int stackNumber)
{
	if (stackNumber == 1)
	{
		if (s->top1 == -1)
			return ERROR;
		*e = s->data[s->top1--];
	}
	else if (stackNumber == 2)
	{
		if (s->top2 == MAXSIZE)
			return ERROR;
		*e = s->data[s->top2++];
	}
	else
		return ERROR;
	return OK;
}