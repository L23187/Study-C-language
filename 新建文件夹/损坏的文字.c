 #include <stdio.h>
int a[10001][101],b[10001];
int main()
{
    int i,j,k,l,m,n,t;
    while(scanf("%d%d%d",&n,&l,&m)!=EOF)
    {
        int count = 0;
        for( i=1;i<=n;i++)
            for(j=1;j<=l;j++)
            {
                scanf("%d",&a[i][j]);
                if(a[i][j]==0)
                    count++;
            }
            for(i=1;i<=n;i++)
                b[i]=0;
            k=1;
            for(i=2;i<=n;i++)
            {
                if(a[i][1]==0 && a[i][2]==0)
                {                           
                    for(j=l;j>=1;j--)    
                    {
                        if(a[i-1][j]==0)
                            b[k]++;  
                        else        
        break;    
                    }
                    k++;
                }
            }
            for(j=l;j>=1;j--)
            {
                if(a[n][j]==0)
                count--;
                else break;
            }
            k--;
            for(i=1;i<=k-1;i++)
            {
                for(j=i+1;j<=k;j++)
                {
                    if(b[i]<b[j])
                    {
                        t=b[i];
                        b[i]=b[j];
                        b[j]=t;
                    }
                }
            }
            for(i=1;i<=m-1;i++)
                count-=b[i];
            printf("%d\n",count-m*2);
    }
            return 0;
}
