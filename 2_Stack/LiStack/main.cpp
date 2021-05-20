#include <stdio.h>
#include <stdlib.h>
#include "LiStack.h"

int main() {
	int i;
	ElemType e;
	LinkStack S;
	InitStack(S);
	for (i=0; i<6; i++) {
		Push(S, i);
	}
	ElemType topElem;
	Pop(S, topElem);
	printf("top Elem is: %d\n", topElem);
	while(S!=NULL) {
		Pop(S, e);
		printf("the value of e is: %d\n", e);
	}
	bool flag = DestoryStack(S);
	if (flag)
		printf("destory failed!\n");
	else 
		printf("destory success!\n");
	return true;
}