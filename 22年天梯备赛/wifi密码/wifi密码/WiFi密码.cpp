#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main(void) {
	int n;
	scanf("%d", &n);
	char a, b;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			scanf(" %c-%c", &a, &b);
			if (b == 'T') {
				printf("%d", a - 'A' + 1);
			}
		}
	}
	return 0;
}