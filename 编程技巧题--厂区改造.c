#include<stdio.h>
int main(){
	int t;
	int n,m,a[1000]={0};
	int i,j,k,result[100]={0};
	int count=0,area;
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%d%d",&n,&m);
		for(j=0;j<n;j++){
			scanf("%d",&a[j]);
		}
		int sum=0;
		for(j=0;j<n;j++){
			sum+=a[j];
		}
		if((sum%m)!=0){
			count=-1;
		}
		else{
			area=sum/m;
			while(n--){
				if(a[0]==0)break;
				else if(a[0]%area==0){
					count+=a[0]/area-1;
					for(k=0;k<n;k++){
						a[k]=a[k+1];
					}
				}
				else{
					a[1]+=a[0];
					count++;
					for(k=0;k<n;k++){
						a[k]=a[k+1];	
					}
				}
				n--;
			}
		}
		result[i]=count;
		printf("%d\n",result[i]);
	} 
	return 0; 
}
