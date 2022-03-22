#include<stdio.h>
#include<malloc.h>

typedef struct node//创建一个结点 有左孩子和右孩子 
{
    struct node *lchild, *rchild;
    char data;
} BTNode;

BTNode* CreateBTree(char *pre, char *in, int n)
{
    int k;
    char *p;
    if (n <= 0)
        return NULL;
    BTNode *b = (BTNode*)malloc(sizeof(BTNode));
    b->data = *pre;
    for (p = in; p < in + n; ++p)
        if (*p == *pre)
            break;
    k = p-in;
    b->lchild = CreateBTree(pre+1, in, k);
    b->rchild = CreateBTree(pre+k+1, p+1, n-k-1);
    return b;
}

int GetHeight(BTNode* BT)
{
    int HL,HR,MaxH;
    if(BT)
    {
        HL = GetHeight(BT->lchild);
        HR = GetHeight(BT->rchild);
        MaxH = HL > HR ? HL:HR;//如果HL大于HR则MaxH=HL	如果HL<HR则MaxH=HR 
        return (MaxH + 1);
    }
    else  return 0;
}

int main()
{
    BTNode* b;
    int h,n;
    scanf("%d",&n);
    char pre[n];
    char in[n];
    scanf("%s",pre);
    scanf("%s",in);

    b = CreateBTree(pre, in, n);
    h = GetHeight(b);
    printf("%d",h);
    return 0;
}
