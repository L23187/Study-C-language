#include <stdio.h>
#include <math.h>
int main(){
	int a,n,i,sum=0.0,m;
	scanf("%d %d",&a,&n);
	m=a;
	for(i=1; i<=n; i++){
		sum=sum+a;
		a=a+m*pow(10,i);
	}
	printf("s = %d",sum);
	return 0;
}
