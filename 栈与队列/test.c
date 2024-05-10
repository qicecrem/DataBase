#include"栈的链式存储结构.h"
int main()
{
	LinkStack l;
	Initstack(&l);
	Pushstack(&l, 1);
	printf("%d %d", l.top->data,l.count);
	return 0;
}