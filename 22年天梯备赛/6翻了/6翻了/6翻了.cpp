#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main(void) {
	char str[1001];
	gets_s(str);//�����ַ���
	int k = 0;//ͳ��6�ĸ���
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == '6') {
			k++;//����ַ�����6��k+1
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
			printf("%c", str[i]);//һ���ַ�һ���ַ������
		}
	}
	//�ж�����6�����
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