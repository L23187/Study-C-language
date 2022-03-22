#include <stdio.h>
int main(){
	int n,account,i;
	double s=0.0,price;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%lf%d",&price,&account);
		 s=s+(price*account);
	}
	if(s>=2000){
		s=s*0.8;
	}
	else if(s>=1000&&s<2000){
		s=s*0.9;
	}else{
		s=s;
	}
	printf("%.2f",s);
	return 0; 
}
