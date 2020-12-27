#include<stdio.h>
 
int main()
{
	int num,n;
	int inp;
	int finished=0;
	int cnt=0;
	scanf("%d %d",&num,&n);
	do{
		scanf("%d",&inp);
		cnt++;
		if(inp<0){
			printf("Game Over\n");
			finished=1;
		}else if(inp>num){
			printf("Too big\n");
		}else if(inp<num){
			printf("Too small\n");
		}else{
			if(cnt==1){
			printf("Bingo!\n");
			}
		else if(cnt<=3){
			printf("Lucky You!\n");
		}else{
			printf("Good Guess!\n");
		}
		finished=1;
	}
	if(cnt==n){
		if(!finished){
			printf("Game Over\n");
			finished=1;
		}
	}
}
	while(finished);
	return 0;
}

