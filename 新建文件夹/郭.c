// GreedySnake.cpp
include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <vector> using namespace std;
#define M 4 #define N 4
//定义数组元素结构体 struct stElement { int i; int j; int value; };
int apple[M][N] = { 7, -1, 4, 18, 4, 0, 1, 1, 15, 7, 11, 100, 0, 12, -2, 0};
vector<stElement> maxPath;
//当前最长路径(路径长度指的是路径上所有苹果的总个数） int maxLen = 0;
//最长路径长度 void Snake(vector<stElement> path, int pathLen, int i, int j) { if (apple[i][j] == -2)
//如果吃到终点的苹果 { if (pathLen > maxLen)
//求最大路径长度 { stElement e; e.i = i; e.j = j;
e.value = apple[i][j]; path.push_back(e);
maxPath = path; maxLen = pathLen;
} return; }
else { 
    if (i >= 0 && i < M && j >= 0 && j < N && apple[i][j] != 0 ) {
         stElement e; e.i = i;
        e.j = j;
        e.value = apple[i][j];
        path.push_back(e);
        if (apple[i][j] != -1) pathLen += apple[i][j];
        int t = apple[i][j];
        apple[i][j] = 0;
//将吃掉的苹果置为0，以免重复搜索 Snake(path, pathLen, i+1, j);
        Snake(path, pathLen, i-1, j);
        Snake(path, pathLen, i, j-1);
        Snake(path, pathLen, i, j+1);
        apple[i][j] = t;
//4个方向都搜索完之后一定要将元素恢复原状 } } } int _tmain(int argc, _TCHAR* argv[]) { vector<stElement> path;
int i,j,pathLen = 0; stElement e;
//找到入口点 for (i = 0; i < M; i++) for (j = 0; j < N; j++) { if (apple[i][j] == -1) { e.i = i; e.j = j;
e.value = -1; break; 
    } 
} 
Snake(path, pathLen, e.i, e.j);
cout<<"the longest path:"<<endl;
    for (i = 0; i < maxPath.size();i++) 
        cout<<"("<<maxPath[i].i<<", "<<maxPath[i].j<<")"<<"\t";
    cout<<endl;
    cout<<"带回苹果数为: "<<maxLen<<endl; system("pause");
    return 0;
}
