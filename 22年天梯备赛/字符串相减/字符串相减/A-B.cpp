#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main(void) {
	char m[10001] = { 0 }, n[10001] = { 0 };
	gets_s(m);
	gets_s(n);
	for (int i = 0; i < strlen(m); i++)
	{
		if (strchr(n, m[i])) {
			//strchr()函数
			//char *strchr(const char *str, int c) 在参数 str 所指向的字符串中搜索第一次出现字符 c（一个无符号字符）的位置。
			continue;
		}
		else
		{
			printf("%c", m[i]);
		}
	}
	return 0;
}