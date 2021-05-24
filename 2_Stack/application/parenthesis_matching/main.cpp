#include <stdio.h>
#include "../../LiStack/LiStack.h"

bool identify(char *c);

char *str = "(1-{[2*(3+4)+5]+4}\0";

int main() {
	bool flag = identify(str);
	if (flag == true)
		printf("matching!\n");
	else
		printf("no matching!\n");
	return true;
}

bool identify(char *str) {
	char c = *str, pop_c;

	LinkStack S;
	InitStack(S);

	while(c != '\0') {
		switch (c) {
		case '(': Push(S, c); break;
		case '[': Push(S, c); break;
		case '{': Push(S, c); break;
		// 如果是右括号，弹出栈顶括号
		// 查看是否与当前括号相匹配
		case ')': 
			Pop(S, pop_c);
			if (pop_c == '(')
				break;
			else 
				return false;
		case ']': 
			Pop(S, pop_c);
			if (pop_c == '[')
				break;
			else
				return false;
		case '}':
			Pop(S, pop_c);
			if( pop_c == '{')
				break;
			else 
				return false;
		default:
			break;
		}
		c = *(++str);
		//printf("identify the vlaue of com is: %c\n", c);
	}
	

	if (StackEmpty(S) == true){
		DestoryStack(S);
		return true;
	} else {
		DestoryStack(S);
		return false;
	}
}