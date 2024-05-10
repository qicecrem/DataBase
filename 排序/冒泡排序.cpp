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
//ð�ݳ���
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

//ð������
void BubbleSort(SqList* L)
{
	int i, j;
	for (i = 1; i < L->length; i++)
	{
		//�Ӻ���ǰѭ��
		for (j = L->length - 1; j >= i; j--)
		{
			if (L->r[j] > L->r[1 + j])
				swap(L, j, j + 1);
		}
	}
}

//ð������Ľ�
void BubbleSort2(SqList* L)
{
	int i, j;
	//flag������Ϊ���
	Status flag = True;
	for (i = 1; i < L->length && flag; i++)
	{
		//��ʼ��flag
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