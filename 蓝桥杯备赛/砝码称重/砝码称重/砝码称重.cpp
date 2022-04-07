#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>

int main()
{
	int i, j, n, sum = 0, w[15] = { 0 }, dp[15][200000] = { 0 }, count = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &w[i]);
		sum = sum + w[i];
	}
	dp[0][w[0]] = 1;
	for (i = 1; i < n; i++)
	{
		for (j = 1; j <= sum; j++)
		{
			if (dp[i - 1][j] == 1)
			{
				dp[i][j] = 1;
				dp[i][j + w[i]] = 1;
				dp[i][abs(j - w[i])] = 1;
			}
		}
	}
	for (j = 1; j <= sum; j++)
	{
		if (dp[n - 1][j] == 1)
		{
			count++;
		}
	}
	printf("%d", count);
	return 0;
}