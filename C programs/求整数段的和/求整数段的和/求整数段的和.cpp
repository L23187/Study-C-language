#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main(void) {
	int a, b, sum = 0, k = 0;
	scanf("%d%d", &a, &b);
	for (int i = a; i <= b; i++)
	{
		k++;
		printf("%5d", i);
		sum += i;
		if (k % 5 == 0 && i != b) {
			printf("\n");
		}
	}
	printf("\nSum = %d", sum);
	return 0;
}