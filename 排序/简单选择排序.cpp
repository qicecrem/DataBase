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
void SelctSort(SqList* L)
{
	int i, j, min;
	for (i = 1; i < L->length; i++)
	{
		//将当前下标定义为最小值下标
		min = i;
		//循环之后的下标
		for (j = i + 1; j <= L->length; j++)
		{
			//如果有小于最小值的关键字
			if (L->r[min] > L->r[j])
			{
				min = j;

			}

		}
//		若min不等于i，说明找到最小值
		if (i != min)
		{
			//交换L->r[i]与L->r[min]的值
			swap(L, i, min);
	    }
	}
}
