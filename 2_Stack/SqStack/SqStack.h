#define true 0
#define false 1
#define MaxSize 10

typedef int ElemType;
typedef struct SqStack {
	ElemType data[MaxSize];
	int top;
}SqStack;

void InitStack(SqStack &S);
bool Push(SqStack &S, ElemType e);
bool Pop(SqStack &, ElemType &e);
bool GetTop(SqStack &S, ElemType &e);
bool DestoryStack(SqStack &S);
bool StackEmpty(SqStack &S);