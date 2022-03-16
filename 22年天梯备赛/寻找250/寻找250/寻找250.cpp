#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main(void) {
	int n, k = 0;
	scanf("%d", &n);
	for (int i = 1; ; i++) {
		if (n == 250 || n == -250){
			printf("%d", i); break;
		}
		scanf("%d", &n);
	}
	return 0;
}