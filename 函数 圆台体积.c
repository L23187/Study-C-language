#include <stdio.h>
#define PI 3.14159
double volume_tc(double r_lower, double r_upper, double h);

int main(void)
{
    double h, r_lower, r_upper, v;

    scanf("%lf%lf%lf", &r_lower, &r_upper, &h);
    v = volume_tc(r_lower, r_upper, h);
    printf("%.2f\n", v);

    return 0;
}
double volume_tc(double R, double r, double h){
	double T;
	T=1.0/3.0*3.14159*h*(R*R+r*r+R*r);/*定义为双精度浮点时需要将所有整数变为浮点数*/ 
	return T;
}
