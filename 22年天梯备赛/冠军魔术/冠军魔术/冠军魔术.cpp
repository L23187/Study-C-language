#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main(void) {
	int z, n;//输入指派的厨师数量和魔术师推送的次数
	scanf("%d %d", &z, &n);
	int num = z;
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 0) {
			num = num * 2;
		}
	}
	if (n % 2 == 0) {
		printf("0 ");
	}
	else if (n % 2 != 0) {
		printf("1 ");
	}
	printf("%d\n", num);
	return 0;
}