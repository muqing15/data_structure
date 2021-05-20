#define OK 0
#define ERR 1

typedef int ElemType;
typedef int bool;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

LinkList ListInit();
LNode *GetElem(LinkList L, int i);
bool ListInsert(LinkList L, ElemType e, int i);
bool ListDelete(LinkList L, int i);