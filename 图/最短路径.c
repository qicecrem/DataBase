//Di jkstra算法
#define MAXVEX 9
#define INFINITY 65535
typedef int Patharc[MAXVEX];//用于存储最短路径下标的数组
typedef int ShortPathtable[MAXVEX];//用于存储各点最短路径权值和
//Dijkstra算法，求有向图的v0顶点到其余顶点最短路径怕【v】及带权长度D【v】
//P[v]的值为前驱顶点下标，D【v】表示从v0到v的最短路径长度
void ShorttestPath(Graph G, int v0, Patharc* P, ShortPathtable* D)
{
	int v, w, k, min;
	//final[w]=1表示求得顶点v0到vw的最短路径
	int final[MAXVEX];
	//初始化数据
	for (v = 0; v < G.vexnum; v++)
	{
		//全部顶点初始化为位置最短路径状态
		final[v] = 0;
		//将与v0点有连线的顶点加上权值
		(*D)[v] = G.arc[v0][v];
		//初始化路径数组为P为-1
		(*P)[v] = -1;
	}
	//v0至v0路径为0
	(*D)[v0] = 0;
	//v0至v0不需要求路径
	final[v0] = 1;
	//开始主循环，每次求得v0到某个v顶点的最短路径
	for (v = 1; v < G.vexnum; v++)
	{
		min = INFINITY;
		//寻找离v0最近的顶点
		for (w = 0; w < G.vexnum; w++)
		{
			if (!final[w] && (*D)[w] < min)
			{
				k = w;
				min = (*D)[w];
			}
		}

		//将目前找到最近节点的顶点置为1
		final[k] = 1;
		//修改当前最短路径及距离
		for (w = 0; w < G.vexnum; w++)
		{
			if (!final[w] && (min + G.arc[k][w] < (*D)[w]))
			{
				//说明找到了更短的路径，修改D[w]和P[w]
				//修改当前路径长度
				(*D)[w] = min + G.arc[k][w];
				(*P)[w] = k;
			}
		}
	}
}




//Floyd算法求网图中各顶点v到其余顶点w的最短路径p[v][w]及带全长度D[v][w]
typedef int Pathmatirx[MAXVEX][MAXVEX];//最短路径权值和矩阵
typedef int ShortPathTable[MAXVEX][MAXVEX];//最短路径前驱矩阵
//
void ShorttestPath_Floyd(Graph G,Pathmatirx *P,ShortPathTable *D)
{
	int v, w, k;
	//初始化D与P
	for (v = 0; v < G.vexnum; v++)
	{
		for (w = 0; w < G.vexnum; w++)
		{
			//D[v][w]的值即为定义点的权值
			(*D)[v][w] = G.matrix[v][w];
			//初始化P
			(*P)[v][w] = w;

		}
	}
	for (k = 0; k < G.vexnum; k++)
	{
		for (v = 0; v < G.vexnum; v++)
		{
			for (w = 0; w < G.vexnum; w++)
			{
				if ((*D)[v][w] > (*D)[v][k] + (*D)[k][w])
				{
					//如果经过下标为k顶点路径比原两点见路径更短
					//将当前两点间全权值设为更小的一个
					(*D)[v][w] = (*D)[v][k] + (*D)[k][w];
					//路径设置经过下标为k的顶点
					(*P)[v][w] = k;
				}
			}
		}

	}

}
//显示代码
for (v = 0; v < G.vexnum; v++)
{
	for (w = v + 1; w < G.vexnum; w++)
	{
		printf("v%d-v%d weight: %d", v, w, D[v][w]);
		//获得第一路径顶点下标
		k = P[v][w];
		//打印源点
		printf("path: %d", v);
		//如果路径顶点下标不是中点
		while (k != w)
		{
			//打印路径顶点
			printf("->%d", k);
			k = P[k][w];
		}
		//打印终点
		printf("->%d", w);
	}
	printf("\n");
}