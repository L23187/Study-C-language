#include <stdio.h>

int main(void) { 
	int lower,upper,i;
	double celsius;
	scanf("%d%d",&lower,&upper);
	if(lower>upper){
	    printf("Invalid.\n");
	}
	else{  
		printf("fahr celsius\n");
	    for(i=lower;i<=upper;i+=2){
	        celsius=5.0*(i-32.0)/9.0;
	        printf("%d%6.1f\n",i,celsius);
	    }
    }
	return 0;
}
