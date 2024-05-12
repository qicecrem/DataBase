#include<stdio.h>
#include<stdlib.h>
#define  ElemType int 
#define OK 1
#define ERROR 0
#define status int
//单链表存储结构
typedef struct Node
{
	ElemType data;
	struct Node* next;
}Node;
typedef struct Node* LinkList;
//获取第i个元素,用e返回L中第i个数据元素的值
status GetElem(LinkList n, int i, ElemType* e)
{
	if (n == NULL)
		return ERROR;
	Node* p;
	p = n->next;
	//j为计数器
	int j = 1;
	//p不为空且计数器还没有等于i是循环继续
	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	if (!p ||j>i)
		//第i节点不存在
		return ERROR;
	*e = p->data;
	return OK;
}
//插入，在L中第i个结点位置之前插入新的数据元素e，L的长度加1
status ListInsert(LinkList* n, int i, ElemType e)
{
	int j = 1;
	LinkList p,s;
	p = *n;
	//寻找第i-1个节点
	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	//第i节点不存在
	if (!p || j > i)
		return ERROR;
	//生成新节点
	s = (LinkList)malloc(sizeof(Node));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}


//：删除L的第i个结点，并用e返回其值，L的长度减1
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
	//释放内存
	free(q);
	return OK;
}
/*初始化n个元素，建立带表头结点的单链线性表L（头插法） */
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
//给第i个元素赋值e
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
/* 初始化n个元素，建立带表头结点的单链线性表L（尾插法） */
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
//单链表的整表删除
status ClearList(LinkList* l)
{
	LinkList p, q;
	p = (*l)->next;
	//没到末尾
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	(*l)->next = NULL;
	return OK;
}
