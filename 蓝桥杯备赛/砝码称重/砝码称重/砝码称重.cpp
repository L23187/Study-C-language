#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
int sum;
int n;
int w[105];
int ans = 0;
int f[105][100005];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &w[i]);
        sum += w[i];
    }
    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= sum; j++)
            f[i][j] = f[i - 1][j] || f[i - 1][j + w[i]] || f[i - 1][abs(j - w[i])];
    //ֻҪ��һ���ǿ�,f[i][j]�ͷǿ�
    for (int i = 1; i <= sum; i++)
        if (f[n][i])
            ans++;
    //��Ϊ��˵������ѡ���������������
    cout << ans;
    return 0;
}