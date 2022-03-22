#include<stdio.h>
#include<stdlib.h>
typedef struct DLnode 
{
	int data;
	struct DLnode *prior;
	struct DLnode *next;
}DLnode, *LinkList;
 
int InitList(LinkList &L) 
{
	L = new DLnode;
	L->next = L;
	L->prior = L;
	return 1;
}
 
void TraveList(LinkList L) 
{
	DLnode *p;
	p = L->next;
	
	while (p != L) 
	{
		printf("%d ", p->data);
		p = p->next;
	}
	
	printf("\n");
}
 
int ListLength(LinkList &L) 
{
	DLnode *p;
	p = L->next;
	int length = 0;
	while (p!=L) 
	{
		length++;
		p = p->next;
	}
	
	return length;
}
 
void CreateList(LinkList &L, int &n)   //尾插法创造
{
	L = new DLnode;
	L->next = L;
	L->prior = L;
	DLnode *p;
	p = L;
	
	for (int i = 0; i < n; i++) 
	{
		printf("请输入第%d个元素的值:", i + 1);
		DLnode *s;
		s = new DLnode;
		scanf("%d", &s->data);
		p->next = s;
		s->next = L;
		s->prior = p;
		p = s;
	}
}
 
void Change(LinkList p)   //核心算法
{
	DLnode *q;
	q = p->prior;
	
	q->prior->next = p;          // p的前驱的前驱之后继为p
	p->prior = q->prior;    // p的前驱指向其前驱的前驱。
	
	q->next = p->next;    // p的前驱的后继为p的后继。 
	p->next->prior = q;   // p的后继的前驱指向原p的前驱
	
	q->prior = p;     // p与其前驱交换
	p->next = q;    // p的后继指向其原来的前驱
}
 
int main() 
{
	LinkList L;
	
	if (InitList(L)) 
	{
		printf("L初始化成功\n");
	}
	else 
	{
		printf("L初始化失败.\n");
	}
 
	printf("请输入链表元素个数:");
	int n;
	scanf("%d", &n);
	CreateList(L, n);
	TraveList(L);
	printf("链表长度:%d\n", ListLength(L));
	
	printf("请输入要交换的结点的值:");
	DLnode *s;
	s = new DLnode;
	scanf("%d", &s->data);
	DLnode *p;
	p = L->next;
	while (p != L) 
	{
		if (p->data == s->data)     //寻找节点
		{
			Change(p);
 
			break;
		}
		else 
		{
			p = p->next;
		}
	}
	
	TraveList(L);
 
	return 0;
}

