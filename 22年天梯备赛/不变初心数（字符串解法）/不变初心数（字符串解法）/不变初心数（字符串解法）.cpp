#define _CRT_SECURE_NO_WARNINGS 1
//PTA���������Ե㲻�ԣ���֪�����ģ�ֻ�ܵ�10�֣�����ѧϰ
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(void) {
	int n, f, x, p, flag = 0, cnt = 0;//fΪ���������ʼ����λ����ӣ�
	//xΪ���ֳ���֮�������pΪ����֮��ĸ���λ��֮��
	scanf("%d", &n);
	char cx[1001], zh[1001];
	for (int i = 0; i < n; i++) {
		f = 0;
		scanf("%s", cx);
		for (int j = 0; cx[j] != '\0'; j++) {
			f += cx[j] - '0';
		}
		for (int j = 2; j <= 9; j++) {
			//atoi�������ַ���ת��Ϊ����
			x = atoi(cx) * 2;
			//sprintf�������������ת��Ϊ�ַ���
			sprintf(zh,"%d",x);
			p = 0;
			for (int k = 0; zh[k] != '\0'; k++) {
				p += zh[k] - '0';
			}
			if (p == f) {
				flag = 1;
			}
			else {
				flag = 0;
			}
		}
		if (flag == 1) {
			printf("%d\n", f);
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
}