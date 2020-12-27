#include <stdio.h> 
int main()
{
    int num, sum = 0;
    
    while(scanf("%d", &num) && num>0)
    {
        if(num%2 != 0)
        {
            sum += num;
        }
    }
    printf("%d", sum);
    
    return 0;
}
