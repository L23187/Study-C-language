#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main(void) {
	int n;
	scanf("%d", &n);
	char str[1001][1001], ch;
	getchar();
	int h = 0, l = 0;
	/*用二维数组依次存储字符串的字符，
	当字符数的到n时，列数加一，
	输出时横纵坐标互换，逆置输出。*/
	while ((ch = getchar()) != '\n') {
		h += l / n;
		l %= n;
		str[h][l++] = ch;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = h; j >= 0; j--)
		{
			putchar(str[j][i] ? str[j][i] : ' ');
		}
		putchar('\n');
	}
	return 0;
}