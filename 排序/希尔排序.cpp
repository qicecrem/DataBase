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
void ShellSort(SqList* L)
{
	int i, j;
	int incream = L->length;
	do {
		//��������
		incream = incream / 3 + 1;
		for (i = incream + 1; i <= L->length; i++)
		{
			if (L->r[i] < L->r[i - incream])
			{
				//��Ҫ��L->r[i]�������������ӱ�
				//�ݴ���L->r[0]
				L->r[0] = L->r[i];
				for (j = i - incream; j > 0 && L->r[0] < L->r[j]; j -= incream)
					//��¼���ƣ����Ҳ���λ��
					L->r[j + incream] = L->r[i];
				//����
				L->r[j + incream] = L -> r[0];

			}
		}
	} while (incream > 1);
}