#include <stdio.h>

int main(){
	int N;
	int a[4],b[4],c[4];
	int n,j,k,l,m,i,o,p,q,r,num,g,f,position,answer,num_1=0,position_1=0;
	while(scanf("%d",&N)!=EOF){
		if(N==0)break;
		int count=0;
		while(scanf("%d%d%d",&n,&num,&position)!=EOF){
			count++;
			if(count==N)break;
			o=n/1000;
			p=(n/100)%10;
			q=(n/10)%10;
			r=n%10;
			a[0]=o;
			a[1]=p;
			a[2]=q;
			a[3]=r;
			c[0]=o;
			c[1]=p;
			c[2]=q;
			c[3]=r;
			for(i=1000;i<=9999;i++){
			j=i/1000;
			k=(i/100)%10;
			l=(i/10)%10;
			m=i%10;
			b[0]=j;
			b[1]=k;
			b[2]=l;
			b[3]=m;	
				for(g=0;g<4;g++){
					for(f=0;f<4;f++){
						if(b[f]==c[g]){
							num_1++;
						}
					}
				}
				for(g=0;g<4;g++){
					if(a[g]==b[g]){
						position_1++;
					}
				}
				if(num_1==num||position_1==position){
					answer=i;
					break;
				}
				position_1=0;
				num_1=0;	
			}
		}
		printf("%d\n",answer);	
	}
	return 0;
}
