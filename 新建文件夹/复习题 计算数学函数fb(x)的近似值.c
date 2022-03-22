#include <stdio.h>

double  fb(double x,  int n, double eps);

int main() {
  int n;
  double x, eps, result;
  scanf("%lf%d%lf", &x, &n, &eps);
  result = fb(x, n, eps);
  printf("%.4lf", result);
  return 0;
}

#include <math.h>
double  fb(double x, int n, double eps){
	int i;
	double sum=0.0,item,a=1.0,b=1.0;
	for(i=1;i<=(2*n)-1;i++){
		a=a*x;
		b=b*i;
		item=a/b;
		if(i%2!=0){
			sum=sum+item;
			a=-a;
			if(fabs(item)<eps)break;
		}
	}
	return sum;
	}

