#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main(void) {
	int n;
	scanf("%d", &n);
	double h;
	char s;
	for (int i = 0; i < n; i++)
	{
		scanf("\n%c %lf", &s, &h);
		/*'\n'��ʾ�������еĿհ��ַ�,����ǿհ��ַ���������,
		����'\n'��ʹc���ջ��з�*/
		if (s == 'F') {
			h = h * 1.09;
			printf("%.2f\n", h);
		}
		else if (s == 'M') {
			 h = h / 1.09;
			 printf("%.2f\n", h);
		}
	}
	return 0;
}