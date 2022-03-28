#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
typedef struct tnode  //�������ڵ�
{
    struct node* lchild, * rchild;
    char data;
} BTNode;
typedef BTNode* ElementType;

typedef struct Node* PtrToNode;
struct Node {          // �����еĽڵ�
    ElementType data;
    PtrToNode Next;
};
typedef PtrToNode Position;

typedef struct QNode* PtrToQNode;
struct QNode {
    Position Front, Rear;  //����ͷβָ��
};
typedef PtrToQNode Queue;

Queue CreateQueue()    // �������У����ڲ��������
{
    Queue Q = (Queue)malloc(sizeof(struct QNode));
    Q->Front = NULL;
    Q->Rear = NULL;
    return Q;
}

void AddQ(Queue Q, ElementType x)  // �������Ԫ��
{
    PtrToNode p = (PtrToNode)malloc(sizeof(struct Node));
    p->Next = NULL;
    p->data = x;
    if (Q->Front == NULL)  // ���п�ʱ
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

BTNode* CreateBTree(int* pre, int* in, int n)   // ���ݺ���������������ȷ�����Ľṹ
{
    int k;   // ��¼���ڵ��������ĸ���
    int* p;  // ָ����ڵ�
    if (n <= 0)
        return NULL;
    BTNode* b = (BTNode*)malloc(sizeof(BTNode));
    b->data = *(pre + n - 1);  // ���ĸ��ڵ�Ϊ�������е����һ�����
    for (p = in; p < in + n; ++p)
        if (*p == *(pre + n - 1))  // ������������Ѱ�Ҹ��ڵ��λ��
            break;				// �ҵ����˳�ѭ��
    k = p - in;          // ��¼���ڵ��������ڵ����
    b->lchild = CreateBTree(pre, in, k);  // �ݹ�
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