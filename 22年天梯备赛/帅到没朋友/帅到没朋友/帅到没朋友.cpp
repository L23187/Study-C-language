#define _CRT_SECURE_NO_WARNINGS 1
//����дVS����ͨ��������PTA��ͨ��    ��������Ϊռ���ڴ�̫�����������Խ��
#include<stdio.h>
int main()
{
    int n, m, j = 0;
    scanf("%d", &n);//��������Ȧ����
    int a[1000000] = { 0 }, i, k;

    for (i = 0; i < n; i++)
    {
        scanf("%d", &m);//��������Ȧ����
        for (j = 0; j < m; j++)
        {
            scanf("%d", &k);//������Ȧ�е�ID�������ȥ
            a[k]++;
            if (m == 1 && a[k] == 1) {//��Щֻ���Լ�һ����������Ȧ����
                a[k] = 0;
            }
        }

    }
    int x, b[100000];
    scanf("%d", &x);//�������ѯ������

    j = 0;
    for (i = 0; i < x; i++)
    {
        scanf("%d", &k);//�������ѯ��ID����
        if (a[k] == 0)
        {
            b[j++] = k;//�����������Ĵ�������
            a[k] = -1;//��ֹ������ѯ
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
            printf("%05d ", b[i]);//��0����
        }
        printf("%05d\n", b[j - 1]);//����β�������������û�пո�
    }
    return 0;
}
                        