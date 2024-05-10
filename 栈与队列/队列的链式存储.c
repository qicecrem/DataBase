#include<stdio.h>
typedef int ElemType;
typedef int status;
#define OK 1
#define ERROR 0
#define MAXSIZE 100
#include<stdlib.h>
typedef struct Qnode {
	ElemType data;
	struct Qnode* next;
}Qnode,*Qnodeptr;
typedef struct {
	Qnodeptr front, rear;
}Linkquenue;
status Enquenue(Linkquenue* q, ElemType e)
{
	Qnodeptr s = (Qnodeptr)malloc(sizeof(Qnode));
	if (!s) {
		return ERROR;
	}
	s->data = e;
	s->next = NULL;
	q->rear->next = s;
	q->rear = s;
	q->front->data++;
	return OK;
}
status Dequenue(Linkquenue* q, ElemType *e)
{
	Qnodeptr p;
	if (q->front == q->rear)
	{
		return ERROR;
	}
	p = q->front->next;
	*e = p->data;
	q->front->next = p->next;
	if (q->rear == p)
	{
		q->rear = q->front;
	}
	free(p);
	q->front->data--;
	return OK;
}

status Initquenu(Linkquenue* q)
{
	q->front = (Qnodeptr)malloc(sizeof(Qnode));
	q->front->data = 0;
	if (!q->front)
	{
		return ERROR;
	}
	q->front->next = NULL;
	q->rear = q->front;
	return OK;
}

int QuenueLength(Linkquenue q)
{
	return q.front->data;
}

status Clearquenue(Linkquenue* q)
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
status Gethead(Linkquenue* q,ElemType* e)
{
	Qnodeptr p;
	if (q->front == q->rear)
	{
		return ERROR;
	}
	p = q->front->next;
	*e = p->data;
	q->front->next = p->next;
	if (q->rear == p)
	{
		q->rear = q->front;
	}
	free(p);
	q->front->data--;
	return OK;
}