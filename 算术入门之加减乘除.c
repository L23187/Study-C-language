#include <stdio.h>
int main(){
	int m,n;//������������ 
	double c;//�����������֮��Ĳ�Ϊ�������� 
	scanf("%d%d",&m,&n);
	printf("%d + %d = %d\n",m,n,m+n);
	printf("%d - %d = %d\n",m,n,m-n);
	printf("%d * %d = %d\n",m,n,m*n);
	if(m%n==0){//���������֮����Ϊ����ʱ 
		printf("%d / %d = %d\n",m,n,m/n);
	}else{
		c=(double)m/n;//ǿ��ת��Ϊ������ 
		printf("%d / %d = %.2f\n",m,n,c);
	}
	return 0;
} 
