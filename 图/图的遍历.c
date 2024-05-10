//����BFS�㷨
#define FALSE 0
#define TRUE 1
#define MAX_VERTEX_NUM 100
bool visited[MAX_VERTEX_NUM];//���ʱ������
void BFSraverse(Graph G)//��ͼG���й�����ȱ���
{
	for (int i = 0; i < G.vexnum; i++)
	{
		visited[i] = FALSE;//���ʱ�������ʼ��

	}
	InitQuenue(Q);//��ʼ����������
	for (int i = 0; i < G.vexnum; i++)
	{
		if (!visited[i])
			BFS(G, i);//viδ���ʣ���vi��ʼBFS
	}

}

//������ȱ���
void BFS(Graph G, int v)//�Ӷ���v������������ȱ���
{
	visit(v);//���ʳ�ʼ�ڵ�v
	visited[v] = TRUE;//��v�����ѷ��ʱ��
	Enquenue(Q, v);//����v�����
	while (!isEmpty(q))
	{
		DeQuenue(Q, v);//����v������
		for (w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w))//���v�����ڽӶ���
		{
			if (!visited[w])//wΪv����δ���ʵ��ڽӶ���
			{
				visit(w);
				visited[w] = TRUE;
				EnQuenue(Q, w);//����w�����
			}
		}
	}
}


//����ͼ��BFS����
bool visited[MAX_VERTEX_NUM];
void BFSraverse(Graph G)
{
	for (int i = 0; i < G.vexnum; i++)
	{
		visited[i] = FALSE;
	}
	InitQuenue(Q);
	for (int i = 0; i < G.vexnum; i++)
	{
		if (!visited[i])
		{
			BFS(G, i);
		}
	}
}

void BFS(Graph, G, int v)
{
	visit(v);
	visited[v] = TRUE;
	Enquenue(Q, v);
	while (!isEmpty(Q))
	{
		DeQuenue(Q, v);
		for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w))
		{
			if (!visited[w])
			{
				visit(w);
				visited[w] = TRUE;
				EnQuenue(Q, w);

			}
		}
	}
}

//������ȱ��� Depth_First_Search
#define MAX 100
//Boolean��bool����
typedef int Boolean;
//���ʱ�־����
Boolean visitted[MAX];
//�ڽӾ����������ȵݹ��㷨
void DFS(Graph g, int i)
{
	int j;
	visited[i] = True;
	printf("%c", g.vexs[i]);
	for (j = 0; j < g.vexnum; j++)
	{
		if (g.arc[i][j] == 1 && !visited[j])
		{
			//�Է��ʵ��ڽӽڵ㶥��ݹ����
			DFS(g, j);
		}
	}

}
//�ڽӾ�����ȱ�������
void DFSTraverse(Graph g)
{
	int i;
	//��ʼ���ж���״̬Ϊδ����״̬
	for (i = 0; i < g.vexnum; i++)
	{
		visited[i] = False;
	}
	for (i = 0; i < g.vexnum; i++)
	{
		if (!visited[i])
		{//��δ���ʵĶ������DFS��������ͨͼ��ֻ��ִ��һ��
			DFS(g, i);
		}
	}
}

//�ڽӱ��������ȵݹ��㷨
void DFS(GraphAdjlist G, int i)
{
	EdgeNode* p;
	visited[i] = True;
	printf("%c", G->adjlist[i].data);
	p = G->adjlist[i].firstedge;
	while (p)
	{
		if (!visited[p->adjvex])
			DFS(G, p->adjvex);
		p = p->next;
	}
}

void DFSTraverse(GraphAdjlist G)
{
	int i;
	for (i = 0; i < G->vexnum; i++) {
		visited[i] = False;

	}
	for (i = 0; i < G->vexnum; i++)
	{
		if (!visited[i])
			DFS(G, i);
	}
}