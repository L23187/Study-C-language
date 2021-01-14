#include <stdio.h>
int main(){
	int m,n,x,a,b;//定义变量 
	scanf("%d%d",&m,&n);//输入两个数 
	if(m>n){//判断输入数的大小，保持一直是大数减小数 
		x=m;
		m=n;
		n=x;
	}
	a=m;//将大数赋值于a 
	b=n;//将小数赋值于b 
	while(b!=0){//最大公约数求解 （辗转相除法） 
		x=a%b;
		a=b;
		b=x;
	}
	printf("%d %d",a,m*n/a);//输出两数的最大公约数和最小公倍数 
	return 0;
}
