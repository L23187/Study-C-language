#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
int main(void) {
	int n;
	scanf("%d", &n);
	int flag = 0, start = 0, l = 0;
	int s = 0;
	//�ж��Ƿ�Ϊ���������Ϊ����ֱ�����1��������
	for (int i = 2;i < sqrt(n); i++)
	{
		if (n % i == 0) {
			flag = 1;
		}
	}
	if (flag == 0) {
		printf("1\n%d\n", n);
	}
	else {
		for (int i = 2; i < sqrt(n); i++) {
			s = 1;
			for (int j = i; s * j <= n; j++) {
				s = s * j;
				//��n�ܱ��������Ҽ�¼�������еĳ���
				if (n % s == 0 && j - i + 1 > l) {
					start = i;
					l = j - i + 1;
				}
			}
		}
		printf("%d\n", l);
		for (int i = start; i < start + l; i++) {
			if (i == start) {
				printf("%d", i);
			}
			else {
				printf("*%d", i);
			}
		}
		printf("\n");
	}
	return 0;
}