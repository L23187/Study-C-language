#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main(void) {
	int y, x, n,temp = 0;
	int a[4];
	scanf("%d %d", &y, &n);
	for (int i = y;; i++)
	{
		a[3] = i % 10;
		a[2] = i / 10 % 10;
		a[1] = i / 100 % 10;
		a[0] = i / 1000;
		for (int j = 0; j < 3; j++) {
			if (a[j] > a[j + 1]) {
				temp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = temp;
			}
		}
		if (a[0] != a[1] && a[0] != a[2] && a[0] != a[3] && a[1] != a[2] && a[1] != a[3] && a[2] != a[3] && n == 4) {
		printf("%d %04d", i - y, i);
		break;
		}
		if (n == 3) {
			if ((a[0] == a[1] && a[0] != a[2] && a[0] != a[3] && a[2] != a[3]) || (a[1] == a[2] && a[0] != a[1] && a[1] != a[3] && a[0] != a[3]) || (a[2] == a[3] && a[0] != a[1] && a[0] != a[2] && a[1] != a[2])) {
				printf("%d %04d", i - y, i);
				break;
			}
		}

		if (a[0] == a[1] && a[0] == a[2] && a[0] != a[3] && n == 2) {
			printf("%d %04d", i - y, i);
			break;
		}
	}
	return 0;
}