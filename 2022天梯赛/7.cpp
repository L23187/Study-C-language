#include<stdio.h>
int main(void){
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	int t,c = 0,x = n*m,a[2] = {0},b[100001] = {0},o[100001] = {0};
	for(int i = 0;i<q;i++){
		scanf("%d%d",&t,&c);
		if(t==0){
			b[c]++;
			if(b[c]<=1){
				a[t]++;
			}
			
		}else if(t==1){
			o[c]++;
			if(o[c]<=1){
				a[t]++;
			}
		}
	}
	x -= m*a[0]+n*a[1];
	x += a[0]*a[1];
	printf("%d",x);
	return 0;
}
