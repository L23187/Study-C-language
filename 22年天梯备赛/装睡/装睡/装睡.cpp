#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main(void) {
	int n;
	scanf("%d", &n);
	char name[5];
	int h, m;
	for (int i = 0; i < n; i++)
	{
		scanf("%s %d %d", name, &h, &m);
		if ((h < 15 || h > 20) || m < 50 || m > 70) {
			puts(name);
		}
	}
	return 0;
}