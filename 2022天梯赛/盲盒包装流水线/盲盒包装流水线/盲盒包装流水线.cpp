#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void find(int n, int* p) {
	for (int i = 0; i < 100001; i++) {
		if (p[n] > 0) {
			printf("%d\n", p[n]);
			break;
		}
	}
}
int main(void) {
	int n, s, k;
	scanf("%d %d", &n, &s);
	int num[100001];//�洢���ӵ����
	//������ӱ��
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}
	//
	int hz[100], x;
	int p[100001];
	for (int i = 0; i < n / s; i++) {
		for (int j = 0; j < s; j++) {
			scanf("%d", &hz[j]);
			x = s - 1;
			p[num[s - 1]] = hz[j];
			x--;
		}
	}

	//������ҵĴ���
	scanf("%d", &k);
	int number,flag = 0;
	for (int i = 0; i < k; i++) {
		flag = 0;
		scanf("%d\n", &number);
		for (int j = 0; j < n; j++) {
			if (number == num[j]) {
				flag = 1;
				break;
			}
		}
		if (flag) {
			find(number, p);
		}
		else {
			printf("Wrong Number\n");
		}
	}
	return 0;
}