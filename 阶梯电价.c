#include <stdio.h>
int main(){
	int elc;//����������� 
	double cost;//���帡�������� 
	scanf("%d",&elc);//�����û����� 
	if(elc<0){//������С��0ʱ 
		printf("Invalid Value!");
	}else if(elc>0&&elc<=50){//����������0С��50ʱ 
		cost=elc*0.53;
		printf("cost = %.2f",cost);
	}
	else{//����������50ʱ 
		cost=(elc-50)*0.58+50*0.53;
		printf("cost = %.2f",cost);//��ѱ�����λС�� 
	}
	return 0;
}
