#define _CRT_SECURE_NO_WARNINGS 1
/*
	����Ŀ��Ҫ�������ֵ������
*/
#include<stdio.h>
int main(void) {
	int a, b, c;
	scanf("%d %d", &a, &b);
	c = a * b;
	int flag = 0;
	//���ֵĵ������
	while (c > 0) {
		flag = 10 * flag + c % 10;
		c /= 10;
	}

	printf("%d", flag);
	return 0;
}