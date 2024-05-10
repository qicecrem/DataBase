#define MAXSIZE 10
typedef struct {
	//用于存储排序数组，r[0]用作哨兵或临时变量
	int r[MAXSIZE + 1];
	//记录顺序表长度
	int length;
}SqList;
//交换元素
void swap(SqList* L, int i, int j)
{
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

void HeapAdjust(SqList* L, int s, int m)
{
	int temp, j;
	temp = L->r[s];
	//沿关键字较大的孩子节点向下筛选
	for (j = 2 * s; j <= m; j *= 2)
	{
		if (j < m && L->r[j] < L->r[j + 1])
			++j;
		if (temp >= L->r[j])
			break;
		L->r[s] = L->r[j];
		s = j;

	}
	//插入
	L->r[s] = temp;
}
void HeapSort(SqList* L)
{
	int i;
	//L中的r构成一个大顶锥
	for (i = L->length / 2; i > 0; i--)
		HeapAdjust(L, i, L->length);
	for (i = L->length; i > 1; i--)
	{
		//将堆顶记录和当前未排序的子序列的最后一个记录交换
		swap(L, 1, i);

		//L->r[1..i-1]重新调整为大顶锥
		HeapAdjust(L, 1, i - 1);
	}
	
}