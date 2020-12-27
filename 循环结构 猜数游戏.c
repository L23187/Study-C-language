#include <stdio.h>
int main(){
	int x,guess,i,n;
	scanf("%d %d",&x,&n);
	for(i=1; i<=n; i++){
	scanf("%d",&guess);
	if(guess==x&&i==1){
		printf("Bingo!\n");break;
	}
	if(guess==x&&i<3&&i!=1){
		printf("Lucky You!\n");break;
	}
	if(guess==x&&i>=3&&i<=n) {
		printf("Good Guess!\n");break;
	}
	if(guess<x&&guess>0){
		printf("Too Small\n");
	}
	if(guess>x&&guess>0){
		printf("Too Big\n");
	}
	if(i==n&&guess!=x){
		printf("Game Over!\n");break;
	}
	if(guess<0){
		printf("Game Over!\n");break;
	}
	}
	return 0;
}
