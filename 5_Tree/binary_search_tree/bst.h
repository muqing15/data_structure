#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct bstNode {
	ElemType key;
	struct bstNode *rchild, *lchild;
}bstNode, *bstTree;

/*
 * init a bst accounding to a number array.
 */
bstTree init_bst(bstTree &T, int *num_array, int len);

/* 
 * insert value into bst
 */
bool insert(bstTree &T, ElemType e);
bool range(bstTree T);

bstTree init_bst(bstTree &T, int *num_array, int len) {
	if (!num_array) {
		printf("the num array is null!\n");
		return NULL;
	}
	for (int i=0; i<len; i++){
		insert(T, num_array[i]);
	}
	return T;	
}

bool insert(bstTree &T, ElemType key) {
	if (T==NULL) {
		T = (bstNode*)malloc(sizeof(bstNode));
		T->key = key;
		T->lchild = T->rchild = NULL;
		return true;
	}

	if(key == T->key) {
		printf("the value is same!\n");
		return false;
	}

	if(key<T->key)
		return insert(T->lchild, key);
	else 
		return insert(T->rchild, key);

	return true;
}

// 使用中序遍历输出值
bool range(bstTree T) {
	if (T == NULL )
		return true;

	range(T->lchild);
	printf("the value of t is: %d\n", T->key);
	range(T->rchild);

	return true;
}
