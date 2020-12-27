#include <stdio.h>
int main(){
	int n,i;
	double a,b,g1=0.0,g2,r,g;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%lf %lf",&a,&b);
		g1=g1+(a*b);
	}
	if(g1>=1000){
		r=0.1;
		g2=g1*r;
	}
	else if(g1>=800&&g1<1000){
		r=0.05;
		g2=g1*r;
	}
	else{
		r=0.0;
		g2=g1*r;
	}
	g=g1+g2;
	printf("%.3f",g);
	return 0;
}
