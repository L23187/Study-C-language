#include  <stdio.h>
int main(){
	int i,N;
	double s;
	s=0.0;
	scanf("%d",&N);
	for(i=1;i<=N;i=i+2){
		s=s+1.0/i;
	}
	printf("sum = %.6f",s) ;
	return 0;
}
