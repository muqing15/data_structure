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
