#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main(void) {
	char m[81];
	int num1 = 0, num2 = 0, first_get = 0;//num1�����������num2�ǳ��������
	for (int i = 0;; i++)
	{
		gets_s(m);
		/*strcmp�����ǱȽ������ַ������������ֵΪ0�����ַ������
		�������ֵ����0��str1����str2���������ֵС��0��str1С��str2*/
		if (strcmp(".", m) == 0) {
			break;
		}
		num1++;
		/*strstr(const char* str1, const char* str2)�����ַ���str1
		���ҵ�һ�γ���str2��λ�ã�����������ֹ��'\0'*/
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