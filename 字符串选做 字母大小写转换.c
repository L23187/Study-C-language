#include <stdio.h>
int main(){
	int i=0;
	char a[30];
	while((a[i]=getchar())!='#'){
		i++;
	}
	a[i]='\0';
	for(i=0;a[i]!='\0';i++){
		if(a[i]>='A'&&a[i]<='Z'){
			a[i]=a[i]+32;
		}else if(a[i]>='a'&&a[i]<='z'){
			a[i]=a[i]-32;
		}
	}
	for(i=0;a[i]!='\0';i++){
		printf("%c",a[i]);
	}
	return 0;
}
