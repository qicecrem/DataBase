#include<stdio.h>
#include<stdlib.h>
typedef char ElemType;
typedef struct BiTNode {
	ElemType data;
	struct BiTNode* lchild, * rchild;
}BiTNode,*BiTree;

/* 二叉树的前序遍历递归算法 */
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

/* 二叉树的中序遍历递归算法 */
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

/* 二叉树的后序遍历递归算法 */
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

/* 按前序输入二叉树中结点的值（一个字符） */
//#表示空树，构造二叉链表表示二叉树T。
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
		/*生成根结点 */
		(*T)->data = ch;
		/*构造左子树 */
		CreateBiTree(&(*T)->lchild);
		/*构造右子树 */
		CreateBiTree(&(*T)->rchild);
	}
}


/*二叉树的二叉线索存储结构定义* /
/* Link==0表示指向左右孩子指针 */
/* Thread==1表示指向前驱或后继的线索 */
typedef enum{Link,Thread} PointerTag;
typedef struct BiThrNode {
	ElemType data;
	struct BiThrNode* lchild, * rchild;
	/*左右标志 */
	PointerTag LTag;
	PointerTag RTag;
}BiThrNode,*BiThrTree;
/* 全局变量，始终指向刚刚访问过的结点 */
BiThrTree pre;
/* 中序遍历进行中序线索化 */
void InThreading(BiThrTree p)
{
	if (p)
	{
		InThreading(p->lchild);
		/*没有左孩子 */
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


/* T指向头结点，头结点左链lchild指向根结点，
头结点右链rchild指向中序遍历的 */
/* 最后一个结点。中序遍历二叉线索链表表示的二
叉树T */
typedef int Status;
Status InOrderTraverse_Thr(BiThrTree T)
{
	BiThrTree p;
	/* p指向根结点 */
	p = T->lchild;
	/*空树或遍历结束时，p==T */
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

//中序二叉树线索化
typedef struct ThreadNode {
	ElemType data;
	struct ThreadNode* lchild, * rchild;
	int ltag, rtag;
}ThreadNode, * ThreadTree;
ThreadNode* pre = NULL;//全局变量pre,指向当前访问节点前驱；
//线索化二叉树
void CreateInThread(ThreadTree T)
{
	pre = NULL;
	if (T != NULL)
	{
		InThread(T);//线索化二叉树
		if (pre->rchild == NULL)
		{
			pre->rtag = 1;//处理遍历最后一个节点
		}
	}
}
void InThread(ThreadTree T)
{
	if (T != NULL)
	{
		InThread(T->lchild);//遍历左子树
		visit(T);//访问节点
		InThread(T->rchild);
	}
}

void vist(ThreadNode* q)
{
	if (q->lchild == NULL)//左子树为空，建立线索前驱
	{
		q->lchild = pre;
		q->ltag = 1;
	}
	if (pre != NULL && pre->rchild == NULL)
	{
		pre->rchild = q;//建立线索前驱的后继节点
		pre->rtag = 1;
	}
	pre = q;
}

//先序线索化
ThreadNode *pre=NULL:
void CreatePreThread(ThreadTree T)
{
	pre = NULL;
	if (T != NULL)
	{
		PreThread(T);
		if (pre->rchild == NULL)//处理遍历最后一个节点
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
	if (q->lchild == NULL)//左子树为空，建立前驱节点
	{
		q->lchild = pre;
		q->ltag = 1;
	}
	if (pre != NULL && pre->rchild == NULL)
	{
		pre->rchild = q;//建立前驱结点的后继线索
		pre->rtag = 1;
	}
	pre = q;
}


//中序线索二叉树找中序后继

//找到以P为根的子树中，第一个被中序遍历的节点
ThreadNode* FirstNode(ThreadNode* p)
{
	//循环找到最左下节点（不一定是叶子节点）
	while (p->ltag == 0)
		p = p->lchild;
	return p;
}

//在中序线索二叉树中找到节点P的后继节点
ThreadNode* Nextnode(ThreadNode* p)
{
	//右子树的最左下结点
	if (p->rtag == 0)
		return Firstnode(p->rchild);
	return p->rchild;//rtag==1直接返回后继线索
}

//对中序线索二叉树进行中序遍历
void Inorder(ThreadNode* T)
{
	for (ThreadNode* p = Firstnode(T); p != NULL; p = Nextnode(p))
	{
		visit(p);
	}
}


//中序线索二叉树找中序前驱

//找到以P为根的子树中，最后一个被中序遍历的节点
ThreadNode* Lastnode(ThreadNode* p)
{
	while (p->rtag == 0)
		p = p->rchild;
	return p;
}

//找到中序线索二叉树节点P的前驱节点
ThreadNode* Prenode(ThreadNode* p)
{
	if (p->ltag == 0)
		return Lastnode(p->lchild);
	return p->lchild;
}

//对中序线索二叉树进行逆向中序遍历
void RevInorder(ThreadNode* T)
{
	for (ThreadNode* p = Lastnode(T); p != NULL; p = Prenode(p))
	{
		visit(p);
	}
}