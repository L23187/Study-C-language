#include<stdio.h>
int main(void){
	int n,i,j;
	scanf("%d",&n);
	int num[n];
	int sum = 0, tem = 0;
	for(i = 0;i < n; i++){
		scanf("%d",&num[i]);
	}
	for(i = 0;i<n;i++){
		for(j = i+1;j<n;j++){
			tem = num[i]*num[j];
			sum += tem;
		}
	}
	printf("%d",sum);
	return 0;
}
