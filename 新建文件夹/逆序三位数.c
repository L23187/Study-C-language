#include <stdio.h>
int main(){
	int m,a,b,c;//定义输入的数字 m	定义百位数字a，十位数字b，个位数字c 
	scanf("%d",&m);
	a=m/100;
	b=(m%100)
	/10;
	c=(m%100)%10;
	if(m%100==0){//当输入为整百数时，如，100,200等 
		printf("%d",a);
	}
	else if(c==0){//当输入的数个位为0时 
		printf("%d%d",b,a);
	}
	else{
		printf("%d%d%d",c,b,a);
	}
	return 0; 
}
/*以下为网上发现更好的写法 
#include <stdio.h>
int main(void) {
         int n;
         int a, b, c;
         scanf("%d",&n);
         a= n % 10;               //个位 
         b= (n / 10) % 10;       //十位 
         c= n / 100;            //百位 
         n= a * 100 + b * 10 + c;
         printf("%d\n",n);  
         return 0;
}*/
