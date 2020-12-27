#include <stdio.h>

double  fd(double x,  int n, double eps);

int main() {
  int n;
  double x, eps, result;
  scanf("%lf%d%lf", &x, &n, &eps);
  result = fd(x, n, eps);
  printf("%.4lf", result);
  return 0;
}

double  fd(double x,  int n, double eps){
	int i;
	double sum=0.0,item,a=1.0,b=1.0;
	for(i=1;i<=n;i++){
		a=a*x;
		item=a/i;
		a=-a;
		sum=sum+item;
		if(item<0){
			item=-item;	
		}if(item<eps)break;
	} 
	return sum; 
}
