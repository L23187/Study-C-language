#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main(void) {
	int n, m;
	scanf("%d%d", &n, &m);
	int tm_num[2][100];
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &tm_num[i][j]);
		}
	}
	int xs_tm[101][101];
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &xs_tm[i][j]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (xs_tm[i][j] == tm_num[1][j]) {
				sum += tm_num[0][j];
			}
		}
		printf("%d\n", sum);
		sum = 0;
	}
	return 0;
}