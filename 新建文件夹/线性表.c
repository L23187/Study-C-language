#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct DLNode{
    ElemType data;
    struct DLNode *next;
    struct DLNode *prior;
}DLNode;

DLNode *InitList(DLNode *DL);//初始化
int ListEmpty(DLNode *DL);//判空
int ListLength(DLNode *DL);//返回链表长度
int ListInsert(DLNode *DL, int i, ElemType e);//插入元素
int ListDelete(DLNode *DL, int i);//删除第i个元素
void TraverseList(DLNode *DL);//遍历线性表

//初始化
DLNode* InitList(DLNode *DL){
    int x;
    DLNode *p = NULL;
    DLNode *r = NULL;

    DL = (DLNode *)malloc(sizeof(DLNode));
    DL->next = DL;
    DL->prior = DL;
    r = DL;

    printf("输入直到-1为止\n");
    while(1){
        scanf("%d", &x);
        if(x == -1){
            printf("初始化成功\n");
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
            printf("空间不足初始化失败\n");
            return NULL;
        }

    }
    return DL;

}

//判空
int ListEmpty(DLNode *DL){
    return (DL->next == DL);
}

//插入元素
int ListInsert(DLNode *DL, int i, ElemType e){
    if(i>ListLength(DL)+1 || i<=0){
        printf("插入位置有误，插入失败\n");
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
    printf("插入成功\n");
    return 1;
}

//删除第i个元素
int ListDelete(DLNode *DL, int i){
    if(i>ListLength(DL) || i<=0){
        printf("删除位置有误，插入失败\n");
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
    printf("删除成功\n");
    return 1;
}


//返回链表长度
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

//遍历线性表
void TraverseList(DLNode *DL){
    if(ListEmpty(DL)){
        printf("空链表");
    }
    DLNode *p = DL->next;
    //终止循环遍历
    while(p->data != DL->data){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}


int main(){
    ElemType e = NULL;
    DLNode *DL = NULL;

    //初始化测试
    DL = InitList(DL);

//    //等价测试
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

    //遍历测试
    TraverseList(DL);
//
//    printf("双向循环链表长度为%d\n",ListLength(DL));


    //插入元素测试
    printf("第3个位置插入999\n");
    ListInsert(DL, 3, 999);
    TraverseList(DL);
//-----------------------------------------------------
    //非法操作?循环双向链表插入一个巨大的位置是否合法？
    //和老师讨论完，算不合法
    printf("第567位置插入999\n");
    ListInsert(DL, 567, 999);
    TraverseList(DL);
//------------------------------------------------------
    //删除元素测试
//    printf("删除第1个位置\n");
//    ListDelete(DL, 1);
//    TraverseList(DL);
//------------------------------------------------------
    //非法操作?同上
    //新问题，1，2，3，4，-1，删除第5个是头节点。
    //和老师讨论完，算不合法
//    printf("删除第55位置\n");
//    ListDelete(DL, 55);
//    TraverseList(DL);
//------------------------------------------------------


}
