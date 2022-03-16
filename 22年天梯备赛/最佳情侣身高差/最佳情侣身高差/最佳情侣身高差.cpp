#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main(void) {
	int n;
	scanf("%d", &n);
	double h;
	char s;
	for (int i = 0; i < n; i++)
	{
		scanf("\n%c %lf", &s, &h);
		/*'\n'表示忽略所有的空白字符,输入非空白字符结束输入,
		不加'\n'会使c接收换行符*/
		if (s == 'F') {
			h = h * 1.09;
			printf("%.2f\n", h);
		}
		else if (s == 'M') {
			 h = h / 1.09;
			 printf("%.2f\n", h);
		}
	}
	return 0;
}