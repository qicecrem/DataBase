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