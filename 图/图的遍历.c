//无向BFS算法
#define FALSE 0
#define TRUE 1
#define MAX_VERTEX_NUM 100
bool visited[MAX_VERTEX_NUM];//访问标记数组
void BFSraverse(Graph G)//对图G进行广度优先遍历
{
	for (int i = 0; i < G.vexnum; i++)
	{
		visited[i] = FALSE;//访问标记数组初始化

	}
	InitQuenue(Q);//初始化辅助队列
	for (int i = 0; i < G.vexnum; i++)
	{
		if (!visited[i])
			BFS(G, i);//vi未访问，从vi开始BFS
	}

}

//广度优先遍历
void BFS(Graph G, int v)//从顶点v出发，广度优先遍历
{
	visit(v);//访问初始节点v
	visited[v] = TRUE;//对v做出已访问标记
	Enquenue(Q, v);//顶点v入队列
	while (!isEmpty(q))
	{
		DeQuenue(Q, v);//顶点v出队列
		for (w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w))//检测v所有邻接顶点
		{
			if (!visited[w])//w为v的尚未访问的邻接顶点
			{
				visit(w);
				visited[w] = TRUE;
				EnQuenue(Q, w);//顶点w入队列
			}
		}
	}
}


//有向图的BFS过程
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

//深度优先遍历 Depth_First_Search
#define MAX 100
//Boolean是bool类型
typedef int Boolean;
//访问标志数组
Boolean visitted[MAX];
//邻接矩阵的深度优先递归算法
void DFS(Graph g, int i)
{
	int j;
	visited[i] = True;
	printf("%c", g.vexs[i]);
	for (j = 0; j < g.vexnum; j++)
	{
		if (g.arc[i][j] == 1 && !visited[j])
		{
			//对访问的邻接节点顶点递归调用
			DFS(g, j);
		}
	}

}
//邻接矩阵深度遍历操作
void DFSTraverse(Graph g)
{
	int i;
	//初始所有顶点状态为未访问状态
	for (i = 0; i < g.vexnum; i++)
	{
		visited[i] = False;
	}
	for (i = 0; i < g.vexnum; i++)
	{
		if (!visited[i])
		{//对未访问的顶点调用DFS，若是连通图，只会执行一次
			DFS(g, i);
		}
	}
}

//邻接表的深度优先递归算法
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