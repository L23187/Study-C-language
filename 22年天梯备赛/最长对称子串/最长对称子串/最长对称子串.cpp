#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
char a[10001];
//���ڶԳ��Ӵ�ǰ�����ֻҪ������һ������ܺ��ҵ�
int judge(int i, int j) {
	while (i <= j) {
		if (a[i++] != a[j--]) {//��ǰ��ͺ���ͬʱ�����ж϶Գ��Ӵ���λ��
			return 0;
		}
	}
	return 1;
}
int main(void) {
	gets_s(a);//�����ַ���
	int maxn = 0;
	//ͨ��˫ָ��ķ����ж�
	for (int i = 0; i < strlen(a); i++)
	{
		for (int j = strlen(a) - 1; j >= i; j--)//�ַ������һ����'/0'��Ҫ��ȥ1
		{
			if (judge(i, j)) {
				maxn = maxn > (j - i + 1) ? maxn : (j - i + 1);
			}
		}
	}
	printf("%d", maxn);
	return 0;
}