#include<stdio.h>
#include<stdlib.h>
#define ElemType int
#define status int
#define OK 1
#define ERROR 0
//双向链表存储结构
typedef struct DulNode {
	ElemType data;
	//后继指针
	struct DulNode* next;
	//前驱指针
	struct DulNode* prior;
}DoulNode,*DuLinklist;
//获取双链表的长度
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
//获取第i个元素
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
//初始化双链表
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
//在第i个位置插入e
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
	//把p->next赋值给s的后继
	s->next = p->next;
	//把p赋值给s的前驱
	s->prior = p;
	//把s赋值给p->next的前驱
	p->next->prior = s;
	// 把s赋值给p的后继
	p->next = s;
	return OK;
}
//删除第i个节点
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
//给第i个节点赋值为e
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
//删除整个双向表
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
