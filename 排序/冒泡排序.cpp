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
//冒泡初级
void BubbleSort0(SqList* L)
{
	int i, j;
	for (i = 1; i < L->length; i++)
	{
		for (j = i + 1; j <= L->length; j++)
		{
			if (L->r[i] > L->r[j])
			{
				swap(L, i, j);
			}
		}
	}
}

//冒泡排序
void BubbleSort(SqList* L)
{
	int i, j;
	for (i = 1; i < L->length; i++)
	{
		//从后往前循环
		for (j = L->length - 1; j >= i; j--)
		{
			if (L->r[j] > L->r[1 + j])
				swap(L, j, j + 1);
		}
	}
}

//冒泡排序改进
void BubbleSort2(SqList* L)
{
	int i, j;
	//flag用来作为标记
	Status flag = True;
	for (i = 1; i < L->length && flag; i++)
	{
		//初始化flag
		flag = False;
		for (j = L->length - 1; j >= i; j--)
		{
			if (L->r[j] > L->r[j + 1])
			{
				swap(L, j, j + 1);
				flag = True;
			}
		}
	}
}