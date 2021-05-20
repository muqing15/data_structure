#include <stdio.h>
#include "SqStack.h"

int main() {
	int i;
	ElemType e;
	SqStack S;
	InitStack(S);
	for(i=0; i<6; i++){
		Push(S, i);
	}
	while (S.top != -1) {
		Pop(S, e);
		printf("the value is %d\n", e);
	}
	return true;
}