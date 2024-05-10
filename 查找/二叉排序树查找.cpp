//二叉树的二叉链表节点结构定义
//节点结构
typedef struct BiNode
{
	//终点数据e;
	int data;
	//左右孩子指针
	struct BiNode* lchild, * rchild;
}BiNode,*BiTree;
/* 递归查找二叉排序树T中是否存在key, */
 /* 指针f指向T的双亲，其初始调用值为NULL */
 /* 若查找成功，则指针p指向该数据元素结点，并返回TRUE */
/* 否则指针p指向查找路径上访问的最后一个结点并返回FALSE */
Status SearchBST(BiTree T, int key, BiTree f, BiTree* p)
{
	//查找不成功
	if (!T)
	{
		*p = f;
		return FALSE;
	}
	else if (key == T->data)
	{
		*p = T;
		return TRUE;
	}
	else if (key < T->data)
	{
		//在左子树继续查找
		return SearchBST(T->lchild, key, T, p);
	}
	else
		//在右子树继续查找
		return SearchBST(T->rchild, key, T, p);
}

/* 当二叉排序树T中不存在关键字等于key的数据元素时， */
/* 插入key并返回TRUE，否则返回FALSE */
Status InsertBST(BiTree* T, int key)
{
	BiTree p, s;
	//查找不成功
	if (!SearchBST(*T, key, NULL, &p))
	{
		s = (BiNode)malloc(sizeof(BiNode));
		s->data = key;
		s->lchild = s->rchild = NULL;
		if (!p)
		{
			//插入s为新的节点
			*T = s;
		}
		else if (key < p->data)
			p->lchild = s;
		else
			p->rchild = s;
		return TRUE;
	}
	else
		//树中已有关键字相同节点，不再插入
		return FALSE;
}

//

//从二叉树中删除节点p,并重接他的左右树
Status Delete(BiTree* p)
{
	BiTree q, s;
	//右子树空则只需重接他的左子树
	if ((*p)->rchild == NULL)
	{
		q = *p;
		*p = (*p)->lchild;
		free(q);
	}
	//左子树为空，只需接右子树
	else if ((*p)->lchild == NULL)
	{
		q = *p;
		*p = (*p)->rchild;
		free(q);
	}
	//左右子树均不为空
	else
	{
		q = *p;
		s = (*p)->lchild;
		//转左，然后享有到尽头（找待删除结点的前驱）
		while (s->rchild)
		{
			q = s; s = s->rchild;
		}
		//s指向被删除节点的直接前驱
		(*p)->data = s->data;
		if (q != *p)
			//重接q的右子树
			q->rchild = s->lchild;
		else
			q->lchild = s->lchild;
		free(s);
	}
	return TRUE;
}
/* 若二叉排序树T中存在关键字等于key的数据元素时，则删除该数据元素结点, */
/* 并返回TRUE；否则返回FALSE */

Status DeleteBSF(BiTree* T, int key)
{
	//不存在关键字等于key的数据元素
	if (!*T)
	{
		return False;
	}
	else
	{
		//找到关键字等于key的数据元素
		if (key == (*T)->data)
			return Delete(T);
		else if (key < (*T)->data)
			return DeleteBSF(&(*T)->lchild, key);
		else
			return DeleteBSF(&(*T)->rchild, key);
	}
}



