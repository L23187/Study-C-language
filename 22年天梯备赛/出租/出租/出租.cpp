#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main(void) {
	char num[12];
	scanf("%s", num);
	int arr[10] = { 0 };
	int index[12] = { 0 };
	int a[10] = { 0 };//判断是否读入过此数字
	for (int i = 0; i < 11; i++)
	{
		a[num[i] - '0'] = 1;//单个字符减去'0'，多是用于字符转数字的时候
	}
	int num_ = 0;//记录有多少个数字
	for (int i = 9; i >= 0; i--)
	{
		if (a[i]) {
			arr[num_++] = i;//降序生成arr
		}
	}
	for (int i = 0; i < 11; i++)
	{
		int n = num[i] - '0';
		int k;//记录数字
		for (k = 0; k < 10; k++) {
			if (n == arr[k])break;//在arr中找到位置
		}
		index[i] = k;
	}
	printf("int[] arr = new int[]{");
	printf("%d", arr[0]);
	for (int i = 1; i < num_; i++)
	{
		printf(",%d", arr[i]);
	}
	printf("};\n");
	printf("int[] index = new int[]{");
	printf("%d", index[0]);
	for (int i = 1; i < 11; i++)
	{
		printf(",%d", index[i]);
	}
	printf("};\n");
	return 0;
}