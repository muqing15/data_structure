#include <stdio.h>
#include "bst.h"

int main() {
	ElemType nums[] = {0, 3, 6, 1, 5, 9, 7};
	/*
	 * tips:
	 *     定义指针变量时，必须指定变量为NULL，
	 *     否则后续使用可能会出现混乱(C语言不会讲指针变量初始化为NULL)
	 */
	bstTree T=NULL;

	init_bst(T, nums, sizeof(nums)/sizeof(ElemType));
	range(T);
	printf("\n");
	bstTree n = BST_Search(T, 6);
	printf("the result of search is: %d\n", n->key);
	return 0;
}
