#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

const int MD = 998244353;
const int N = 2.1e5;

int dfn[N], low[N], st[N + 1], stp, cnt, top, a[N];
vector<int> dcc[N], adj[N];

void dfs(int i, int fa) {
	dfn[i] = low[i] = stp++;
	st[top++] = i;
	for (int j : adj[i]) {
		if (j == fa)
			continue;
		if (dfn[j] == -1) {
			dfs(j, i);
			low[i] = min(low[i], low[j]);
		} else {
			low[i] = min(low[i], dfn[j]);
		}
	}
	if (dfn[i] == low[i]) {
		for (; st[top - 1] != i;) {
			dcc[cnt].push_back(st[--top]);
		}
		dcc[cnt].push_back(st[--top]);
		cnt++;
	}
}

int col[N], ins[N];

bool colour(int i, bool c) {
	col[i] = c;
	bool res = 1;
	for (int j : adj[i]) {
		if (ins[j]) {
			if (col[j] == -1)
				res &= colour(j, c ^ 1);
			else
				res &= col[j] ^ col[i];
		}
	}
	return res;
}

bool bipartite(const vector<int>& st) {
	for (int i : st) {
		ins[i] = 1;
		col[i] = -1;
	}
	bool ret = colour(st[0], 0);
	for (int i : st)
		ins[i] = 0;
	return ret;
}

int solve() {
	int n, m, v;
	scanf("%d%d%d", &n, &m, &v);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; ++i)
		vector<int>().swap(adj[i]);
	for (int i = 0, u, v; i < m; ++i) {
		scanf("%d%d", &u, &v);
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	stp = top = cnt = 0;
	memset(dfn, -1, n * sizeof *dfn);
	for (int i = 0; i < n; ++i)
		vector<int>().swap(dcc[i]);
	dfs(0, n);
	int res = 1;
	for (int i = 0; i < cnt; ++i) {
		int fu = dcc[i].size();
		if (bipartite(dcc[i])) {
			int c = -1;
			for (int j : dcc[i]) {
				if (a[j] == -1)
					fu--;
				else if (c == -1)
					c = a[j];
				else if (c != a[j])
					return 0;
			}
			if (fu == 0)
				res = (long long) res * v % MD;
		} else {
			for (int j : dcc[i]) {
				if (a[j] != 0 && a[j] != -1)
					return 0;
			}
		}
	}
	return res;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) printf("%d\n", solve());
}
