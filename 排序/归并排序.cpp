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
void MergeSort(SqList* L)
{
	MSort(L->r, L->r, 1, L->length);
}
void MSort(int SR[], int TR1[], int s, int t)
{
	int m;
	int TR2[MAXSIZE + 1];
	if (s == t)
	{
		TR1[s] = SR[s];
	}
	else
	{
		//��SR[s..t]ƽ��SR[s..m]��SR[m+1..t]
		m = (s + t) / 2;
		//�ݹ齫SR[s..m]�鲢Ϊ�����TR2[s..m]
		MSort(SR, TR2, s, m);
		//�ݹ齫SR[m+1..t]�鲢Ϊ�����TR2[m+1..t]
		MSort(SR, TR2, m + 1, t);
			//��TR2[s..m]��TR2[m+1..t]�鲢��TR1[s..t]
			Merge(TR2, TR1, s, m, t);
	}

}

void Merge(int SR[], int TR[], int i, int m, int n)
{
	int j, k, l;
	//��SR�м�¼��С������TR
	for (j = m + 1, k = i; i <= m && j <= n; k++)
	{
		if (SR[i] < SR[j])
			TR[k] = SR[i++];
		else
			TR[k] = SR[j++];
	}
	if (i <= m)
	{
		for (l = 0; l <= m - 1; l++)//��ʣ���SR[i..m]���Ƶ�TR
			TR[k + 1] = SR[i + 1];

	}
	if (j <= n)
	{
		for (l = 0; l <= n - j; l++)
		{//��ʣ���SR[j..n]���Ƶ�TR
			TR[k + 1] = SR[j + 1];
		}
	}
}


//�ǵݹ�Ĺ鲢����
void MergeSort2(SqList* L)
{
	//�������ռ�
	int* TR = (int*)malloc(L->length * sizeof(int));
	int k = 1;
	while (k < L->length)
	{
		MergePass(L->r, TR, k, L->length);
		//�����г��ȼӱ�
		k = 2 * k;
		MergePass(TR, L->r, k, L->length);
		//�����г��ȼӱ�
		k = 2 * k;
	}
}
void MergePass(int SR[], int TR[], int s, int n)
{
	int i = 1;
	int j;
	while (i <= n - 2 * s + 1)
	{
		//�����鲢
		Merge(SR, TR, i, i + s - 1, i + 2 * s - 1);
		i = i + 2 * s;
	}
	//�鲢�����������
	if (i < n - s + 1)
	{
		Merge(SR, TR, i, i + s - 1, n);

	}
	else
		for (j = i; j <= n; j++)
			TR[j] = SR[j];
}