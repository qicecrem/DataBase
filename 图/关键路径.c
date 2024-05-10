int* etv, * ltv;//事件最早发生的时间和最迟发生的时间数组
int* stack2;//用于存储拓扑排序序列的栈
int top2;//用于stack2的指针
//拓扑排序，用于关键路径计算
Status ToplogicalSort(GraphAdjList G)
{
	EdgeNode* e;
	int i, k, gettop;
	//用于栈指针下标
	int top;
	//用于统计输出顶点的个数
	int count = 0;
	//建栈将入度为零的顶点入栈
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

//求关键路径，G为有向网，输出G的各项关键活动
void CriticalPath(GraphAdjList G)
{
	EdgeNode* e;
	int i, gettop, k, j;
	//声明活动最找发生时间和最迟发生时间变量
	int ete, lte;
	//求拓扑序列，计算数组etv和stack2的值
	ToplogicalSort(G);
	//时间最晚发生时间
	ltv = (int*)malloc(G->vexnum * sizeof(int));
	for (i = 0; i < G->vexnum; i++)
	{
		//初始化ltv;
		ltv[i] = etv[G->vexnum - 1];
	}
	//计算itv
	while (top2 != 0)
	{
		//将拓扑出栈，后进先出
		gettop = stack2[top2--];
		for (e = G->adjList[gettop].firstedge; e; e = e->next)
		{
			//求各顶点事件的最迟发生时间ltv的值
			k = e->adjvex;
			//求个顶点时间最晚发生时间ltv
			if (ltv[k] - e->weight < ltv[gettop])
				ltv[gettop] = ltv[k] - e->weight;
		}
	}
	//求ete,lte和关键活动
	for (j = 0; j < G->vexnum; j++)
	{
		for (e = G->adjList[j].firstedge; e; e = e->next)
		{
			k = e->adjvex;
			//活动最早发生时间
			ete = etv[j];
			//获得最迟发生时间
			lte = ltv[k] - e->weight;
			//两者相等即在关建路径
			if (ete == lte)
			{
				printf("<v%d,v%d> length:%d", G->adjList[j].data, G->adjList[k].data, e->weight);
			}
		}
	}
}

