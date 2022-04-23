#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main(void) {
	char str[10001];
	scanf("%s", str);
	int g = 0, p = 0, l = 0, t = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == 'G'||str[i]=='g') {
			g++;
		}
		if (str[i] == 'P'||str[i]=='p') {
			p++;
		}
		if (str[i] == 'L'||str[i] =='l') {
			l++;
		}
		if (str[i] == 'T'||str[i]=='t') {
			t++;
		}
	}
	while (1) {
		if (g > 0) {
			printf("G");
			g--;
		}
		if (p > 0) {
			printf("P");
			p--;
		}
		if (l > 0) {
			printf("L");
			l--;
		}
		if (t > 0) {
			printf("T");
			t--;
		}
		if (g == 0 && p == 0 && l == 0 && t == 0)
			break;

	}
	return 0;
}