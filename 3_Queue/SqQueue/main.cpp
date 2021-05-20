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