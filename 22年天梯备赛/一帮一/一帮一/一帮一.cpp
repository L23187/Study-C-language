#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
struct student
{
	int sex;
	char name[20];
};//����ṹ�崢��ѧ����Ϣ
int main(void){
	int n;
	scanf("%d", &n);
	struct student stu[100];
	int b[100] = { 0 };//�ǵý��г�ʼ��
	for (int i = 0; i < n; i++)
	{
		scanf("%d %s", &stu[i].sex,stu[i].name);//����ѧ����Ϣ
	}
	for (int i = 0; i < n/2; i++)//��ǰ��α���
	{
		printf("%s ", stu[i].name);
		for (int j = n-1; j >=n/2; j--)//ÿһ������ν��бȽ��Ա�
		{
			if (b[j] == 0 && stu[j].sex != stu[i].sex) {//�ԳƵĽ��бȽ��Ա�
				printf("%s\n", stu[j].name);
				b[j] = 1;
				break;
			}
		}
	}
	return 0;
	}