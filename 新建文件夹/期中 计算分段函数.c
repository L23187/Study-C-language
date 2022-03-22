#include <stdio.h>
int main(){
	int x,b,i;
	scanf("%d",&x);
	if(x>3){
		b=5*x-1;
	}if(x>-2&&x<=3){
		b=1-3*x;
	}if(x<=-2){
		b=-1*x*x;
	}
	printf("%d",b);
	return 0;
} 
