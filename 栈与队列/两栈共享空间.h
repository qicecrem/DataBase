#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
#define MAXSIZE 100
typedef int status;
#define OK 1
#define ERROR 0
typedef struct {
	ElemType data[MAXSIZE];
	int top1;//栈1栈顶指针
	int top2;//栈2栈顶指针
}sqDoubleStack;
status pushstack(sqDoubleStack* s, ElemType e, int stackNumber)//插入元素e到栈stackNumber
{
	if (s->top1 + 1 == s->top2)//栈已满不能在插入新元素
	{
		return ERROR;
	}
	if (stackNumber == 1)//栈1元素进栈
	{
		s->data[++s->top1] = e;//top1加1后给数组赋值
	}
	else if (stackNumber == 2)//栈2元素进栈
	{
		s->data[--s->top2] = e;//top2减1后给数组元素赋值
	}
	return OK;
}
status popstack(sqDoubleStack* s, ElemType* e, int stackNumber)/* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR */
{
	if (stackNumber == 1)
	{
		if (s->top1 == -1)//栈1是空栈返回ERROR
			return ERROR;
		*e = s->data[s->top1--];//将栈1元素出栈
	}
	else if (stackNumber == 2)
	{
		if (s->top2 == MAXSIZE)//栈2空栈
			return ERROR;
		*e = s->data[s->top2++];//将栈2元素出栈
	}
	else
		return ERROR;
	return OK;
}