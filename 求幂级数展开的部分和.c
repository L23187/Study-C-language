#include <stdio.h>
#include <math.h>
int main(){
	double m,i,sum=1.0,a,b=1.0,k;
	scanf("%lf",&m);
	for(i=1;i<1000;i++){
		a=pow(m,i);
		b*=i;
		k=a/b;
		sum=sum+k;	
		if(k<0.00001){
			break;
		}	 
	}
	printf("%.4f",sum);
	return 0;
}
