#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main(void) {
	int x;
	scanf("%d", &x);
	int w = 1, k = 0, num = 0;
	while (1)
	{
		if (w / x != 0) {
			k = 1;//�ж���λ�Ƿ�Ϊ�㣬���Ϊ�㲻��Ҫ���
		}
		num++;//ÿ��ѭ����һλ
		if (k) {
			printf("%d", w / x);
		}
		w = w % x; 
		if (w == 0) {
			break;
		}
		w = w * 10 + 1;
	}
	printf(" %d", num);
	return 0;
}