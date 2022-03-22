#include <stdio.h>
#include <math.h>
int main(){
	int N,i,d,a,x;
	x=0;
	scanf("%d",&N);
	for (i=0;i<=9;i=i+1){
		a=pow(10,i);
		d=N/a;
		if(d<10)break;
	}
	while(N>0){
		x=x+N%10;
		N=N/10;
	}
	printf("%d %d",i+1,x);
	return 0;
}  
