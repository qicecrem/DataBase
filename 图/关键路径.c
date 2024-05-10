int* etv, * ltv;//�¼����緢����ʱ�����ٷ�����ʱ������
int* stack2;//���ڴ洢�����������е�ջ
int top2;//����stack2��ָ��
//�����������ڹؼ�·������
Status ToplogicalSort(GraphAdjList G)
{
	EdgeNode* e;
	int i, k, gettop;
	//����ջָ���±�
	int top;
	//����ͳ���������ĸ���
	int count = 0;
	//��ջ�����Ϊ��Ķ�����ջ
	int* stack = (int*)malloc(G->vexnum * sizeof(int));
	for (i = 0; i < G->vexnum; i++)
	{
		if (G->adjList[i].in == 0)
			stack[++top] = i;
	}
	top2 = 0;
	etv = (int*)malloc(G->vexnum * sizeof(int));
	for (i = 0; i < G->vexnum; i++)
	{
		etv[i] = 0;
	}
	stack2 = (int*)malloc(G->vexnum * sizeof(int));
	while (top != 0)
	{
		gettop = stack[top--];
		count++;
		stack2[++top2] = gettop;
		for (e = G->adjList[gettop].firstedge; e; e = e->next)
		{
			k = e->adjvex;
			if (!(--G->adjList[k].in))
				stack[++top] = k;
			if (etv[gettop] + e->weight > etv[k])
			{
				etv[k] = etv[gettop] + e->weight;
			}
		}

	}
	if (count < G->vexnum)
		return ERROR;
	else
		return OK;
}

//��ؼ�·����GΪ�����������G�ĸ���ؼ��
void CriticalPath(GraphAdjList G)
{
	EdgeNode* e;
	int i, gettop, k, j;
	//��������ҷ���ʱ�����ٷ���ʱ�����
	int ete, lte;
	//���������У���������etv��stack2��ֵ
	ToplogicalSort(G);
	//ʱ��������ʱ��
	ltv = (int*)malloc(G->vexnum * sizeof(int));
	for (i = 0; i < G->vexnum; i++)
	{
		//��ʼ��ltv;
		ltv[i] = etv[G->vexnum - 1];
	}
	//����itv
	while (top2 != 0)
	{
		//�����˳�ջ������ȳ�
		gettop = stack2[top2--];
		for (e = G->adjList[gettop].firstedge; e; e = e->next)
		{
			//��������¼�����ٷ���ʱ��ltv��ֵ
			k = e->adjvex;
			//�������ʱ��������ʱ��ltv
			if (ltv[k] - e->weight < ltv[gettop])
				ltv[gettop] = ltv[k] - e->weight;
		}
	}
	//��ete,lte�͹ؼ��
	for (j = 0; j < G->vexnum; j++)
	{
		for (e = G->adjList[j].firstedge; e; e = e->next)
		{
			k = e->adjvex;
			//����緢��ʱ��
			ete = etv[j];
			//�����ٷ���ʱ��
			lte = ltv[k] - e->weight;
			//������ȼ��ڹؽ�·��
			if (ete == lte)
			{
				printf("<v%d,v%d> length:%d", G->adjList[j].data, G->adjList[k].data, e->weight);
			}
		}
	}
}

