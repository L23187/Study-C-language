#include <stdio.h>
int main(){
	int n,m;//������������n		�Լ�����m 
	scanf("%d",&n);//��������n 
	m=n%5;//������������5������ 
	if(m>0&&m<=3){
		printf("Fishing in day %d",n);
	}
	else{
		printf("Drying in day %d",n);
	}
	return 0;
}
