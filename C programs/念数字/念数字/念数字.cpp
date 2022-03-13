#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main(void) {
	int f;
	scanf("%d", &f);
	int c = 5 * (f - 32) / 9;
	printf("Celsius = %d", c);
	return 0;
}