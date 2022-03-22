#include <stdio.h>

double  fc(double x,  int n, double eps);

int main() {
  int n;
  double x, eps, result;
  scanf("%lf%d%lf", &x, &n, &eps);
  result = fc(x, n, eps);
  printf("%.4lf", result);
  return 0;
}

#include <math.h>
double  fc(double x,  int n, double eps){
	int i;
	double sum=0.0,item,a,b=1.0;
	if(eps>1)return 1;
	a=x;
	for(i=2;i<=(2*n)-2;i++){
		a=a*x;
		b=b*i;
		item=a/b;
		if(i%2==0){
			sum=sum+item;
			a=-a;
			if(fabs(item)<eps)break;
		}
	}
	sum=1-sum;
	return sum;
}
