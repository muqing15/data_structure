#include <stdio.h>
#include <stdlib.h>
#include "thread_tree.h"

int main(){
   thread_tree node_a, node_b, node_c, node_d, node_e,node_f, node_g;

    node_a = init_node('a');
    node_b = init_node('b');
    node_c = init_node('c');
    node_d = init_node('d');
    node_e = init_node('e');
    node_f = init_node('f');
    node_g = init_node('g');

    node_a->lchild = node_b;
    node_a->rchild = node_c;
    node_b->lchild = node_g;
    node_b->rchild = node_d;
    node_c->rchild = node_e;
    node_e->lchild = node_f;
    
    // 将node_a树线索化
    create_thread_tree(node_a);

    // 遍历二叉树
    thread_tree_node *p = first_node(node_a);
    while(p) {
        printf("%c ", p->data);
        p = next_node(p);
    }

    printf("\n");
}
