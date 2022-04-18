#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main(void) {
	int small;
	double k, l;
	scanf("%lf%d%lf", &k, &small, &l);
	double m;
	if (small == 0) {
		m = k * 2.455;
		printf("%.2f ",m);
		if (m >= l) {
			printf("T_T");
		}
		else {
			printf("^_^");
		}
	}
	if (small == 1) {
		m = k * 1.26;
		printf("%.2f ", m);
		if (m >= l) {
			printf("T_T");
		}
		else {
			printf("^_^");
		}
	}
	return 0;
}