#include"ջ����ʽ�洢�ṹ.h"
int main()
{
	LinkStack l;
	Initstack(&l);
	Pushstack(&l, 1);
	printf("%d %d", l.top->data,l.count);
	return 0;
}