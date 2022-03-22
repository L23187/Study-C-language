#include <stdio.h>
int main()
{
    int rand_number, n;//定义一个随机数和猜测最大次数 
    scanf("%d %d", &rand_number, &n);
    int i;
    int m;
    int flag = 0;
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &m);//输入用户猜测的数 
        if (m < 0)
            break;
        if (m > rand_number)
            printf("Too big\n");
        if (m < rand_number)
            printf("Too small\n");
        if (m == rand_number)//当猜对了 
        {
            if (i == 1)//当第一次猜对时  
            {
                flag = 1;
                printf("Bingo!\n");
                break;
            }
            if (i == 2 || i == 3)//当在三次内猜对时 
            {
                flag = 1;
                printf("Lucky You!\n");
                break;
            }
            if (i > 3)//当猜测次数大于三次时 
            {
                flag = 1;
                printf("Good Guess!\n");
                break;
            }
        }
    }
    if (flag == 0)//以flag作为标志去衡量程序是否结束 
        printf("Game Over\n");
    return 0;
}
