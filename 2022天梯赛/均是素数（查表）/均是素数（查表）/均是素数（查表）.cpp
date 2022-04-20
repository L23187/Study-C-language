#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
int judge(int m) {
	if (m < 2)
		return 0;
	for (int i = 2; i <= sqrt(m); i++) {
		if (m % i == 0)
			return 0;
	}
	return 1;
}
int find(int n, int* ss,int length) {
	for (int i = 0; i < length; i++) {
		if (n == ss[i]) {
			return 1;
			break;
		}
		else {
			return 0;
		}
	}
}
int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	int ss[1001], k = 0;
	for (int i = 1; i <= 1000; i++) {
		if (judge(i)) {
			ss[k] = i;
			k++;
		}
	}
	for (int i = 0; i < k; i++) {
		printf("%d ", ss[i]);
	}
	int x = 0;
	for (int p = 0; p < m; p++) {
		for (int q = p+1; q < m; q++) {
			for (int r = q+1; r < m; r++) {
				if (find(ss[p] * ss[q] + ss[r], ss,k) && find(ss[q] * ss[r] + ss[p], ss,k) && find(ss[r] * ss[p] + ss[q], ss,k)) {
					x++;
				}
			}
		}
	}
	printf("\n%d", x);
	return 0;
}