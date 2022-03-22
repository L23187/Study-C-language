#include <stdio.h>
#include <math.h>
int main(){
	double a,b,c;//定义三角形三条边长 
	double area,perimeter,s;//定义面积、周长以及中间变量s 
	scanf("%lf%lf%lf",&a,&b,&c);//输入三条边 
	s=(a+b+c)/2.0;
	if(a+b>c&&a+c>b&&b+c>a){//判断是不是三角形 
		perimeter=a+b+c;//求周长 
		area=sqrt(s*(s-a)*(s-b)*(s-c));//求面积 
		printf("area = %.2f; perimeter = %.2f\n",area,perimeter);
	}else{
		printf("These sides do not correspond to a valid triangle");
	}
	return 0;
} 
