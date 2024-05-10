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

void HeapAdjust(SqList* L, int s, int m)
{
	int temp, j;
	temp = L->r[s];
	//�عؼ��ֽϴ�ĺ��ӽڵ�����ɸѡ
	for (j = 2 * s; j <= m; j *= 2)
	{
		if (j < m && L->r[j] < L->r[j + 1])
			++j;
		if (temp >= L->r[j])
			break;
		L->r[s] = L->r[j];
		s = j;

	}
	//����
	L->r[s] = temp;
}
void HeapSort(SqList* L)
{
	int i;
	//L�е�r����һ����׶
	for (i = L->length / 2; i > 0; i--)
		HeapAdjust(L, i, L->length);
	for (i = L->length; i > 1; i--)
	{
		//���Ѷ���¼�͵�ǰδ����������е����һ����¼����
		swap(L, 1, i);

		//L->r[1..i-1]���µ���Ϊ��׶
		HeapAdjust(L, 1, i - 1);
	}
	
}