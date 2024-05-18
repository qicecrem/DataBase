#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;//ElemType类型根据实际情况而定，
#define MAXSIZE 100
typedef int status;
#define OK 1
#define ERROR 0
typedef struct {
	ElemType data[MAXSIZE];
	int top;//用于栈顶指针
}sqstack;
status pushstack(sqstack* s, ElemType e)//进栈， 插入元素e为新的栈顶元素
{
	if (s->top == MAXSIZE - 1)//若栈满
	{
		return ERROR;
	}
	s->data[++s->top] = e;//栈顶指针加一，将新元素赋值给栈顶空间
	return OK;
}
status popstack(sqstack* s, ElemType* e)//出栈 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
{
	if (s->top == -1)
	{
		return ERROR;
	}
	*e = s->data[s->top];//将要删除的栈顶元素赋值给e 
	s->top--;// 栈顶指针减一
	return OK;
}
status ClearStack(sqstack* s)// 将栈清空
{
	s->top = -1;
	return OK;
}
status GetTop(sqstack s, ElemType* e)//若栈存在且非空，用e返回S的栈顶元素
{
	if (s.top == -1)
	{
		return ERROR;
	}
	*e = s.data[s.top];
	return OK;
}
 int StackLength(sqstack s)//  返回栈S的元素个数。
{
	 return s.top + 1;
}