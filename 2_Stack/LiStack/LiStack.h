#define true 0
#define false 1

typedef int ElemType; 
typedef struct LinkNode {
	ElemType data;
	struct LinkNode *next;
}LinkNode, *LinkStack;

void InitStack(LinkStack &S);
bool Push(LinkStack &S, ElemType e);
bool Pop(LinkStack &S, ElemType &e);
bool GetTop(LinkStack &S, ElemType &e);
bool StackEmpty(LinkStack &S);
bool DestoryStack(LinkStack &S);

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