#include <stdio.h>

#define MAX_NUMS 30

typedef char ElemType;
// Use sequentail storage to store binary tree
// Store data from index 1
typedef struct SSTree{
	ElemType data[MAX_NUMS];
	int nums;
}SSTree, *Tree;

/* 
 * add nodes to the binary tree
 */
void addNode(SSTree &T, ElemType v, int index);

/* 
 * return the index of left child of the 
 * node represented by the index
 */
int Lchild(SSTree &T, int index);

/*
 * return the index of right child of the
 * node represented by the index
 */
int Rchild(SSTree &T, int index);

void initSSTree(SSTree &T) {
	for (int i=0; i<MAX_NUMS; i++) {
		T.data[i] = ' ';
	}
	T.nums = 0;
}

void addNode(SSTree &T, ElemType v, int index) {
	if ((T.nums+1)>MAX_NUMS || (index+1) > MAX_NUMS || index < 1) return;

	T.data[index] = v;
	T.nums ++;
}

int Lchild(SSTree &T, int index) {
	if (index*2 >= MAX_NUMS) return -1;

	return T.data[index*2]!=' '?index*2:(-1);
}

int Rchild(SSTree &T, int index) {
	if ((index*2+1) >= MAX_NUMS) return -1;

	return T.data[index*2+1]!=' '?(index*2+1):(-1);
}
