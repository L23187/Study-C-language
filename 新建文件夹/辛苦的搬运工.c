#include <stdio.h>
#include <string.h>
#include <math.h>
int main(){
	int a[4],i;
	double d,time;
	char b[4];
	while(scanf("%s",&b[4])!=EOF){
		if(b[4]="end")break;
		for(i=0;i<4;i++){
			scanf("%d",&a[i]);
		}	
		d=sqrt(pow(a[2]-a[0],2)+pow(a[3]-a[1],2));
		d=d/1000.0;
		time=d/20.0;
		printf("%.2lf",time);
	}
	return 0;
}
