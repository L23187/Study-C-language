#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
int main(void) {
	int m, n;
	int ss[1001] = {0};
	scanf("%d%d", &m, &n);
	int k = 0;
	for (int i = m + 1; i <= n; i++) {
		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				break;
			}
		}
		ss[k] = i;
		k++;
	}
	for (int i = 0; i < sizeof(ss); i++) {
		printf("%d ",ss[i]);
	}
	return 0;
}