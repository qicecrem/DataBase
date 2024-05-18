#include<stdio.h>
typedef int ElemType;/* QElemType类型根据实际情况而定，这里假设为int */
typedef int status;
#define OK 1
#define ERROR 0
#define MAXSIZE 100
#include<stdlib.h>
typedef struct Qnode {/* 结点结构 */
	ElemType data;
	struct Qnode* next;
}Qnode,*Qnodeptr;
typedef struct { /* 队列的链表结构 */
	Qnodeptr front, rear; /*队头、队尾指针 */
}Linkquenue;
status Enquenue(Linkquenue* q, ElemType e)/* 插入元素e为Q的新的队尾元素 */
{
	Qnodeptr s = (Qnodeptr)malloc(sizeof(Qnode));
	if (!s) {  /*存储分配失败 */
		return ERROR;
	}
	s->data = e;
	s->next = NULL;
	q->rear->next = s; /*把拥有元素e新结点s赋值给原队尾结点的后继， */
	q->rear = s; /*把当前的s设置为队尾结点，rear指向s，见上图中② */
	q->front->data++;//头节点数值代表队列长度
	return OK;
}
status Dequenue(Linkquenue* q, ElemType *e)/* 若队列不空，删除Q的队头元素，用e返回其值，并返回OK，否则返回ERROR */
{
	Qnodeptr p;
	if (q->front == q->rear)
	{
		return ERROR;
	}
	p = q->front->next; /*将欲删除的队头结点暂存给p，见上图中① */

	*e = p->data;
	q->front->next = p->next;
	if (q->rear == p) /*若队头是队尾，则删除后将rear指向头结点，见上图中*/
	{
		q->rear = q->front;
	}
	free(p);
	q->front->data--;//头节点数值代表队列长度
	return OK;
}

status Initquenu(Linkquenue* q)//初始化队列
{
	q->front = (Qnodeptr)malloc(sizeof(Qnode));
	if (!q->front)
	{
		return ERROR;
	}
	q->front->data = 0;//初始化队列长度为0
	q->front->next = NULL;
	q->rear = q->front;
	return OK;
}

int QuenueLength(Linkquenue q)/* 返回队列的元素个数，也就是队列的当前长度 */
{
	return q.front->data;
}

status Clearquenue(Linkquenue* q)//清除整个队列
{
	Qnodeptr a;
	Qnodeptr p = q->front->next;
	while (p != q->rear)
	{
		a = p->next;
		free(p);
		p = a;
		q->front->data--;
	}
	free(p);
	q->front->data--;
	q->front->next = NULL;
	q->rear = q->front;
	return OK;
}
