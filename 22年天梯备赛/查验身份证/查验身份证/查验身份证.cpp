#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int n;
	//定义身份证号
	char code[19];
	//给定权值
	int q[17] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
	//给定校验码的值
	char M[11] = { '1','0','X','9','8','7','6','5','4','3','2' };
	//定义对加权求和之后进行取模得到的值m，对前17位数字加权求和sum以及判断号码是否正确的值flag
	int sum = 0, m, flag = 0;
	//输入身份证个数n
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		//每次循环开始时加权求和的值为0
		sum = 0;
		//输入身份证号
		scanf("%s", code);
		for (int j = 0; j < 17; j++)
		{
			//计算加权求和
			sum += (code[j]- '0') * q[j];
		}
		//计算模值
		m = sum % 11;
		//比较得到的模值和校验码的关系
		if (M[m] != code[17]) {
			printf("%s\n", code);
			flag = 1;
		}
	}
	if (!flag) {
		printf("All passed");
	}
	return 0;
}
