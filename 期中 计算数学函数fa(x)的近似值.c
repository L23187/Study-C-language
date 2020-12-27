 #include <stdio.h>

double  fa(double x,  int n, double eps);

int main() {
  int n;
  double x, eps, result;
  scanf("%lf%d%lf", &x, &n, &eps);
  result = fa(x, n, eps);
  printf("%.4lf\n", result);
  return 0;
}
 
double  fa(double x,  int n, double eps){
		int i;
		double a=1.0,b=1.0,sum=1.0,c;
		for(i=1;i<=n;i++){
			a*=x;
			b*=i;
			a=-a;
			c=a/b;
			sum=sum+c;
			if(c<=0){
			c=-c;
            }	
			 if(c<eps){
				break;
			} 
	}
	return sum;
}
