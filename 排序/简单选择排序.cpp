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
void SelctSort(SqList* L)
{
	int i, j, min;
	for (i = 1; i < L->length; i++)
	{
		//����ǰ�±궨��Ϊ��Сֵ�±�
		min = i;
		//ѭ��֮����±�
		for (j = i + 1; j <= L->length; j++)
		{
			//�����С����Сֵ�Ĺؼ���
			if (L->r[min] > L->r[j])
			{
				min = j;

			}

		}
//		��min������i��˵���ҵ���Сֵ
		if (i != min)
		{
			//����L->r[i]��L->r[min]��ֵ
			swap(L, i, min);
	    }
	}
}
