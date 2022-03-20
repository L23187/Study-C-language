#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main(void) {
	int x, y;
	scanf("%d%d", &x, &y);
	printf("%d", 5000 - (x * y / 2) - (y + 100) * (100 - x) / 2);
	return 0;
}