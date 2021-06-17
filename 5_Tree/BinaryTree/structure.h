#define ture 0
#define false 1
#define bool int

typedef char ElemType;
typedef struct TreeNode {
    ElemType data;
    struct TreeNode *lchild, *rchild;
}TreeNode, *Tree;

typedef struct QueueNode {
    TreeNode *node;
    struct QueueNode *next; 
}QueueNode, *QNode;

typedef struct Queue {
    struct QueueNode *front, *rear;
}Queue;