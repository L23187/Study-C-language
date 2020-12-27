#include <stdio.h>
int main(){
	int x,y,i;
	y=0;
while(scanf("%d",&x)){
	if(x<=0) break;
	else if(x%2!=0){
		y=y+x;
	}
}
	printf("%d",y);
	return 0;
}

