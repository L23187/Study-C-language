#include <stdio.h>
int main(){
	char a[81];
	int i=0,j,k;
	while((a[i]=getchar())!='\n'){
		i++;
	}
	a[i]='\0';
	for(j=i-1;j>=0;j--){
		printf("%c",a[j]);
	}
	return 0;
}
