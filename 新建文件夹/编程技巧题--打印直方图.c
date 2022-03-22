#include <stdio.h>
int main(){
	int n,w;
	double result[100]={0.0};//用于存放每组的计算结果
 	int group=0;//统计输入组数
 	int i,j;
	while(scanf("%d%d",&n,&w)!=EOF){//题目要求输入
		if(n==0&&w==0)break;
 		double num[100]={0};//存放输入的数字
 		int max=0;//记录输入数字中的最大值
 		for(i=0;i<n;i++){
 			scanf("%d",&num[i]);
 			if(num[i]>max||num[i]==max){
 				max=num[i];
			}
		}
		double space[100]={0.0};//记录每个区间内的数字数量
		int step=0,space_count=0;//step用来标记当前区间、space_count用于统计区间总数
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
		double max_space=0;//记录数字最多的区间
		for(i=0;i<space_count;i++){
		 	if(space[i]>max_space||space[i]==max_space){
		 		max_space=space[i];
			}
		}
		double ink=0.0;
 		for(i=0, j = space_count-1;i<space_count;i++, j--){//计算耗墨量
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
