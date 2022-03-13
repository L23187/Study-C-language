#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main(void) {
	int n;
	scanf("%d", &n);
	int sum = 0, temp = 1;
	for (int i = 1; i <= n; i++)
	{
		temp *= i;
		sum += temp;
	}
	printf("%d\n", sum);
	return 0;
}