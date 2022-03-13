#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
struct student
{
	int sex;
	char name[20];
};//定义结构体储存学生信息
int main(void){
	int n;
	scanf("%d", &n);
	struct student stu[100];
	int b[100] = { 0 };//记得进行初始化
	for (int i = 0; i < n; i++)
	{
		scanf("%d %s", &stu[i].sex,stu[i].name);//输入学生信息
	}
	for (int i = 0; i < n/2; i++)//在前半段遍历
	{
		printf("%s ", stu[i].name);
		for (int j = n-1; j >=n/2; j--)//每一个与后半段进行比较性别
		{
			if (b[j] == 0 && stu[j].sex != stu[i].sex) {//对称的进行比较性别
				printf("%s\n", stu[j].name);
				b[j] = 1;
				break;
			}
		}
	}
	return 0;
	}