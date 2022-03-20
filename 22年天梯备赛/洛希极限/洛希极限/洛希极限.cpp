#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
int main(void) {
	/*大天体密度与小天体的密度的比值开 3 次方后计算出的值和
	两个天体的距离与大天体半径的比值*/
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