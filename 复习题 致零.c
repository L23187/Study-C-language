#define
#include <stdio.h>
int main(){
	int n,i,m=0;
	scanf("%d",&n);
	for(i=1;i<=9999999;i++){
		if(n%2!=0){
			n=n-1;
		}
		else{
			n=n/2;
		}
		m++;
		if(n==0)break;
	}
	printf("%d",m);
	return 0;
}
