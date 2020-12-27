#include<stdio.h>
struct staff
{
  char name[11];
  double z1;
  double z2;
  double z3;
  double sum;
};
int main()
{
  int n,i;
  scanf("%d",&n);
  struct staff ren[n];
  for(i=0;i<n;i++)
  {
    scanf("%s %lf %lf %lf",ren[i].name,&ren[i].z1,&ren[i].z2,&ren[i].z3);
    ren[i].sum=ren[i].z1+ren[i].z2-ren[i].z3;
  }
  for(i=0;i<n;i++)
  {
       printf("%s %.2lf\n",ren[i].name,ren[i].sum);
  }
  return 0;
}

