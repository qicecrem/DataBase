//�ڽӾ���
//�ʺϳ���ͼ
#define MaxVertexNum 100//����������
typedef struct {
	char Vex[MaxVertexNum];//�����
	int Edge[MaxVertexNum];//�ڽӾ�����߱�
	int vexnum, arcnum;//ͼ�ĵ�ǰ������������
};

//�ڽӾ��󷨴洢��Ȩͼ
#define MaxVertexNum 100
#define INFINITY 65535 //����
typedef char VertexType;
typedef int EdgeType;
typedef struct {
	VertexType Vexs[MaxVertexNum];//����
	EdgeType Edge[MaxVertexNum][MaxVertexNum];//�ߵ�Ȩ
	int vexnum, arcnum;//ͼ�Ķ�����������
}Graph;
//����������ͼ���ڽӴ�Ȩ�����ʾ
void CreateGraph(Graph* g)
{
	int i,j,k, w;
	printf("���붥�����ͱ�����\n");
	scanf("%d %d", &g->vexnum, &g->arcnum);
	for ( i = 0; i < g->vexnum; i++)//����ڵ���Ϣ�����������
	{
		scanf(&g->Vexs[i]);
	}
	//�����ʼ��
	for ( i = 0; i < g->vexnum; i++)
	{
		for (j = 0; j < g->vexnum; j++)
		{
			g->Edge[i][j] = INFINITY;
		}
	}
	//����numEdge���ߣ������ڽӾ���
	for ( k = 0; k < g->arcnum; k++)
	{
		printf("����ߵ��±�i��j��Ȩֵ\n");
		scanf("%d,%d,%d", &i, &j, &w);
		g->Edge[i][j] = w;
		g->Edge[j][i] = w;
	}
}
//�ڽӱ�
//�ʺ�ϡ��ͼ
typedef char VertexType;
typedef int EdgeType;
typedef struct EdgeNode {
	int adjvex;//��ָ��Ľڵ�
	struct EdgeNode* next;//ָ����һ���ߵĽڵ�
	EdgeType weight;//��Ȩֵ
}EdgeNode;
 //�����ڵ�
typedef struct VertexNode {
	VertexType data;//������Ϣ
	EdgeNode* first;
}VertexNode,AdjList[MaxVertexNum];

typedef struct {
	AdjList adjList;
	int vexnum, edgnum;
}ALGraph;
//����ͼ���ڽӱ�ṹ
void createAlGraph(ALGraph* G)
{
	int i, j, k;
	EdgeNode* e;
	printf("���붥�����ͱ���");
	scanf("%d, %d", & G->vexnum, &G->edgnum);
	for (i = 0; i < G->vexnum; i++)
	{
		scanf(&G->adjList[i].data);//���붥����Ϣ
		G->adjList[i].first = NULL;//���߱���Ϊ��
	}
	//�����߱�
	for (k = 0; k < G->edgnum; k++)
	{
		printf("����ߣ�vi,vj>�ϵĶ�����ţ�\n");
		scanf("%d,%d", &i, &j);
		//���ɱ�ڵ�
		//ͷ�巨�����
		e = (EdgeNode*)malloc(sizeof(EdgeNode));
		e->adjvex = j;
		e->next = G->adjList[i].first;
		G->adjList[i].first = e;
		//����ͼһ���߶�Ӧ��������
		e = (EdgeNode*)mallo(sizeof(EdgeNode));
		e->adjvex = i;
		e->next = G->adjList[j].first;
		G->adjList[j].first = e;
	}        
}

