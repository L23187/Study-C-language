#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main(void) {
	int n;
	scanf("%d", &n);
	char psw[81];
	getchar();
	for (int i = 0; i < n; i++)
	{
		gets_s(psw);
		int cha = 0, num = 0, d = 0, other = 0;//应该放到里面每次循环都会刷新
		if (strlen(psw) < 6) {
			printf("Your password is tai duan le.\n");
		}
		else
		{
			for (int i = 0; i < strlen(psw); i++) {
				if (psw[i] >= 'a' && psw[i] <= 'z' || psw[i] >= 'A' && psw[i] <= 'Z') {
					cha++;
				}
				else if (psw[i] >= '0' && psw[i] <= '9') {
					num++;
				}
				else if (psw[i] == '.') {
					d++;
				}
				else {
					other++;
				}
			}
			if (other > 0) {
				printf("Your password is tai luan le.\n");
			}
			else if (cha > 0 && num == 0) {
				printf("Your password needs shu zi.\n");
			}
			else if (num > 0 && cha == 0) {
				printf("Your password needs zi mu.\n");
			}
			else
			{
				printf("Your password is wan mei.\n");
			}
		}
	}
	return 0;
}