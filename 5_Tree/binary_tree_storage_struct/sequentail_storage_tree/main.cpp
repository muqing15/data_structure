#include <stdio.h>
#include "sequentail_storage_tree.h"

int main() {
	SSTree T;
	initSSTree(T);

	addNode(T, 'a', 1);
	addNode(T, 'b', 2);
	addNode(T, 'c', 3);
	addNode(T, 'd', 5);
	addNode(T, 'e', 7);
	addNode(T, 'f', 10);

	int index_a = Lchild(T, 1);
	int index_c = Rchild(T, 3);

	printf("the left of a is: %c\n", T.data[Lchild(T, 1)]);
	printf("the right of c is: %c\n", T.data[Rchild(T, 3)]);

	return 0;
}