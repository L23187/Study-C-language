#include<stdio.h>
int main()
{
	int a, b, c, m, n;
	scanf("%d %d", &m, &n);
	if(m<n){
		c=m;
		m=n;
		n=c;
	}
	a=m;
	b=n;
	while(b!=0){
		c=a%b;
		a=b;
		b=c;
	}
	printf("%d %d", a, m*n/a);
	
	return 0;
}

