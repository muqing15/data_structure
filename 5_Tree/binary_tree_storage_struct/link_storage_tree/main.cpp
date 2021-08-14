#include "link_tree.h"

int main() {
    Tree t;
    initTree(t);

    t = (TreeNode*)malloc(sizeof(TreeNode));
    t->data = 'a';
    t->lchild = NULL;
    t->rchild = NULL;

    addChild(t, 'b', 'l');
    addChild(t, 'c', 'r');
    addChild(t->lchild, 'd', 'r');
    addChild(t->lchild, 'g', 'l');
    addChild(t->rchild, 'e', 'r');
    addChild(t->rchild->rchild, 'f', 'l');

    printf("先序遍历顺序:\n");
    PreOrder(t);
    printf("\n---------------------\n");

    printf("中序遍历顺序:\n");
    InOrder(t);
    printf("\n---------------------\n");

    printf("后序遍历顺序:\n");
    PostOrder(t);
    printf("\n---------------------\n");

    printf("层次遍历顺序:\n");
    levelOrder(t);
    printf("\n--------------------\n");

    return 0;
}
