#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
int sam(int m) {//�ж����� 
	int i;
	if (m < 2)	return 0;
	for (i = 2; i * i <= m; i++) {
		if (m % i == 0)	return 0;
	}
	return 1;
}
int main() {
	int L, k, i;
	char n[1000], arr[10] = { 0 };//�ַ�����Ϊ L ��K λ�������֣�����Ϊ L �������� N�ַ���
	scanf("%d %d %s", &L, &k, n);//L==strlen(n)
	for (i = 0; i <= L - k; i++) {
		strncpy(arr, n + i, k);//strncpy()�������ڽ�ָ�����ȵ��ַ������Ƶ��ַ�����
		if (sam(atoi(arr))) {//atoi()���ַ���ת������������һ������
			printf("%s", arr);
			return 0;
		}
	}
	printf("404");
	return 0;
}