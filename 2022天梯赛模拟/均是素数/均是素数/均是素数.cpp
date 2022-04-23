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
int main(void) {
	int m, n;
	int ss[1001];//将在范围内的素数存入数组中
	scanf("%d %d", &m, &n);
	int k = 0,flag = 0;
	for (int i = m ; i <= n; i++) {
		if (judge(i)) {
			ss[k] = i;
			k++;
		}
	}
	int x = 0;
	for (int p = 0; p < k; p++) {
		for (int q = p+1; q < k; q++) {
			for (int r = q+1; r < k; r++) {
				if (judge(ss[p] * ss[q] + ss[r]) && judge(ss[q] * ss[r] + ss[p]) && judge(ss[r] * ss[p] + ss[q])) {
					x++;
				}
			}
		}
	}
	printf("%d", x);
	return 0;
}