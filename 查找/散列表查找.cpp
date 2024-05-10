#define SUCESS 1
#define UNSUCESS 0
//����ɢ�б�Ϊ����ĳ���
#define HASHSIZE 12
#define NULLKEY -32768
typedef struct {
	//����Ԫ�ش洢��ַ����̬��������
	int* elem;
	//��ǰ����Ԫ�ظ���
	int count;
}HashTable;
//ɢ�б����ȫ�ֱ���
int m = 0;
//��ʼ��ɢ�б�
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
//ɢ�к���
int Hash(int key)
{
	//����������
	return key % m;
}
//����ؼ��ֽ�ɢ�б�
void InsertHash(HashTable* H, int key)
{
	//��ɢ�е�ַ
	int addr = Hash(key);
	while (H->elem[addr] != NULLKEY)
		//���Ŷ���ַ��������̽��
		addr = (addr + 1) % m;
	//ֱ���п�λ�����ؼ���
	H->elem[addr] = key;
}

//ɢ�б���ҹؼ���
Status SearchHash(HashTable H, int key, int* addr)
{
	//��ɢ�б�
	*addr = Hash(key);
	//�����Ϊ�����ͻ
	while (H.elem[*addr] != key)
	{
		//���Ŷ�ַ��������̽��
		*addr = (*addr + 1) % m;
		if (H.elem[*addr] == NULLKEY || *addr == Hash(key))
		{
			//���ѭ���ص�ԭ����˵���ؼ��ֲ�����
			return UNSUCESS;
		}
	}
	return SUCESS;
}