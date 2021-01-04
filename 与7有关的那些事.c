# include<stdio.h>
int main()
{
	int a,b,c[1000],d,e,flag=0,m,n=1,s,q;
	scanf("%d",&a);
	while(n<=a)  //用来判断输入的个数
	{
			scanf("%d",&m);
			for(b=7;b<=m;b++) //判断7和7的倍数，还有包含7的数字
		 {
		 	flag=0;
			if(b%7==0)//判断是否为7的倍数
			{
				flag=1;
			}
			else if(b>10)//判断是否为包含7的数字
			{     s=b;
				for(e=0;d<1000,s>0;e++)
				{
					c[e]=s%10;
					s/=10;
				}
				for(q=0;q<e;q++)//最后一位在数组中为0要舍去
				{
					if((c[q]%7==0)&&(c[q]!=0))
					{
						flag=1;
						break;
					}
				}
			}
				if(flag)
				{
					printf("%d ",b);
				}
		}
		printf("\n");
		n++;
	}
	return 0;
}

