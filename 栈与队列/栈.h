#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
#define MAXSIZE 100
typedef int status;
#define OK 1
#define ERROR 0
typedef struct {
	ElemType data[MAXSIZE];
	int top;
}sqstack;
status pushstack(sqstack* s, ElemType e)
{
	if (s->top == MAXSIZE - 1)
	{
		return ERROR;
	}
	s->data[++s->top] = e;
	return OK;
}
status popstack(sqstack* s, ElemType* e)
{
	if (s->top == -1)
	{
		return ERROR;
	}
	*e = s->data[s->top];
	s->top--;
	return OK;
}
status stackInit(sqstack* s, ElemType e)
{
	s->top = -1;
	return OK;
}