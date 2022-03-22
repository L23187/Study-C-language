#include <stdio.h>
int main(){
	double m,n;
	double x;
	scanf("%lf%lf",&m,&n);
	if(m<n+n*0.1){
		printf("OK");
	}
	else if(m>=n+n*0.1&&m<n+n*0.5){
		x=((m/n)-1.0)*100.0;
		printf("Exceed %.0f%%. Ticket 200\n",x);
	}else{
		x=((m/n)-1.0)*100.0;
		printf("Exceed %.0f%%. License Revoked\n",x);
	}
	return 0;
} 
