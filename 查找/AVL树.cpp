//�������Ķ�������ڵ�ṹ����
//�ڵ�ṹ
typedef struct BiTNode {
	//�ڵ�����
	int data;
	//����ƽ������
	int bf;
	//���Һ���ָ��
	struct BiTNode* lchild, * rchild;
}BiTNode,*BiTree;

//��pΪ���Ķ�������������������
//����֮��pָ���µ����ڵ㣬����ת����ǰ���������ĸ��ڵ�
void R_Rotate(BiTree* p)
{
	BiTree L;
	//Lָ��p�����������ڵ�
	L = (*p)->lchild;
	//L���������ҽ�p��������
	(*p)->lchild = L->rchild;
	L->rchild = (*p);
	//pָ���µĸ��ڵ�
	*p = L;
}

//��pΪ���Ķ�������������������
//����֮��pָ���µ����ڵ㣬����ת����ǰ���������ĸ��ڵ�
void L_Rotate(BiTree* p)
{
	BiTree L;
	//Lָ��P�����������ڵ�
	L = (*p)->rchild;
	//L���������ҽ�p��������
	(*p)->rchild = L->lchild;
	L->lchild = (*p);
	*p = L;
}

//����ָ��T��ָ�ڵ�Ϊ���Ķ���������������
//�㷨����ָ��Tָ���µĸ��ڵ�
#define LH 1//���
#define EH 0//�ȸ�
#define RH -1//�Ҹ�
void LeftBalance(BiTree* T)
{
	BiTree L, Lr;
	//Lָ��T�����������ڵ�
	L = (*T)->lchild;
	switch (L->bf)
	{
		//���T����������ƽ��ȣ�����Ӧƽ�⴦��
		//�½ڵ������T�����ӵ��������ϣ�Ҫ������������
	case LH:
		(*T)->bf = L->bf = EH;
		R_Rotate(T);
		break;
		//�½ڵ������T�����������Һ������ϣ�Ҫ��˫������
	case RH:
		//Lrָ��T�����ӵ���������
		Lr = L->rchild;
		//�޸�T�������ӵ�ƽ������
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
		//��T��������������ƽ�⴦��
		L_Rotate(&(*T)->lchild);
		//��T������ƽ�⴦��
		R_Rotate(T);
	}
}

void RightBalance(BiTree* T)
{
	BiTree R, Rl;
	R = (*T)->rchild; // R ָ��ǰ�ڵ�����������ڵ�
	switch (R->bf) {
		// ��鵱ǰ�ڵ����������ƽ��ȣ�����Ӧ��ƽ�⴦��
		// �½ڵ�����ڵ�ǰ�ڵ���Һ��ӵ��������ϣ�Ҫ������������
	case RH:
		(*T)->bf = R->bf = EH;
		L_Rotate(T);
		break;
		// �½ڵ�����ڵ�ǰ�ڵ���Һ��ӵ��������ϣ�Ҫ��˫������
	case LH:
		// Rl ָ��ǰ�ڵ���Һ��ӵ����������ڵ�
		Rl = R->lchild;
		// �޸ĵ�ǰ�ڵ㼰���Һ��ӵ�ƽ������
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
		// �Ե�ǰ�ڵ��������������ƽ�⴦��
		R_Rotate(&(*T)->rchild);
		// �Ե�ǰ�ڵ�������ƽ�⴦��
		L_Rotate(T);
		break;
	}
}

//����ƽ��Ķ���������T�в����ں�e����ͬ�ؼ��ֵĽڵ㣬�����һ��
//����Ԫ��Ϊe���½�㲢����1�����򷵻�0��
//��������ʹ������ʧȥƽ�⣬����ƽ����ת������������taller��ӳT�������
Status InsertAVL(BiTree* T, int e, Status* taller)
{
	if (!*T)
	{
		//�����½ڵ㣬�����ߣ���tallerΪTrue
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
			//������ͬ���ٲ���
			*taller = False;
			return False;

		}
		else if (e < (*T)->data)
		{
			//������T���������н�������
			//δ����
			if (!InsertAVL(&((*T)->lchild), e, taller))
				return False;
			//�Ѳ��뵽T��������������������
			if (*taller)
			{
				//���T��ƽ���
				switch ((*T)->bf)
				{
					//ԭ�����������������ߣ�������ƽ�⴦��
				case LH:
					LeftBalance(T);
					*taller = False;
					break;
					//ԭ�����ҵȸߣ���������
				case EH:
					(*T)->bf = LH;
					*taller = True;
					break;
					//ԭ������������ߣ������ҵȸ�
				case RH:
					(*T)->bf = EH;
					*taller = False;
					break;
				}
			}
		}
		else
		{
			//������������
			//δ����
			if (!InsertAVL(&(*T)->rchild, e, taller))
				return False;
			if (*taller)
			{
				//���T��ƽ���
				switch ((*T)->bf)
				{
					//ԭ����Ҹߣ������ҵȸ�
				case LH:
					(*T)->bf = EH;
					*taller = False;
					break;
					//ԭ���ҵȸߣ����Ҹ�
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