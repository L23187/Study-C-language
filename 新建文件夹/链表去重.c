#include<stdio.h>
#include<math.h>

typedef struct Node
{
	int date;//������ 
	int next;//ָ���� 
}Node;

int first[100005]; // ��ŵ�һ������ĵ�ַ 
int f = 0;
int flag[100005]; // �ж��Ƿ����ظ���0����δ�ظ���1�����Ѵ��� 
int is = 0;
int last[100005]; // ��ŵڶ�������ĵ�ַ 
int l = 0;

void print(Node arr[],int g[],int n);

int main()
{
	Node arr[100005];
	int head; // �׵�ַ 
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
		is = abs(arr[p].date); // ȡ����ֵ�ľ���ֵ 
		// �жϸü�ֵ�Ƿ���� 
		if(!flag[is])
		{
			// �ü�ֵ������ 
			first[f++] = p; // ���ü�ֵ�ĵ�ַ�����һ�������� 
			flag[is] = 1; // ���ü�ֵλ����Ϊ1����ʾ�Ѵ��� 
		}
		else
		{
			// �ü�ֵ���� 
			last[l++] = p; // ���ü�ֵ��ַ����ڶ��������� 
		}
		p = arr[p].next; // ������һλ�� 
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

