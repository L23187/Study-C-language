#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main(void) {
	char name[100][15];
	int k = 0;
	for (int i = 0;; i++)
	{
		scanf("%s", name[i]);
		if (name[i][0] == '.') {
			break;
		}
		k++;
	}
	if (k >= 14) {
		printf("%s and %s are inviting you to dinner...", name[1], name[13]);
	}
	else if (k >= 2) {
		printf("%s is the only one for you...", name[1]);
	}
	else {
		printf("Momo... No one is for you ...");
	}
	return 0;
}