#include <stdio.h>
int main(){
	int n,w;
	double result[100]={0.0};//���ڴ��ÿ��ļ�����
 	int group=0;//ͳ����������
 	int i,j;
	while(scanf("%d%d",&n,&w)!=EOF){//��ĿҪ������
		if(n==0&&w==0)break;
 		double num[100]={0};//������������
 		int max=0;//��¼���������е����ֵ
 		for(i=0;i<n;i++){
 			scanf("%d",&num[i]);
 			if(num[i]>max||num[i]==max){
 				max=num[i];
			}
		}
		double space[100]={0.0};//��¼ÿ�������ڵ���������
		int step=0,space_count=0;//step������ǵ�ǰ���䡢space_count����ͳ����������
		while(step<max||step==max){
		 	int count=0;
		 	for(i=0;i<n;i++){
		 		if(num[i]>step||num[i]==step&&num[i]<(step+w)){
		 			count++;
				}
			}
			space[space_count]=count;
			space_count++;
			step+=w;
		}
		double max_space=0;//��¼������������
		for(i=0;i<space_count;i++){
		 	if(space[i]>max_space||space[i]==max_space){
		 		max_space=space[i];
			}
		}
		double ink=0.0;
 		for(i=0, j = space_count-1;i<space_count;i++, j--){//�����ī��
 			ink+=(space[i]/max_space)*(1.0*j/(space_count-1));
		}
		ink+=0.01;
		result[group]=ink;
		group++;
		printf("%lf\n",ink);
	}
	for(i=0;i<group;i++){
		printf("%lf\n",result[i]);
	}
	return 0;
}
