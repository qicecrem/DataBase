#include<stdio.h>
typedef int ElemType;/* QElemType类型根据实际情况而定，这里假设为int */
typedef int status;
#define OK 1
#define ERROR 0
#define MAXSIZE 100
typedef struct {
	ElemType data[MAXSIZE-1];
	int front;/* 头指针 */
	int rear;/*尾指针，若队列不空,指向队列尾元素的下一个位置 */
}Squenue;
status InitQueue(Squenue* Q)/* 初始化一个空队列Q */
{
	Q->front = 0;
	Q->rear = 0;  
	return OK;
}
int QuenueLength(Squenue Q)/* 返回Q的元素个数，也就是队列的当前长度 */
{
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}
status Enquenue(Squenue* Q, ElemType e)/* 若队列未满，则插入元素e为Q新的队尾元素 */
{
	if ((Q->rear+1)%MAXSIZE==Q->front)
	{
		return ERROR;
	}
	Q->data[Q->rear] = e; /*将元素e赋值给队尾 */
	Q->rear = (Q->rear + 1) % MAXSIZE; /* rear指针向后移一位置， */
	return OK;
}
status Dequenue(Squenue* Q, ElemType* e)/* 若队列不空，则删除Q中队头元素，用e返回其值 */
{
	if (Q->front == Q->rear) /*队列空的判断 */
	{
		return ERROR;
	}
	*e = Q->data[Q->front]; /*将队头元素赋值给e */
	Q->front = (Q->front + 1) % MAXSIZE; /* front指针向后移一位置， 若到最后则转到数组头部 */
	return OK;
}
