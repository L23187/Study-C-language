#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main(void) {
	//��һ�����1000λ���ֵ��ַ���
	char a[1001];
	scanf("%s", a);
	int k = 1;
	//���ַ���������С�������У����ٴ洢��һ������������
	for (int i = 0; i < strlen(a) - 1; i++) {
		for (int j = 0; j < strlen(a) - 1 - i; j++) {
			if (a[j] - '0' > a[j + 1] - '0') {
				char num = a[j];
				a[j] = a[j + 1];
				a[j + 1] = num;
			}
		}
	}
	int s[1001];
	for (int i = 0; i < strlen(a); i++) {
		s[i] = a[i] - '0';
	}
	for (int i = 0; i < strlen(a); i++) {
		if (s[i] == s[i + 1]) {
			k++;
		}
		if (s[i] != s[i + 1]) {
			printf("%d:%d\n", s[i],k);
			k = 1;
		}
	}
	return 0;
}