#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main(void) {
	int n;
	scanf("%d", &n);
	int dw, dy, cj;
	int sc[10000], b[1000] = { 0 };
	for (int i = 0; i < n; i++) {
		scanf("%d-%d %d", &dw, &dy, &sc[i]);
		b[dw] = b[dw] + sc[i];
	}
	int max = 0, tem = 0;
	for (int i = 0; i < 1000; i++) {
		if (max < b[i]) {
			max = b[i];
			tem = i;
		}
	}
	printf("%d %d", tem, max);
	return 0;
}