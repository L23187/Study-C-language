#include <stdio.h>
#include <math.h>
int main(){
	int x=1,i=1;
	double y,S=0,n=1.0;
	scanf("%lf",&y);
	if(y>=1){
	printf("sum = %.6f",n);
	}else{
	while(fabs(n)>y){
		n=x*1.0/i;
		S=S+n;
		i=i+3;
		x=-x;
	}

	printf("sum = %.6f",S);
}
	return 0;
}
