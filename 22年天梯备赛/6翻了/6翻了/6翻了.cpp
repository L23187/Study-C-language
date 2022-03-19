#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main(void) {
	char str[1001];
	gets_s(str);//输入字符串
	int k = 0;//统计6的个数
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == '6') {
			k++;//如果字符串是6，k+1
		}
		else {
			if (k <= 3) {
				for (int j = 0; j < k; j++) {
					printf("6");
				}
			}
			else if (k > 3 && k <= 9) {
				printf("9");
			}
			else {
				printf("27");
			}
			k = 0;
			printf("%c", str[i]);//一个字符一个字符的输出
		}
	}
	//判断最后的6的输出
	if (k > 0) {
		if (k <= 3) {
			for (int j = 0; j < k; j++) {
				printf("6");
			}
		}
		else if (k > 3 && k <= 9) {
			printf("9");
		}
		else {
			printf("27");
		}
	}
	return 0;
}