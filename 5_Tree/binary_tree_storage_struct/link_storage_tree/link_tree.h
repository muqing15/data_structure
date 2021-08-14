#include <stdio.h>
#include <stdlib.h>
#include "level_queue.h"

#define ture 1
#define false 0
#define bool int

/*
 * init Tree with var 't'
 */
void initTree(Tree t);

/*
 * add lchild or rchild for parent if parent`s lchild or rchild is NULL.
 * if successfully add node, return true,
 * otherwise, return false.
 */
bool addChild(TreeNode *parent, TreeNode *child, char pos);

/*
 * visit tree`s nodes order by NLR
 */
void PreOrder(Tree t);

/*
 * visit tree`s nodes order by LNR
 */
void InOrder(Tree t);

/*
 * visit tree`s nodes order by LRN
 */
void PostOrder(Tree t);

/*  
 * visit tree`s nodes order by level
 */
void levelOrder(Tree t);

void initTree(Tree t) {
    t = NULL;
}

bool addChild(TreeNode *parent, ElemType data, char pos) {
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->lchild = NULL;
    node->rchild = NULL;

    if (pos == 'l' && parent->lchild == NULL) {
        parent->lchild = node;
        return true;
    } 
    if(pos == 'r' && parent->rchild == NULL) {
        parent->rchild = node;
        return true;
    }

    return false;
}

void visit(TreeNode* node) {
    printf("%c ", node->data);
}

void PreOrder(Tree T) {
    if (T!=NULL) {
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

void InOrder(Tree T) {
    if (T!=NULL) {
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}

void PostOrder(Tree T) {
    if(T!=NULL) {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}

void levelOrder(Tree T) {
    if(T==NULL) return;

    Tree p;
    Queue q;
    InitQueue(q);
    EnQueue(q, T);
    while (!IsEmpty(q)){
        DeQueue(q, p);
        //printf("the localtion of pointer which returned from Dequeue is: %p\n", p);
        visit(p);
        if(p->lchild!=NULL) 
            EnQueue(q, p->lchild);
        if(p->rchild!=NULL)
            EnQueue(q, p->rchild);
    }
    Destory(q);
}
