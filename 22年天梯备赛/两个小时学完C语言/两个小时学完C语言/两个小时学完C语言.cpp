#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main(void) {
	int n, k, m;
	scanf("%d %d %d", &n, &k, &m);
	printf("%d", n - (k * m));
	return 0;
}