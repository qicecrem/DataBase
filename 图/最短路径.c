//Di jkstra�㷨
#define MAXVEX 9
#define INFINITY 65535
typedef int Patharc[MAXVEX];//���ڴ洢���·���±������
typedef int ShortPathtable[MAXVEX];//���ڴ洢�������·��Ȩֵ��
//Dijkstra�㷨��������ͼ��v0���㵽���ඥ�����·���¡�v������Ȩ����D��v��
//P[v]��ֵΪǰ�������±꣬D��v����ʾ��v0��v�����·������
void ShorttestPath(Graph G, int v0, Patharc* P, ShortPathtable* D)
{
	int v, w, k, min;
	//final[w]=1��ʾ��ö���v0��vw�����·��
	int final[MAXVEX];
	//��ʼ������
	for (v = 0; v < G.vexnum; v++)
	{
		//ȫ�������ʼ��Ϊλ�����·��״̬
		final[v] = 0;
		//����v0�������ߵĶ������Ȩֵ
		(*D)[v] = G.arc[v0][v];
		//��ʼ��·������ΪPΪ-1
		(*P)[v] = -1;
	}
	//v0��v0·��Ϊ0
	(*D)[v0] = 0;
	//v0��v0����Ҫ��·��
	final[v0] = 1;
	//��ʼ��ѭ����ÿ�����v0��ĳ��v��������·��
	for (v = 1; v < G.vexnum; v++)
	{
		min = INFINITY;
		//Ѱ����v0����Ķ���
		for (w = 0; w < G.vexnum; w++)
		{
			if (!final[w] && (*D)[w] < min)
			{
				k = w;
				min = (*D)[w];
			}
		}

		//��Ŀǰ�ҵ�����ڵ�Ķ�����Ϊ1
		final[k] = 1;
		//�޸ĵ�ǰ���·��������
		for (w = 0; w < G.vexnum; w++)
		{
			if (!final[w] && (min + G.arc[k][w] < (*D)[w]))
			{
				//˵���ҵ��˸��̵�·�����޸�D[w]��P[w]
				//�޸ĵ�ǰ·������
				(*D)[w] = min + G.arc[k][w];
				(*P)[w] = k;
			}
		}
	}
}




//Floyd�㷨����ͼ�и�����v�����ඥ��w�����·��p[v][w]����ȫ����D[v][w]
typedef int Pathmatirx[MAXVEX][MAXVEX];//���·��Ȩֵ�;���
typedef int ShortPathTable[MAXVEX][MAXVEX];//���·��ǰ������
//
void ShorttestPath_Floyd(Graph G,Pathmatirx *P,ShortPathTable *D)
{
	int v, w, k;
	//��ʼ��D��P
	for (v = 0; v < G.vexnum; v++)
	{
		for (w = 0; w < G.vexnum; w++)
		{
			//D[v][w]��ֵ��Ϊ������Ȩֵ
			(*D)[v][w] = G.matrix[v][w];
			//��ʼ��P
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
					//��������±�Ϊk����·����ԭ�����·������
					//����ǰ�����ȫȨֵ��Ϊ��С��һ��
					(*D)[v][w] = (*D)[v][k] + (*D)[k][w];
					//·�����þ����±�Ϊk�Ķ���
					(*P)[v][w] = k;
				}
			}
		}

	}

}
//��ʾ����
for (v = 0; v < G.vexnum; v++)
{
	for (w = v + 1; w < G.vexnum; w++)
	{
		printf("v%d-v%d weight: %d", v, w, D[v][w]);
		//��õ�һ·�������±�
		k = P[v][w];
		//��ӡԴ��
		printf("path: %d", v);
		//���·�������±겻���е�
		while (k != w)
		{
			//��ӡ·������
			printf("->%d", k);
			k = P[k][w];
		}
		//��ӡ�յ�
		printf("->%d", w);
	}
	printf("\n");
}