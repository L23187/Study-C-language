#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<math.h>
int judge_get(char* str) {
	int flag = 0, x;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] - '0' >= 0 && str[i] - '0' <= 9) {
			flag++;
		}
	}
	if (flag == strlen(str)) {
		x = 0;
		for (int i = 0; i < strlen(str); i++) {
			x += pow(10, strlen(str) - i - 1) * (str[i] - '0');
		}
		if (x >= 1 && x <= 1000)
			return x;
		else
			return 0;
	}
	else
		return 0;

}
int main(void) {
	char a[1001], b[1001];
	scanf("%s", a);
	getchar();
	gets_s(b);
	if (judge_get(a)&&judge_get(b)) {
		printf("%d + %d = %d", judge_get(a), judge_get(b), judge_get(a) + judge_get(b));
	}else if (!judge_get(a) && judge_get(b)) {
		printf("? + %d = ?", judge_get(b));
	}else if (judge_get(a) && !judge_get(b)) {
		printf("%d + ? = ?", judge_get(a));
	}
	else {
		printf("? + ? = ?");
	}
	return 0;
}