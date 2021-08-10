#include <stdio.h>
#include "bst.h"

int main() {
	ElemType nums[] = {0, 3, 6, 1, 5, 9, 7};
	bstTree T;

	init_bst(T, nums, sizeof(nums)/sizeof(ElemType));
	//printf("the value of t is: %d\n", T->key);
	range(T);
	return true;
}