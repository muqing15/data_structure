#include <stdio.h>
#include <stdlib.h>
#include "var.h"
#include "operations.c"

int main() {
	SqList *L;
	bool result;
	InitList(L);
	result = ListInsert(L, 1, 1);
	result = ListInsert(L, 2, 2);
	result = ListInsert(L, 3, 1);
	if (result == false) {
		printf("insert failed!");
		return false;
	}
	ElemType e, e2;
	ListDelete(L, e, 2);
	// printf("insert success! the value is %d, %d\n", L->data[0], L->data[1]);
	for (int i=0; i<L->length; i++)
		printf("%d\n", *(L->data++));
	// ListDestory(L);

	return true;
}