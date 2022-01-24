#include<stdio.h>
#include<stdlib.h>
typedef struct node * Linklist;
struct node
{
	int data;
	Linklist next;
}node;
 
Linklist Create()
{
	Linklist L=(Linklist)malloc(sizeof(struct node));
	L->next=NULL;
	return L;
}
 
int main()
{
	int i,m,c=0,count=0;
	Linklist L=Create();
	Linklist T,L1;
	L1=L;
	scanf("%d",&m);
	while(1)
	{
		scanf("%d",&c);
		if(c<0)break;
		T=(Linklist)malloc(sizeof(struct node));
		T->data=c;
		T->next=NULL;
		L1->next=T;
		L1=T;
	    count++;
	}
	if(count<m)
		printf("NULL");
	else
	{
		for(i=0;i<count-m+1;i++)
		{
			L=L->next;
		}
		printf("%d\n",L->data);
	
	}
    return 0;
}
