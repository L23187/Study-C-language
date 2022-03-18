#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main(void) {
	int pa, pb;
	scanf("%d%d", &pa, &pb);
	int p1, p2, p3, p;
	scanf("%d%d%d", &p1, &p2, &p3);
	p = p1 + p2 + p3;
	if ((pa<pb&&p>1)||(pa>pb&&p==3))
	{
		printf("The winner is b: %d + %d", pb, p);
	}
	else {
		printf("The winner is a: %d + %d", pa, 3-p);
	}
	return 0;
}