#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
typedef struct {
	int dw;
	int dy;
	int sc;
}data;
int main(void) {
	int n;
	scanf("%d", &n);
	data a[1000] = { 0 };
	for (int i = 0; i < n; i++)
	{
		scanf("%d-%d %d", &a[i].dw, &a[i].dy, &a[i].sc);
	}
	int sc[1000] = { 0 };
	for (int i = 0; i < n; i++) {
		for (int j = n; j > i; j--) {
			if (a[i].dw == a[j].dw) {
				sc[i] = a[i].sc + a[j].sc;
			}
		}
	}
	int max = 0, temp;
	for (int i = 0; i < 1000; i++) {
		if (max < sc[i]) {
			max = sc[i];
			temp = i;
		}
	}
	printf("%d %d\n", a[temp].dw, sc[temp]);
	return 0;
}