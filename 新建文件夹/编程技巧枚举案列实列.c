#include <stdio.h>
int main(){
	int a[5]={0};
	long int i,j,k,n=0,sum=0;
	for(i=10000;i<99999;i++){
		a[0]=i/10000%10;
		a[1]=i/1000%10;
		a[2]=i/100%10;
		a[3]=i/10%10;
		a[4]=i%10;
		for(j=0;j<5;j++){
			if(a[j]==7&&i%7!=0){
				sum=sum+i;
				n++;
				break;
			}else{
				continue;
			}
		}
	}
	printf("%d %d\n",n,sum); 
	return 0;
}
