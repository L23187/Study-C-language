#include <stdio.h>
int main(){
	int n,x=0,b=0;				//定义步数 
	double d,sum=0.0,i,a[100];	//定义米数 ，定义数组用于储存数据 
	while(scanf("%lf",&d)!=EOF){
		if(d==0.00)break;		//d=0时输入结束 
		a[x]=d;					//将输入的数字储存在数组中 
		x++;
		b=x;
	}
	for(x=0;x<b;x++){
		for(n=1;n<500;n++){
			i=1.0/(n+1.0);
			sum=sum+i;
			if(sum>a[x]){
				sum=0.0;
				break;	
			}
		}
		printf("%d step(s)\n",n); 
	}
	return 0;
}

