#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
int main(void) {
	/*�������ܶ���С������ܶȵı�ֵ�� 3 �η���������ֵ��
	��������ľ����������뾶�ı�ֵ*/
	double k, r;
	int x;
	scanf("%lf %d %lf", &k, &x, &r);
	double lx_limit;
	if (x == 0) {
		lx_limit = 2.455 * k;
	}
	if (x == 1) {
		lx_limit = 1.26 * k;
	}
	if (lx_limit > r) {
		printf("%.2f T_T", lx_limit);
	}
	else {
		printf("%.2f ^_^", lx_limit);
	}
	return 0;
}