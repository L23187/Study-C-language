#include <stdio.h>
int main(){
	char x,a[80];
	int i;
	scanf("%c",&x);
	scanf("%s",&a[80]);
	for(i=0;i<80;i++){
		if(a[i]==x){
			break;
		}
	}
	if(i==80){
		printf("Not Found\n");
	}else{
	printf("%d",i);
	}
	return 0;
}
