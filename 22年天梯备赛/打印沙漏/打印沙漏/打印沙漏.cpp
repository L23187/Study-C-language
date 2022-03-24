#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main(void) {
	int n;
	char x;
	int m;
	scanf("%d %c", &n, &x);
	int temp = 0;
	for (int i = 1;; i = i + 2) {
		if (n < temp * 2 - 1) {
			break;
		}
		temp += i;
		m = temp * 2 - 1;
	}
	printf("%d\n", m);
	return 0;
}