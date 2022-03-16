#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main(void) {
	int n;
	char c='0';
	scanf("%d %c", &n, &c);
	char s[10000];
	getchar();
	gets_s(s);
	if (n >= strlen(s)) {
		for (int i = 0; i < n-strlen(s); i++)
		{
			printf("%c", c);
		}
		printf("%s", s);
	}
	else {
		for (int i = strlen(s) - n; i < strlen(s); i++)
		{
			putchar(s[i]);
		}
	}
	return 0;
}