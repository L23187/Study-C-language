#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main(void) {
	char a[1000], b[1000];
	scanf("%s", &a);
	gets_s(b);//�������뷽ʽ��ϣ�����������ڶ����ַ�����ͷ�Ŀո�����һ�����Ե�
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
	if (test_a && test_b)//�������Ҳ�ǱȽ����׳���ģ����ǵ�tempa��tempbһ��Ҫд��ǰ�棬����ᱨ��ģ�������һ�ԾͿ����������ˣ����������ǻ��˺ܾ�
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
	for (int i = strlen(a)-1;i >=0;i--)//���ﵽ0�����������������ѭ�����Ա�
	{
		if (a[i] - '0' >= 0 && a[i] - '0' <= 9)//����ʹ�õ���ѭ�����е���ģ���Ϊ�����sumx��������
		{
			x += (a[i] - '0') * sumx;
			sumx *= 10;
			if (a[0] == '0' || x > 1000)//�������Ƕ�����д��������ҿ��Ժ������if���ԱȻᷢ���ǲ�һ����
				tempa = 0;
		}
		else
		{
			tempa = 0;
		}
	}
	for (int j = strlen(b)-1;j >=1;j--)//��������Ҫ��1�����ģ���Ϊb[0]�ǿո�
	{
		if (b[j] - '0'>=0 && b[j] - '0' <= 9)
		{
			y += (b[j] - '0') * sumy;
			sumy *= 10;
			if (b[1] == '0' || y > 1000)//�н������ѭ��������������Ҫ�ж�b[0]
				tempb = 0;
		}
		else
		{
			tempb = 0;
		}
	}
	if (tempa&&tempb)//�������Ҳ�ǱȽ����׳���ģ����ǵ�tempa��tempbһ��Ҫд��ǰ�棬����ᱨ��ģ�������һ�ԾͿ����������ˣ����������ǻ��˺ܾ�
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