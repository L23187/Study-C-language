#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main(void) {
	int a, b;
	double x;
	scanf("%d%d", &a, &b);
	x = (double)a / b;
	if (b < 0) {
		printf("%d/(%d)=%.2f", a, b, x);
	}
	else if (b == 0) {
		printf("%d/%d=Error", a, b);
	}
	else {
		printf("%d/%d=%.2f", a, b, x);
	}
	return 0;
}
