//顺序查找，a为数组，n为要查找的数组长度，key为要查找的关键字
int Sequential_Search(int* a, int n, int key)
{
	int i;
	for (i = 1; i <= n; i++)
	{
		if (a[i] == key)
			return i;
	}
	return 0;
}

//有哨兵顺序查找
int Sequential_Search2(int* a, int n, int key)
{
	int i;
	//设置a[0]为关键字值，称之为哨兵
	a[0] = key;
	i = n;
	while (a[i] != key)
	{
		i--;
	}
	//返回0则说明查找失败
	return i;
}