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
            if (a[i] == ' ')   //�����пո���Ϊһ�� 
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

        for (i = 0; i < c; i++)   //strstr���ص��ǵ�ַ�� 
        {
            if (i == 0 && b[i] == ' ') continue;
            if ((i == 0 || judge(i - 1)) && strstr(b + i, "could you") == &b[i] && (i + 9 == c || judge(i + 9))) //iʹ��������Ƿ�����β���� 
            {                                                                                    //judge����Ƿ��ھ��ж��� 
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
                if (i == c - 1)  continue;  //��β�ո� 
                if (!judge(i + 1))//����ո��һ�������ֻ�����ĸ ֱ�ӹ��˵���� 
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