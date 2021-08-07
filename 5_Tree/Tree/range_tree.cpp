// 1)先根遍历
void PreOrder(TreeNode *R) {
	if (R != NULL) {
		visit(R);
		while(R还有下一个子树T){
			PreOrder(T);
		}
	}
}