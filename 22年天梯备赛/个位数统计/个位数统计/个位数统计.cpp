#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main(void) {
	int n;
	scanf("%d", &n);
	int a[10];
	int x = 0;
	for (int i = 0; i < 1000; i++) {
		x = n % 10;
		n = n / 10;
		if (n == 0)
			break;
		printf("%d\n", x);
	}
	return 0;
}