#include<stdio.h>
int main(void){
	int a,b;
	scanf("%d%d",&a,&b);
	int x = 1,i;
	for(i = 1;i<=a+b;i++){
		x *= i;
	}
	printf("%d",x);
	return 0;
}
