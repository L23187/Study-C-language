#include<stdio.h>
int main()
{
  int a,b;//定义a为加油量	定义b为汽油品种 
  double sum;//定义sum为应付款额 
  char c;//定义服务类型 
  scanf("%d%d %c",&a,&b,&c);/*此处%d和%c之间要写一个空格	
  输入样例中97与m之间有空格，要是%d与%c之间没空格，%c输入的就是‘ ’了。*/ 
  switch(b)//用选择语句完成 
  {
    case 90:
    sum=6.95;
    break;
    case 93:
    sum=7.44;
    break;
    case 97:
    sum=7.93;
    break;
  }
  if(c=='m')
  printf("%.2f\n",0.95*sum*a);
  else
  printf("%.2f\n",sum*0.97*a);
  return 0;
}


