#include <stdio.h>
int main(){
	int n;//定义输入的项数 
	while(scanf("%d",&n)!=EOF){
		if(n==0) break;//当 n = 0 时停止运行 
		int i, k, j;//定义i为项数，k为前一项的项数，j为2,3,5,7四个质因数存在的数组 
		long long int a[5843];//定义一个长数组 
		int b[4]={2,3,5,7};//将四个质因数赋值在一个数组中 
		a[1]=1;//将第一个数字定为 1 
		for( i = 2; i <= 5842; i ++)//从第二项开始把整个数组输入 
	{
		a[i] = 2000000001;//令每次循环都与该数组最大一项对比 
			for(j = 0; j < 4; j ++)//该循环以及下一个循环的意义是将第 i-1 项的数与2,3,5,7相乘并将最小值保留下来 
		{
				for( k = i-1; k >= 1; k --)
			{
					if(a[k]*b[j] <= a[i-1])//保证第i-1项小于第i项 
						break;
					if(a[k]*b[j] < a[i])//保证第 i-1 项乘以2,3,5,7后是小于第n项的
						a[i] = a[k]*b[j];
				}
			}
		
	}
	printf("The %d",n);//将第几项以英文输出 
	if(n%10==1&&n%100!=11){
		printf("st");
	}
	else if(n%10==2&&n%100!=12){
		printf("nd");
	}
	else if(n%10==3&&n%100!=13){
		printf("rd");
	}
	else{
		printf("th");
	}
	printf(" humble number is %lld.\n",a[n]);
	}
	return 0;
}
