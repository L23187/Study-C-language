#include <stdio.h>
int main(){
	double x,cost;
	scanf("%lf",&x) ;
	
	
	
	if (x<=50&&x>=0)
	{
		cost=0.53*x;
		printf("cost = %.2f\n",cost);
	
			
	}
	else if(x<0){
		
		printf("Invalid Value!");
	}
	else if(x>50)
	{
		cost=(x-50)*0.58+26.5;
		printf("cost = %.2f\n",cost);
}
	

	return 0;
}
