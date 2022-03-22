#include<stdio.h>
int main()
{
	int n;
	char s[100];
	int a[16];
	while(scanf("%d",&n)!=-1)
	{
		int i,j,k,m,flag;
		for(i=2;i<=16;i++)
		{
			m=n;k=0;flag=0;
			while(m)
			{
				if(m%i>=0&&m%i<=9)
					s[k++]=m%i+'0';
				else
					s[k++]=m%i-10+'A';
				m=m/i;
			}
			for(j=0;j<k;j++)
				if(s[j]!=s[--k])
					flag=1;
			if(flag==0)
				break;
		}
		if(flag==0)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
/*对于十进制转2-16进制，我们只需要用辗转相除法取余数
然后将余数转化为字符存储在字符数组中；
最后通过遍历字符数组判断是否存在回文数即可*/
