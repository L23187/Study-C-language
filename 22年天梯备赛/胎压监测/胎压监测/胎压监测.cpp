#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
int main(void) {
	int a[5], max = 0, min, sub, count = 0;
	int x;
	for (int i = 1; i <=4; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] > max) {
			max = a[i];
		}
	}
	scanf("%d %d", &min, &sub);
	for (int i = 1; i <= 4; i++)
	{
		if (max - a[i] > sub || a[i] < min) {
			count++;
			x = i;
		}
	}
	if (!count) {
		printf("Normal\n");
	}
	else if (count == 1)
		printf("Warning: please check #%d!", x);
	else
		printf("Warning: please check all the tires!");
	return 0;
}