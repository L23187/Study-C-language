#include <stdio.h>
int main(){
	int m,n;//定义两个整数 
	double c;//定义两数相除之后的不为整数的数 
	scanf("%d%d",&m,&n);
	printf("%d + %d = %d\n",m,n,m+n);
	printf("%d - %d = %d\n",m,n,m-n);
	printf("%d * %d = %d\n",m,n,m*n);
	if(m%n==0){//当两数相除之后数为整数时 
		printf("%d / %d = %d\n",m,n,m/n);
	}else{
		c=(double)m/n;//强制转换为浮点数 
		printf("%d / %d = %.2f\n",m,n,c);
	}
	return 0;
} 
