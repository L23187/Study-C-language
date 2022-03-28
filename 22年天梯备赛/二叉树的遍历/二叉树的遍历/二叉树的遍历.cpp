#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
typedef struct tnode  //二叉树节点
{
    struct node* lchild, * rchild;
    char data;
} BTNode;
typedef BTNode* ElementType;

typedef struct Node* PtrToNode;
struct Node {          // 队列中的节点
    ElementType data;
    PtrToNode Next;
};
typedef PtrToNode Position;

typedef struct QNode* PtrToQNode;
struct QNode {
    Position Front, Rear;  //队列头尾指针
};
typedef PtrToQNode Queue;

Queue CreateQueue()    // 创建队列（用于层序输出）
{
    Queue Q = (Queue)malloc(sizeof(struct QNode));
    Q->Front = NULL;
    Q->Rear = NULL;
    return Q;
}

void AddQ(Queue Q, ElementType x)  // 队列添加元素
{
    PtrToNode p = (PtrToNode)malloc(sizeof(struct Node));
    p->Next = NULL;
    p->data = x;
    if (Q->Front == NULL)  // 队列空时
    {
        Q->Front = p;
        Q->Rear = p;
    }
    else
    {
        Q->Rear->Next = p;
        Q->Rear = p;
    }
}

ElementType DeleteQ(Queue Q)
{
    ElementType n;
    Position FrontCell;
    FrontCell = Q->Front;
    if (Q->Front == Q->Rear)
    {
        Q->Front = Q->Rear = NULL;
    }
    else {
        Q->Front = Q->Front->Next;
    }
    n = FrontCell->data;
    free(FrontCell);
    return n;
}

int IsEmpty(Queue Q)
{
    if (Q->Front == NULL)
        return 1;
    else
        return 0;
}

BTNode* CreateBTree(int* pre, int* in, int n)   // 根据后序和中序遍历序列确定树的结构
{
    int k;   // 记录根节点左子树的个数
    int* p;  // 指向根节点
    if (n <= 0)
        return NULL;
    BTNode* b = (BTNode*)malloc(sizeof(BTNode));
    b->data = *(pre + n - 1);  // 树的根节点为后序序列的最后一个编号
    for (p = in; p < in + n; ++p)
        if (*p == *(pre + n - 1))  // 在中序序列中寻找根节点的位置
            break;				// 找到后退出循环
    k = p - in;          // 记录根节点左子树节点个数
    b->lchild = CreateBTree(pre, in, k);  // 递归
    b->rchild = CreateBTree(pre + k, p + 1, n - k - 1);
    return b;
}


void LevelorderTraversal(BTNode* BT)
{
    Queue Q;
    BTNode* T;
    int temp = 1;
    if (!BT) return;

    Q = CreateQueue();
    AddQ(Q, BT);
    while (!IsEmpty(Q))
    {
        T = DeleteQ(Q);
        if (temp)
        {
            printf("%d", T->data);
            temp = 0;
        }
        else
            printf(" %d", T->data);
        if (T->lchild)
            AddQ(Q, T->lchild);
        if (T->rchild)
            AddQ(Q, T->rchild);
    }
}


int main()
{
    BTNode* b;
    int n, i;
    scanf("%d", &n);
    int pre[n], in[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &pre[i]);
    }
    for (i = 0; i < n; i++)
    {
        scanf("%d", &in[i]);
    }


    b = CreateBTree(pre, in, n);
    LevelorderTraversal(b);
    return 0;
}

}