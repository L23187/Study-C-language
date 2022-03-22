#include <stdio.h>
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int num=0,a[5000][4]={0},i,j;
		int xmin,xmax,ymin,ymax;
		for(i=0;i<n;i++){
			for(j=0;j<4;j++){
				scanf("%d",&a[i][j]); 
			}
		}
		for(i=0;i<n;i++){
				if(a[i][0]<=a[i+1][0]&&a[i+1][0]<=a[i][1]){
						num++;
				}else if(i==n-1){
					if(a[0][0]<=a[i][0]&&a[i][0]<=a[0][1]){
						num++;
					}
				} 
		}
		printf("%d\n",num);
	}
	
	return 0;
}
/*有若干个矩形，它们的边平行于坐标轴，这里用矩形所覆盖区域的最小和最大坐标值来表示一个矩形，
如0，4，0，2表示矩形覆盖区域的坐标值在0<=x<=4,0<=y<=2范围内。
现在请你统计一下有多少矩形是被其他矩形完全覆盖的。*/
