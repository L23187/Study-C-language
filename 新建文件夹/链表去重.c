#include<stdio.h>
#include<math.h>

typedef struct Node
{
	int date;//数据域 
	int next;//指针域 
}Node;

int first[100005]; // 存放第一条链表的地址 
int f = 0;
int flag[100005]; // 判断是否有重复，0代表未重复，1代表已存在 
int is = 0;
int last[100005]; // 存放第二条链表的地址 
int l = 0;

void print(Node arr[],int g[],int n);

int main()
{
	Node arr[100005];
	int head; // 首地址 
	int n;
	int ads;
	scanf("%d %d",&head,&n);
	int i ;
	for(i=0;i<n;i++)
	{
		scanf("%d",&ads);
		scanf("%d %d",&arr[ads].date,&arr[ads].next);
	}
	int p = head;
	while(p != -1)
	{
		is = abs(arr[p].date); // 取出键值的绝对值 
		// 判断该键值是否存在 
		if(!flag[is])
		{
			// 该键值不存在 
			first[f++] = p; // 将该键值的地址放入第一条链表中 
			flag[is] = 1; // 将该键值位置置为1，表示已存在 
		}
		else
		{
			// 该键值存在 
			last[l++] = p; // 将该键值地址放入第二条链表中 
		}
		p = arr[p].next; // 移向下一位置 
	}
	print(arr,first,f);
	print(arr,last,l);
	return 0;
}
void print(Node arr[],int g[],int n)
{
	int j;
	for(j=0;j<n;j++)
	{
		if(j == n-1)
		{
			printf("%05d %d -1\n",g[j],arr[g[j]].date);
		}
		else
		{
			printf("%05d %d %05d\n",g[j],arr[g[j]].date,g[j+1]);
		}
	}
}

