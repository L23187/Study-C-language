#include <stdio.h>
int main(){
	int elc;//定义变量电量 
	double cost;//定义浮点变量电费 
	scanf("%d",&elc);//输入用户电量 
	if(elc<0){//当电量小于0时 
		printf("Invalid Value!");
	}else if(elc>0&&elc<=50){//当电量大于0小于50时 
		cost=elc*0.53;
		printf("cost = %.2f",cost);
	}
	else{//当电量大于50时 
		cost=(elc-50)*0.58+50*0.53;
		printf("cost = %.2f",cost);//电费保留两位小数 
	}
	return 0;
}
