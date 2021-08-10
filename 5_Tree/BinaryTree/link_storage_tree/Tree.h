#include <stdio.h>
#include <stdlib.h>
#include "SecondaryQueue.h"

/* 
 * Add new tree`s node order by complete binary tree
 * t: root node of binary tree
 * data: new data(char)
 */
bool addNode(Tree t, ElemType data);

/*
 * init Tree with var 't'
 */
void initTree(Tree t);

/* 
 * visit tree`s nodes in hierarchical order.
 * t: root node of binary tree
 * tn: new node would to be add to the tree
 * visit: the function how to visit access nodes
 */
void levelVisit(Tree t, TreeNode *tn, bool (*visit)(TreeNode *parent, TreeNode *child));

/*
 * visit tree`s nodes order by 
 */
void orderVisit(Tree t);

/*
 * add lchild or rchild for parent if parent`s lchild or rchild is NULL.
 * if successfully add node, return true,
 * otherwise, return false.
 */
bool addChild(TreeNode *parent, TreeNode *child);

/*
 * range tree`s nodes follow the method defined by visit().
 */
static void rangeTree(Queue *q, TreeNode *pn, TreeNode *tn, bool (*visit)(TreeNode *parent, TreeNode *child));

void initTree(Tree t) {
    printf("init Tree!\n");
    t = NULL;
}

bool addChild(TreeNode *parent, TreeNode *child) {
    printf("the parent`s data is: %c\n", parent->data);
    if (parent->lchild == NULL) {
        parent->lchild == child;
        return true;
    } else if(parent->rchild == NULL) {
        parent->rchild == child;
        return true;
    } else {
        return false;
    }
}

bool printNode(TreeNode *pn, TreeNode *uselessNode) {
    printf("%c\n", pn->data);
    return false;
}

void levelVisit(Tree t, TreeNode *tn, bool (*visit)(TreeNode *parent, TreeNode *child)) {
    if (t == NULL)
        return ;
    
    TreeNode *pn = t;
    Queue q;
    initQueue(&q);
    bool flag;

    flag = visit(pn, tn);
    if (flag == true)
        return ;

    rangeTree(&q, pn, tn, visit);

    destory(&q);
}

static void rangeTree(Queue *q, TreeNode *t, TreeNode *tn, bool (*visit)(TreeNode *parent, TreeNode *child)) {
    while(empty(*q) != true) {
        bool flag = visit(t, tn);
        if (flag == true) {
            break;
        }
        if (t->lchild != NULL) {
            enQueue(q, t->lchild);
        }
        if(t->rchild != NULL) {
            enQueue(q, t->rchild);
        }
        delQueue(q, t);
    }
}

bool addNode(Tree t, ElemType data) {
    TreeNode *tn = (TreeNode*)malloc(sizeof(TreeNode));
    tn->data = data;
    printf("tn->data is: %c\n", tn->data);
    tn->lchild = NULL;
    tn->rchild = NULL;

    if (t == NULL) {
        t = tn;
        printf("the value of t is : %c\n---------------\n", t->data);
        return true;
    }

    printf("t != NULL, will init levelVisist(%c, %c)", t->data, tn->data);
    levelVisit(t, tn, addChild);
    return true;
}