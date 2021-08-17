#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct scare{
    int x, y;//x, y分别是稻草人的横纵坐标 
    int r;//r是稻草人所能守护的哈密尔顿距离 
    int num;//num是稻草人守护范围内未被守护的点的个数 
};//设置结构体用来存放与是稻草人相关的量 

int main()
{
    int n;//n是农田的大小 
    while(scanf("%d", &n) != EOF && n!=0)
    {
        int k, f=0, a[n][n];//k是可以放稻草人的十字路口的个数；f记录农田中是否存在未被守护的点，用来控制输出；a[n][n]数组做地图，用以模拟农田 
        int i, j, c, d;//控制循环的变量 
        scanf("%d", &k);
        int count=0;//记录放置稻草人的个数 
        memset(a, 0, sizeof(a));//将a[n][n]数组集体置0（规定未被守护的点的位置为0，已被守护的点的位置为1） 
        struct scare s[k];//实例化结构体数组，按顺序存入稻草人数据 
        for(i=0;i<k;i++)//输入十字路口位置 
            scanf("%d%d", &s[i].x, &s[i].y);
        for(i=0;i<k;i++)//输入该路口下的稻草人能守护的曼哈顿距离 
            scanf("%d", &s[i].r);
        for(i=0;i<k;i++)//循环，k个位置全被插满稻草人为止 
        {
            int max=0, t=-1;//max为最多未被守护的点的个数，t是该稻草人的记号 
            for(j=0;j<k;j++)//循环，找到当前地图条件下能覆盖最多未被守护的点的稻草人 
            {
                s[j].num=0;//初始化num 
                for(c=0;c<n;c++)
                    for(d=0;d<n;d++)
                        if((abs(c-s[j].x+1)+abs(d-s[j].y+1))<=s[j].r && a[c][d]==0)
                            s[j].num++;
                if(s[j].num >= max)
                    max=s[j].num, t=j;
            }
            for(c=0;c<n;c++)//更新地图，将稻草人插下，未被守护的点变为已被守护的 
                for(d=0;d<n;d++)
                    if((abs(c-s[t].x+1)+abs(d-s[t].y+1))<=s[t].r && a[c][d]==0)
                        a[c][d] = 1;
            count++;//记录插下稻草人的数量 
            s[t].r = -1;//将插下的稻草人半径改为-1（不可能存在），避免参与下一次运算影响结果 
            for(c=0;c<n;c++)//查找是否还有未被覆盖的点 
                for(d=0;d<n;d++)
                    if(a[c][d] == 0)
                        goto con;//如果有则跳转至con标记的语句处运行 
            f = 1;
            break;//点全被覆盖，f为1，跳出循环 
            con: f = 0;//con标记的语句：有未被覆盖的点，f为0，继续循环；若稻草人插完同样结束循环，此时f为0 
        }
        (f==0) ? printf("-1\n") : printf("%d\n", count);//f为0输出-1，f不为0输出已插稻草人的个数 
    }
    return 0;
}
