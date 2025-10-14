#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int N = 1e6;
char s[N + 1], t[N + 1];
int ch[N + 2][26], fail[N + 1], pi[N];

int main() {
	int n, m;
	scanf("%s\n%s", s, t);
	n = strlen(s);
	m = strlen(t);
	for (int i = 0; i < m; ++i)
		ch[i][t[i] - 'A'] = i + 1;
	for (int i = 1; i <= m; ++i) {
		for (int k = 0; k < 26; ++k) {
			int& j = ch[i][k];
			if (j)
				fail[j] = ch[fail[i]][k];
			else
				j = ch[fail[i]][k];
		}
	}
	//i hate fucking strings
	for (int j = 0, i = 0; j < n; ++j) {
		i = ch[i][s[j] - 'A'];
		if (i == m)
			printf("%d\n", j - m + 2);
	}
	for (int i = 1; i <= m; ++i)
		printf("%d%c", fail[i], " \n"[i == m]);
}
