#define true 0
#define false 1
#define MaxSize 10

typedef int ElemType;
typedef struct Queue{
	ElemType data[MaxSize];
	int front, rear;
}Queue;

// operations of queue
void Init(Queue &q);
bool IsEmpty(Queue &q);
bool EnQueue(Queue &q, ElemType e);
bool DeQueue(Queue &q, ElemType &e);
bool GetElem(Queue &q, ElemType &e);