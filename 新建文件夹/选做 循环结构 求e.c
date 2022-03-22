#include <stdio.h>
int main(){
	int i, n;
	double sum=1.0, k=1.0;
	scanf("%d",&n);
	for(i=1; i<=n; i++){
		k*=i;
		sum+=1/k;
	}
	printf("%.8lf",sum);
	return 0;
}
