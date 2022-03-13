#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

const int N = 40;

int n, count1;
int postorder[N], inorder[N];               //前序遍历，中序遍历
unordered_map<int, int> l, r, pos;          //用哈希表模拟二叉树

int build(int il, int ir, int pl, int pr)
{
    int root = postorder[pr];
    int k = pos[root];                      //得到根节点在中序遍历中的下标

    //k大于il表示根节点左边还有节点，即当前根节点存在左子树，下同
    //下面两行是难点，举例解释见图
    if (il < k) l[root] = build(il, k - 1, pl, pl + k - 1 - il);
    if (ir > k) r[root] = build(k + 1, ir, pl + k - il, pr - 1);

    return root;
}

void bfs(int root)                          //BFS用来层序遍历输出
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
        if (l.count(t)) q.push(l[t]);       //判断该节点的左右儿子是否存在
        if (r.count(t)) q.push(r[t]);       //存在则加入队列，等待下一层遍历
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> postorder[i];
    for (int i = 0; i < n; i++)
    {
        cin >> inorder[i];
        pos[inorder[i]] = i;                //记录中序遍历每个点位置（剪枝）
    }

    int root = build(0, n - 1, 0, n - 1);   //参数为中序遍历区间和后序遍历区间
    bfs(root);

    return 0;
}