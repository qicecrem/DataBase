#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
// Status�Ǻ��������ͣ���ֵ�Ǻ������״̬���룬��OK��
typedef int status;
//���Ա����󳤶�
#define MAXSIZE 20
//ElemType ���͸��ݾ�������ɸı�
typedef int ElemType;


//��̬����
typedef struct Sqlist {
	//����洢����Ԫ�أ����ֵΪMAXSIZE
	ElemType data[MAXSIZE];
	//���Ա�ǰ����
	int length;
}Sqlist;
//���Ԫ�ز�������e����L�е�i������Ԫ�ص�ֵ 
status GetElem(const Sqlist* l, int i,ElemType*e)
{
	//���ڷ�Χ
	if (i<1 || i>l->length || l->length == 0)
	{
		return ERROR;
	}
	*e = l->data[i - 1];
	return OK;
}
//�����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1
status ListInsert(Sqlist* l, int i, ElemType e)
{   
	//��i���ڷ�Χ��ʱ
	if (i<1 || i>l->length + 1)
	{
		return ERROR;
	}   
	// ˳�����Ա��Ѿ���
	if (l->length == MAXSIZE)
	{
		return ERROR;
	}
	//����������λ�ò��ڱ�β
	if (i < l->length)
	{
		//��Ҫ����λ�ú�����Ԫ������ƶ�һλ
		for (int k = l->length-1; k >= i - 1; k--)
		{
			l->data[k + 1] = l->data[k];
		}
	}
	// ����Ԫ�ز���
	l->data[i - 1] = e;
	l->length++;
	return OK;
}
//ɾ��������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1
status ListDelete(Sqlist* L, int i,ElemType *e)
{
	int k;
	//�����Ա�Ϊ��
	if (L->length == 0)
		return ERROR;
	//��ɾ��λ�ò���ȷ
	if (i<1 || i>L->length)
		return ERROR;
	*e = L->data[i - 1];
	//��ɾ���������һλ
	if (i < L->length)
	{
		//��ɾ��λ�ú�Ԫ��ǰ��
		for (k = i; k < L->length; k++)
		{
			L->data[k - 1] = L->data[k];
		}
	}
	L->length--;
	return OK;
}
//����Ԫ�ط����±�
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

//��̬����
typedef struct {
	ElemType* data;//������ݵ�����
	int length;
	int capacity;//˳��������
}SeqList;

//��ʼ��
status  InitSqList(int capacity,SeqList *L)
{
	L = (SeqList*)malloc(sizeof(SeqList));//����˳���ṹ�ڴ�
	if (L == NULL)//�ڴ����ʧ��
		return ERROR;
	L->data = (int*)malloc(capacity * sizeof(ElemType));//���������ݵ������ڴ�
	if (L->data == NULL)//�ڴ����ʧ��
		return ERROR;
	L->length = 0;
	L->capacity = capacity;
	return OK;
}

status Insert(SeqList* L, int i, ElemType e)
{
	//����λ�ò��Ϸ�
	if (L == NULL || i<1 || i>L->length)
		return ERROR;
	//�����ǰ�����Ѿ�������������Ҫ����
	if (L->length == L->capacity)
	{
		L->data = (int*)realloc(L->data, (L->capacity * 2) * sizeof(ElemType));
		if (L->data == NULL)//�ڴ����ʧ��
			return ERROR;
	}
	L->capacity *= 2;
	//����������λ�ò��ڱ�β
	if (i < L->length)
	{
		//��i-1�����Ԫ�����κ���һλ
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
	//�����Ա�Ϊ��
	if (L->length == 0)
		return ERROR;
	//��ɾ��λ�ò���ȷ
	if (i<1 || i>L->length)
		return ERROR;
	*e = L->data[i - 1];
	//��ɾ���������һλ
	if (i < L->length)
	{
		//��ɾ��λ�ú�Ԫ��ǰ��
		for (k = i; k < L->length; k++)
		{
			L->data[k - 1] = L->data[k];
		}
	}
	L->length--;
	return OK;
}
//�ͷ�˳����ڴ�
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