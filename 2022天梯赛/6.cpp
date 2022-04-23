#include<stdio.h>
#include<string.h>

void judge(char* a,char* s){
	for (int i = 1; i < strlen(a); i++) {
  		if ((a[i]) % 2 == (a[i-1]) % 2) {
    		s += max(a[i], a[i-1]);
  		}	
	}
}
int main(void){
	char a[10001],b[10001],s[10001];
	gets(a);
	gets(b);
	return 0;
}
