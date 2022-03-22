#include <stdio.h>
int main(){
	int i=0,cnt=0,j,flag=0;
	char a[81];
	char b[81];
	while((a[i]=getchar())!='\n'){
		b[i]=a[i];
		i++;
	}
	a[i]=0;
	for(i=0;a[i]!='\0';i++){
		flag=0;
		if(a[i]>='A'&&a[i]<='Z'){
			for(j=0;j<i;j++){
				if(b[i]==a[i]){
					flag=1;
				}
			}
			if(flag==0){
				printf("%c",a[i]);
				cnt++;
			}
		}
	}
	if(cnt==0){
		printf("Not Found");
	}
	return 0;
}
