
#include <stdio.h>

int moveChar (char *str, char ch );

int main() {
        char s[81], ch;
    int n;
    gets(s);
    scanf("%c", &ch);
    n = moveChar(s, ch);
    printf("%d:%s\n", n, s);
    return 0;
}

int moveChar (char *str, char ch ){
	int cnt;
	while(*str=='\0'){
		str++;
		if(*str==ch)break;
		cnt++;
	} 
	return cnt;
} 
