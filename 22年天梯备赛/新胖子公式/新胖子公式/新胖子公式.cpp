#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
int main(void) {
	double h, w, temp;
	scanf("%lf%lf", &w, &h);
	temp = w/(h*h);
	if (temp > 25) {
		printf("%.1f\nPANG",temp);
	}
	else {
		printf("%.1f\nHai Xing",temp);
	}
	return 0;
}