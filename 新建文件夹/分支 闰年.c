#include<stdio.h>
int main(){
 int x, y;
 scanf("%d", &x);
 if(x>2003&&x<=2100){
  for(y=2001;y<=x;y++){
   if(y%4==0&&y%100!=0||y%400==0){
    printf("%d\n",y);
   }else{
   }
  }
 }else if(x>2000&&x<=2003){
  printf("None");
 }else if(x<=2000||x>2100){
  printf("Invalid year!");
 }
 return 0;
}
