#include <stdio.h>
int main(){
	int i,m,sum=0;
	double average,n;
	scanf("%lf",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&m);
		sum=sum+m;
	}
	average=sum/n;
	printf("%.2f",average);
	return 0;
} 
