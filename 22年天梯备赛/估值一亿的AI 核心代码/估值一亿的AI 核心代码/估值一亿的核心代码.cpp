#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

char b[1005];
int judge(int x)
{
    return !((b[x] >= 'A' && b[x] <= 'Z') || (b[x] >= 'a' && b[x] <= 'z') || (b[x] >= '0' && b[x] <= '9'));
}


int main(void)
{
    int i, j;
    int n, c;
    char a[1005];

    scanf("%d", &n);
    getchar();

    while (n--)
    {
        gets_s(a);
        puts(a);
        printf("AI: ");
        c = i = 0;

        for (i = 0; a[i]; i++)
        {
            if (a[i] == ' ')   //把所有空格窦归为一个 
            {
                while (a[i] == ' ')
                {
                    i++;
                }
                b[c++] = ' ';
                i--;
            }
            else if (a[i] == '?')
            {
                b[c++] = '!';
            }
            else if (a[i] >= 'A' && a[i] <= 'Z' && a[i] != 'I')
            {
                b[c++] = a[i] + 32;
            }
            else
            {
                b[c++] = a[i];
            }
        }

        for (i = 0; i < c; i++)   //strstr返回的是地址！ 
        {
            if (i == 0 && b[i] == ' ') continue;
            if ((i == 0 || judge(i - 1)) && strstr(b + i, "could you") == &b[i] && (i + 9 == c || judge(i + 9))) //i使用来检查是否在首尾独立 
            {                                                                                    //judge检查是否在句中独立 
                printf("I could");
                i += 8;
            }
            else if ((i == 0 || judge(i - 1)) && strstr(b + i, "can you") == &b[i] && (i + 7 == c || judge(i + 7)))
            {
                printf("I can");
                i += 6;
            }
            else if ((i == 0 || judge(i - 1)) && b[i] == 'm' && b[i + 1] == 'e' && (i + 2 == c || judge(i + 2)))
            {
                printf("you");
                i++;
            }
            else if ((i == 0 || judge(i - 1)) && b[i] == 'I' && (i + 1 == c || judge(i + 1)))
            {
                printf("you");
            }
            else if (b[i] == ' ')
            {
                if (i == c - 1)  continue;  //结尾空格 
                if (!judge(i + 1))//如果空格后一个是数字或者字母 直接过滤掉标点 
                {
                    printf(" ");
                }
            }
            else
            {
                printf("%c", b[i]);
            }
        }
        printf("\n");
    }

    return 0;
}