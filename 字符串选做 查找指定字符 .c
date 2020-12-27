#include <stdio.h>
int main(void){
	char a[81];
	char x;
	scanf("%c\n",&x);
	int i=0,flag=0,c;
	while(1){
		scanf("%c",&a[i]);
		if(a[i]=='\n')break;
		if(a[i]==x){
			flag=1;
			c=i;
		}
		i++;
	}
	if(!flag){
		printf("Not Found\n");
	}
	else{
		printf("index = %d",c);
	}
	
	return 0;
} 
