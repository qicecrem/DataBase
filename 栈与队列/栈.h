#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;//ElemType���͸���ʵ�����������
#define MAXSIZE 100
typedef int status;
#define OK 1
#define ERROR 0
typedef struct {
	ElemType data[MAXSIZE];
	int top;//����ջ��ָ��
}sqstack;
status pushstack(sqstack* s, ElemType e)//��ջ�� ����Ԫ��eΪ�µ�ջ��Ԫ��
{
	if (s->top == MAXSIZE - 1)//��ջ��
	{
		return ERROR;
	}
	s->data[++s->top] = e;//ջ��ָ���һ������Ԫ�ظ�ֵ��ջ���ռ�
	return OK;
}
status popstack(sqstack* s, ElemType* e)//��ջ ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
{
	if (s->top == -1)
	{
		return ERROR;
	}
	*e = s->data[s->top];//��Ҫɾ����ջ��Ԫ�ظ�ֵ��e 
	s->top--;// ջ��ָ���һ
	return OK;
}
status ClearStack(sqstack* s)// ��ջ���
{
	s->top = -1;
	return OK;
}
status GetTop(sqstack s, ElemType* e)//��ջ�����ҷǿգ���e����S��ջ��Ԫ��
{
	if (s.top == -1)
	{
		return ERROR;
	}
	*e = s.data[s.top];
	return OK;
}
 int StackLength(sqstack s)//  ����ջS��Ԫ�ظ�����
{
	 return s.top + 1;
}