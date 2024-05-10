#define MAXSIZE 10
typedef struct {
	//���ڴ洢�������飬r[0]�����ڱ�����ʱ����
	int r[MAXSIZE + 1];
	//��¼˳�����
	int length;
}SqList;
//����Ԫ��
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
//��˳�����п�������
void QSort(SqList* L, int low, int high)
{
	int pivot;
	if (low < high)
	{
		//��L->r[low..high]һ��Ϊ��
		//�������ֵpivot
		pivot = Partition(L, low, high);
		//�Ե��ӱ�ݹ�����
		QSort(L, low, pivot - 1);
		//�Ը��ӱ�ݹ�����
		QSort(L, pivot + 1, high);

	}
}
/* ����˳���L���ӱ�ļ�¼��ʹ�����¼��λ��������������λ�� */
/* ��ʱ����֮ǰ���󣩵ļ�¼������С�������� */
int Partition(SqList* L, int low, int high)
{
	int pivotkey;
	//���ӱ�ĵ�һ����¼�������¼
	pivotkey = L->r[low];
	//�ӱ�����˽������м�ɨ��
	while (low < high)
	{
		while (low < high && L->r[high] >= pivotkey)
			high--;
			//���������¼С�ļ�¼�������Ͷ�
			swap(L, low, high);
			while (low < high && L->r[low] <= pivotkey)
				low++;
			swap(L, low, high);
		
	}
	return low;
}


















//���������Ż�
#define MAX_INSERT_SORT 7
void QuickSort(SqList* L)
{
	QSort(L, 1, L->length);
}
//��˳�����п�������
void QSort(SqList* L, int low, int high)
{
	//�Ż�С��������
//�Ż��ݹ�
	int pivot;
	if ((high - low) > MAX_INSERT_SORT)
	{
		while(low < high)
		{
			//��L->r[low..high]һ��Ϊ��
			//�������ֵpivot
			pivot = Partition(L, low, high);
			//�Ե��ӱ�ݹ�����
			QSort(L, low, pivot - 1);
			//β�ݹ�
			low = pivot + 1;
		}
	}
	else
		InsertSort(L);
}
int Partition(SqList* L, int low, int high)
{
	
	//�Ż�����Ҫ����
	//�Ż�����ѡȡ
	int pivotkey;
	int m = low + (high - low) / 2;
	if (L->r[low] > L->r[high])
		//����������Ҷ�����
		swap(L, low, high);
	if (L->r[m] > L->r[high])
		//��֤�м��С
		swap(L, m, high);
	if (L->r[m] > L->r[low])
		//��������֤��˽�С
		swap(L, m, low);
	//��ʱr[low]Ϊ�м�ֵ
	//���ӱ�ĵ�һ����¼�������¼
	pivotkey = L->r[low];
	//������ؼ��ֱ��ݵ�L->r[0]
	L->r[0] = pivotkey;
	//�ӱ�����˽������м�ɨ��
	while (low < high)
	{
		while (low < high && L->r[high] >= pivotkey)
			high--;
		//��ȡ�滻�����ǽ���
		L->r[low] = L->r[high];
		while (low < high && L->r[low] <= pivotkey)
			low++;
		L->r[high] = L->r[low];
	}
	//��������ֵ�滻��L.r[low]
	L->r[low] = L->r[0];
	//��������λ��
	return low;
}
void InsertSort(SqList* L)
{
	int i, j;
	for (i = 2; i < L->length; i++)
	{
		if (L->r[i] < L->r[i - 1])
		{
			//�����ڱ�
			L->r[0] = L->r[i];
			for (j = i - 1; L->r[j] > L->r[0]; j--)
			{
				L->r[j + 1] = L->r[j];
			}
			//�嵽��ȷλ��
			L->r[j + 1] = L->r[0];
		}
	}
}