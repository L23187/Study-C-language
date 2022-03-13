#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main()
{
    double temp = 1.0;
    char num[52];
    gets_s(num);
    int i, count = 0;
    for (i = 0; i < strlen(num); i++)
    {
        if (num[i] == '2')
            count++;
    }
    int x = strlen(num);
    if (num[0] == '-')
    {
        x = x - 1;
        temp *= 1.5;
    }
    if (num[x] % 2 == 0)
        temp *= 2.0;
    temp = 100 * temp * count / x;
    printf("%.2lf\%%\n", temp);
    return 0;
}
