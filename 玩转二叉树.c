#include <stdio.h>
#include <stdlib.h>
 
typedef struct TNode{      //�����
    int Data;
    struct TNode *Left;
    struct TNode *Right;
}*BinTree;
typedef struct Node{  //�����������ʽ���н��
    BinTree T;
    struct Node * Next;
}*PtrToNode;
typedef struct QNode{   //���ж���
    PtrToNode Front,Rear;
}*Queue;
int in[35],pre[35]; //���������������������
BinTree CreatBinTree(int in[],int pre[],int length){ //����������������� ��ת! ����������
    if(!length) return NULL;
    BinTree BT=(BinTree)malloc(sizeof(struct TNode));
    BT->Data=pre[0];
    int i=0;
    for(i=0;i<length;i++){
        if(in[i]==pre[0])
            break;
    }
    BT->Right=CreatBinTree(in,pre+1,i); //������������Ӧ���� BT->Left
    BT->Left=CreatBinTree(in+i+1,pre+i+1,length-i-1); //������������ΪBT->Right
    return BT;
}
Queue CreatQueue(){  //�����ն���
    Queue Q=(Queue) malloc(sizeof(struct QNode));
    Q->Front=(PtrToNode)malloc(sizeof(struct Node));
    Q->Front->Next=NULL;
    Q->Rear=Q->Front;
    return Q;
}
void AddQ(Queue Q,BinTree BT){  //��Ӳ���
    PtrToNode tmp=(PtrToNode)malloc(sizeof(struct Node));
    tmp->T=BT;
    tmp->Next=NULL;
    Q->Rear->Next=tmp;
    Q->Rear=tmp;
}
BinTree DeleteQ(Queue Q){ //���Ӳ��������س��ӵ������
    PtrToNode tmp=Q->Front->Next;
    if(Q->Front->Next==Q->Rear){
        Q->Rear=Q->Front;
        Q->Front->Next=NULL;
    }
    else {
        Q->Front->Next=tmp->Next;
    }
    BinTree BT=tmp->T;
    return BT;
}
int IsEmpty(Queue Q){ //�ж϶����Ƿ�Ϊ�գ��շ���1
    if(Q->Front->Next==NULL) return 1;
    else return 0;
}
void LevelOrder(BinTree BT){  //�������������
    if(!BT) return;
    BinTree T;
    int flag=0;
    Queue Q=CreatQueue();
    AddQ(Q,BT);
    while(!IsEmpty(Q)){
        T=DeleteQ(Q);
        if(flag) printf(" ");
        else flag=1;
        printf("%d",T->Data);
        if(T->Left) AddQ(Q,T->Left);
        if(T->Right) AddQ(Q,T->Right);
    }
}
 
int main()
{
    int N;
    scanf("%d",&N);
    int i,j;
    for( i=0;i<N;i++)
        scanf("%d",&in[i]);
    for(j=0;j<N;j++)
        scanf("%d",&pre[j]);
    BinTree BT=NULL;
    BT=CreatBinTree(in,pre,N);
    LevelOrder(BT);
    return 0;
}
