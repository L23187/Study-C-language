#include<stdio.h>
int main(){
	char a[81];
	int i=0,cnt=0;
	while((a[i]=getchar())!='\n'){
		i++;
	}
	a[i]='\0';
	for(i=0;a[i]!='\0';i++){
		if(a[i]>='A'&&a[i]<='Z'&&a[i]!='A'&&a[i]!='E'&&a[i]!='I'&&a[i]!='O'&&a[i]!='U'){
			cnt++;
		}
	}
	printf("%d",cnt);
	return 0;
}
