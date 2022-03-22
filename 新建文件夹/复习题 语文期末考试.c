#include <stdio.h>
int main(){
	int i,grade;
	double sum=0.0,average,n;
	scanf("%lf",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&grade);
		sum=sum+grade;
	}
	average=sum/n;
	printf("%.1f",average);
	return 0;
}
