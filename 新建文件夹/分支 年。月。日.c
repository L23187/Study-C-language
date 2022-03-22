
#include <stdio.h>
int main(){
	int x,y,z,d,g,l,i;
	scanf("%d/%d/%d",&x,&y,&z);
	l=0;
	for(i=1;i<y;i++){
	
	switch(i){
		case 1: g=31;break; 
		case 3: g=31;break;
		case 5: g=31;break;
		case 7: g=31;break;
		case 8: g=31;break;
		case 10: g=31;break;
		case 12: g=31;break;
		case 2: g=28;break;
		default: g=30;break; 
	}
	if(x%4==0&&x%100!=0||x%400==0){
		g=g+1;
		l=g+l-1;
	}else{
		l=g+l;
}








	
}
	d=z+l;
	
	if((x%4==0&&x%100!=0)||(x%400==0&&y>2)){//确保是闰年时有366天 且在2月前是正确天数。 
		printf("%d",d+1);
	}else{
		printf("%d",d);
	}
	 
	return 0;
}

