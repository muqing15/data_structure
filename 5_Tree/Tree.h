#include <stdio.h>
#include <stdlib.h>

#define true 0
#define false 1

typedef char ElemType;
typedef struct TreeNode {
    ElemType data;
    struct TreeNode *lchild, *rchild;
}TreeNode, *Tree;

static void initTree(Tree t, ElemType *str);
static void levelVisit(Tree t);
static void orderVisit(Tree t);