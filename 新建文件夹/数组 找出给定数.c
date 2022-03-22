#include <stdio.h>
int main(){
	int X1,X2,i ;
	scanf("%d %d",&X1,&X2);
	int N[X1];
	for(i=0; i<X1; i++)
	{
		scanf("%d",&N[i]);
	 if(N[i]==X2){
	 	printf("%d",i);	break;
		}
}
 	if(N[i]!=X2){
			printf("Not Found");
		}	
	return 0;
}
