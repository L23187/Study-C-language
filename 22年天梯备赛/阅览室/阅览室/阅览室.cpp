#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main(void) {
	int x, y, z;
	char a[5];
	int sum = 0, s = 0, n, b[1005];
	scanf("%d", &n);//输入记录天数
	for (int i = 0; i < 1005; i++)
	{
		b[i] = -1;
	}
	for (int j = 1; j <= n; j++)
	{
		while (1) {
			scanf("%d %s %d:%d", &x, a, &y, &z);//输入书号 键值 发生时间
			//当输入的书号为0时，表示结束一天的工作
			if (x == 0) {
				if (s != 0) {
					printf("%d %0.0f\n", s, (double)sum / s);
				}
				else {
					printf("0 0\n");
				}
				sum = 0;
				s = 0;
				break;
			}
			else {
				//当输入的是S时表示借书
				if (a[0] == 'S') {
					b[x] = y * 60 + z;//将时间换为数字储存在数组中
				}
				else if (a[0] == 'E' && b[x] != -1) {
					s++;
					sum = sum + y * 60 + z - b[x];
					b[x] = -1;
				}
			}
		}
	}
	return 0;

}