#include<stdio.h>

int main()
{
	int N,U,D;//���微�����n��һ����������u�� ��һ��������d�� 
	int T = 0;
	
	scanf("%d %d %d",&N,&U,&D);
	
	while(N>0)
	{
		if(N>U)//�����������������ʱ���������ܹ��������ľ������ 
		{
			T += 2;
		}
		else//������С�������߶�ʱ����1���Ӵ���ʱ�� 
		{
			T += 1;
		}
		
		if(N<=U)
		{
			N = N -U;
		}
		else
		{
			N = N - U + D;
		}
	}
	
	printf("%d",T); 
	
	return 0;
}

