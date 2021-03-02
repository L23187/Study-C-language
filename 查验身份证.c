#include<stdio.h>
#include<string.h>
int main()
{
  int n,i,j,a[100]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2},t,flag2=0,flag,flag1,sum;
  char ch[100],ch1[100]={"10X98765432"};
  scanf("%d",&n);
  getchar();
  for(i=0;i<n;i++)
  {
    sum=0;
    flag=0;
    flag1=0;
    gets(ch);
    for(j=0;j<17;j++)
    {
      if(!(ch[j]>='0'&&ch[j]<='9'))
      {
        flag=1;
      }
      sum=sum+(ch[j]-'0')*a[j];
    }
    t=sum%11;
    if(ch1[t]==ch[17]) flag1=1;
    if(flag1==0||flag==1)
    {
        printf("%s\n",ch);
        flag2=1;
    }
  }
  if(flag2==0) printf("All passed");
  return 0;
}

