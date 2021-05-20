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