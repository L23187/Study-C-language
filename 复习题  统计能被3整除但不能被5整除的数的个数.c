#include <stdio.h>
int main(){
	int n,m,i,a=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&m);
		if(m%3==0&&m%5!=0){
			a++;
		}
	}
	printf("%d\n",a);
	return 0;
}
