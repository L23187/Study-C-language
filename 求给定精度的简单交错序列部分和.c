#include <stdio.h>
#include <math.h>
int  main(){
	int i=1,flag=1;//������źͷ�ĸ 
	double eps,item=1.0,sum=0.0;//���徫���������ܺ� 
	scanf("%lf",&eps);//���뾫�� 
	if(eps>=1) //�����ȴ���1ʱ 
      	printf("sum = %.6f",item);
      else{
		while(fabs(item)>eps){//�������ھ���ʱֹͣ 
		item=flag*1.0/i;
        sum=sum+item;
        i+=3;
        flag=-flag;//��֤����һ��һ�� 
		}
	printf("sum = %.6f",sum);
	}
	return 0;
} 
