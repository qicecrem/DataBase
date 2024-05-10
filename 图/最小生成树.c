//prime�㷨������С������
void MiniSpanTree(Graph G)
{
	int min, i, j, k;
	int adjvex[MAXVEX];//������ض����±�
	int lowcost[MAXVEX];//���涥���ߵ�Ȩֵ
	lowcost[0] = 0;
	//��ʼ����һ�������±�
	adjvex[0] = 0;
	//ѭ�����±�Ϊ0��ȫ������
	for (i = 1; i < G.vexnum; i++)
	{
		//��v0������֮�бߵ�Ȩֵ��������
		lowcost[i] = G.arc[0][i];
		adjvex[i] = 0;
	}
	for (i = 1; i < G.vexnum; i++)
	{
		//��ʼ����СȨֵ
		min = INFINITY;
		j = 1; k = 0;
		//ѭ��ȫ���ڵ�
		while (j < G.vexnum)
		{
			if (lowcost[j] != 0 && lowcost[j] < min)
			{
				//���õ�ǰȨֵΪ��Сֵ
				min = lowcost[j];
				k = j;
			}
			j++;
		}
		//��ӡ��ǰ�������Ȩֵ��С��
		printf("(%d,%d)", adjvex[k], k);
		//����ǰ�������Ȩֵ����Ϊ0����ʾ�����Ѿ��������
		lowcost[k] = 0;
		//�ٴ�ѭ�����»�û����ĸ��������lowcostֵ
		for (j = 1; j < G.vexnum; j++)//
		{
			if (lowcost[j] != 0 && G.arc[k][j] < lowcost[j])
			{
				//����СȨֵ����lowcost
				lowcost[j] = G.arc[k][j];
				adjvex[j] = k;
			}
		}
	}
}


//Kruskal�㷨
//�Ա߼���edge�ṹ�Ķ���
typedef struct {
	int begin;
	int end;
	int weight;
}Edge;

//������С������
void MiniSpanTree(Graph G)
{
	int i, n, m;
	Edge edges[MAX];
		//����һ�������жϱ�����Ƿ��γɻ�·
	int parent[MAX];
	//���ڽӾ���ת��Ϊ�߼�����,������С��������
		i = 0;
	for (n = 0; n < G.vexnum; n++)
	{
		for (m = 0; m < G.vexnum; m++)
		{
			if (G.arc[n][m] != 0 && G.arc[n][m] < INFINITY)
			{
				edges[i].begin = n;
				edges[i].end = m;
				edges[i].weight = G.weight;
			}
		}
	}
	sort(edges[MAX]);

	//
	for (i = 0; i < G.vexnum; i++)
	{
		parent[i] = 0;
	}
	for (i = 0; i < G.vexnum; i++)
	{
		n = Find(parent, edges[i].begin);
		m = Find(parent, edges[i].end);
		//��n��m�������˵���˱�������������û�����ɻ�·
		if (n != m)
		{
	//���˱ߵ�β�ڵ�����±�Ϊ����parent��
			//��ʾ�˶�������������������
			parent[n] = m;
			printf("(%d,%d) %d", edges[i].begin, edges[i].end, edges[i].weight);
		}
	}
}

int Find(int* parent, int f)
{
	while (parent[f] > 0)
		f = parent[f];
	return f;
}