#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main(void) {
	int z, n;//����ָ�ɵĳ�ʦ������ħ��ʦ���͵Ĵ���
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