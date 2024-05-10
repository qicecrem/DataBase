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

void QuickSort(SqList *L)
{
	QSort(L, 1, L->length);
}
//对顺序表进行快速排序
void QSort(SqList* L, int low, int high)
{
	int pivot;
	if (low < high)
	{
		//将L->r[low..high]一分为二
		//算出枢轴值pivot
		pivot = Partition(L, low, high);
		//对低子表递归排序
		QSort(L, low, pivot - 1);
		//对高子表递归排序
		QSort(L, pivot + 1, high);

	}
}
/* 交换顺序表L中子表的记录，使枢轴记录到位，并返回其所在位置 */
/* 此时在它之前（后）的记录均不大（小）于它。 */
int Partition(SqList* L, int low, int high)
{
	int pivotkey;
	//用子表的第一个记录做枢轴记录
	pivotkey = L->r[low];
	//从表的两端交替向中间扫描
	while (low < high)
	{
		while (low < high && L->r[high] >= pivotkey)
			high--;
			//将比枢轴记录小的记录交换到低端
			swap(L, low, high);
			while (low < high && L->r[low] <= pivotkey)
				low++;
			swap(L, low, high);
		
	}
	return low;
}


















//快速排序优化
#define MAX_INSERT_SORT 7
void QuickSort(SqList* L)
{
	QSort(L, 1, L->length);
}
//对顺序表进行快速排序
void QSort(SqList* L, int low, int high)
{
	//优化小数组排序
//优化递归
	int pivot;
	if ((high - low) > MAX_INSERT_SORT)
	{
		while(low < high)
		{
			//将L->r[low..high]一分为二
			//算出枢轴值pivot
			pivot = Partition(L, low, high);
			//对低子表递归排序
			QSort(L, low, pivot - 1);
			//尾递归
			low = pivot + 1;
		}
	}
	else
		InsertSort(L);
}
int Partition(SqList* L, int low, int high)
{
	
	//优化不必要交换
	//优化枢轴选取
	int pivotkey;
	int m = low + (high - low) / 2;
	if (L->r[low] > L->r[high])
		//交换左端与右端数据
		swap(L, low, high);
	if (L->r[m] > L->r[high])
		//保证中间较小
		swap(L, m, high);
	if (L->r[m] > L->r[low])
		//交换，保证左端较小
		swap(L, m, low);
	//此时r[low]为中间值
	//用子表的第一个记录做枢轴记录
	pivotkey = L->r[low];
	//将枢轴关键字备份到L->r[0]
	L->r[0] = pivotkey;
	//从表的两端交替向中间扫描
	while (low < high)
	{
		while (low < high && L->r[high] >= pivotkey)
			high--;
		//采取替换而不是交换
		L->r[low] = L->r[high];
		while (low < high && L->r[low] <= pivotkey)
			low++;
		L->r[high] = L->r[low];
	}
	//将枢轴数值替换回L.r[low]
	L->r[low] = L->r[0];
	//返回枢轴位置
	return low;
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