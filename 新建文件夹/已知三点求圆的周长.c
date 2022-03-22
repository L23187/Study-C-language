#include <stdio.h>
#include <math.h>
#define pi 3.141592653589793
int main()
{
    double x1,y1,x2,y2,x3,y3;
    double a,b,c;
    double cos,sin,d;
    while(scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3)!=EOF)
    {
        a=sqrt(pow(x1-x2,2)+pow(y1-y2,2));
        b=sqrt(pow(x1-x3,2)+pow(y1-y3,2));
        c=sqrt(pow(x2-x3,2)+pow(y2-y3,2));
        cos=(b*b+c*c-a*a)/(2*b*c);
        sin=sqrt(1-cos*cos);
        d=a/sin;
        printf("%.2f\n",pi*d);
    }
    return 0;
}

