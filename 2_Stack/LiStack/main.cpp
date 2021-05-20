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

void InitStack(LinkStack &S) {
	S=NULL;
}

bool Push(LinkStack &S, ElemType e) {
	LinkStack n = (LinkStack) malloc(sizeof(LinkNode));
	n->data = e;
	n->next = S;
	S=n;
	return false;
}

bool Pop(LinkStack &S, ElemType &e){
	if (S == NULL )
		return false;
	LinkStack n = S;
	e = n->data;
	S = S->next; 
	free(n);
	return false;
}

bool StackEmpty(LinkStack &S){
	if (S == NULL )
		return true;
	else
		return false;
}

bool GetTop(LinkStack &S, ElemType &e) {
	if (S == NULL )
		return false;
	e = S->data;
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