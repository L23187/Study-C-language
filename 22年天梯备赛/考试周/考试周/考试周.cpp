#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main(void) {
	int a, b;
	scanf("%d%d", &a, &b);
	double x;
	x = (double) a / b;
	printf("%d/%.1f=%d", a, x, b);
	return 0;
}