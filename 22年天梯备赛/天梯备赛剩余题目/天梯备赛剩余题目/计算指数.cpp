#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
int main(void) {
	int n;
	scanf("%d", &n);
	int x;
	x = pow(2, n);
	printf("2^%d = %d", n, x);
	return 0;
}