#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main(void) {
	char a[10001] = {0};
	int m = 0, n = 0, q = 0, p = 0;
	scanf("%s", a);//输入字符串
	//统计字符串中gplt各有多少
	for (int i = 0; i < strlen(a); i++)
	{
		if (a[i] == 'G' || a[i] == 'g') {
			m++;
		}
		else if (a[i] == 'P' || a[i] == 'p') {
			n++;
		}
		else if (a[i] == 'L' || a[i] == 'l') {
			q++;
		}
		else if (a[i] == 'T' || a[i] == 't') {
			p++;
		}
	}
	//do-while的用法：while语句中条件成立，do中语句执行
	do
	{
		if (m > 0) {
			printf("G");
		}
		m--;
		if (n > 0) {
			printf("P");
		}
		n--;
		if (q > 0) {
			printf("L");
		}
		q--;
		if (p > 0) {
			printf("T");
		}
		p--;
	} while (m > 0 || n > 0 || q > 0 || p > 0);
	return 0;
}