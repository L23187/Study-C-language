#include <stdio.h>
int main(){
	int m,i;
	scanf("%d",&m);
	int n[m];
	for(i=0; i<m; i++){
		scanf("%d",&n[i]);		
	}if(i=0){
	} 
	for(i=m-1; i>=0; i--){
		if(i==0)
		{
		printf("%d",n[0]);		
		} else{
		printf("%d ",n[i]);}
	}
	return 0;
}
