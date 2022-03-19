#define _CRT_SECURE_NO_WARNINGS 1
/*
	本题目主要考察数字倒序输出
*/
#include<stdio.h>
int main(void) {
	int a, b, c;
	scanf("%d %d", &a, &b);
	c = a * b;
	int flag = 0;
	//数字的倒序输出
	while (c > 0) {
		flag = 10 * flag + c % 10;
		c /= 10;
	}

	printf("%d", flag);
	return 0;
}