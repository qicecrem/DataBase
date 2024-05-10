//邻接矩阵法
//适合稠密图
#define MaxVertexNum 100//顶点最大个数
typedef struct {
	char Vex[MaxVertexNum];//顶点表
	int Edge[MaxVertexNum];//邻接矩阵表，边表
	int vexnum, arcnum;//图的当前顶点数，边数
};

//邻接矩阵法存储带权图
#define MaxVertexNum 100
#define INFINITY 65535 //无穷
typedef char VertexType;
typedef int EdgeType;
typedef struct {
	VertexType Vexs[MaxVertexNum];//顶点
	EdgeType Edge[MaxVertexNum][MaxVertexNum];//边的权
	int vexnum, arcnum;//图的顶点数，边数
}Graph;
//建立无向网图的邻接带权矩阵表示
void CreateGraph(Graph* g)
{
	int i,j,k, w;
	printf("输入顶点数和边数：\n");
	scanf("%d %d", &g->vexnum, &g->arcnum);
	for ( i = 0; i < g->vexnum; i++)//读入节点信息，建立定点表
	{
		scanf(&g->Vexs[i]);
	}
	//矩阵初始化
	for ( i = 0; i < g->vexnum; i++)
	{
		for (j = 0; j < g->vexnum; j++)
		{
			g->Edge[i][j] = INFINITY;
		}
	}
	//读入numEdge条边，建立邻接矩阵
	for ( k = 0; k < g->arcnum; k++)
	{
		printf("输入边的下标i，j和权值\n");
		scanf("%d,%d,%d", &i, &j, &w);
		g->Edge[i][j] = w;
		g->Edge[j][i] = w;
	}
}
//邻接表
//适合稀疏图
typedef char VertexType;
typedef int EdgeType;
typedef struct EdgeNode {
	int adjvex;//边指向的节点
	struct EdgeNode* next;//指向下一条边的节点
	EdgeType weight;//边权值
}EdgeNode;
 //顶点表节点
typedef struct VertexNode {
	VertexType data;//顶点信息
	EdgeNode* first;
}VertexNode,AdjList[MaxVertexNum];

typedef struct {
	AdjList adjList;
	int vexnum, edgnum;
}ALGraph;
//建立图的邻接表结构
void createAlGraph(ALGraph* G)
{
	int i, j, k;
	EdgeNode* e;
	printf("输入顶点数和边数");
	scanf("%d, %d", & G->vexnum, &G->edgnum);
	for (i = 0; i < G->vexnum; i++)
	{
		scanf(&G->adjList[i].data);//输入顶点信息
		G->adjList[i].first = NULL;//将边表置为空
	}
	//建立边表
	for (k = 0; k < G->edgnum; k++)
	{
		printf("输入边（vi,vj>上的顶点序号：\n");
		scanf("%d,%d", &i, &j);
		//生成表节点
		//头插法插入边
		e = (EdgeNode*)malloc(sizeof(EdgeNode));
		e->adjvex = j;
		e->next = G->adjList[i].first;
		G->adjList[i].first = e;
		//无向图一条边对应两个顶点
		e = (EdgeNode*)mallo(sizeof(EdgeNode));
		e->adjvex = i;
		e->next = G->adjList[j].first;
		G->adjList[j].first = e;
	}        
}

