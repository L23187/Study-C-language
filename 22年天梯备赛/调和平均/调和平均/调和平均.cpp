#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main(void) {
	int n;
	scanf("%d", &n);
	double x, sum = 0.0;
	for (int i = 0; i < n; i++)
	{
		scanf("%lf", &x);
		sum = sum + 1.0/x;
	}
	sum = sum / n;
	printf("%.2f\n", 1.0 / sum);
	return 0;
}