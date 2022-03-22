#include <stdio.h>
int main(){
	int i,m=1000000000;
	for(i=1;i<m;i++){
		if(i%5==1&&i%6==5&&i%7==4&&i%11==10){
			break;
		}
	}
	printf("%d",i);
	return 0;
}
