int Pibonacci_Search(int* a, int n, int key)
{
	int low, high, mid, i, k;
	low = 1;
	high = n;
	k = 0;
	//����nλ��쳲��������е�λ��
	while (n > F[k] - 1);
	k++;
	//����������ֵ��ȫ
	for (i = n; i < F[k] - 1; i++)
		a[i] = a[n];
	while (low <= high)
	{
		//���㵱ǰ�ָ����±�
		mid = low + F[k - 1] - 1;
		//�����Ҽ�¼С�ڵ�ǰ�ָ���¼
		if (key < a[mid])
		{
			//����±�������ָ��±�mid-1��
			high = mid - 1;
			//쳲����������±��һλ
			k = k - 1;
		}
		//�����Ҽ�¼���ڵ�ǰ�ָ���¼
		else if (key > a[mid])
		{
			low = mid + 1;
			//쳲��������������±����λ
			k = k - 2;
		}
		else
		{
			if (mid <= n)
				//�������˵��mid��Ϊ���ҵ���λ��
				return mid;
			else
				//��mid>n˵���ǲ�ȫ��ֵ����n
				return n;
		}
	}
	return 0;
}