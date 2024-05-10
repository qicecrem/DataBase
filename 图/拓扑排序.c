//拓扑排序算法
//边表界点
typedef struct EdgeNode {
	//邻接点域，存储该点对应下标
	int adjvex;
	//存储边权值，对于非网图可以不需要
	int weight;
	//链域，指向下一个邻接点
	struct EdgeNOde* next;
}EdgeNode;

//顶点表节点
typedef struct VertexNode {
	//顶点入度
	int in;
	//顶点域存储顶点信息
	int data;
	//边表头指针
	EdgeNode* firstedge;
}VertexNode,AdjList[MAXVEX];

typedef struct
{
	AdjList adjlist;
	//图中当前顶点数和边数
	int vexnum, edgenum;
}graphAdjList,*GraphAdjList;
//拓扑排序，若GL无回路，则输出拓扑排序并返回OK，若有回路返回ERROR
Status TopologicalSort(GraphAdjList GL)
{
	EdgeNode* e;
	int i, k, gettop;
	//用于栈顶指针下标
	int top = 0;
	//用于统计输出定点数
	int count = 0;
	//建栈存储入度为0的顶点
	int* stack;
	stack = (int*)malloc(GL->vexnum * sizeof(int));
	for (i = 0; i < GL->vexnum; i++)
	{
		if (GL->adjlist[i].in == 0)
		{
			//将入度为零的点入栈
			stack[++top] = i;
		}
		while (top != 0)
		{
			//出栈
			gettop = stack[top--];
			//打印此顶点
			printf("%d->", GL->adjlist[gettop].data);
			count++;
			//对此顶点弧表进行遍历
			for (e = GL->adjList[gettop].firstedge; e; e = e->next)
			{
				k = e->adjvex;
				//将k号顶点邻接点的入度减一
				if (!(--GL->adjList[k].in))
				{
					//若为零则入栈，以便下一次循环
					stack[++top] = k;
				}
			}
			//如果count小于顶点数，说明存在环
			if (count < GL->vexnum)
			{
				return ERROR;
			}
			else
				return OK;
		}
	}

}

