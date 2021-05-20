#define true 0
#define false 1
#define InitSize 10

typedef int ElemType;
typedef int bool;

typedef struct {
	ElemType *data;
	int length;
}SqList;

bool InitList(SqList *L);
bool ListInsert(SqList *L, ElemType e, int i);
bool ListDelete(SqList *L, ElemType e, int i);
bool ListDestory(SqList *L);