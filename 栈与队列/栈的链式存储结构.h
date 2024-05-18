#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
#define MAXSIZE 100
typedef int status;
#define OK 1
#define ERROR 0
typedef struct StackNode {//ջ�ڵ�ṹ
	ElemType data;
	struct StackNode* next;//ָ����һ��ջ�ڵ�
}StackNode, * LinkStackPtr;
typedef struct LinKStack {//��������ջ
	LinkStackPtr top;//ջ��ָ��
	int count;//
}LinkStack;
status Initstack(LinkStack* l)//��ʼ��ջ
{
	if (!l)
	{
		return ERROR;
	}
	l->top = NULL;
	l->count = 0;
	return OK;
}

status Pushstack(LinkStack* l, ElemType e) /* ����Ԫ��eΪ�µ�ջ��Ԫ�� */
{
	LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
	if (!s) {
		return ERROR;
	}
	s->data = e; /*�ѵ�ǰ��ջ��Ԫ�ظ�ֵ���½���ֱ�Ӻ��*/
	s->next = l->top;
	l->top = s; /*���µĽ��s��ֵ��ջ��ָ�� */
	l->count++;
	return OK;
}
status Popstack(LinkStack* l, ElemType* e) /* ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR */
{
	LinkStackPtr p;
	if (l->count<1)
	{
		return ERROR;
	}
	*e = l->top->data;
	p = l->top;
	l->top = p->next;
	free(p);  /*�ͷŽ��p */
	l->count--;
	return OK;
}
