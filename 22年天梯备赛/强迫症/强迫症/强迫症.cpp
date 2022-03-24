#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main(void) {
	char cs[7] = {0};
	scanf("%s", cs);
	int num;
	if (strlen(cs) == 4) {
		num = (cs[0] - '0') * 10 + (cs[1] - '0');
		if (num < 22) {
			printf("20%c%c-%02d\n", cs[0], cs[1], (cs[2] - '0') * 10 + (cs[3] - '0'));
		}
		else {
			printf("19%c%c-%02d\n", cs[0], cs[1], (cs[2] - '0') * 10 + (cs[3] - '0'));
		}
	}
	else {
		printf("%c%c%c%c-%c%c\n", cs[0], cs[1], cs[2], cs[3], cs[4], cs[5]);
	}
	return 0;
}