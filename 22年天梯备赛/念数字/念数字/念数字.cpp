#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
int main(void) {
	char num[1000];
	scanf("%s", num);
	for (int i= 0; i < strlen(num); i++)
	{
		if (num[i] == '-') {
			printf("fu");
		}
		if (num[i] == '0') {
			printf("ling");
		}
		if (num[i] == '1') {
			printf("yi");
		}
		if (num[i] == '2') {
			printf("er");
		}
		if (num[i] == '3') {
			printf("san");
		}
		if (num[i] == '4') {
			printf("si");
		}
		if (num[i] == '5') {
			printf("wu");
		}
		if (num[i] == '6') {
			printf("liu");
		}
		if (num[i] == '7') {
			printf("qi");
		}
		if (num[i] == '8') {
			printf("ba");
		}
		if (num[i] == '9') {
			printf("jiu");
		}
		if (i < strlen(num)-1) {
			printf(" ");
		}
	}
	return 0; 
}