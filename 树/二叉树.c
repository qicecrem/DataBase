#include<stdio.h>
#include<stdlib.h>
typedef char ElemType;
typedef struct BiTNode {
	ElemType data;
	struct BiTNode* lchild, * rchild;
}BiTNode,*BiTree;

/* ��������ǰ������ݹ��㷨 */
void PreOrderTraverse(BiTree T)
{
	if (T == NULL)
	{
		return;
	}
	printf("%c", T->data);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}

/* ����������������ݹ��㷨 */
void InOrderTraverse(BiTree T)
{
	if (T == NULL)
	{
		return;
	}
	InOrderTraverse(T->lchild);
		printf("%c", T->data);
		InOrderTraverse(T->rchild);
}

/* �������ĺ�������ݹ��㷨 */
void PostOrderTraverse(BiTree T)
{
	if (T == NULL)
	{
		return;
	}
	PostOrderTraverse(T->lchild);
	PostOrderTraverse(T->rchild);
	printf("%c", T->data);
}

/* ��ǰ������������н���ֵ��һ���ַ��� */
//#��ʾ������������������ʾ������T��
void CreateBiTree(BiTree* T)
{
	ElemType ch;
	scanf("%c", &ch);
	if (ch == '#')
	{
		*T = NULL;
	}
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		if (!*T)
		{
			exit(0);
		}
		/*���ɸ���� */
		(*T)->data = ch;
		/*���������� */
		CreateBiTree(&(*T)->lchild);
		/*���������� */
		CreateBiTree(&(*T)->rchild);
	}
}


/*�������Ķ��������洢�ṹ����* /
/* Link==0��ʾָ�����Һ���ָ�� */
/* Thread==1��ʾָ��ǰ�����̵����� */
typedef enum{Link,Thread} PointerTag;
typedef struct BiThrNode {
	ElemType data;
	struct BiThrNode* lchild, * rchild;
	/*���ұ�־ */
	PointerTag LTag;
	PointerTag RTag;
}BiThrNode,*BiThrTree;
/* ȫ�ֱ�����ʼ��ָ��ոշ��ʹ��Ľ�� */
BiThrTree pre;
/* ��������������������� */
void InThreading(BiThrTree p)
{
	if (p)
	{
		InThreading(p->lchild);
		/*û������ */
		if (!p->lchild)
		{
			p->LTag = Thread;
			p->lchild = pre;
		}
		if (!pre->rchild)
		{
			pre->RTag = Thread;
			pre->rchild = p;
		}
		pre = p;
		InThreading(p->rchild);
	}
}


/* Tָ��ͷ��㣬ͷ�������lchildָ�����㣬
ͷ�������rchildָ����������� */
/* ���һ����㡣��������������������ʾ�Ķ�
����T */
typedef int Status;
Status InOrderTraverse_Thr(BiThrTree T)
{
	BiThrTree p;
	/* pָ������ */
	p = T->lchild;
	/*�������������ʱ��p==T */
	while (p != T)
	{
		while (p->LTag == Link)
		{
			p = p->lchild;
		}
		printf("%c", p->data);
		while (p->RTag == Thread && p->rchild != T)
		{
			p = p->rchild;
			printf("%c", p->data);
		}
		p = p->rchild;
	}
	return 1;
}

//���������������
typedef struct ThreadNode {
	ElemType data;
	struct ThreadNode* lchild, * rchild;
	int ltag, rtag;
}ThreadNode, * ThreadTree;
ThreadNode* pre = NULL;//ȫ�ֱ���pre,ָ��ǰ���ʽڵ�ǰ����
//������������
void CreateInThread(ThreadTree T)
{
	pre = NULL;
	if (T != NULL)
	{
		InThread(T);//������������
		if (pre->rchild == NULL)
		{
			pre->rtag = 1;//����������һ���ڵ�
		}
	}
}
void InThread(ThreadTree T)
{
	if (T != NULL)
	{
		InThread(T->lchild);//����������
		visit(T);//���ʽڵ�
		InThread(T->rchild);
	}
}

void vist(ThreadNode* q)
{
	if (q->lchild == NULL)//������Ϊ�գ���������ǰ��
	{
		q->lchild = pre;
		q->ltag = 1;
	}
	if (pre != NULL && pre->rchild == NULL)
	{
		pre->rchild = q;//��������ǰ���ĺ�̽ڵ�
		pre->rtag = 1;
	}
	pre = q;
}

//����������
ThreadNode *pre=NULL:
void CreatePreThread(ThreadTree T)
{
	pre = NULL;
	if (T != NULL)
	{
		PreThread(T);
		if (pre->rchild == NULL)//����������һ���ڵ�
			pre->rtag = 1;
	}
}
void PreThread(ThreadTree T )
	{
	if (T != NULL)
	{
		visit(T);
		if (T->ltag == 0)
		{
			PreThread(T->lchild);
		}
		PreThread(T->rchild);
	}
	}
void visit(ThreadNOde* q)
{
	if (q->lchild == NULL)//������Ϊ�գ�����ǰ���ڵ�
	{
		q->lchild = pre;
		q->ltag = 1;
	}
	if (pre != NULL && pre->rchild == NULL)
	{
		pre->rchild = q;//����ǰ�����ĺ������
		pre->rtag = 1;
	}
	pre = q;
}


//����������������������

//�ҵ���PΪ���������У���һ������������Ľڵ�
ThreadNode* FirstNode(ThreadNode* p)
{
	//ѭ���ҵ������½ڵ㣨��һ����Ҷ�ӽڵ㣩
	while (p->ltag == 0)
		p = p->lchild;
	return p;
}

//�������������������ҵ��ڵ�P�ĺ�̽ڵ�
ThreadNode* Nextnode(ThreadNode* p)
{
	//�������������½��
	if (p->rtag == 0)
		return Firstnode(p->rchild);
	return p->rchild;//rtag==1ֱ�ӷ��غ������
}

//���������������������������
void Inorder(ThreadNode* T)
{
	for (ThreadNode* p = Firstnode(T); p != NULL; p = Nextnode(p))
	{
		visit(p);
	}
}


//��������������������ǰ��

//�ҵ���PΪ���������У����һ������������Ľڵ�
ThreadNode* Lastnode(ThreadNode* p)
{
	while (p->rtag == 0)
		p = p->rchild;
	return p;
}

//�ҵ����������������ڵ�P��ǰ���ڵ�
ThreadNode* Prenode(ThreadNode* p)
{
	if (p->ltag == 0)
		return Lastnode(p->lchild);
	return p->lchild;
}

//�������������������������������
void RevInorder(ThreadNode* T)
{
	for (ThreadNode* p = Lastnode(T); p != NULL; p = Prenode(p))
	{
		visit(p);
	}
}