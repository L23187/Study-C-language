#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
void judge(string a, string s) {
	for (int i = 1; i < size(a); i++) {
		if ((a[i]) % 2 == (a[i - 1]) % 2) {
			s += max(a[i], a[i - 1]);
		}
	}
	cout << s;
}

int main(void) {
	string s, a, b;
	cin >> a;
	cin >> b;
	judge(a,s);
	return 0;
}