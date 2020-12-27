#include <stdio.h>
int main(){
	int  x,c;
	scanf("%d",&x);
	c=x/10;
	switch(c){
	
	case 10: printf("A") ;break;       
	case 9:	printf("A");break;
	case 8:	printf("B");break;
	case 7:	printf("C");break;
	case 6: printf("D");break;
	default :printf("E");
}
return 0;
}
