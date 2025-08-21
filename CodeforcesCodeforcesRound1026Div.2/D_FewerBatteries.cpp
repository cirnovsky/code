// time-limit: 3000
// problem-url: https://codeforces.com/contest/2110/problem/D
#include <bits/stdc++.h>
using namespace std;

using PI = pair<int, int>;

int cumin(int i, int j) {
	if (i == -1) return j;
	else if (j == -1) return i;
	return min(i, j);
}

const int N = 2e5;
vector<PI> adj[N];
int dp[N], a[N];

int search(int ok, int ng, int n) {
	int res = -1;
	while (ok != ng) {
		int md = ok + (ng - ok) / 2;
		memset(dp, -1, n * sizeof *dp);
		dp[n - 1] = 0;
		queue<int> qu({n - 1});
		while (qu.size()) {
			int j = qu.front();
			qu.pop();
			for (auto&& [i, w] : adj[j]) {
				if (dp[j] + min(a[j], md - dp[j]) >= w) dp[i] = cumin(dp[i], dp[j] + min(a[j], md - dp[j]));
			}
		}
		if (dp[0] != -1) {
			ng = md, res = md;
		} else {
			ok = md + 1;
		}
	}
	return res;
}

int solve() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) vector<PI>().swap(adj[i]);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	int upp = 0;
	for (int u, v, w; m--;) {
		scanf("%d%d%d", &u, &v, &w);
		u--;
		v--;
		adj[v].emplace_back(u, w);
		upp = max(upp, w);
	}
	//BS on answer
	return search(0, upp + 1, n);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) printf("%d\n", solve());
}
