bool InitList(SqList *L) {
	L->data = (ElemType*)malloc(sizeof(ElemType)*InitSize);
	if (!L->data){
		printf("init list failed!\n");
		return false;
	}

	L->length=0;
	return true;
}

bool ListInsert(SqList *L, ElemType e, int i) {
	if (i < 1 || i > L->length+1) {
		return false;
	}
	if (L->length > InitSize) {
		return false;
	}

	for (int j=L->length; j>=i; j--)
		L->data[j] = L->data[j-1];
	L->data[i-1] = e;
	L->length += 1;

	return true;
}

bool ListDelete(SqList *L, ElemType e, int i) {
	if (i<1 || i>L->length) 
		return false;

	e = (L->data[i-1]);
	for(int j=i-1; j<L->length-1; j++)
		L->data[j] = L->data[j+1];
	L->length--;
	return true;
}

bool ListDestory(SqList *L) {
	if (!L->data) {
		printf("SqList is null!\n");
		return false;
	}
	L->length=0;
	free(L->data);
	L->data=NULL;
	return true;	
}