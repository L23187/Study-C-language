#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main(void) {
	int A_Max, B_Max;//定义甲和乙的酒量
	scanf("%d %d", &A_Max, &B_Max);
	int A_n = 0, A_a = 0, B_n = 0, B_a = 0;//定义甲喊和甲划，乙喊和乙划
	int n = 0, a = 0, b = 0;//a为甲喝的杯数，b为乙喝的杯数
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d %d", &A_n, &A_a, &B_n, &B_a);
		if (A_a == A_n+B_n&&B_a!=A_n+B_n)
		{
			a++;
		}
		else if (B_a == A_n + B_n&&A_a != A_n + B_n)
		{
			b++;
		}
		if (a == A_Max+1 || b == B_Max+1) {
			break;
		}
	}
	if (a == A_Max + 1) {
		printf("A\n%d", b);
	}
	else if (b == B_Max + 1) {
		printf("B\n%d", a);
	}
	return 0;
}