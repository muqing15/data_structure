#include <stdlib.h>
#include <Queue.h>

typedef int ElemType;
typedef struct iTNode {
	ElemType data;
	struct LinkTree *lchild, *rchild;
}BiTNode, *BiTree;

// 层次遍历二叉树
void levelOrder(BiTree T);


void levelOrder(BiTree T) {
	Queue q;
	InitQueue(q);
	BiTree tNode;
	EnQueue(T);
	while(isQueueTree(q) != NULL) {
		DelQueue(q, tNode);
		visit(tNode);
		if (tNode->lchild != NULL) {
			EnQueue(q, tNode->lchild);
		}
		if (tNode->rchild != NULL) {
			EnQueue(q, tNode->rchild);
		}
	}
}