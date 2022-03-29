#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void sort(int num[], int n) {//将成绩从大到小排序
	int temp;
	//冒泡排序
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (num[j] < num[j + 1]) {
				temp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = temp;
			}
		}
	}
}

void sort1(double score[], int n) {//把成绩从大到小排序
	double temp;
	for(int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (score[j] > score[j + 1]) {
				temp = score[j];
				score[j] = score[j + 1];
				score[j + 1] = temp;
			}
		}
	}
}
int main(void) {
	int n, k, m;
	int nums;
	double score[10001];//存放每个人成绩评分的总和
	scanf("%d %d %d", &n, &k, &m);
	for (int i = 0; i < n; i++) {
		int num[11];//将成绩存入
		for (int j = 0; j < k; j++) {
			scanf("%d", &num[j]);
		}
		sort(num, k);//先对成绩从大到小排序
		nums = 0;
		for (int j = 1; j < k - 1; j++) {//除去最高分和最低分
			nums += num[j];
		}
		score[i] = nums * 1.0;//将nums处理为浮点类型
	}
	sort1(score, n);
	for (int i = n - m; i < n - 1; i++) {
		printf("%.3f ", score[i] / (k - 2));
	}
	printf("%.3f", score[n - 1] / (k - 2));//保证最后一个输出没有空格
	return 0;
}