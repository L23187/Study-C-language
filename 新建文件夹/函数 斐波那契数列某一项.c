int fib(int n)
{
    int o=1,p=1,i=1;
    int s;
    if(n<=2)
        return 1;
    else
    for(i=1;i<=n-2;i++)
    {
        s=o+p;o=p;p=s;
    }
    return s;
}
#include <stdio.h>

int fib( int n );

int main()
{
    int n;

    scanf("%d", &n);
    printf("%d\n", fib(n));

    return 0;
}
