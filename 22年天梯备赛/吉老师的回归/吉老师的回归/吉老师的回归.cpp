#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main(void) {
	int n, m;
	scanf("%d%d", &n, &m);
	char tm[1000],cnt = 1;
	getchar();
	while(n--){
		gets_s(tm);
		//��tm�ַ�������"easy"��"qiandao"�����Ӵ�
		if (strstr(tm, "easy") || strstr(tm, "qiandao")) {
		}
		else {
			if (m == 0) {
				puts(tm);
				cnt = 0;
			}
			m--;
		}
	}
	if (cnt) {
		puts("Wo AK le");
	}
	return 0;
}