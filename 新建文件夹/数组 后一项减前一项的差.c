#include <stdio.h>
int main(){
	int m,i,a,b=0;
	scanf("%d",&m);
	int n[m];
	for(i=0; i<m; i++){
		scanf("%d",&n[i]);
		}
		for(i=0; i<m-1; i++){
		b++;
		if(b%3==0||i+1==m-1){
			printf("%d\n",n[i+1]-n[i]);
		}else{
			printf("%d ",n[i+1]-n[i]);
		}		
	}
	
	return 0;
}
