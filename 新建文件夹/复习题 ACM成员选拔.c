#include <stdio.h>
int main(){
	int n,i,g;
	double sum=0.0,average;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&g);
		sum+=g;
	}
	average=sum/n;
	printf("%.1f",average);
	return 0;
}
