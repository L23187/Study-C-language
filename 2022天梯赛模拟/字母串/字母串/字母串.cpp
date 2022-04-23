#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main(void) {
	int n;
	scanf("%d", &n);
	char s[10001];
	int flag;
	for (int i = 0; i < n; i++) {
		flag = 0;
		scanf("%s", s);
		for (int i = 0; i < strlen(s) - 1; i++) {
			if (s[i] >= 'A' && s[i] <= 'Z') {
				if (s[i + 1] == s[i] + 32 || s[i + 1] == s[i] + 1) {
					flag += 1;
				}
				else {
					flag = -1;
				}
			}if (s[i] >= 'a' && s[i] <= 'z') {
				if (s[i + 1] == s[i] - 32 || s[i + 1] == s[i] - 1) {
					flag += 1;
				}
				else {
					flag = -1;
				}
			}
			/*printf("%d %d\n", i, flag);*/
		}
		if (flag == strlen(s)-1) {
			printf("Y\n", flag);
		}
		else {
			printf("N\n", flag);
		}
	}
	return 0;
}