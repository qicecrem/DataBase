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
void ShellSort(SqList* L)
{
	int i, j;
	int incream = L->length;
	do {
		//增量序列
		incream = incream / 3 + 1;
		for (i = incream + 1; i <= L->length; i++)
		{
			if (L->r[i] < L->r[i - incream])
			{
				//需要将L->r[i]插入有序增量子表
				//暂存在L->r[0]
				L->r[0] = L->r[i];
				for (j = i - incream; j > 0 && L->r[0] < L->r[j]; j -= incream)
					//记录后移，查找插入位置
					L->r[j + incream] = L->r[i];
				//插入
				L->r[j + incream] = L -> r[0];

			}
		}
	} while (incream > 1);
}