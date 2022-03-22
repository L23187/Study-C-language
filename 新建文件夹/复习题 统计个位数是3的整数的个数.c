#include <stdio.h>
int main(){
	int n,m,i,a=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&m);
		if(m%10==3){
			a++;
		}
	}
	printf("%d",a);
	return 0;
}
