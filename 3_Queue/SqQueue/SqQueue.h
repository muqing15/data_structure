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

void Init(Queue &q) {
	q.front = 0;
	q.rear = 0;	
}

bool IsEmpty(Queue &q) {
	if (q.front == q.rear) 
		return true;
	else
		return false;
}

bool EnQueue(Queue &q, ElemType e) {
	if ((q.rear+1)%MaxSize == q.front){
		printf("queue full !\n");
		return false;
	}

	q.data[q.rear] = e;
	q.rear = (q.rear+1)%MaxSize;

	return true;
}

bool DeQueue(Queue &q, ElemType &e) {
	if (IsEmpty(q)==true)
		return false;

	e = q.data[q.front];
	q.front = (q.front + 1)%MaxSize;

	return true;
}

bool GetElem(Queue &q, ElemType &e) {
	if (IsEmpty(q) == true)
		return false;

	e = q.data[q.front];

	return true;
}