#include<stdio.h>
#include<string.h>
int main() 
{
    int N,len;
    int i,j,k; 
    char a[1000];
    scanf("%d",&N);
    while(N>=0)
    {
        gets(a);
        len=strlen(a);
        j=0;
        for(i=0;i<=len;i++)
        {
            if(a[i]==' '||a[i]=='\0')
            {
                for(k=i-1;k>=j;k--){//�������ǿո���������ַ�������ʱ��ֱ����k����ǰһ�������������
                    printf("%c",a[k]);
				}
                  if(a[i]!='\0'){
                    printf(" ");//��Ϊ�����ǲ�Ϊ�ո����������Ի�Ҫ������֮��ֱ�����
                  	j=i;
				  }//��¼�����ո���߱�����ʱ����i
             }
        }
        N--;
        printf("\n");
    }
    return 0; 
}
