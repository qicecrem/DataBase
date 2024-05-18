#include<stdio.h>
#include<stdlib.h>
#define Maxsize 10
#define ElemType int//ElemType 类型根据具体情况可改变
#define OK 1
#define ERROR 0
#define status int
typedef struct node {
	ElemType data;
	int cur;
}Componet,StaticList[Maxsize];

status InitList(StaticList space)
{
	int i = 0;
	for (; i < Maxsize-1; i++)
	{
		space[i].cur = i + 1;
	}
	space[Maxsize - 1].cur = 0;
	return OK;
}

int Malloc_SLL(StaticList space)
{
	int i = space[0].cur;
	if (space[0].cur)
	{
		space[0].cur = space[i].cur;
	}
	return i;
}
int ListLength(StaticList l)
{
	int j = 0;
	int i = l[Maxsize - 1].cur;
	while (i)
	{
		i = l[i].cur;
		j++;
	}
	return j;
}
status ListInsert(StaticList l, int i, ElemType e)
{
	int j, k, h;
	k = Maxsize - 1;
	if (i<1 || i>ListLength(l) + 1)
	{
		return ERROR;
	}
	j = Malloc_SLL(l);
	if (j)
	{
		l[j].data = e;
		for (h = 1; h <= i - 1; i++)
		{
			k = l[k].cur;
	  }
		l[i].cur = l[k].cur;
		l[k].cur = j;
		return OK;
	}
	return ERROR;
}
status ListDelete(StaticList l, int i)
{
	int j, k;
	if (i<1 || i>Listlength(l))
	{
		return ERROR;
	}
	k = Maxsize - 1;
	for (j = 1; j < i - 1; j++)
	{
		k = l[k].cur;
	}
	j = l[k].cur;
	l[k].cur = l[j].cur;
	Free_SLL(l, j);
	return OK;
}
void Free_SSL(StaticList l, int i)
{
	l[i].cur = l[0].cur;
	l[0].cur = i;
}