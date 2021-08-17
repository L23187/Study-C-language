#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main(){
	int N;
	int a[4],b[4],c[4];
	int n,i,j,k,l,m,o,p,q,r,num=0,g,f,position=0;
	while(scanf("%d",&N)!=EOF){
		if(N==0)break;
		srand((unsigned int)time(NULL));
		n=rand()%9000+1000;
		j=n/1000;
		k=n/100-10*j;
		l=n/10-100*j-10*k;
		m=n%1000%100%10;
		a[0]=j;
		a[1]=k;
		a[2]=l;
		a[3]=m;
		c[0]=j;
		c[1]=k;
		c[2]=l;
		c[3]=m;
		while(i!=n){
			scanf("%d",&i);//输入猜的数 
			o=i/1000;
			p=i/100-10*o;
			q=i/10-100*o-10*p;
			r=i%1000%100%10;
			b[0]=o;
			b[1]=p;
			b[2]=q;
			b[3]=r;
			for(g=0;g<4;g++){//猜中几个数字 
				for(f=0;f<4;f++){
					if(b[f]==c[g])
					num++;
				}
			}
			for(g=0;g<4;g++){//猜的数字位置对了几个 
				if(a[g]==b[g])
				position++;
			}
			printf("%d %d %d %d\n",n,i,num,position); 
			position=0;
			num=0;
		}	
	}
	return 0;
}
