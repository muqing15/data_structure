#include <stdlib.h>
#include <stdio.h>

#define true 1
#define false 0
#define ElemType char

typedef struct thread_tree_node {
    ElemType data;
    int ltag, rtag;
    struct thread_tree_node *lchild, *rchild;
}thread_tree_node, *thread_tree;

void inthread(thread_tree &t);
void create_thread(thread_tree &t);
thread_tree_node* first_node(thread_tree t);
thread_tree_node* next_node(thread_tree_node *n);

thread_tree_node* init_node(ElemType data) {
    thread_tree_node *node = (thread_tree_node*)malloc(sizeof(thread_tree_node));

    node->data = data;
    node->ltag = 0;
    node->rtag = 0;
    node->lchild = NULL;
    node->rchild = NULL;
    
    return node;
}

void in_thread(thread_tree &t, thread_tree &pre) {
    if (t==NULL) return ;

    thread_tree_node *p=t;

    in_thread(p->lchild, pre);

    if(p->lchild == NULL)  {
        p->lchild == pre;
        p->ltag = 1;
    } else {
        if(pre!=NULL && pre->rchild == NULL) {
            pre->rchild = p;
            pre->rtag = 1; 
        }
    }
    pre = p;

    in_thread(p->rchild, pre);
}

void create_thread_tree(thread_tree &t){
    thread_tree pre = NULL;
    
    if (t != NULL) {
        in_thread(t, pre);
        pre->rtag = 1;
        pre->rchild = NULL;
    }
}

thread_tree_node* first_node(thread_tree t) {
    if(t == NULL) return NULL;

    while(t->ltag == 0) t=t->lchild;
    
    return t;
}

thread_tree_node* next_node(thread_tree p) {
    if(p->rtag == 0) {
        return first_node(p->rchild);
    } else {
        return p->rchild; 
    }
}
