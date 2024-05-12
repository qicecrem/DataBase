#include<stdio.h>
#include<stdlib.h>
#define  ElemType int 
#define OK 1
#define ERROR 0
#define status int
//������洢�ṹ
typedef struct Node
{
	ElemType data;
	struct Node* next;
}Node;
typedef struct Node* LinkList;
//��ȡ��i��Ԫ��,��e����L�е�i������Ԫ�ص�ֵ
status GetElem(LinkList n, int i, ElemType* e)
{
	if (n == NULL)
		return ERROR;
	Node* p;
	p = n->next;
	//jΪ������
	int j = 1;
	//p��Ϊ���Ҽ�������û�е���i��ѭ������
	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	if (!p ||j>i)
		//��i�ڵ㲻����
		return ERROR;
	*e = p->data;
	return OK;
}
//���룬��L�е�i�����λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1
status ListInsert(LinkList* n, int i, ElemType e)
{
	int j = 1;
	LinkList p,s;
	p = *n;
	//Ѱ�ҵ�i-1���ڵ�
	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	//��i�ڵ㲻����
	if (!p || j > i)
		return ERROR;
	//�����½ڵ�
	s = (LinkList)malloc(sizeof(Node));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}


//��ɾ��L�ĵ�i����㣬����e������ֵ��L�ĳ��ȼ�1
status ListDelete(LinkList *n, int i, ElemType* e)
{
	LinkList p, q;
	p = *n;
	int j = 1;
	while (p->next&& j < i)
	{
		j++;
		p=p->next;

	}
	if (!(p->next) || j > i)
		return ERROR;
	q = p->next;
	p->next = q->next;
	*e = q->data;
	//�ͷ��ڴ�
	free(q);
	return OK;
}
/*��ʼ��n��Ԫ�أ���������ͷ���ĵ������Ա�L��ͷ�巨�� */
void CreateListHead(LinkList* l, int n)
{
	LinkList p;
	int i = 0;
	*l = (Node*)malloc(sizeof(Node));
	(*l)->next = NULL;
	for (; i < n; i++)
	{
		p = (Node*)malloc(sizeof(Node));
		p->data = 0;
		p->next = (*l)->next;
		(*l)->next = p;
	}
}
//����i��Ԫ�ظ�ֵe
status Assignment(LinkList l, int i, ElemType e)
{
	LinkList p;
	int k = 1;
	while (p->next && k < i)
	{
		p = p->next;
		k++;
	}
	if (!p || k <i)
	{
		return ERROR;
	}
	p->data = e;
	return OK;
}
/* ��ʼ��n��Ԫ�أ���������ͷ���ĵ������Ա�L��β�巨�� */
void CreateListTail(LinkList* l, int n)
{
	LinkList p, s;
	int i = 0;
	*l = (Node*)malloc(sizeof(Node));
	s= *l;
	for (; i < n; i++)
	{
		p = (Node*)malloc(sizeof(Node));
		p->data = 0;
		s->next = p;
		s = p;
	}
	s->next = NULL;
}
//�����������ɾ��
status ClearList(LinkList* l)
{
	LinkList p, q;
	p = (*l)->next;
	//û��ĩβ
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	(*l)->next = NULL;
	return OK;
}
