#include<stdio.h>
typedef int ElemType;/* QElemType���͸���ʵ������������������Ϊint */
typedef int status;
#define OK 1
#define ERROR 0
#define MAXSIZE 100
#include<stdlib.h>
typedef struct Qnode {/* ���ṹ */
	ElemType data;
	struct Qnode* next;
}Qnode,*Qnodeptr;
typedef struct { /* ���е�����ṹ */
	Qnodeptr front, rear; /*��ͷ����βָ�� */
}Linkquenue;
status Enquenue(Linkquenue* q, ElemType e)/* ����Ԫ��eΪQ���µĶ�βԪ�� */
{
	Qnodeptr s = (Qnodeptr)malloc(sizeof(Qnode));
	if (!s) {  /*�洢����ʧ�� */
		return ERROR;
	}
	s->data = e;
	s->next = NULL;
	q->rear->next = s; /*��ӵ��Ԫ��e�½��s��ֵ��ԭ��β���ĺ�̣� */
	q->rear = s; /*�ѵ�ǰ��s����Ϊ��β��㣬rearָ��s������ͼ�Т� */
	q->front->data++;//ͷ�ڵ���ֵ������г���
	return OK;
}
status Dequenue(Linkquenue* q, ElemType *e)/* �����в��գ�ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK�����򷵻�ERROR */
{
	Qnodeptr p;
	if (q->front == q->rear)
	{
		return ERROR;
	}
	p = q->front->next; /*����ɾ���Ķ�ͷ����ݴ��p������ͼ�Т� */

	*e = p->data;
	q->front->next = p->next;
	if (q->rear == p) /*����ͷ�Ƕ�β����ɾ����rearָ��ͷ��㣬����ͼ��*/
	{
		q->rear = q->front;
	}
	free(p);
	q->front->data--;//ͷ�ڵ���ֵ������г���
	return OK;
}

status Initquenu(Linkquenue* q)//��ʼ������
{
	q->front = (Qnodeptr)malloc(sizeof(Qnode));
	if (!q->front)
	{
		return ERROR;
	}
	q->front->data = 0;//��ʼ�����г���Ϊ0
	q->front->next = NULL;
	q->rear = q->front;
	return OK;
}

int QuenueLength(Linkquenue q)/* ���ض��е�Ԫ�ظ�����Ҳ���Ƕ��еĵ�ǰ���� */
{
	return q.front->data;
}

status Clearquenue(Linkquenue* q)//�����������
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
