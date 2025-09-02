#include <stdio.h>
#include <string.h>
using namespace std;

const int N = 1e6;
char s[N + 1], t[N + 1];

int main() {
	int n, m;
	scanf("%s\n%s", s, t);
	n = strlen(s);
	m = strlen(t);
	for (int i = 0; i < m; ++i)
		ch[i][t[i] - 'A'] = i + 1;
	for (int i = 1; i <= m; ++i) {
		for (int j : ch[i]) {
			if (j)
				fail[j] = ch[fail[i]][j];
			else
				ch[j] = ch[fail[i]][j];
		}
	}
