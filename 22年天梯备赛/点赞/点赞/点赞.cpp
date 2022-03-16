#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main(void) {
	int n;
	scanf("%d", &n);
	int k, f[1000]={0}, j, t;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &k);
		for (j = 0; j < k; j++)
		{
			scanf("%d", &t);
			f[t]++;
		}
	}
	int max = 0, id;
	for (int i = 1000; i >= 1; i--)
	{
		if (f[i] > max) {
			max = f[i];
			id = i;
		}
	}
	printf("%d %d", id, max);
	return 0;
}