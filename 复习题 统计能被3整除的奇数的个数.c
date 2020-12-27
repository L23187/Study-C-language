#include <stdio.h>
int main(){
	int n,m,i,a=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
	 	scanf("%d",&m);
	 	if(m%2!=0&&m%3==0){
	 		a++;	
		}
	}
	printf("%d",a);
	return 0;
} 
