#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main(void) {
	int n;
	scanf("%d", &n);
	int x, y, z;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d", &x, &y, &z);
		if ((x * x + y * y + z * z) == 3 * x * y * z) {
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}
	}
	return 0;
}