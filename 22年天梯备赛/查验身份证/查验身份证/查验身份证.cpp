#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int n;
	//�������֤��
	char code[19];
	//����Ȩֵ
	int q[17] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
	//����У�����ֵ
	char M[11] = { '1','0','X','9','8','7','6','5','4','3','2' };
	//����Լ�Ȩ���֮�����ȡģ�õ���ֵm����ǰ17λ���ּ�Ȩ���sum�Լ��жϺ����Ƿ���ȷ��ֵflag
	int sum = 0, m, flag = 0;
	//�������֤����n
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		//ÿ��ѭ����ʼʱ��Ȩ��͵�ֵΪ0
		sum = 0;
		//�������֤��
		scanf("%s", code);
		for (int j = 0; j < 17; j++)
		{
			//�����Ȩ���
			sum += (code[j]- '0') * q[j];
		}
		//����ģֵ
		m = sum % 11;
		//�Ƚϵõ���ģֵ��У����Ĺ�ϵ
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
