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
                for(k=i-1;k>=j;k--){//当遇到是空格或者整个字符结束的时候，直接让k等于前一个数，逆序输出
                    printf("%c",a[k]);
				}
                  if(a[i]!='\0'){
                    printf(" ");//因为条件是不为空格的情况，所以还要逆序完之后直接输出
                  	j=i;
				  }//记录遇见空格或者标点符号时，的i
             }
        }
        N--;
        printf("\n");
    }
    return 0; 
}
