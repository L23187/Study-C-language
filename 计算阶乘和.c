#include <stdio.h>
int main(){
	int n,i,item=1;//����һ������n	ÿ�������item 
	int sum=0;	//�ܺ�sum 
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		item*=i;
		sum=sum+item;
	}
	printf("%d",sum);
	return 0;
} 
