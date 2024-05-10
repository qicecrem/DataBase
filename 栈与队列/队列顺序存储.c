#include<stdio.h>
typedef int ElemType;
typedef int status;
#define OK 1
#define ERROR 0
#define MAXSIZE 100
typedef struct {
	ElemType data[MAXSIZE-1];
	int front;
	int rear;
}Squenue;
status InitQueue(Squenue* Q)
{
	Q->front = 0;
	Q->rear = 0;
	return OK;
}
int QuenueLength(Squenue Q)
{
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}
status Enquenue(Squenue* Q, ElemType e)
{
	if ((Q->rear+1)%MAXSIZE==Q->front)
	{
		return ERROR;
	}
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;
	return OK;
}
status Dequenue(Squenue* Q, ElemType* e)
{
	if (Q->front == Q->rear)
	{
		return ERROR;
	}
	*e = Q->data[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
	return OK;
}
status Clearquenue(Squenue* q)
{
	q->front = 0;
	q->rear = 0;
	return OK;
}
status Gethead(Squenue q, ElemType* e)
{
	if (q.front == q.rear)
	{
		return ERROR;
	}
	*e = q.data[q.front];
	q.front = (q.front + 1) % MAXSIZE;
	return OK;
}