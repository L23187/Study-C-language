// GreedySnake.cpp
include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <vector> using namespace std;
#define M 4 #define N 4
//��������Ԫ�ؽṹ�� struct stElement { int i; int j; int value; };
int apple[M][N] = { 7, -1, 4, 18, 4, 0, 1, 1, 15, 7, 11, 100, 0, 12, -2, 0};
vector<stElement> maxPath;
//��ǰ�·��(·������ָ����·��������ƻ�����ܸ����� int maxLen = 0;
//�·������ void Snake(vector<stElement> path, int pathLen, int i, int j) { if (apple[i][j] == -2)
//����Ե��յ��ƻ�� { if (pathLen > maxLen)
//�����·������ { stElement e; e.i = i; e.j = j;
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
//���Ե���ƻ����Ϊ0�������ظ����� Snake(path, pathLen, i+1, j);
        Snake(path, pathLen, i-1, j);
        Snake(path, pathLen, i, j-1);
        Snake(path, pathLen, i, j+1);
        apple[i][j] = t;
//4������������֮��һ��Ҫ��Ԫ�ػָ�ԭ״ } } } int _tmain(int argc, _TCHAR* argv[]) { vector<stElement> path;
int i,j,pathLen = 0; stElement e;
//�ҵ���ڵ� for (i = 0; i < M; i++) for (j = 0; j < N; j++) { if (apple[i][j] == -1) { e.i = i; e.j = j;
e.value = -1; break; 
    } 
} 
Snake(path, pathLen, e.i, e.j);
cout<<"the longest path:"<<endl;
    for (i = 0; i < maxPath.size();i++) 
        cout<<"("<<maxPath[i].i<<", "<<maxPath[i].j<<")"<<"\t";
    cout<<endl;
    cout<<"����ƻ����Ϊ: "<<maxLen<<endl; system("pause");
    return 0;
}
