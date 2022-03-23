#define _CRT_SECURE_NO_WARNINGS 1
//本题思路是将所有时间换算为分钟，然后再输出
#include<stdio.h>
int main(void) {
	int d, h, m, n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d:%d", &d, &h, &m);
		int t;
		if (d == 0) {
			printf("%d %02d:%02d\n", d, h, m);
		}
		else {
			t = 1440 * (d - 1) + 60 * h + m;
			t = t / 2;
			int day = 0, hh = 0, mm = 0;
			day = t / 1440;
			hh = (t - 1440 * day) / 60;
			mm = t - 1440 * day - 60 * hh;
			printf("%d %02d:%02d\n", day + 1, hh, mm);
		}
	}
	return 0;
}