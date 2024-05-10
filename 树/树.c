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
 /* 孩子结点 */

typedef struct CTnode {
	int child;
	struct CTnode* next;
}Childptr;

/* 表头结构 */
typedef struct {
	ElemType data;
	Childptr firstchild;
	int parent;
}CTbox;
/* 树结构 */
typedef struct {
	CTbox nodes[MAXSIZE];
	int r, n;
}CTree;

/* 树的孩子兄弟表示法结构定义 */
typedef struct CSNode
{
	ElemType data;
	struct CSNode* firstchild,
		* rightsib;

}CSnode,*CSTree;