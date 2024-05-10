#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20
typedef int ElemType;
typedef struct Sqlist {
	ElemType data[MAXSIZE];
	int length;
}Sqlist;
#define OK 1
#define ERROR 0
typedef int status;
/* Status是函数的类型，其值是函数结果状态代
码，如OK等 */
status GetElem(const Sqlist* l, int i,ElemType*e)
{
	if (i<1 || i>l->length || l->length == 0)
	{
		return ERROR;
	}
	*e = l->data[i - 1];
	return OK;
}

status ListInsert(Sqlist* l, int i, ElemType e)
{
	if (i<1 || i>l->length + 1)
	{
		return ERROR;
	}   
	if (l->length == MAXSIZE)
	{
		return ERROR;
	}
	if (i < l->length)
	{
		for (int k = l->length-1; k >= i - 1; k--)
		{
			l->data[k + 1] = l->data[k];
		}
	}
	l->data[i - 1] = e;
	l->length++;
	return OK;
}
status List_push_back(Sqlist* l, ElemType e)
{
	if (l->length == MAXSIZE)
	{
		return ERROR;
	}
	l->data[l->length- 1] = e;
	l->length++;
	return OK;
}

status List_pop_back(Sqlist* l)
{
	if (l->length == 0)
		return ERROR;
	l->length--;
	return OK;
}

status ListDelete_order(Sqlist* l, int i)
{
	if (l->length == 0)
		return ERROR;
	if (i<1 || i>l->length)
		return ERROR;
	if (i < l->length)
	{
		for (int k = i ; k <l->length; k++)
		{
			l->data[k - 1] = l->data[k];
		}
	}
	l->length--;
	return OK;
}
int Listfind(const Sqlist* l, ElemType e)
{
	for (int i = 0; i < l->length; i++)
	{
		if (l->data[i] == e)
		{
			return i+1;
		}
	}
	return -1;
}
status ListDelete_val(Sqlist* l, ElemType e)
{
	int n = Listfind(l, e);
	if ( n)
	{
		ListDelete_order(l, n);
		return OK;
	}
	return ERROR;
}
