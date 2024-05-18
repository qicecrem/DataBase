#include<stdio.h>
typedef int ElemType;/* QElemType���͸���ʵ������������������Ϊint */
typedef int status;
#define OK 1
#define ERROR 0
#define MAXSIZE 100
typedef struct {
	ElemType data[MAXSIZE-1];
	int front;/* ͷָ�� */
	int rear;/*βָ�룬�����в���,ָ�����βԪ�ص���һ��λ�� */
}Squenue;
status InitQueue(Squenue* Q)/* ��ʼ��һ���ն���Q */
{
	Q->front = 0;
	Q->rear = 0;  
	return OK;
}
int QuenueLength(Squenue Q)/* ����Q��Ԫ�ظ�����Ҳ���Ƕ��еĵ�ǰ���� */
{
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}
status Enquenue(Squenue* Q, ElemType e)/* ������δ���������Ԫ��eΪQ�µĶ�βԪ�� */
{
	if ((Q->rear+1)%MAXSIZE==Q->front)
	{
		return ERROR;
	}
	Q->data[Q->rear] = e; /*��Ԫ��e��ֵ����β */
	Q->rear = (Q->rear + 1) % MAXSIZE; /* rearָ�������һλ�ã� */
	return OK;
}
status Dequenue(Squenue* Q, ElemType* e)/* �����в��գ���ɾ��Q�ж�ͷԪ�أ���e������ֵ */
{
	if (Q->front == Q->rear) /*���пյ��ж� */
	{
		return ERROR;
	}
	*e = Q->data[Q->front]; /*����ͷԪ�ظ�ֵ��e */
	Q->front = (Q->front + 1) % MAXSIZE; /* frontָ�������һλ�ã� ���������ת������ͷ�� */
	return OK;
}
