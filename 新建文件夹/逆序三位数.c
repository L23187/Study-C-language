#include <stdio.h>
int main(){
	int m,a,b,c;//������������� m	�����λ����a��ʮλ����b����λ����c 
	scanf("%d",&m);
	a=m/100;
	b=(m%100)
	/10;
	c=(m%100)%10;
	if(m%100==0){//������Ϊ������ʱ���磬100,200�� 
		printf("%d",a);
	}
	else if(c==0){//�����������λΪ0ʱ 
		printf("%d%d",b,a);
	}
	else{
		printf("%d%d%d",c,b,a);
	}
	return 0; 
}
/*����Ϊ���Ϸ��ָ��õ�д�� 
#include <stdio.h>
int main(void) {
         int n;
         int a, b, c;
         scanf("%d",&n);
         a= n % 10;               //��λ 
         b= (n / 10) % 10;       //ʮλ 
         c= n / 100;            //��λ 
         n= a * 100 + b * 10 + c;
         printf("%d\n",n);  
         return 0;
}*/
