#include <stdio.h>
#include "LiQueue.h"

int main() {
	Queue q;
	ElemType e;
	InitQueue(q);
	EnQueue(q, 1);
	EnQueue(q, 2);
	EnQueue(q, 3);
	EnQueue(q, 4);
	while(IsEmpty(q) != true){
		DeQueue(q, e);
		printf("the value of e is: %d\n", e);
	}
	return true;
}