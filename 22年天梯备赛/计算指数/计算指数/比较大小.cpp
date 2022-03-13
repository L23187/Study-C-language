#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main(void) {
	int a, b, c;
	int num[3], temp;
	for (int i = 0; i < 3; i++)
	{
		scanf("%d", &num[i]);
	}
	for (int i = 0; i < 3 - 1; i++)
	{
		for (int i = 0; i < 3 - i; i++)
		{
			if (num[i] > num[i + 1]) {
				temp = num[i];
				num[i] = num[i + 1];
				num[i + 1] = temp;
			}
		}
	}
	a = num[0];
	b = num[1];
	c = num[2];
	printf("%d->%d->%d\n", a, b, c);

	return 0;
}