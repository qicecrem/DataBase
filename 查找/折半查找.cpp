//�۰����
int Binary_Search(int* a, int n, int key)
{
	int low, int high, mid;
	//��������±�Ϊ��¼��λ
	low = 1;
	//��������±�Ϊ��¼ĩβ
	high = n;
	while (low <= high)
	{
		//�۰�
		mid = (low + high) / 2;
		//������ֵ����ֵС
		if (key < a[mid])
		{
			//���λ�±��������λ�±�Сһλ
			high = mid - 1;
		}
		//������ֵ����ֵ��
		else if (key > a[mid])
		{
			//����±��������λ�±��һλ
			low = mid + 1;
		}
		else
			//�������˵��mid��ΪҪ���ҵ�λ��
			return mid;
	}
	return 0;
}