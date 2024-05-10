//���������㷨
//�߱���
typedef struct EdgeNode {
	//�ڽӵ��򣬴洢�õ��Ӧ�±�
	int adjvex;
	//�洢��Ȩֵ�����ڷ���ͼ���Բ���Ҫ
	int weight;
	//����ָ����һ���ڽӵ�
	struct EdgeNOde* next;
}EdgeNode;

//�����ڵ�
typedef struct VertexNode {
	//�������
	int in;
	//������洢������Ϣ
	int data;
	//�߱�ͷָ��
	EdgeNode* firstedge;
}VertexNode,AdjList[MAXVEX];

typedef struct
{
	AdjList adjlist;
	//ͼ�е�ǰ�������ͱ���
	int vexnum, edgenum;
}graphAdjList,*GraphAdjList;
//����������GL�޻�·��������������򲢷���OK�����л�·����ERROR
Status TopologicalSort(GraphAdjList GL)
{
	EdgeNode* e;
	int i, k, gettop;
	//����ջ��ָ���±�
	int top = 0;
	//����ͳ�����������
	int count = 0;
	//��ջ�洢���Ϊ0�Ķ���
	int* stack;
	stack = (int*)malloc(GL->vexnum * sizeof(int));
	for (i = 0; i < GL->vexnum; i++)
	{
		if (GL->adjlist[i].in == 0)
		{
			//�����Ϊ��ĵ���ջ
			stack[++top] = i;
		}
		while (top != 0)
		{
			//��ջ
			gettop = stack[top--];
			//��ӡ�˶���
			printf("%d->", GL->adjlist[gettop].data);
			count++;
			//�Դ˶��㻡����б���
			for (e = GL->adjList[gettop].firstedge; e; e = e->next)
			{
				k = e->adjvex;
				//��k�Ŷ����ڽӵ����ȼ�һ
				if (!(--GL->adjList[k].in))
				{
					//��Ϊ������ջ���Ա���һ��ѭ��
					stack[++top] = k;
				}
			}
			//���countС�ڶ�������˵�����ڻ�
			if (count < GL->vexnum)
			{
				return ERROR;
			}
			else
				return OK;
		}
	}

}

