//string����������

int Index(string s, string t, int pos)
{
	int i = pos;
	int j = 1;
	while (i <= strlen(s) && j <= strlen(t))
	{
		if (s[i] == t[j])
		{
			i++;
			j++;
		}
		/*
ָ��������¿�ʼƥ�� */
		else
		{
			/* i�˻ص��ϴ�ƥ����λ����һλ */
			i = i - j + 2;
			j = 1;
		}
	}
	if (j = strlen��t))
	{
	return i - j;
}
	else
		return 0;
}