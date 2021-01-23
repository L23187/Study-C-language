#include <stdio.h>
int main(){
	int n,i,item=1;//定义一个整数n	每项的项数item 
	int sum=0;	//总和sum 
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		item*=i;
		sum=sum+item;
	}
	printf("%d",sum);
	return 0;
} 
