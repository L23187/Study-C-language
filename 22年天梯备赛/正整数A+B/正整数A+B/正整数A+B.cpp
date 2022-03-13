#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main(void) {
	char a[1000], b[1000];
	scanf("%s", &a);
	gets_s(b);//两种输入方式结合，避免读不出第二个字符串开头的空格，其中一个测试点
	int x = 0, y = 0, test_a = 1, test_b = 1;
	int suma = 1, sumb = 1;
	for (int i = strlen(a)-1; i >= 0; i--)
	{
		if (a[i] - '0' >= 0 && a[i] - '0' <= 9) {
			x += (a[i] - '0') * suma;
			suma *= 10;
			if (a[0] == '0' || x > 1000) {
				test_a = 0;
			}
		}
		else
		{
			test_a = 0;
		}
	}
	for (int j = strlen(b)-1; j >= 1; j--)
	{
		if (b[j] - '0' >= 0 && b[j] - '0' <= 9) {
			y += (b[j] - '0') * sumb;
			sumb *= 10;
			if (b[1] == '0' || y > 1000) {
				test_b = 0;
			}
		}
		else
		{
			test_b = 0;
		}
	}
	if (test_a && test_b)//最后的输出也是比较容易出错的，我们的tempa和tempb一定要写在前面，否则会报错的，可以试一试就看出来问题了，我在这里徘徊了很久
		printf("%d + %d = %d", x, y, x + y);
	else if (test_a)
		printf("%d + ? = ?", x);
	else if (test_b)
		printf("? + %d = ?", y);
	else
		printf("? + ? = ?");
	return 0;
}
/*
#include<stdio.h>
#include<string.h>
int main()
{
	char a[1000], b[1000];
	scanf("%s", &a);
	gets(b);
	int x = 0, y = 0, tempa = 1, tempb = 1;
	int sumx = 1,sumy=1;
	for (int i = strlen(a)-1;i >=0;i--)//这里到0结束，可以与下面的循环做对比
	{
		if (a[i] - '0' >= 0 && a[i] - '0' <= 9)//这里使用倒序循环是有道理的，因为下面的sumx便于运算
		{
			x += (a[i] - '0') * sumx;
			sumx *= 10;
			if (a[0] == '0' || x > 1000)//这里我们都可以写出来，大家可以和下面的if做对比会发现是不一样的
				tempa = 0;
		}
		else
		{
			tempa = 0;
		}
	}
	for (int j = strlen(b)-1;j >=1;j--)//这里是需要到1结束的，因为b[0]是空格
	{
		if (b[j] - '0'>=0 && b[j] - '0' <= 9)
		{
			y += (b[j] - '0') * sumy;
			sumy *= 10;
			if (b[1] == '0' || y > 1000)//承接上面的循环条件，这里需要判断b[0]
				tempb = 0;
		}
		else
		{
			tempb = 0;
		}
	}
	if (tempa&&tempb)//最后的输出也是比较容易出错的，我们的tempa和tempb一定要写在前面，否则会报错的，可以试一试就看出来问题了，我在这里徘徊了很久
		printf("%d + %d = %d", x,y,x+y);
	else if (tempa)
		printf("%d + ? = ?", x);
	else if (tempb)
		printf("? + %d = ?", y);
	else
		printf("? + ? = ?");
	return 0;
}
*/