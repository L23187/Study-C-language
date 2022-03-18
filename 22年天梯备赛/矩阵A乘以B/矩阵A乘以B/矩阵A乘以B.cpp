#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main(void) {
	int ra, ca, rb, cb, k = 0;
	scanf("%d%d", &ra, &ca);
	int a[101][101], b[101][101], c[100][100];
	//输入a集合
	for (int i = 0; i < ra; i++)
	{
		for (int j = 0; j < ca; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	//输入b集合
	scanf("%d%d", &rb, &cb);
	for (int i = 0; i < rb; i++)
	{
		for (int j = 0; j < cb; j++)
		{
			scanf("%d", &b[i][j]);
		}
	}
	if (ca == rb) {
		for (int i = 0; i < ra; i++) {
			int sum = 0;
			for (int j = 0; j < cb; j++) {
				int sum = 0;
				for (int k = 0; k < ca; k++) {
					sum += (a[i][k] * b[k][j]);
				}
				c[i][j] = sum;
			}
		}
		printf("%d %d\n", ra, cb);
		for (int i = 0; i < ra; i++)
		{
			for (int j = 0; j < cb; j++)
			{
				printf("%d", c[i][j]);
				if (j != cb - 1) {
					printf(" ");
				}
			}
			if (i != ra - 1) {
				printf("\n");
			}
		}
	}
	else {
		printf("Error: %d != %d", ca, rb);
	}
	return 0;
}