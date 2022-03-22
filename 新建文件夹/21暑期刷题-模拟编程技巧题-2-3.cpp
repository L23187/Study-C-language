#include<iostream>
using namespace std;
int add_up(int n, int m)
{
	int count = 0; 
	int house[1000] = { 0 };
	int sum=0;
	for(int i=0;i<n;i++)
	{
		cin >> house[i];
		sum+=house[i];
	}
	if((sum%m)!=0)
	{
		return -1;
	}
	else
	{
		int area = sum/m;
		while(n>=0)
		{
			if(house[0] == 0)
			{
				break;
			}
			else if(house[0]%area == 0)
			{
				count += house[0]/area - 1;
				for(int i=0;i<n;i++)
				{
					house[i]=house[i+1];
				}
			}
			else
			{
				house[1] += house[0];
				count++;
				for(int i=0;i<n;i++)
				{
					house[i]=house[i+1];
				}
			}
			n--;
		}
		return count;
	}
	
}

int main()
{
	int T,n, m;
	int result[100] = { 0 };
	cin >> T;
	for(int i=0;i<T;i++)
	{
		cin >> n >> m;
		result[i] = add_up(n,m);
	}
	for(int i=0;i<T;i++)
	{
		cout << "Case #" << i+1 << ": " << result[i] << endl;
	}
	return 0;
}
