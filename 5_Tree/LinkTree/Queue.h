#include <stdio.h>
#include <stdlib.h>

#define true 1;
#define false 0;

typedef int ElemType;
typedef struct BiTNode {
	ElemType data;
	struct LinkTree *lchild, *rchild;
}BiTNode, *BiTree;

typedef struct QNode {
	BiTNode *data;
	struct QNode *next;
}QNode;

typedef struct Queue {
	QNode *front, rear;	
}Queue;

void InitQueue(Queue &q){
	q.front = NULL;
	q.rear = NULL;
}

bool EnQueue(Queue &q, BiTNode data) {
	QNode *n = (QNode*)malloc(sizeof(QNode));
	n->data = data;
	if (q.front == NULL) {
		q.front = n;
		q.rear = n;
		return true;
	}

	n->next = q.front;
	q.front = n;
	return true;
}

bool DelQueue(Queue &q, BiTNode &data) {
	if (q.front = NULL && q.front == NULL)
		return false;

	data = *(q.front->data);
	QNode *n = q.front;
	if (q.front == q.rear && q.front != NULL) {
		q.front = NULL;
		q.rear = NULL;
		
	} else {
		q.front = q.front->next;
	}

	free(n);
	return true;
}

bool IsQueueEmpty(Queue &q) {
	if (q.front == NULL && q.rear == NULL)
		return true;
	else
		return false;
}









