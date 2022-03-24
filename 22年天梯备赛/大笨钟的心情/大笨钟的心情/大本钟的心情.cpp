#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main(void) {
	int xq[24];
	for (int i = 0; i < 24; i++) {
		scanf("%d", &xq[i]);
	}
	int wy;
	for (int i = 0;;i++) {
		scanf("%d", &wy);
		if (wy < 0 || wy>23) {
			break;
		}
		if (xq[wy] > 50) {
			printf("%d Yes\n", xq[wy]);
		}
		else {
			printf("%d No\n", xq[wy]);
		}
	}
	return 0;
}