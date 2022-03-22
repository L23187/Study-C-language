#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main(void) {
	int n, f;
	scanf("%d", &n);
	char cx[1000001];
	for (int i = 0; i < n; i++) {
		f = 0;
		scanf("%s", cx);
		for (int j = 0; cx[j] != '\0'; j++) {
			f += cx[j] - '0';
		}
	}
	printf("%d %d", cx - '0',f);
	return 0;
}