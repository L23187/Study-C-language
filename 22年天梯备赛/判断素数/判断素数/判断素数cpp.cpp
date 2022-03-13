#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
int main(void) {
	int n, num, j;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num);
		if (num == 1) {
			printf("No\n");
		}
		else {
			for (j = 2; j <= sqrt(num); j++)
			{
				if (num % j == 0) {
					break;
				}
			}
			if (j > sqrt(num)) {
				printf("Yes\n");
			}
			else {
				printf("No\n");
			}
		}
	}
	return 0;
}