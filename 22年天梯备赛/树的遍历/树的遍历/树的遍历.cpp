#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

const int N = 40;

int n, count1;
int postorder[N], inorder[N];               //ǰ��������������
unordered_map<int, int> l, r, pos;          //�ù�ϣ��ģ�������

int build(int il, int ir, int pl, int pr)
{
    int root = postorder[pr];
    int k = pos[root];                      //�õ����ڵ�����������е��±�

    //k����il��ʾ���ڵ���߻��нڵ㣬����ǰ���ڵ��������������ͬ
    //�����������ѵ㣬�������ͼ�ͼ
    if (il < k) l[root] = build(il, k - 1, pl, pl + k - 1 - il);
    if (ir > k) r[root] = build(k + 1, ir, pl + k - il, pr - 1);

    return root;
}

void bfs(int root)                          //BFS��������������
{
    queue<int> q;
    q.push(root);
    while (q.size())
    {
        auto t = q.front();
        q.pop();
        if (count1 == 0)cout << t;
        else cout << " " << t;
        count1++;
        if (l.count(t)) q.push(l[t]);       //�жϸýڵ�����Ҷ����Ƿ����
        if (r.count(t)) q.push(r[t]);       //�����������У��ȴ���һ�����
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> postorder[i];
    for (int i = 0; i < n; i++)
    {
        cin >> inorder[i];
        pos[inorder[i]] = i;                //��¼�������ÿ����λ�ã���֦��
    }

    int root = build(0, n - 1, 0, n - 1);   //����Ϊ�����������ͺ����������
    bfs(root);

    return 0;
}