#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef int ElemType;
//typedef struct Ptnode {
//	ElemType data;
//	int parent;
//	int firstchild;
//	int rightsib;
//}Ptnode;
//typedef struct {
//	Ptnode nodes[MAXSIZE];
//	int r, n;
//}Ptree;
 /* ���ӽ�� */

typedef struct CTnode {
	int child;
	struct CTnode* next;
}Childptr;

/* ��ͷ�ṹ */
typedef struct {
	ElemType data;
	Childptr firstchild;
	int parent;
}CTbox;
/* ���ṹ */
typedef struct {
	CTbox nodes[MAXSIZE];
	int r, n;
}CTree;

/* ���ĺ����ֵܱ�ʾ���ṹ���� */
typedef struct CSNode
{
	ElemType data;
	struct CSNode* firstchild,
		* rightsib;

}CSnode,*CSTree;