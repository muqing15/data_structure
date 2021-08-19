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

typedef struct LinkNode {
	Tree data;
	struct LinkNode *next;
}LinkNode, *LinkStack;

void InitStack(LinkStack &S);
bool Push(LinkStack &S, Tree t);
bool Pop(LinkStack &S, Tree &t);
bool GetTop(LinkStack &S, Tree &t);
bool StackEmpty(LinkStack &S);
bool DestoryStack(LinkStack &S);

void InitQueue(Queue &q){ 
	q.front = NULL;
	q.rear = NULL;
}

void EnQueue(Queue &q, Tree e) {
	LiNode n = (LiNode)malloc(sizeof(Node));
	n->data = e;
    n->next = NULL;
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

void InitStack(LinkStack &S) {
	S=NULL;
}

bool Push(LinkStack &S, Tree t) {
	LinkStack n = (LinkStack) malloc(sizeof(LinkNode));
	n->data = t;
	n->next = S;
	S=n;
	//printf("push %c\n", t->data);
	return false;
}

bool Pop(LinkStack &S, Tree &t){
	if (S == NULL )
		return false;
	LinkStack n = S;
	t = n->data;
	S = S->next; 
	//printf("Pop %c\n", t->data);
	free(n);
	return false;
}

bool StackEmpty(LinkStack &S){
	if (S == NULL )
		return true;
	else
		return false;
}

bool GetTop(LinkStack &S, Tree &t) {
	if (S == NULL )
		return false;
	t = S->data;
	return true;
}

bool DestoryStack(LinkStack &S) {
	if (S == NULL )
		return false;
	LinkStack n = S;
	while ( n != NULL ) {
		S = S->next;
		free (n) ;
		n = S;
	}
	return true;
}
