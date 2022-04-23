#include<stdio.h>
int main(void){
	int ban,ac,age1,age2;
	scanf("%d%d%d%d",&ban,&ac,&age1,&age2);
	if(age1<ban&&age2>=ac||age2<ban&&age1>=ac){
		printf("%d-Y %d-Y\n",age1,age2);
		if(age1>age2){
			printf("qing 1 zhao gu hao 2");
		}else{
			printf("qing 2 zhao gu hao 1");
		}
	}else if(age1>ban&&age2>ban){
		printf("%d-Y %d-Y\n",age1,age2);
		printf("huan ying ru guan");
	}else if(age1<ban&&age2<ban){
		printf("%d-N %d-N\n",age1,age2);
		printf("zhang da zai lai ba");
	}else if(age1 > ban && age2 < ban && age1<ac&&age2<ac|| age1 < ban && age2 > ban&&age1<ac&&age2<ac){
		if(age1 > ban){
			printf("%d-Y %d-N\n",age1,age2);
			printf("1: huan ying ru guan");
		}
		if(age2 > ban){
			printf("%d-N %d-Y\n",age1,age2);
			printf("2: huan ying ru guan");
		}
	}
	return 0;
}
