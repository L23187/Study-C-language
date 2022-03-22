#include<stdio.h>

int main()
{
	int N,U,D;//定义井的深度n，一分钟向上爬u寸 ，一分钟下落d寸 
	int T = 0;
	
	scanf("%d %d %d",&N,&U,&D);
	
	while(N>0)
	{
		if(N>U)//当井深大于上升距离时以两分钟总共的上升的距离代替 
		{
			T += 2;
		}
		else//当井深小于上升高度时，以1分钟代表时间 
		{
			T += 1;
		}
		
		if(N<=U)
		{
			N = N -U;
		}
		else
		{
			N = N - U + D;
		}
	}
	
	printf("%d",T); 
	
	return 0;
}

