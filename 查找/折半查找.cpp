//折半查找
int Binary_Search(int* a, int n, int key)
{
	int low, int high, mid;
	//定义最低下标为记录首位
	low = 1;
	//定义最高下标为记录末尾
	high = n;
	while (low <= high)
	{
		//折半
		mid = (low + high) / 2;
		//若查找值比中值小
		if (key < a[mid])
		{
			//最高位下标调整到中位下标小一位
			high = mid - 1;
		}
		//若查找值比中值大
		else if (key > a[mid])
		{
			//最低下标调整到中位下标大一位
			low = mid + 1;
		}
		else
			//若相等则说明mid即为要查找的位置
			return mid;
	}
	return 0;
}