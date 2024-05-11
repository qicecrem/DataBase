#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
// Status是函数的类型，其值是函数结果状态代码，如OK等
typedef int status;
//线性表的最大长度
#define MAXSIZE 20
//ElemType 类型根据具体情况可改变
typedef int ElemType;


//静态分配
typedef struct Sqlist {
	//数组存储数据元素，最大值为MAXSIZE
	ElemType data[MAXSIZE];
	//线性表当前长度
	int length;
}Sqlist;
//获得元素操作，用e返回L中第i个数据元素的值 
status GetElem(const Sqlist* l, int i,ElemType*e)
{
	//不在范围
	if (i<1 || i>l->length || l->length == 0)
	{
		return ERROR;
	}
	*e = l->data[i - 1];
	return OK;
}
//插入操作，在L中第i个位置之前插入新的数据元素e，L的长度加1
status ListInsert(Sqlist* l, int i, ElemType e)
{   
	//当i不在范围内时
	if (i<1 || i>l->length + 1)
	{
		return ERROR;
	}   
	// 顺序线性表已经满
	if (l->length == MAXSIZE)
	{
		return ERROR;
	}
	//若插入数据位置不在表尾
	if (i < l->length)
	{
		//将要插入位置后数据元素向后移动一位
		for (int k = l->length-1; k >= i - 1; k--)
		{
			l->data[k + 1] = l->data[k];
		}
	}
	// 将新元素插入
	l->data[i - 1] = e;
	l->length++;
	return OK;
}
//删除操作，删除L的第i个数据元素，并用e返回其值，L的长度减1
status ListDelete(Sqlist* L, int i,ElemType *e)
{
	int k;
	//若线性表为空
	if (L->length == 0)
		return ERROR;
	//若删除位置不正确
	if (i<1 || i>L->length)
		return ERROR;
	*e = L->data[i - 1];
	//若删除不是最后一位
	if (i < L->length)
	{
		//将删除位置后元素前移
		for (k = i; k < L->length; k++)
		{
			L->data[k - 1] = L->data[k];
		}
	}
	L->length--;
	return OK;
}
//查找元素返回下标
int Listfind(const Sqlist* l, ElemType e)
{
	for (int i = 0; i < l->length; i++)
	{
		if (l->data[i] == e)
		{
			return i;
		}
	}
	return -1;
}

//动态分配
typedef struct {
	ElemType* data;//存放数据的数组
	int length;
	int capacity;//顺序表的容量
}SeqList;

//初始化
status  InitSqList(int capacity,SeqList *L)
{
	L = (SeqList*)malloc(sizeof(SeqList));//分配顺序表结构内存
	if (L == NULL)//内存分配失败
		return ERROR;
	L->data = (int*)malloc(capacity * sizeof(ElemType));//分配存放数据的数组内存
	if (L->data == NULL)//内存分配失败
		return ERROR;
	L->length = 0;
	L->capacity = capacity;
	return OK;
}

status Insert(SeqList* L, int i, ElemType e)
{
	//插入位置不合法
	if (L == NULL || i<1 || i>L->length)
		return ERROR;
	//如果当前长度已经等于容量，需要扩容
	if (L->length == L->capacity)
	{
		L->data = (int*)realloc(L->data, (L->capacity * 2) * sizeof(ElemType));
		if (L->data == NULL)//内存分配失败
			return ERROR;
	}
	L->capacity *= 2;
	//若插入数据位置不在表尾
	if (i < L->length)
	{
		//将i-1后面的元素依次后移一位
		for (int k = L->length - 1; k >= i - 1; k--)
		{
			L->data[k + 1] = L->data[k];
		}
	}
	L->data[i - 1] = e;
	L->length--;
	return OK;
}
status Delete(SeqList* L, int i, ElemType* e)
{
	int k;
	//若线性表为空
	if (L->length == 0)
		return ERROR;
	//若删除位置不正确
	if (i<1 || i>L->length)
		return ERROR;
	*e = L->data[i - 1];
	//若删除不是最后一位
	if (i < L->length)
	{
		//将删除位置后元素前移
		for (k = i; k < L->length; k++)
		{
			L->data[k - 1] = L->data[k];
		}
	}
	L->length--;
	return OK;
}
//释放顺序表内存
status FreeList(SeqList* L)
{
	if (L == NULL)
		return ERROR;
	free(L->data);
	L->data = NULL;
	free(L);
	L = NULL;
	return OK;
}