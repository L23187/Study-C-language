#include<stdio.h>
int main(void)
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int min;
    if(a>b)//��a>b���Ƚ�a������Сֵ��b�ٸ���a���ٽ���Сֵ����b����ͬ�� 
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
