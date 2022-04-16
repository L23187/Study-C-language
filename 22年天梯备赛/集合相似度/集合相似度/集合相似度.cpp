#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <set>
using namespace std;
int main(void) {
	int n;
	scanf("%d", &n);
	int m, l;
	int k, a, b;
	set<int>s[55];
	for (int i = 0; i < n; i++) {
		scanf("%d", &m);
		while (m--) {
			scanf("%d", &l);
			s[i].insert(l);
		}
	}
	scanf("%d", &k);
	while (k--) {
		scanf("%d %d", &a, &b);
		int cta = s[a - 1].size(), ctb = s[b - 1].size();
		int ct = 0;
		set<int>::iterator iter;
		for (iter = s[a - 1].begin(); iter != s[a - 1].end(); iter++) {
			if (s[b - 1].find(*iter) != s[b - 1].end()) {
				ct++;
			}
		}
		printf("%.2lf%%\n", ct * 1.0 / (cta + ctb - ct) * 100);
	}
	return 0;
}