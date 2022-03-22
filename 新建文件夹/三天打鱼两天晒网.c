#include <stdio.h>
int main(){
	int n,m;//定义输入天数n		以及余数m 
	scanf("%d",&n);//输入天数n 
	m=n%5;//计算天数除以5的余数 
	if(m>0&&m<=3){
		printf("Fishing in day %d",n);
	}
	else{
		printf("Drying in day %d",n);
	}
	return 0;
}
