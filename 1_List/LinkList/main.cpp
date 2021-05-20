#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

int main(){
    LinkList L = ListInit();

    LinkList n = GetElem(L, 2);
    printf("the value of n->data is: %d\n", n->data);
    return 0;
}

LinkList ListInit(){
    LinkList s, L; int x;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    scanf("%d", &x);
    while(x!=999){
        s = (LinkList)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}

LNode *GetElem(LinkList L, int i){
    if (i==0)
        return L;
    if (i<0)
        return NULL;
    printf("the value of i is: %d\n", i);
    LinkList s=L->next;
    printf("s->data is: %d\n", s->data);
    int j=1;
    while(s!=NULL && j<i){
        s=s->next;
    }
    return s;
}