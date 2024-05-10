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
void InsertSort(SqList* L)
{
	int i, j;
	for (i = 2; i < L->length; i++)
	{
		if (L->r[i] < L->r[i - 1])
		{
			//设置哨兵
			L->r[0] = L->r[i];
			for (j = i - 1; L->r[j] > L->r[0]; j--)
			{
				L->r[j + 1] = L->r[j];
			}
			//插到正确位置
			L->r[j + 1] = L->r[0];
		}
	}
}