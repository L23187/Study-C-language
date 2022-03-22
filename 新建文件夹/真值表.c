#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
// �ַ�������Ƭ�ο������� 
void copy(char temp1[], char st[], int start, int end)
{
    int i, j = 0;
    for (i = start; i <= end; i++)  
 { 
 temp1[j++] = st[i]; 
 }
    temp1[j] = '\0';
}
// �����ά�ṹ�����Դ�����Ľڵ� 
struct point
{
    char str[20];
    char oper;
    int value;
} e[10][10];
//   ����
int build_tree(char s[20]){
int i,j=0,k=0,g,th,len,m=0;
strcpy(e[0][0].str,s);
for(j=1;j<10;j++){
 len=th=g=0;
 for(g=0;g<7;g++)
 {
 k=strlen(e[j-1][g].str);
 if(k<3){
 strcpy(e[j][th].str,e[j-1][g].str); 
 th++;
 }
 
if((e[j-1][g].str[0]=='(')&&(e[j-1][g].str[strlen(e[j-1][g].str)-1]==')'))
{  
for(i=1;i<k-1;i++)
{
if(e[j-1][g].str[i]=='('||i==k-2) {copy(e[j-1][g].str,e[j-1][g].str,1,strlen(e[j-1][g].str)-2); break;}
if(e[j-1][g].str[i]==')')  break;
}
}
 
for(i=0;i<k;i++)
{  
if(e[j-1][g].str[i]=='(') {m++; continue;}
if(e[j-1][g].str[i]==')'&&(m==1)) {m--; continue;}


if(m==0)
{
 if(e[j-1][g].str[i]=='=')
 {
copy(e[j][th].str,e[j-1][g].str,0,i-1);
 copy(e[j][th+1].str,e[j-1][g].str,i+1,k-1);
 e[j-1][g].oper='=';
 th+=2;
 len++;  
 goto begin;
 }
}
}
 
for(i=0;i<k;i++)
{  
if(e[j-1][g].str[i]=='(') {m++; continue;}
if(e[j-1][g].str[i]==')'&&(m==1)) {m--; continue;}


if(m==0)
{
 if(e[j-1][g].str[i]=='>')
 {
copy(e[j][th].str,e[j-1][g].str,0,i-1);
 copy(e[j][th+1].str,e[j-1][g].str,i+1,k-1);
 e[j-1][g].oper='>';
 th+=2;
 len++;  
 goto begin;
 }
}
}  


for(i=0;i<k;i++)
{  
if(e[j-1][g].str[i]=='(') {m++; continue;}
if(e[j-1][g].str[i]==')'&&(m==1)) {m--; continue;}


if(m==0)
{
 if(e[j-1][g].str[i]=='|')
 {
copy(e[j][th].str,e[j-1][g].str,0,i-1);
 copy(e[j][th+1].str,e[j-1][g].str,i+1,k-1);
 e[j-1][g].oper='|';
 th+=2;
 len++;  
 goto begin;
 }
}
}


for(i=0;i<k;i++)
{  
if(e[j-1][g].str[i]=='(') {m++; continue;}
if(e[j-1][g].str[i]==')'&&(m==1)) {m--; continue;}


if(m==0)
{
 if(e[j-1][g].str[i]=='&')
 {
copy(e[j][th].str,e[j-1][g].str,0,i-1);
 copy(e[j][th+1].str,e[j-1][g].str,i+1,k-1);
 e[j-1][g].oper='&';
 th+=2;
 len++;  
 goto begin;
 }
}
}


if(strlen(e[j-1][g].str)>2){
 copy(e[j][th].str,e[j-1][g].str,1,k-1);
 e[j-1][g].oper='!';
 th+=1;
 len++;  
}
begin:;
}
if(len==0)
break;
}
return j;
}


void show_tree(int j){
int i,d,le;
le=strlen(e[0][0].str);
for(i=0;i<j;i++){
 printf("��%d��  ",i);
 for(d=0;d<10;d++){
 if(strlen(e[i][d].str)<1) break;
 printf("%s  ",e[i][d].str);
 }
 printf("\n");
}
}


void print_table(int j){
 int i,k,in,g=1,m,n,le;
//�����Ҷ��!p����ʽ���������p����ʽ
if(e[j-1][0].str[0]=='!') printf("%c  ",e[j-1][0].str[1]);
else printf("%s  ",e[j-1][0].str);
 for(in=1;in<10;in++){
 if(strlen(e[j-1][in].str)==0){
 break;  
 }
//�����Ҷ�������Ԫ��ǰ����Ҷ���ظ����������һ����Ҷ�� 
 for(k=0;k<in;k++){
if(!strcmp(e[j-1][in].str,e[j-1][k].str)||(e[j-1][in].str[0]==e[j-1][k].str[1])||(e[j-1][in].str[1]==e[j-1][k].str[0]))break;
 
if(k==in-1){
g++  ;//��g��¼�����Ԫ�ĸ����� 
if(strlen(e[j-1][in].str)==2) printf("%c  ",e[j-1][in].str[1]);
else printf("%s  ",e[j-1][in].str);
}
 }
}
printf("��ֵ\n");
// Ϊ�����Ԫ��ֵ������ø�ֵ�µ���ֵ
for(le=0;le<pow(2,g);le++){
n=0;
for(i=0;i<in;i++){
m=i-n;
if(i==0) {
 e[j-1][0].value=le&1;
 printf("%d  ",e[j-1][0].value);
 }
else for(k=0;k<i;k++){
 if(!strcmp(e[j-1][i].str,e[j-1][k].str)||(e[j-1][i].str[0]==e[j-1][k].str[1])||(e[j-1][i].str[1]==e[j-1][k].str[0]))
 {
    e[j-1][i].value=e[j-1][k].value;
    if(strlen(e[j-1][k].str)==2) e[j-1][i].value=!e[j-1][i].value;
    n++;
 break;  
 }
    if(k==i-1){
 e[j-1][i].value=le&(int)(pow(2,m));
    e[j-1][i].value=e[j-1][i].value>>m;
 printf("%d  ",e[j-1][i].value);
    }
}
 if(strlen(e[j-1][i].str)==2) e[j-1][i].value=!e[j-1][i].value;//��Ҷ�����!p����ʽ����valueΪ��p�� 
 }
//ͨ�����ṹ������Ҷ������������ֵ
for(m=j-2;m>=0;m--){
i=0;  
    for(n=0;n<10;n++){
switch(e[m][n].oper){
 case '&':e[m][n].value=e[m+1][i].value&&e[m+1][i+1].value; i+=2;break;
 case '|':e[m][n].value=e[m+1][i].value||e[m+1][i+1].value; i+=2;break;
 case '>':e[m][n].value=!(e[m+1][i].value)||e[m+1][i+1].value; i+=2;break;
 case '=':e[m][n].value=(!(e[m+1][i].value)||e[m+1][i+1].value)&&((e[m+1][i].value)||!e[m+1][i+1].value);i+=2;break;
 case '!':e[m][n].value=!(e[m+1][i].value); i+=1;break;
 default:
 if((strlen(e[m][n].str))>0){
 e[m][n].value = e[m+1][i].value;
 i+=1;  
 }
 break;
        }
    }
}
//��ӡ������ֵ 
printf("%d\n",e[0][0].value);
}  
}
/***************������****************/ 
int main(){
int j;
char s[20];
printf("���������⹫ʽ��");
scanf("%s",s);
// ������ ����j��¼���Ĳ��� 
j=build_tree(s);
// ������ṹ 
show_tree(j);
// �����ֵ��
print_table(j);
}
