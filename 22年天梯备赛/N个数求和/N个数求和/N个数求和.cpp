#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//递归求通分后分子和分母的最大公约数
 int gcd( int a, int b) {
	return b ? gcd(b, a % b) : a;
}
int main(void) {
	int n = 0;
	scanf("%d", &n);
	int i;
	int a = 0, b = 0, sum_a = 0, sum_b = 1, t;
	for ( i = 0; i < n; i++)
	{
		scanf("%d/%d", &a, &b);
		//通分相加
		sum_a *= b;
		sum_a += a * sum_b;
		sum_b *= b;
		//约分
		t = gcd(sum_a, sum_b);
		sum_a = sum_a / t;
		sum_b = sum_b / t;
	}
	if (sum_a % sum_b == 0) {
		printf("%d\n", sum_a / sum_b);
	}
	else if(sum_a < sum_b)
	{
		printf("%d/%d\n", sum_a, sum_b);
	}
	else
	{
		printf("%d %d/%d\n", sum_a / sum_b, sum_a % sum_b, sum_b);
	}
}