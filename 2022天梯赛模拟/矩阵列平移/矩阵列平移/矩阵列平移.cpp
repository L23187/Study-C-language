#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main(void) {
	int n, k, x;
	scanf("%d%d%d", &n, &k, &x);
	int num[101][101];
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &num[i][j]);
		}
	}
	int m = 1, count = 0;
	for (j = 1; j < n; j += 2) {
		count = m;
		m++;
		if (m > k) {
			m = 1;
		}
		for (i = n - 1; i >= 0; i--) {
			num[i][j] = num[i-count][j];
			if (i < count) {
				num[i][j] = x;
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum = 0;
		for (int j = 0; j < n; j++) {
			sum += num[i][j];
		}
		printf("%d", sum);
		if (i < n - 1) {
			printf(" ");
		}
	}
	return 0;
}