# include<stdio.h>
int main()
{
	int a,b,c[1000],d,e,flag=0,m,n=1,s,q;
	scanf("%d",&a);
	while(n<=a)  //�����ж�����ĸ���
	{
			scanf("%d",&m);
			for(b=7;b<=m;b++) //�ж�7��7�ı��������а���7������
		 {
		 	flag=0;
			if(b%7==0)//�ж��Ƿ�Ϊ7�ı���
			{
				flag=1;
			}
			else if(b>10)//�ж��Ƿ�Ϊ����7������
			{     s=b;
				for(e=0;d<1000,s>0;e++)
				{
					c[e]=s%10;
					s/=10;
				}
				for(q=0;q<e;q++)//���һλ��������Ϊ0Ҫ��ȥ
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

