//二叉树的二叉链表节点结构定义
//节点结构
typedef struct BiTNode {
	//节点数据
	int data;
	//结点的平衡因子
	int bf;
	//左右孩子指针
	struct BiTNode* lchild, * rchild;
}BiTNode,*BiTree;

//以p为根的二叉排序树做右旋处理
//处理之后p指向新的树节点，即旋转处理前的左子树的根节点
void R_Rotate(BiTree* p)
{
	BiTree L;
	//L指向p的左子树根节点
	L = (*p)->lchild;
	//L的右子树挂接p的左子树
	(*p)->lchild = L->rchild;
	L->rchild = (*p);
	//p指向新的根节点
	*p = L;
}

//以p为根的二叉排序树做右旋处理
//处理之后p指向新的树节点，即旋转处理前的左子树的根节点
void L_Rotate(BiTree* p)
{
	BiTree L;
	//L指向P的右子树根节点
	L = (*p)->rchild;
	//L的左子树挂接p的右子树
	(*p)->rchild = L->lchild;
	L->lchild = (*p);
	*p = L;
}

//对以指针T所指节点为根的二叉树做左旋处理
//算法结束指针T指向新的根节点
#define LH 1//左高
#define EH 0//等高
#define RH -1//右高
void LeftBalance(BiTree* T)
{
	BiTree L, Lr;
	//L指向T的左子树根节点
	L = (*T)->lchild;
	switch (L->bf)
	{
		//检查T的左子树的平衡度，做相应平衡处理
		//新节点插入在T的左孩子的左子树上，要做单右旋处理
	case LH:
		(*T)->bf = L->bf = EH;
		R_Rotate(T);
		break;
		//新节点插入在T的左子树的右孩子树上，要做双旋处理
	case RH:
		//Lr指向T的左孩子的右子树根
		Lr = L->rchild;
		//修改T及其左孩子的平衡因子
		switch (Lr->bf)
		{
		case LH:
			(*T)->bf = RH;
			L->bf = EH;
			break;
		case EH:
			(*T)->bf = L->bf = EH;
			break;
		case RH:
			(*T)->bf = EH;
			L->bf = LH;
			break;
		}
		Lr->bf = EH;
		//对T的左子树做左旋平衡处理
		L_Rotate(&(*T)->lchild);
		//对T做右旋平衡处理
		R_Rotate(T);
	}
}

void RightBalance(BiTree* T)
{
	BiTree R, Rl;
	R = (*T)->rchild; // R 指向当前节点的右子树根节点
	switch (R->bf) {
		// 检查当前节点的右子树的平衡度，做相应的平衡处理
		// 新节点插入在当前节点的右孩子的右子树上，要做单左旋处理
	case RH:
		(*T)->bf = R->bf = EH;
		L_Rotate(T);
		break;
		// 新节点插入在当前节点的右孩子的左子树上，要做双旋处理
	case LH:
		// Rl 指向当前节点的右孩子的左子树根节点
		Rl = R->lchild;
		// 修改当前节点及其右孩子的平衡因子
		switch (Rl->bf) {
		case LH:
			(*T)->bf = EH;
			R->bf = RH;
			break;
		case EH:
			(*T)->bf = R->bf = EH;
			break;
		case RH:
			(*T)->bf = LH;
			R->bf = EH;
			break;
		}
		Rl->bf = EH;
		// 对当前节点的右子树做右旋平衡处理
		R_Rotate(&(*T)->rchild);
		// 对当前节点做左旋平衡处理
		L_Rotate(T);
		break;
	}
}

//若在平衡的二叉排序树T中不存在和e有相同关键字的节点，则插入一个
//数据元素为e的新结点并返回1，否则返回0，
//若因插入而使二叉树失去平衡，则作平衡旋转处理，布尔变量taller反映T长高与否
Status InsertAVL(BiTree* T, int e, Status* taller)
{
	if (!*T)
	{
		//插入新节点，树长高，置taller为True
		*T = (BiTree)malloc(sizeof(BiTree));
		(*T)->data = e;
		(*T)->lchild = (*T)->rchild = NULL;
		(*T)->bf = EH;
		*taller = True;
	}
	else
	{
		if (e == (*T)->data)
		{
			//已有相同不再插入
			*taller = False;
			return False;

		}
		else if (e < (*T)->data)
		{
			//继续在T的左子树中进行搜索
			//未插入
			if (!InsertAVL(&((*T)->lchild), e, taller))
				return False;
			//已插入到T的左子树且左子树长高
			if (*taller)
			{
				//检查T的平衡度
				switch ((*T)->bf)
				{
					//原本左子树比右子树高，需做左平衡处理
				case LH:
					LeftBalance(T);
					*taller = False;
					break;
					//原本左右等高，现做增高
				case EH:
					(*T)->bf = LH;
					*taller = True;
					break;
					//原本右子树比左高，现左右等高
				case RH:
					(*T)->bf = EH;
					*taller = False;
					break;
				}
			}
		}
		else
		{
			//在右子树搜素
			//未插入
			if (!InsertAVL(&(*T)->rchild, e, taller))
				return False;
			if (*taller)
			{
				//检查T的平衡度
				switch ((*T)->bf)
				{
					//原左比右高，先左右等高
				case LH:
					(*T)->bf = EH;
					*taller = False;
					break;
					//原左右等高，现右高
				case EH:
					(*T)->bf = RH;
					*taller = True;
					break;
				case RH:
					RightBalance(T);
					*taller = False;
					break;

				}
			}
		}
	}
	return True;
}