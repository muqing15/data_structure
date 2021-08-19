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

void PreOrder2(Tree T) {
    if (T==NULL) return;

    LinkStack S;
    InitStack(S);

    Tree p = T;
    while(p != NULL || !StackEmpty(S)) {
        if (p) {
            visit(p);
            Push(S, p);
            p = p->lchild;
        } else {
            Pop(S, p);
            p = p->rchild; 
        }
    }

    DestoryStack(S);
}

void InOrder(Tree T) {
    if (T!=NULL) {
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}

void InOrder2(Tree T) {
    LinkStack S;
    InitStack(S);

    Tree p = T;
    while(p || !StackEmpty(S)){
        if(p) {
            Push(S, p);
            p = p->lchild; 
        } else {
            Pop(S, p);
            visit(p);
            p = p->rchild;
        }
    }

    DestoryStack(S);
}

void PostOrder(Tree T) {
    if(T!=NULL) {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}

void PostOrder2(Tree T) {
    if (T == NULL) return;

    LinkStack S;
    InitStack(S);

    Tree p = T, r=NULL; 

    while(p || !StackEmpty(S)) {
        if (p) {
            Push(S, p);
            p = p->lchild;  // 最左边的孩子结点全部入列
        } else {
            GetTop(S, p);
            if (p->rchild && p->rchild != r) { // 如果p的右孩子存在且没有被访问过
                p = p->rchild;
            } else {
                Pop(S, p);
                visit(p);
                r = p;
                p = NULL;
            }
        }
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


// 使用递归的方法寻找节点之间的路径
bool get_path(LinkStack &S, Tree t, ElemType target) {
    if (t == NULL) return false;

    Push(S, t);

    if (t->data == target)
        return true;
    if (get_path(S, t->lchild, target))
        return true;
    if (get_path(S, t->rchild, target))
        return true;

    Pop(S, t);
    //printf("link_tree.h pop t is: %c\n", t->data);
    return false;
}

void get_target_path(Tree t, ElemType target) {
    LinkStack S;
    InitStack(S);

    get_path(S, t, target);

    Tree node;
    while(!StackEmpty(S)) {
        Pop(S, node);
        printf("%c", node->data);
    }

    printf("\n");
    DestoryStack(S);
}
