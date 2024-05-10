//�������Ķ�������ڵ�ṹ����
//�ڵ�ṹ
typedef struct BiNode
{
	//�յ�����e;
	int data;
	//���Һ���ָ��
	struct BiNode* lchild, * rchild;
}BiNode,*BiTree;
/* �ݹ���Ҷ���������T���Ƿ����key, */
 /* ָ��fָ��T��˫�ף����ʼ����ֵΪNULL */
 /* �����ҳɹ�����ָ��pָ�������Ԫ�ؽ�㣬������TRUE */
/* ����ָ��pָ�����·���Ϸ��ʵ����һ����㲢����FALSE */
Status SearchBST(BiTree T, int key, BiTree f, BiTree* p)
{
	//���Ҳ��ɹ�
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
		//����������������
		return SearchBST(T->lchild, key, T, p);
	}
	else
		//����������������
		return SearchBST(T->rchild, key, T, p);
}

/* ������������T�в����ڹؼ��ֵ���key������Ԫ��ʱ�� */
/* ����key������TRUE�����򷵻�FALSE */
Status InsertBST(BiTree* T, int key)
{
	BiTree p, s;
	//���Ҳ��ɹ�
	if (!SearchBST(*T, key, NULL, &p))
	{
		s = (BiNode)malloc(sizeof(BiNode));
		s->data = key;
		s->lchild = s->rchild = NULL;
		if (!p)
		{
			//����sΪ�µĽڵ�
			*T = s;
		}
		else if (key < p->data)
			p->lchild = s;
		else
			p->rchild = s;
		return TRUE;
	}
	else
		//�������йؼ�����ͬ�ڵ㣬���ٲ���
		return FALSE;
}

//

//�Ӷ�������ɾ���ڵ�p,���ؽ�����������
Status Delete(BiTree* p)
{
	BiTree q, s;
	//����������ֻ���ؽ�����������
	if ((*p)->rchild == NULL)
	{
		q = *p;
		*p = (*p)->lchild;
		free(q);
	}
	//������Ϊ�գ�ֻ���������
	else if ((*p)->lchild == NULL)
	{
		q = *p;
		*p = (*p)->rchild;
		free(q);
	}
	//������������Ϊ��
	else
	{
		q = *p;
		s = (*p)->lchild;
		//ת��Ȼ�����е���ͷ���Ҵ�ɾ������ǰ����
		while (s->rchild)
		{
			q = s; s = s->rchild;
		}
		//sָ��ɾ���ڵ��ֱ��ǰ��
		(*p)->data = s->data;
		if (q != *p)
			//�ؽ�q��������
			q->rchild = s->lchild;
		else
			q->lchild = s->lchild;
		free(s);
	}
	return TRUE;
}
/* ������������T�д��ڹؼ��ֵ���key������Ԫ��ʱ����ɾ��������Ԫ�ؽ��, */
/* ������TRUE�����򷵻�FALSE */

Status DeleteBSF(BiTree* T, int key)
{
	//�����ڹؼ��ֵ���key������Ԫ��
	if (!*T)
	{
		return False;
	}
	else
	{
		//�ҵ��ؼ��ֵ���key������Ԫ��
		if (key == (*T)->data)
			return Delete(T);
		else if (key < (*T)->data)
			return DeleteBSF(&(*T)->lchild, key);
		else
			return DeleteBSF(&(*T)->rchild, key);
	}
}



