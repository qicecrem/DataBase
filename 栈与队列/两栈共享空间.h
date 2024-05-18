#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
#define MAXSIZE 100
typedef int status;
#define OK 1
#define ERROR 0
typedef struct {
	ElemType data[MAXSIZE];
	int top1;//ջ1ջ��ָ��
	int top2;//ջ2ջ��ָ��
}sqDoubleStack;
status pushstack(sqDoubleStack* s, ElemType e, int stackNumber)//����Ԫ��e��ջstackNumber
{
	if (s->top1 + 1 == s->top2)//ջ���������ڲ�����Ԫ��
	{
		return ERROR;
	}
	if (stackNumber == 1)//ջ1Ԫ�ؽ�ջ
	{
		s->data[++s->top1] = e;//top1��1������鸳ֵ
	}
	else if (stackNumber == 2)//ջ2Ԫ�ؽ�ջ
	{
		s->data[--s->top2] = e;//top2��1�������Ԫ�ظ�ֵ
	}
	return OK;
}
status popstack(sqDoubleStack* s, ElemType* e, int stackNumber)/* ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR */
{
	if (stackNumber == 1)
	{
		if (s->top1 == -1)//ջ1�ǿ�ջ����ERROR
			return ERROR;
		*e = s->data[s->top1--];//��ջ1Ԫ�س�ջ
	}
	else if (stackNumber == 2)
	{
		if (s->top2 == MAXSIZE)//ջ2��ջ
			return ERROR;
		*e = s->data[s->top2++];//��ջ2Ԫ�س�ջ
	}
	else
		return ERROR;
	return OK;
}