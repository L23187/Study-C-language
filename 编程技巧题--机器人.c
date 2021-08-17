#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void){
	int r,c,s,k,group=0;
	int step1[100]={0},step2[100]={0};
	while(scanf("%d%d%d",&r,&c,&s)!=EOF){
		if(r==0&&c==0&&s==0)break;
		char a[10][10]={'\0'};
		int i,j;
		for(i=0;i<r;i++){
			for(j=0;j<c;j++){
				scanf("%c",&a[i][j]);
			}
		}
		int b[10][10];
		int m=0,n=s-1,count=0,count_1=0;
		while(1){
			switch(b[m][n]){
				case 'W':
					b[m][n]=1;
					n=n-1;
					break;
				case 'E':
					b[m][n]=1;
					n=n+1;
					break;
				case 'N':
					b[m][n]=1;
					m=m-1;
					break;
				case 'S':
					b[m][n]=1;
					m=m+1;
					break;
			}
			if(b[m][n]==1){
				int b_1[10][10]={0};
				while(1){
					switch(b[m][n]){
						case 'W':
							b_1[m][n]=1;
							n=n-1;
							break;
						case 'E':
							b_1[m][n]=1;
							n=n+1;
							break;
						case 'N':
							b_1[m][n]=1;
							m=m-1;
							break;
						case 'S':
						b_1[m][n]=1;
						m=m+1;
						break;	
					}
					if(b_1[m][n]==1){
						count_1++;
						break;
					}
					count_1++;
				}
				count=count-count_1+1;
				break;
			}
			if(m==-1||n==-1||m==r||n==c){
				count++;
				break;
			}
			count++;
		}
		step1[group]=count;
		step2[group]=count_1;
		group++;
	}
	for(k=0;k<group;k++){
		if(step2[k]==0){
			printf("%d step(s) to exit\n",step1[k]);
		}
		else{
			printf("%d step(s) before a loop of %d step(s)\n",step1[k],step2[k]);
		}
	}
	return 0;
}
