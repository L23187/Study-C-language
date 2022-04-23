#include<stdio.h>
int main(void){
	int num[7];
	for(int i = 0;i<6;i++){
		scanf("%d",&num[i]);
	}
	int n;
	scanf("%d",&n);
	int s[7];
	for(int i = 0;i<6;i++){
		s[i] = num[i];
	}
	int x = 0;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<6;j++){
			s[j] = s[j]-x;
			if(s[j]<6-i-x&&s[j]!=6-i-x){
				s[j] = 6-i;
			}if(s[j]==num[j]){
				s[j] = s[j]-1;
			}
		}
		x = 1;
	}
	for(int i = 0;i<6;i++){
		if(i<5){
			printf("%d ",s[i]);
		}else{
			printf("%d",s[i]);
		}
	}
	return 0;
}
