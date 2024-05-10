#define SUCESS 1
#define UNSUCESS 0
//定义散列表长为数组的长度
#define HASHSIZE 12
#define NULLKEY -32768
typedef struct {
	//数据元素存储基址，动态分配数组
	int* elem;
	//当前数据元素个数
	int count;
}HashTable;
//散列表表长，全局变量
int m = 0;
//初始化散列表
Status InitHashTable(HashTable* H)
{
	int i;
	m = HASHSIZE;
	H->count = m;
	H->elem = (int*)malloc(m * sizeof(int));
	for (i = 0; i < m; i++)
		H->elem[i] = NULLKEY;
		return OK;
	
}
//散列函数
int Hash(int key)
{
	//除留余数法
	return key % m;
}
//插入关键字进散列表
void InsertHash(HashTable* H, int key)
{
	//求散列地址
	int addr = Hash(key);
	while (H->elem[addr] != NULLKEY)
		//开放定地址法的线性探测
		addr = (addr + 1) % m;
	//直到有空位后插入关键字
	H->elem[addr] = key;
}

//散列表查找关键字
Status SearchHash(HashTable H, int key, int* addr)
{
	//求散列表
	*addr = Hash(key);
	//如果不为空则冲突
	while (H.elem[*addr] != key)
	{
		//开放定址法的线性探测
		*addr = (*addr + 1) % m;
		if (H.elem[*addr] == NULLKEY || *addr == Hash(key))
		{
			//如果循环回到原点则说明关键字不存在
			return UNSUCESS;
		}
	}
	return SUCESS;
}