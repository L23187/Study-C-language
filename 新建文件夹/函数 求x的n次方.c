#include <stdio.h> 
double mypow( double x, int n ){
	double H=1.0,i;
	for(i=1.0; i<=n; i++){
		H*=x;
	}
	return H;
}
