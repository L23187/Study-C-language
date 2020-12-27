#include <stdio.h>
int main()
{
	double a,b,x;
	scanf("%d %d",&a,&b);
	if(a>b){
		if(a>=b+0.1*b&&a<b+0.5*b){
			x=(a-b)/b; 
			printf("Exceed %.0f%%. Ticket 200",x*100);
		}else if(a>=b+0.5*b){
			x=(a-b)/b;
			printf("Exceed %.0f%%. License Revoked",x*100);
		}else{
			printf("OK");
		}
		
	}
	return 0;
}

