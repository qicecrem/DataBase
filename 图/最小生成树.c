//prime算法生成最小生成树
void MiniSpanTree(Graph G)
{
	int min, i, j, k;
	int adjvex[MAXVEX];//保存相关顶点下标
	int lowcost[MAXVEX];//保存顶点间边的权值
	lowcost[0] = 0;
	//初始化第一个顶点下标
	adjvex[0] = 0;
	//循环出下标为0的全部顶点
	for (i = 1; i < G.vexnum; i++)
	{
		//将v0顶点与之有边的权值存入数组
		lowcost[i] = G.arc[0][i];
		adjvex[i] = 0;
	}
	for (i = 1; i < G.vexnum; i++)
	{
		//初始化最小权值
		min = INFINITY;
		j = 1; k = 0;
		//循环全部节点
		while (j < G.vexnum)
		{
			if (lowcost[j] != 0 && lowcost[j] < min)
			{
				//则让当前权值为最小值
				min = lowcost[j];
				k = j;
			}
			j++;
		}
		//打印当前顶点边中权值最小边
		printf("(%d,%d)", adjvex[k], k);
		//将当前顶点边中权值设置为0，表示顶点已经完成任务
		lowcost[k] = 0;
		//再次循环更新还没加入的各个顶点的lowcost值
		for (j = 1; j < G.vexnum; j++)//
		{
			if (lowcost[j] != 0 && G.arc[k][j] < lowcost[j])
			{
				//将较小权值存入lowcost
				lowcost[j] = G.arc[k][j];
				adjvex[j] = k;
			}
		}
	}
}


//Kruskal算法
//对边集组edge结构的定义
typedef struct {
	int begin;
	int end;
	int weight;
}Edge;

//生成最小生成树
void MiniSpanTree(Graph G)
{
	int i, n, m;
	Edge edges[MAX];
		//定义一组数组判断边与边是否形成环路
	int parent[MAX];
	//将邻接矩阵转化为边集数组,并按由小到大排序
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
		//如n与m不相等则说明此边与现有生成树没有生成回路
		if (n != m)
		{
	//将此边的尾节点放入下标为起点的parent中
			//表示此顶点已在生成树集合中
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