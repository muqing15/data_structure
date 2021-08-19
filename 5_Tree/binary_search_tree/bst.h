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
bool insert(bstTree &T, ElemType key);
bool range(bstTree T);
bool insert_nonrecursive(bstTree &T, ElemType key);

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

bool insert_nonrecursive(bstTree &T, ElemType key) {
	bstNode *node = (bstNode*)malloc(sizeof(bstNode));
	node->key = key;
	node->lchild = node->rchild = NULL;

	if (T == NULL) {
		T = node;
		return true;
	}

	bstNode *cur_node = T;
	while (true) {
		if (key == cur_node->key) {
			printf("the value is same!\n");
			return false;
		} else if (key < cur_node->key) {
			if (cur_node->lchild == NULL) {
				cur_node->lchild = node;
				break;
			}
			else 
				cur_node = cur_node->lchild;
		} else {
			if (cur_node->rchild == NULL){
				cur_node->rchild = node;
				break;
			}
			else
				cur_node = cur_node->rchild;
		}
	}
	
	return true;
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
}

// 使用中序遍历输出值
bool range(bstTree T) {
	if (T == NULL )
		return true;
	range(T->lchild);
	printf("%d ", T->key);
	range(T->rchild);

	return true;
}

bstNode *BST_Search(bstTree T, ElemType key) {
	while(T != NULL && T->key != key) {
		if (T->key < key) T = T->rchild;
		else T = T->rchild;
	}

	return T;
}