#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main(void) {
	char m[81];
	getchar();
	for (int i = 0;; i++)
	{
		gets_s(m);
		if (m[i] == '.') {
			printf("%d\n", i);
			break;
		}

	}

	return 0;
}