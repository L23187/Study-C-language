#include <stdio.h>
int main()
{
    int n;
    int num;
    int a;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&num);
        if(0==i) a=num;
        else a=(a>num? num : a);
    }
    printf("min = %d\n",a);
    return 0;
} 
