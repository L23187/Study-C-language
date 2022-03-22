#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main(void) {
	int n, j;
	scanf("%d", &n);
	int cx, m, mask = 1, sum = 0, t, f, c;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &cx);
		t = cx;
		sum = 0;
		while (t) {
			sum += t % 10;
			t /= 10;
		}
		f = sum;
		c = 0;
		for (j = 2; j < 10; j++) {
			t = cx * j;
			sum = 0;
			while (t) {
				sum += t % 10;
				t /= 10;
			}if (sum == f) {
				c++;
			}
		}
		if (c == 8) {
			printf("%d\n", f);
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
}