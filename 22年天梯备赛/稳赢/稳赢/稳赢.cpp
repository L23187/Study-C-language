#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main(void) {
	int k;
	scanf("%d", &k);
	char chuz[10], n = 0;
	for (int i = 0; ; i++) {
		scanf("%s",chuz);
		

		if (chuz[0] == 'C') {
			n++;
			if (n > k) {
				printf("%s\n",chuz);
				n = 0;
			}
			else
			{
				printf("Bu\n");
			}
		}
		else if (chuz[0] == 'B') {
			n++;
			if (n > k) {
				printf("%s\n", chuz);
				n = 0;
			}
			else
			{
				printf("JianDao\n");
			}
		}
		else if (chuz[0] == 'J') {
			n++;
			if (n > k) {
				printf("%s\n", chuz);
				n = 0;
			}
			else
			{
				printf("ChuiZi\n");
			}
		}
		if (chuz[0] == 'E') {
			break;
		}
	}
	return 0;
}