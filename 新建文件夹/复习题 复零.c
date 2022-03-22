#include <stdio.h>
int main(){
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=999999;i++){
		if(n%3==0){
			n=n/3;
		}else{
			n=n-1;
		}
		if(n==0)break;
	}
	printf("%d",i);
	return 0;
}
