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

void InitStack(SqStack &S){
	S.top=-1;
}

bool Push(SqStack &S, ElemType e) {
	if (S.top==MaxSize-1)
		return false;
	S.data[++S.top] = e;
	return true;
}

bool Pop(SqStack &S, ElemType &e) {
	if (S.top == -1)
		return false;
	e = S.data[S.top--];
	return false;
}

bool GetTop(SqStack &S, ElemType &e) {
	if (S.top == -1)
		return false;
	e = S.data[S.top];
	return false;
}