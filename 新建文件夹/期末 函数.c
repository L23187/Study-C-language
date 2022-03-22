
#include <stdio.h>
#include <string.h>

int calc ( int m,  int n );
void strOp(char *str,  int idx,  char ch);

int main( ) {
    int m, n, idx, choice;
    char  ch, str[33];
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            scanf("%d%d", &m, &n);
            printf("%d\n", calc(m, n));
            break;
        case 2:
            scanf("%s%d", str, &idx);
            getchar();
            scanf("%c", &ch);
            strOp(str, idx, ch);
            printf("%s\n", str);
            break;
    }
    return 0;
}
int calc ( int m,  int n ){
	int a,b,c,d,o,p,i;
	for(i=m;i<=n;i++){
		a=i/1000;
		b=(i%1000)/100;
		c=(i%100)/10;
		d=i%10;
		o=a+d;
		p=b+c;
		if(o==p){
			break;
		}
	}
	return i;
}
void strOp(char *str,  int idx,  char ch){
	int i;
	i=100; 
} 
