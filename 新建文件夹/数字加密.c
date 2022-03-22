#include <stdio.h>
int main()
{
	
	int num[4],i;//定义一个数组用来之后方便计算输出 
	
	scanf ("%d",&i);//输入一个数，之后用来一个一个分开独立计算 
	num[0]=i/1000;
	num[1]=(i/100)%10;
	num[2]=(i/10)%100-num[1]*10;
	num[3]=i%1000-num[1]*100-num[2]*10;
 
	for (i=0;i<4;i++)//通过循环用来对输入的数字进行加密处理 
		num[i]=(num[i]+9)%10;
	printf("The encrypted number is %d%d%d%d\n",num[2],num[3],num[0],num[1]);
	return 0;
}
