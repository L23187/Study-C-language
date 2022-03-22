#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main(void) {
	int n;
	scanf("%d", &n);
	int a[201];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int tem = 0;
	for (int i = 0; i < n-1; i++) {
		for(int j = 0; j < n - 1 - i; j++) {
			if (a[j] > a[j + 1]) {
				tem = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tem;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	return 0;
}