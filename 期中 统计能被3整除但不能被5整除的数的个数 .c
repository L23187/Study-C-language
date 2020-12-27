#include <stdio.h> 
int main(){
	int i,n,a,j=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a);
		if(a%3==0&&a%5!=0){
			j++;
		}
	}
	printf("%d",j);
	return 0;
} 
