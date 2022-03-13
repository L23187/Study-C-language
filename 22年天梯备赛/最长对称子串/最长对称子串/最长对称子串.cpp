#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
char a[10001];
//由于对称子串前后相等只要从两边一起遍历很好找到
int judge(int i, int j) {
	while (i <= j) {
		if (a[i++] != a[j--]) {//从前面和后面同时遍历判断对称子串的位置
			return 0;
		}
	}
	return 1;
}
int main(void) {
	gets_s(a);//输入字符串
	int maxn = 0;
	//通过双指针的方法判断
	for (int i = 0; i < strlen(a); i++)
	{
		for (int j = strlen(a) - 1; j >= i; j--)//字符串最后一个是'/0'需要减去1
		{
			if (judge(i, j)) {
				maxn = maxn > (j - i + 1) ? maxn : (j - i + 1);
			}
		}
	}
	printf("%d", maxn);
	return 0;
}