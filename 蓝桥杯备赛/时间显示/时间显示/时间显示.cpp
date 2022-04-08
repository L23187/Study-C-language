#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main(void) {
	long long int n;
	scanf("%lld", &n);
	int h, m, s;
	n = n / 1000;
	n %= (24 * 60 * 60);//舍去天数
	h = n / 3600;
	n %= 3600;//舍去整点数
	m = n / 60;
	s = n % 60;
	printf("%02d:%02d:%02d\n", h, m, s);
	return 0;
}