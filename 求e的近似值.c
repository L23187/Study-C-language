#include <stdio.h>
int main() {
	double m=1.0,item,sum=1.0;
	int i,n;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		m*=i;
		item=1.0/m;
		sum=sum+item;
	}
	printf("%.8f",sum);
	return 0; 
}
