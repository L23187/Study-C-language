#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main(void) {
	int n;
	scanf("%d", &n);
	int sex, h, w;
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &sex, &h, &w);
		if (sex == 1) {
			if (h <= 130) {
				if (h == 130) {
					printf("wan mei! ");
				}
				else {
					printf("duo chi yu! ");
				}
			}
			else {
				printf("ni li hai! ");
			}
			if (w <= 27) {
				if (w == 27) {
					printf("wan mei!\n");
				}
				else {
					printf("duo chi rou!\n");
				}
			}
			else {
				printf("shao chi rou!\n");
			}
		}
		if (sex == 0) {
			if (h <= 129) {
				if (h == 129) {
					printf("wan mei! ");
				}
				else {
					printf("duo chi yu! ");
				}
			}
			else {
				printf("ni li hai! ");
			}
			if (w <= 25) {
				if (w == 25) {
					printf("wan mei!\n");
				}
				else {
					printf("duo chi rou!\n");
				}
			}
			else {
				printf("shao chi rou!\n");
			}
		}
	}
	return 0;
}