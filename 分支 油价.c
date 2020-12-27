#include <stdio.h>
int main(){
	double a,b,k;
	char c; 
	scanf("%lf %lf %c",&a,&b,&c);
	
	if(b==90&&c=='m') {
		k=a*6.95*0.95;
		printf("%.2f",k);
	}
	if(b==90&&c=='e') {
		k=a*6.95*0.97;
		printf("%.2f",k);
	}
	if(b==93&&c=='m') {
		k=a*7.44*0.95;
		printf("%.2f",k);
	}
	if(b==93&&c=='e') {
		k=a*7.44*0.97;
		printf("%.2f",k);
	} 
	if(b==97&&c=='m') {
		k=a*7.93*0.95;
		printf("%.2f",k);
	}
	if(b==97&&c=='e') {
		k=a*7.93*0.97;
		printf("%.2f",k);
	}
	printf("%lf %lf %c",a,b,c); 
	return 0;
	
	 
}
