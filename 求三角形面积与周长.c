#include <stdio.h>
#include <math.h>
int main(){
	double a,b,c;//���������������߳� 
	double area,perimeter,s;//����������ܳ��Լ��м����s 
	scanf("%lf%lf%lf",&a,&b,&c);//���������� 
	s=(a+b+c)/2.0;
	if(a+b>c&&a+c>b&&b+c>a){//�ж��ǲ��������� 
		perimeter=a+b+c;//���ܳ� 
		area=sqrt(s*(s-a)*(s-b)*(s-c));//����� 
		printf("area = %.2f; perimeter = %.2f\n",area,perimeter);
	}else{
		printf("These sides do not correspond to a valid triangle");
	}
	return 0;
} 
