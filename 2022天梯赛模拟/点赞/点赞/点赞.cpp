#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main(void) {
	int n,j;
	scanf("%d", &n);
	int k, s1[1001] = {0}, t = 0;//数组一定要初始化，不然后面数组无法计算
	for (int i = 0; i < n; i++) {
		scanf("%d", &k);
		for (j = 0; j < k; j++) {
			scanf("%d", &t);
			s1[t]++;//统计t出现的次数并将次数存入数组中
		}
	}

	int max = 0, id = 0;
	for (int i = 0; i < 1001; i++)			//数据输出
	{
		if (s1[i] >= max) {
			max = s1[i];
			id = i;
		}
	}
	printf("%d %d", id, max);
	return 0; 
}