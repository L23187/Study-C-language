#include<stdio.h>
int main(){
	int a[3] = {1,2,3};
	int numsSize = 3;
	int i;
	for(i = 0;i<numsSize;i++){
		if(i = numsSize-1){
			a[numsSize-1] = a[numsSize-1] + 1;
		}
	}
	for(i = 0;i<3;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
