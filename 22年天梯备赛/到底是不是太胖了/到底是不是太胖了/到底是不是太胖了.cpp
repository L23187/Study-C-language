#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
int main(void) {
	int n;
	scanf("%d", &n);
	int height;
	double per ,w_z, weight;
	for (int i = 0; i < n; i++)
	{
		scanf("%d%lf", &height, &weight);
		per = (height - 100) * 0.9;
		w_z = 0.5 * weight;
		if (fabs(w_z-per) < per*0.1) {
			printf("You are wan mei!\n");
		}
		else {
			if (w_z <= per * 0.9) {
				printf("shou");
			}
			else
			{
				printf("pang");
			}
		}
	}
	return 0;
}