#include <stdio.h> 
int main()
{
	int i,j,t,n,k,o,a[10][10];
	scanf("%d",&t);
	for(k=0;k<t;k++){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				scanf("%d",&a[i][j]);
			}
		}
	}
	for(k=0;k<t;k++){
		if(i>j&&a[i][j]!=0){
				o=1;
			}
		else{
			o=0;
		}
	}
	for(k=0;k<t;k++){
		if(o==1){
			printf("YES\n");
		}	
		else{
			printf("NO\n");
		}
	}	
	return 0;
}
