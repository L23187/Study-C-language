#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void output(int n, int* p) {
	printf("%d\n",p[n]);
}
int find(int k, int* num, int n, int flag,int number) {
	for (int j = 0; j < n; j++) {
		if (number == num[j]) {
			return 1;
		}
	}
	return 0;
}
int main(void) {
	int n, s, k;
	scanf("%d %d", &n, &s);
	int num[1001];//存储盒子的序号
	//输入盒子编号
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}
	int nw;
	int p[100001];
	int t;
	for (int i = 1; i <= n / s; i++) {
		t = s * i  - 1;
		for (int j = 0; j < s; j++) {
			scanf("%d", &nw);
			p[num[t]] = nw;
			t--;
		}
	}
	//输入查找的次数
	scanf("%d", &k);
	int number,flag = 0;
	for (int i = 0; i < k; i++) {
		flag = 0;
		scanf("%d", &number);
		if (find(k, num, n, flag, number)) {
			output(number, p);
		}
		else {
			printf("Wrong Number\n");
		}
	}
	return 0;
}