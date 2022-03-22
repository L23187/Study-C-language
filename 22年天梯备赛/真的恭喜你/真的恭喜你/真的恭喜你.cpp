#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main(void) {
	int score;
	scanf("%d", &score);
	if (score >= 90) {
		printf("gong xi ni kao le %d fen!", score);
	}
	else
	{
		printf("kao le %d fen bie xie qi!", score);
	}
	return 0;
}