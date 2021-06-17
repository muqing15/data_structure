#include <stdlib.h>
#include "structure.h"

void initQueue(Queue *q);
void enQueue(Queue *q, TreeNode *node);
bool delQueue(Queue *q, TreeNode *node);
bool empty(Queue q);
void destory (Queue *q);

void initQueue(Queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

void enQueue(Queue *q, TreeNode *node){
    QNode qn = (QNode)malloc(sizeof(QueueNode));
    qn->node = node;
    qn->next = NULL;
    if (q->front == NULL && q->rear == NULL) {
        q->front = qn;
        q->rear = qn;
        return ;
    }
    q->rear->next = qn;
    q->rear = qn;
}

bool delQueue(Queue *q, TreeNode *node) {
    if (q->front == NULL)
        return false;
    QNode qn = q->front;
    node = qn->node;
    if (q->front == q->rear){
        q->front = NULL;
        q->rear = NULL;
    } else {
        q->front = qn->next;
    }
    free(qn);
    return ture;
}

bool empty(Queue q) {
    if (q.front == NULL)
        return ture;
    return false;
}

void destory (Queue *q) { 
    TreeNode *node;
    while (empty(*q) != ture) {
        delQueue(q, node);
    }
}