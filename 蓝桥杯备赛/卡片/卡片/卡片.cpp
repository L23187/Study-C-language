#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int n, ans, cnt;
int main(void) {
	while (1) {
		n = ans;
		while (n) {
			if (n % 10 == 1)cnt++;
			n /= 10;
		}
		if (cnt < 2021)
			ans++;
		else 
			break;
	}
	printf("%d", ans);
	return 0;
}