#include <stdio.h>
#include "SqQueue.h"

int main() {
	Queue q;
	Init(q);
	EnQueue(q, 1);
	EnQueue(q, 2);
	EnQueue(q, 3);
	EnQueue(q, 4);
	EnQueue(q, 5);
	EnQueue(q, 6);
	EnQueue(q, 7);
	EnQueue(q, 8);
	EnQueue(q, 9);
	EnQueue(q, 10);
	EnQueue(q, 11);
	EnQueue(q, 12);

	ElemType e ;
	while (IsEmpty(q)!=true){
		DeQueue(q, e);
		printf("the value of elem is: %d\n", e);
	}
	return true;
}

void Init(Queue &q) {
	q.front = 0;
	q.rear = 0;	
}

bool IsEmpty(Queue &q) {
	if (q.front == q.rear) 
		return true;
	else
		return false;
}

bool EnQueue(Queue &q, ElemType e) {
	if ((q.rear+1)%MaxSize == q.front){
		printf("queue full !\n");
		return false;
	}

	q.data[q.rear] = e;
	q.rear = (q.rear+1)%MaxSize;

	return true;
}

bool DeQueue(Queue &q, ElemType &e) {
	if (IsEmpty(q)==true)
		return false;

	e = q.data[q.front];
	q.front = (q.front + 1)%MaxSize;

	return true;
}

bool GetElem(Queue &q, ElemType &e) {
	if (IsEmpty(q) == true)
		return false;

	e = q.data[q.front];

	return true;
}
