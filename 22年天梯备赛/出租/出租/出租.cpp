#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main(void) {
	char num[12];
	scanf("%s", num);
	int arr[10] = { 0 };
	int index[12] = { 0 };
	int a[10] = { 0 };//�ж��Ƿ�����������
	for (int i = 0; i < 11; i++)
	{
		a[num[i] - '0'] = 1;//�����ַ���ȥ'0'�����������ַ�ת���ֵ�ʱ��
	}
	int num_ = 0;//��¼�ж��ٸ�����
	for (int i = 9; i >= 0; i--)
	{
		if (a[i]) {
			arr[num_++] = i;//��������arr
		}
	}
	for (int i = 0; i < 11; i++)
	{
		int n = num[i] - '0';
		int k;//��¼����
		for (k = 0; k < 10; k++) {
			if (n == arr[k])break;//��arr���ҵ�λ��
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