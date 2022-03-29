#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main(void) {
	int n;
	scanf("%d", &n);
	long long int zkz;
	int s, k;
	long long int b[1001][2] = {0};
	//长整型输入为lld，长整型可以存十几位数
	for (int i = 0; i < n; i++) {
		scanf("%lld %d %d", &zkz, &s, &k);
		b[s][0] = zkz;
		b[s][1] = k;
	}
	int m;
	scanf("%d", &m);
	int x;
	for (int i = 0; i < m; i++) {
		scanf("%d", &x);
		printf("%lld %d\n", b[x][0], b[x][1]);
	}
	return 0;
}