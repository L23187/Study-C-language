#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
int main(void) {
	int n;
	scanf("%d", &n);
	int flag = 0, start = 0, len = 0;
	int s = 0;
	//判断输入的数是否是素数，如果是，则输出1和它本身
	for (int i = 2; i < sqrt(n); i++)
	{
		if (n % i == 0) {
			flag = 1;
		}
	}
	if (flag == 0) {
		printf("1\n%d\n", n);
	}
	//若不是素数
	//对于一个数 N，他的所有因子都肯定在 sqrt(N) 内
	//枚举每一次的因子为起点，往后求连续因子数，
	//与之前的连续因子数作比较，取最大值，并计下作为起点的因子数。
	else {
		for (int i = 2; i < sqrt(n); i++) {
			s = 1;
			//当s逐渐接近n时
			for (int j = i; s * j <= n; j++) {
				s = s * j;
				//保证s可以整除n并且
				if (n % s == 0 && j - i + 1 > len) {
					start = i;
					len = j - i + 1;
				}
			}
		}
		printf("%d\n", len);
		for (int i = start; i < start + len; i++) {
			if (i == start) {
				printf("%d", i);
			}
			else {
				printf("*%d", i);
			}
		}
		printf("\n");
	}
	return 0;
}