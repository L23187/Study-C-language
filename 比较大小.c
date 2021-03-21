#include<stdio.h>
int main(void)
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int min;
    if(a>b)//若a>b则先将a赋予最小值，b再赋予a，再将最小值赋予b以下同理 
    {
        min=a;
        a=b;
        b=min;
    }
    if(a>c)
    {
        min=a;
        a=c;
        c=min;
    }
    if(b>c)
    {
        min=b;
        b=c;
        c=min;
    }
    printf("%d->%d->%d",a,b,c);
} 
