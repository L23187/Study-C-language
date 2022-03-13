#define _CRT_SECURE_NO_WARNINGS 1
//这样写VS不会通过，但是PTA会通过    可能是因为占用内存太大或者是数组越界
#include<stdio.h>
int main()
{
    int n, m, j = 0;
    scanf("%d", &n);//输入朋友圈个数
    int a[1000000] = { 0 }, i, k;

    for (i = 0; i < n; i++)
    {
        scanf("%d", &m);//输入朋友圈人数
        for (j = 0; j < m; j++)
        {
            scanf("%d", &k);//将朋友圈中的ID号输入进去
            a[k]++;
            if (m == 1 && a[k] == 1) {//那些只有自己一个人在朋友圈的人
                a[k] = 0;
            }
        }

    }
    int x, b[100000];
    scanf("%d", &x);//输入待查询的人数

    j = 0;
    for (i = 0; i < x; i++)
    {
        scanf("%d", &k);//输入待查询的ID号码
        if (a[k] == 0)
        {
            b[j++] = k;//将符合条件的储存起来
            a[k] = -1;//防止反复查询
        }
    }
    if (j == 0)
    {
        printf("No one is handsome\n");
        return 0;
    }
    else
    {
        for (i = 0; i < j - 1; i++)
        {
            printf("%05d ", b[i]);//将0补齐
        }
        printf("%05d\n", b[j - 1]);//将行尾的数单独输出，没有空格
    }
    return 0;
}
                        