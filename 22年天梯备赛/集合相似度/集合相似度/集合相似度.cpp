#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main(void) {
	int n, m, k;
	int nums[100][100], j;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &m);
		for (j = 1; j <= m; j++)
		{
			scanf("%d", &nums[i][j]);
		}
		nums[i][j] = '#';
	}
	scanf("%d", &k);
	int a[2000][2];
	for (int i = 1; i <= k; i++)
	{
		for (int j = 1; j <= 2; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			nums[a[i]]
		}
	}
}