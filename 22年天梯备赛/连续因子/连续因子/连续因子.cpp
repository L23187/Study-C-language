#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
int main(void) {
	int n;
	scanf("%d", &n);
	int flag = 0, start = 0, len = 0;
	int s = 0;
	//�ж���������Ƿ�������������ǣ������1��������
	for (int i = 2; i < sqrt(n); i++)
	{
		if (n % i == 0) {
			flag = 1;
		}
	}
	if (flag == 0) {
		printf("1\n%d\n", n);
	}
	//����������
	//����һ���� N�������������Ӷ��϶��� sqrt(N) ��
	//ö��ÿһ�ε�����Ϊ��㣬������������������
	//��֮ǰ���������������Ƚϣ�ȡ���ֵ����������Ϊ������������
	else {
		for (int i = 2; i < sqrt(n); i++) {
			s = 1;
			//��s�𽥽ӽ�nʱ
			for (int j = i; s * j <= n; j++) {
				s = s * j;
				//��֤s��������n����
				if (n % s == 0 && j - i + 1 > len) {
					start = i;
					len = j - i + 1;
				}
			}
		}
		printf("%d\n", len);
		for (int i = start; i < start + len; i++) {
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