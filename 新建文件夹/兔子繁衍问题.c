#include <stdio.h>
int main(){
	int n,i,x=0;//�輸���º���n������ 
	int a[100]={1,1};//��x�º���n������
	scanf("%d",&n);
	for(i=0;i<10000;i++){
	 	if(i>=2){
	 		a[i+1]=a[i]+a[i-1];
	 		if(a[i+1]>n){
	 			break;
			 }
		 }
	}
	for(i=0;i<9;i++){
		printf("%d\n",a[i]);
	}
	return 0; 
} 
