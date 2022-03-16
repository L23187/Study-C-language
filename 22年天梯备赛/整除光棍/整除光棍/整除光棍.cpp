#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main(void) {
	int x;
	scanf("%d", &x);
	int w = 1, k = 0, num = 0;
	while (1)
	{
		if (w / x != 0) {
			k = 1;//判断首位是否为零，如果为零不需要输出
		}
		num++;//每次循环加一位
		if (k) {
			printf("%d", w / x);
		}
		w = w % x; 
		if (w == 0) {
			break;
		}
		w = w * 10 + 1;
	}
	printf(" %d", num);
	return 0;
}