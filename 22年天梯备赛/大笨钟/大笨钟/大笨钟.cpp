#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main(void) {
	int hour,min;
	scanf("%d:%d", &hour, &min);
	if (hour >= 12) {
		if (hour == 12 && min == 0) 
			printf("Only %02d:%02d.  Too early to Dang.", hour, min);
		
		else if (min > 0) {
			hour++;
		}
		for (int i = 0; i < hour - 12; i++) {
			printf("Dang");
		}
	}
	if (hour < 12) {
		printf("Only %02d:%02d.  Too early to Dang.", hour, min);
	}
	return 0;
}