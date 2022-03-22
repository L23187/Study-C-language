#include <stdio.h>
#include <math.h>
int  main(){
	int i=1,flag=1;//定义符号和分母 
	double eps,item=1.0,sum=0.0;//定义精度项数和总和 
	scanf("%lf",&eps);//输入精度 
	if(eps>=1) //当精度大于1时 
      	printf("sum = %.6f",item);
      else{
		while(fabs(item)>eps){//项数大于精度时停止 
		item=flag*1.0/i;
        sum=sum+item;
        i+=3;
        flag=-flag;//保证项数一正一负 
		}
	printf("sum = %.6f",sum);
	}
	return 0;
} 
