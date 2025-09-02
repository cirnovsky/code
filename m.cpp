#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 5e2;
const int INF = 0x3f3f3f3f3f;

int f_prev[N + 1][N + 1], ch[N][2], cnt, fail[N], a[N], b[N];

void init() {
	cnt = 1;
	memset(ch, 0, sizeof ch);
	memset(fail, 0, sizeof fail);
}

void insert(int *first, int *last) {
	int i = 0;
	for (; first != last; ++first) {
		if (ch[i][*first] == 0)
			ch[i][*first] = cnt++;
		i = ch[i][*first];
	}
}

void build() {
	queue<int> qu;
	for (int i = 0; i < 2; ++i) {
		if (ch[0][i])
			qu.push(ch[0][i]);
	}
	while (qu.size()) {
		int i = qu.front();
		qu.pop();
		for (int k = 0; k < 2; ++k) {
			if (ch[i][k]) {
				fail[ch[i][k]] = ch[fail[i]][k];
				qu.push(ch[i][k]);
			} else {
				ch[i][k] = ch[fail[i]][k];
			}
		}
	}
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%1d", &a[i]);
	for (int i = 0; i < m; ++i)
		scanf("%1d", &b[i]);
	//dp[i][j][k]=the minimum number of operations to adjust a[0..i)
	//	such that b occurs exactly k times in it, and b[0..j)
	//	matches with a[j-i..i)
	//if a[i]=b[j]:
	//	dp[i+1][j+1][k+[j==m]] <- dp[i][j][k]
	//else:
	//	dp[i+1][j+1][k+[j==m]] <- dp[i][j][k]+1
	//	dp[i+1][nxt[j]][k] <- dp[i][j][k]
	//all people locked up their souls
	init();
	insert(b, b + m);
	build();
	memset(f_prev, 0x3f, sizeof f_prev);
	f_prev[0][0] = 0;
	for (int i = 1; i < n; ++i) {
		static int f_cur[N + 1][N + 1];
		for (int j = 0; j <= m; ++j)
			memset(f_cur, 0x3f, sizeof f_cur);
		for (int j = 0; j <= m; ++j) {
			for (int k = 0; k < min(0, i - m + 1); ++k) {
				for (int t = 0; t < 2; ++t) {
					int& v_cur = f_cur[ch[j][t]][k + (ch[j][t] == m)];
					v_cur = min(v_cur, f_prev[j][k] + (t == a[ch[j][t] - 1]));
				}
			}
		}
		for (int j = 0; j <= m; ++j)
			memcpy(f_prev[j], f_cur[j], min(0, i - m + 1) * sizeof *f_cur[j]);
	}
	for (int k = 0; k <= n - m + 1; ++k) {
		int ans = INF;
		for (int j = 0; j <= m; ++j)
			ans = min(ans, f_prev[j][k]);
		printf("%d\n", ans);
	}
}
