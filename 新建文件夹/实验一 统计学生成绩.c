#include <stdio.h>
int main(){
	int a,b,c,n,i,e=0,f=0,g=0,h=0,j=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a);
		if(a>=90&&a<=100){
			e++;
		}
		if(a<90&&a>=80){
			f++;
		}
		if(a<80&&a>=70){
			g++;
		}
		if(a<70&&a>=60){
			h++;
		}
		if(a<60){
			j++;
		}
	}
	printf("%d %d %d %d %d",e,f,g,h,j);
	return 0;
}
