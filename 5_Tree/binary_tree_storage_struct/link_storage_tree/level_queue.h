#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef char ElemType;
typedef struct TreeNode {
    ElemType data;
    struct TreeNode *lchild, *rchild;
}TreeNode, *Tree;
typedef struct Node {
	Tree data;
	struct Node *next;
}Node, *LiNode;
typedef struct Queue{
	LiNode front, rear;
}Queue;

void InitQueue(Queue &q);
void EnQueue(Queue &q, Tree e);
bool DeQueue(Queue &q, Tree &e);
bool GetElem(Queue &q, Tree e);
void Destory(Queue &q);

void InitQueue(Queue &q){ 
	q.front = NULL;
	q.rear = NULL;
}

void EnQueue(Queue &q, Tree e) {
	LiNode n = (LiNode)malloc(sizeof(Node));
	n->data = e;
    printf("%c\n", e->data);
	if (q.front == NULL) {
		q.front = n;
		q.rear = n;
		return;
	}
	q.rear->next = n;
	q.rear = n;
}

bool DeQueue(Queue &q, Tree &e) {
	if (q.front == NULL)
		return false;
	LiNode n = q.front;
	e = n->data;
	// 删除最后一个元素
	if (n->next == NULL){
		q.front = NULL;
		q.rear = NULL;
	} else {
		q.front = n->next;
	}
	free(n);
	return true;
}

bool IsEmpty(Queue &q) {
	if (q.front == NULL && q.rear == NULL)
		return true;
	else 
		return false;
}

bool GetElem(Queue &q, Tree e) {
	if (IsEmpty(q)==true)
		return false;
	e = q.front->data;
	return true;
}

void Destory(Queue &q) {
	LiNode	n;
	while (q.front != NULL) {
		n = q.front;
		q.front = n->next;
		free(n);
	}
}