#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main(void) {
	int n,row;
	char x;
	scanf("%d %c", &n, &x);
	if (n % 2 == 0) {
		row = n / 2;
	}
	else {
		row = n / 2 + 1;
	}
	for (int i = 0; i < row; i++)
	{
		for (int i = 0; i < n; i++)n
		{
			putchar(x);
		}
		printf("\n");
	}
	return 0;
}