#include <stdio.h>
#include <math.h>
int main() {
  int n,i;
  double x,eps,sum=0.0,item,a,b=1.0;
	scanf("%lf%d%lf", &x, &n, &eps);
	a=x;
	for(i=2;i<(2*n)-2;i++){
		a=a*x;
		b=b*i;
		item=a/b;
		if(i%2==0){
			sum=sum+item;
			a=-a;
			printf("%.4f\n",item);
			if(fabs(item)<eps)break;
		}
	}
	sum=1-sum;
	printf("%.4f\n",sum);
  return 0;
}
