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
			//strchr()����
			//char *strchr(const char *str, int c) �ڲ��� str ��ָ����ַ�����������һ�γ����ַ� c��һ���޷����ַ�����λ�á�
			continue;
		}
		else
		{
			printf("%c", m[i]);
		}
	}
	return 0;
}