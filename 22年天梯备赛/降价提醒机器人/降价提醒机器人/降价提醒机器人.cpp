#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	double p;
	for (int i = 0; i < n; i++) {
		scanf("%lf", &p);
		if (p < m) {
			printf("On Sale! %.1f\n", p);
		}
	}
	return 0;
}