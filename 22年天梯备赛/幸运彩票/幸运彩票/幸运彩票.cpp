#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main(void) {
	int n;
	scanf("%d", &n);
	char cp[7], l = 0;
	for (int i = 0; i < n; i++) {
		scanf("%s", cp);
		if ((cp[0] - '0') + (cp[1] - '0') + (cp[2] - '0') == (cp[3] - '0') + (cp[4] - '0') + (cp[5] - '0')) {
			printf("You are lucky!\n");
		}
		else
		{
			printf("Wish you good luck.\n");
		}
	}
	return 0;
}