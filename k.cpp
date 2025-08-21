#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<int>& tag, const vector<int>& adj) {
	tag[u] = 1;
	if (adj[u] >= 0 && !tag[u])
		dfs(adj[u], tag, adj);
}

void solve() {
	//suppose at x at time t, k|(|x-pi|+t-di), turn around
	//+: k|(pi-x+t-di), group traffic lights by (pi-di)%k
	//will collide with (x-t)%k group
	//-: k|(x+t-pi-di), (pi+di)%k
	//(x+t)%k group
	//build a graph with nodes (i, +/-)
	//every node with <= 1 out edge
	int n;
	long long k;
	cin >> n >> k;
	vector<long long> p(n), d(n);
	for (auto& x : p) cin >> x;
	for (auto& x : d) cin >> x;
	vector<vector<int>> pos(k), neg(k);
	for (int i = 0; i < n; ++i) {
		pos[(p[i] + k - d[i] % k) % k].push_back(i);
		neg[(p[i] + d[i]) % k].push_back(i);
	}
	vector<int> dd(2 * n), adj(2 * n, -1);
	auto find = [&](const vector<int>& vec, long long x) {
		int l = 0, r = (int) vec.size() - 1, res = (int) vec.size();
		while (l <= r) {
			int m = (l + r) / 2;
			if (p[vec[m]] >= x) {
				r = m - 1, res = m;
			} else {
				l = m + 1;
			}
		}
		return res;
	};
	for (int i = 0; i < n; ++i) {
		auto& vec = pos[(p[i] + k - d[i] % k) % k];
		int j = find(vec, p[i] + 1);
		if (j < (int) vec.size()) {
			adj[i + n] = vec[j];
			dd[vec[j]]++;
		}
		vec = neg[(p[i] + d[i]) % k];
		j = find(vec, p[i]);
		if (j > 0) {
			adj[i] = vec[j] + n - 1;
			dd[vec[j] + n - 1]++;
		}
	}
	vector<int> tag(2 * n);
	for (int i = 0; i < 2 * n; ++i) {
		if (dd[i] == 0 && !tag[i])
			dfs(i, tag, adj);
	}
	for (int i = 0; i < 2 * n; ++i) {
		if (!tag[i]) tag[i] = 2;
	}
	int q;
	cin >> q;
	while (q--) {
		long long x;
		cin >> x;
		const auto& vec = pos[x % k];
		int j = find(vec, x);
		if (j < (int) vec.size()) {
			cout << (tag[vec[j]] == 2 ? "NO\n" : "YES\n");
		} else {
			cout << "9YES\n";
		}
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) solve();
}
