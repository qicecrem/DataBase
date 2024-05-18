#include<stdio.h>
#include<stdlib.h>
#define ElemType int
#define status int
#define OK 1
#define ERROR 0
//˫������洢�ṹ
typedef struct DulNode {
	ElemType data;
	//���ָ��
	struct DulNode* next;
	//ǰ��ָ��
	struct DulNode* prior;
}DoulNode,*DuLinklist;
//��ȡ˫����ĳ���
int GetLength(DuLinklist l)
{
	DuLinklist p;
	p = l->next;
	int count = 1;
	while (l != p)
	{
		p = p->next;
		count++;
	}
	return count;
}
//��ȡ��i��Ԫ��
status GetEle(DuLinklist l,int i,ElemType* e)
{
	DuLinklist p;
	p = l->next;
	int j = 1;
	while (p!=l&&j<i)
	{
		p =p->next;
		j++;
	}
	if (j < i)
		return ERROR;
	*e = p->data;
	return OK;
}
//��ʼ��˫����
status InitList(DuLinklist* l)
{
	if ((*l))
	{
		return ERROR;
	}
	*l = (DuLinklist)malloc(sizeof(DulNode));
	(*l)->next = *l;
	(*l)->prior = *l;
	return OK;
}
//�ڵ�i��λ�ò���e
status ListInsert(DuLinklist* l, int i, ElemType e)
{
	int j = 1;
	DuLinklist p,s;
	p = *l;
	while (p!=*l&&j < i)
	{
		p = p->next;
		j++;
	}
	if (j < i)
		return ERROR;
	s = (DuLinklist)malloc(sizeof(DoulNode));
	s->data = e;
	//��p->next��ֵ��s�ĺ��
	s->next = p->next;
	//��p��ֵ��s��ǰ��
	s->prior = p;
	//��s��ֵ��p->next��ǰ��
	p->next->prior = s;
	// ��s��ֵ��p�ĺ��
	p->next = s;
	return OK;
}
//ɾ����i���ڵ�
status ListDelete(DuLinklist* l, int i, ElemType* e)
{
	DuLinklist p, q;
	p = *l;
	int j = 1;
	while (p!=*l&&j < i)
	{
		j++;
		p = p->next;
	}
	if (j < i)
		return ERROR;
	q = p->next;
	p->next = q->next;
	q->next->prior = p;
	free(q);
	q = NULL;
	return OK;
}
//����i���ڵ㸳ֵΪe
status Assignment(DuLinklist* l, int i, ElemType e)
{
	DuLinklist p;
	int k = 1;
	p = (*l)->next;
	while (p != *l&&k<i)
	{
		p = p->next;
		k++;
	}
	if (k < i)
	{
		return ERROR;
	}
	p->data = e;
	return OK;
}
//ɾ������˫���
status ClearList(DuLinklist* l)
{
	DuLinklist p, q;
	p = (*l)->next;
	while (p!=*l)
	{
		q = p->next;
		free(p);
		p = q;
	}
	*l = NULL;
	return OK;
}
