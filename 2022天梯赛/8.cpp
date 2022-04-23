#include<stdio.h>
int main(void){
	int n,k,s;
	scanf("%d%d%d",&n,&k,&s);
	int t[10001] = {0},p[10001] = {0},x = 0,tt,pat;
	for(int i = 0;i<n;i++){
		scanf("%d%d",&tt,&pat);
		if(tt>=175){
			t[tt]++;
			if(pat>=s){
				x++;
			}
			if(t[tt]<=1){
				x++;
			}
		}
	}
	printf("%d",x+1);
	return 0;
}
