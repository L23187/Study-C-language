#define _CRT_SECURE_NO_WARNINGS 1
//PTA有两个测试点不对，不知道在哪，只能得10分，仅供学习
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(void) {
	int n, f, x, p, flag = 0, cnt = 0;//f为输入数字最开始各个位数相加，
	//x为数字乘完之后的数，p为乘完之后的各个位数之和
	scanf("%d", &n);
	char cx[1001], zh[1001];
	for (int i = 0; i < n; i++) {
		f = 0;
		scanf("%s", cx);
		for (int j = 0; cx[j] != '\0'; j++) {
			f += cx[j] - '0';
		}
		for (int j = 2; j <= 9; j++) {
			//atoi函数将字符串转化为数字
			x = atoi(cx) * 2;
			//sprintf函数将乘完得数转换为字符串
			sprintf(zh,"%d",x);
			p = 0;
			for (int k = 0; zh[k] != '\0'; k++) {
				p += zh[k] - '0';
			}
			if (p == f) {
				flag = 1;
			}
			else {
				flag = 0;
			}
		}
		if (flag == 1) {
			printf("%d\n", f);
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
}