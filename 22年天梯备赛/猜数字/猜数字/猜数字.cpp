#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
/*
	本题目主要考察的是二维字符数组的使用和查找最小值
*/
int main(void) {
	int n;
	scanf("%d", &n);
	char name[10001][9];
	int num[10001];
	double sum = 0.0, avge = 0.0;
	getchar();
	for (int i = 0; i < n; i++)
	{
		scanf("%s %d", &name[i], &num[i]);
		sum += num[i];
		avge = sum / n;
	}
	printf("%.0f ", avge / 2);
	int min,flag = 0;
	min = num[0] - avge / 2;
	if (min < 0) {
		min = min * -1;
	}
	for (int i = 0; i < n; i++) {
		int j = num[i] - avge / 2;
		if (j < 0) {
			j = j * -1;
		}
		if (j < min) {
			flag = i;
			min = j;
		}
	}
	printf("%s", name[flag]);
	return 0;
}