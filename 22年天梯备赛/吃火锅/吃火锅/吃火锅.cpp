#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main(void) {
	char m[81];
	int num1 = 0, num2 = 0, first_get = 0;//num1是总语句数，num2是出现语句数
	for (int i = 0;; i++)
	{
		gets_s(m);
		/*strcmp函数是比较两个字符串的如果返回值为0则两字符串相等
		如果返回值大于0则str1大于str2，如果返回值小于0则str1小于str2*/
		if (strcmp(".", m) == 0) {
			break;
		}
		num1++;
		/*strstr(const char* str1, const char* str2)是在字符串str1
		查找第一次出现str2的位置，但不包括终止符'\0'*/
		char* p = strstr(m, "chi1 huo3 guo1");
		if (p != NULL) {
			num2++;
			if (num2 == 1) {
				first_get = num1;
			}
		}
	}
	printf("%d\n", num1);
	if (num2 == 0) {
		printf("-_-#");
	}
	else {
		printf("%d %d", first_get, num2);
	}
	return 0;
}