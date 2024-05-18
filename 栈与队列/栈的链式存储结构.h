#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
#define MAXSIZE 100
typedef int status;
#define OK 1
#define ERROR 0
typedef struct StackNode {//栈节点结构
	ElemType data;
	struct StackNode* next;//指向下一个栈节点
}StackNode, * LinkStackPtr;
typedef struct LinKStack {//管理整个栈
	LinkStackPtr top;//栈顶指针
	int count;//
}LinkStack;
status Initstack(LinkStack* l)//初始化栈
{
	if (!l)
	{
		return ERROR;
	}
	l->top = NULL;
	l->count = 0;
	return OK;
}

status Pushstack(LinkStack* l, ElemType e) /* 插入元素e为新的栈顶元素 */
{
	LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
	if (!s) {
		return ERROR;
	}
	s->data = e; /*把当前的栈顶元素赋值给新结点的直接后继*/
	s->next = l->top;
	l->top = s; /*将新的结点s赋值给栈顶指针 */
	l->count++;
	return OK;
}
status Popstack(LinkStack* l, ElemType* e) /* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR */
{
	LinkStackPtr p;
	if (l->count<1)
	{
		return ERROR;
	}
	*e = l->top->data;
	p = l->top;
	l->top = p->next;
	free(p);  /*释放结点p */
	l->count--;
	return OK;
}
