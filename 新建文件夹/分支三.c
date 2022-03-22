#include <stdio.h>
#include <math.h>
int main(void){
	double a,b,c,C,s,S,q;
	scanf("%lf %lf %lf",&a,&b,&c);
	C=a+b+c;
	s=(a+b+c)/2;
	q=s*(s-a)*(s-b)*(s-c);
	S=sqrt (q);
	if(a+b<=c||a+c<=b||b+c<=a)
	{
	printf("These sides do not correspond to a valid triangle\n");
	}
	else
	{
		printf("area = %.2f; perimeter = %.2f\n",S,C);
	}
	return 0;
}
