#include <stdio.h>
int main()
{
	
	int num[4],i;//����һ����������֮�󷽱������� 
	
	scanf ("%d",&i);//����һ������֮������һ��һ���ֿ��������� 
	num[0]=i/1000;
	num[1]=(i/100)%10;
	num[2]=(i/10)%100-num[1]*10;
	num[3]=i%1000-num[1]*100-num[2]*10;
 
	for (i=0;i<4;i++)//ͨ��ѭ����������������ֽ��м��ܴ��� 
		num[i]=(num[i]+9)%10;
	printf("The encrypted number is %d%d%d%d\n",num[2],num[3],num[0],num[1]);
	return 0;
}
