#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct DLNode{
    ElemType data;
    struct DLNode *next;
    struct DLNode *prior;
}DLNode;

DLNode *InitList(DLNode *DL);//��ʼ��
int ListEmpty(DLNode *DL);//�п�
int ListLength(DLNode *DL);//����������
int ListInsert(DLNode *DL, int i, ElemType e);//����Ԫ��
int ListDelete(DLNode *DL, int i);//ɾ����i��Ԫ��
void TraverseList(DLNode *DL);//�������Ա�

//��ʼ��
DLNode* InitList(DLNode *DL){
    int x;
    DLNode *p = NULL;
    DLNode *r = NULL;

    DL = (DLNode *)malloc(sizeof(DLNode));
    DL->next = DL;
    DL->prior = DL;
    r = DL;

    printf("����ֱ��-1Ϊֹ\n");
    while(1){
        scanf("%d", &x);
        if(x == -1){
            printf("��ʼ���ɹ�\n");
            break;
        }
        p = (DLNode *)malloc(sizeof(DLNode));
        if(p){
            p->data = x;
            p->prior = r;
            p->next = DL;
            r->next = p;
            DL->prior = p;
            r = p;
        }else{
            printf("�ռ䲻���ʼ��ʧ��\n");
            return NULL;
        }

    }
    return DL;

}

//�п�
int ListEmpty(DLNode *DL){
    return (DL->next == DL);
}

//����Ԫ��
int ListInsert(DLNode *DL, int i, ElemType e){
    if(i>ListLength(DL)+1 || i<=0){
        printf("����λ�����󣬲���ʧ��\n");
        return 0;
    }
    DLNode *p = DL;
    int j = 0;
    while(j<i){
        p = p->next;
        j++;
    }

    DLNode *nDLNode = (DLNode *)malloc(sizeof(DLNode));
    nDLNode->data = e;
    nDLNode->prior = p->prior;
    p->prior->next = nDLNode;
    p->prior = nDLNode;
    nDLNode->next = p;
    printf("����ɹ�\n");
    return 1;
}

//ɾ����i��Ԫ��
int ListDelete(DLNode *DL, int i){
    if(i>ListLength(DL) || i<=0){
        printf("ɾ��λ�����󣬲���ʧ��\n");
        return 0;
    }
    DLNode *p = DL;
    int j = 0;
    while(j<i){
        p = p->next;
        j++;
    }
    p->prior->next = p->next;
    p->next->prior = p->prior;

    free(p);
    printf("ɾ���ɹ�\n");
    return 1;
}


//����������
int ListLength(DLNode *DL){
    int len = 0;
    if(ListEmpty(DL)) return 0;
    DLNode *p = DL->next;
    while(p->data!=DL->data){
        len++;
        p = p->next;
    }
    return len;
}

//�������Ա�
void TraverseList(DLNode *DL){
    if(ListEmpty(DL)){
        printf("������");
    }
    DLNode *p = DL->next;
    //��ֹѭ������
    while(p->data != DL->data){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}


int main(){
    ElemType e = NULL;
    DLNode *DL = NULL;

    //��ʼ������
    DL = InitList(DL);

//    //�ȼ۲���
//    DLNode *d = DL->next->next;
//    if(d->next->prior == d->prior->next){
//        printf("d->next->prior == d->prior->next\n");
//    }
//    if(d->next->prior == d){
//        printf("d->next->prior == d\n");
//    }
//    if(d == d->prior->next){
//        printf("d == d->prior->next\n");
//    }

    //��������
    TraverseList(DL);
//
//    printf("˫��ѭ��������Ϊ%d\n",ListLength(DL));


    //����Ԫ�ز���
    printf("��3��λ�ò���999\n");
    ListInsert(DL, 3, 999);
    TraverseList(DL);
//-----------------------------------------------------
    //�Ƿ�����?ѭ��˫���������һ���޴��λ���Ƿ�Ϸ���
    //����ʦ�����꣬�㲻�Ϸ�
    printf("��567λ�ò���999\n");
    ListInsert(DL, 567, 999);
    TraverseList(DL);
//------------------------------------------------------
    //ɾ��Ԫ�ز���
//    printf("ɾ����1��λ��\n");
//    ListDelete(DL, 1);
//    TraverseList(DL);
//------------------------------------------------------
    //�Ƿ�����?ͬ��
    //�����⣬1��2��3��4��-1��ɾ����5����ͷ�ڵ㡣
    //����ʦ�����꣬�㲻�Ϸ�
//    printf("ɾ����55λ��\n");
//    ListDelete(DL, 55);
//    TraverseList(DL);
//------------------------------------------------------


}
