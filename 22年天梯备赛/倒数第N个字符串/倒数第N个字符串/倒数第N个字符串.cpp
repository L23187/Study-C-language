#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int main(void) {
	int l, n;
	char c[10] = {"aaaaaaaaa"};
	scanf("%d%d", &l, &n);
	int q = pow(26, l) - n;
	for (int i = l - 1; i >= 0; i--) {
		c[i] = c[i] + q % 26;//qΪl�����ַ��������н��
		q = q / 26;//��λ
	}
	for (int i = 0; i< l; i++) {
		printf("%c", c[i]);
	}
	return 0;
}
