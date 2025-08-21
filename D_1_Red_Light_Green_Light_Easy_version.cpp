#include <bits/stdc++.h>
using namespace std;

using IT = vector<int>::iterator;

const int N = 2e5;
long long p[N], d[N];
int adj[N * 2], tag[N * 2], dd[N * 2];

IT bisect(IT first, IT last, long long x) {
	IT res = last;
	while (first != last) {
		IT mid = first + (last - first) / 2;
		if (p[*mid] >= x) {
			res = mid, last = mid;
		} else {
			first = mid + 1;
		}
	}
	return res;
}

void dfs(int u) {
	tag[u] = 1;
	if (adj[u] >= 0) {
		int v = adj[u];
		if (!tag[v]) dfs(v);
		else tag[u] = 2;
	}
}

void solve() {
	int n;
	long long k;
	scanf("%d%lld", &n, &k);
	for (int i = 0; i < n; ++i) scanf("%lld", &p[i]);
	for (int i = 0; i < n; ++i) scanf("%lld", &d[i]);
	//suppose at x at time t, k|(|x-pi|+t-di), turn around
	//+: k|(pi-x+t-di), group traffic lights by (pi-di)%k
	//will collide with (x-t)%k group
	//-: k|(x+t-pi-di), (pi+di)%k
	//(x+t)%k group
	vector<vector<int>> pos(k), neg(k);
	for (int i = 0; i < n; ++i) {
		pos[(p[i] + k - d[i] % k) % k].push_back(i);
		neg[(p[i] + d[i]) % k].push_back(i);
	}
	memset(dd, 0, 2 * n * sizeof *dd);
	memset(adj, -1, 2 * n * sizeof *adj);
	vector<int> out(2 * n, 0);
	for (int i = 0; i < n; ++i) {
		auto& vec = pos[(p[i] + k - d[i] % k) % k];
		auto j = bisect(vec.begin(), vec.end(), p[i] + 1);
		if (j != vec.end()) {
			out[i + n]++;
			adj[i + n] = *j;
			dd[*j]++;
		}
		vec = neg[(p[i] + d[i]) % k];
		j = bisect(vec.begin(), vec.end(), p[i]);
		if (j != vec.begin()) {
			out[i]++;
			adj[i] = *(j - 1) + n;
			dd[*(j - 1) + n]++;
		}
	}
	memset(tag, 0, 2 * n * sizeof *tag);
	for (int i = 0; i < 2 * n; ++i) {
		assert(out[i] <= 1);
		if (dd[i] == 0 && !tag[i]) dfs(i);
	}
	for (int i = 0; i < 2 * n; ++i) {
		if (!tag[i]) tag[i] = 2;
	}
	int q;
	scanf("%d", &q);
	while (q--) {
		long long x;
		scanf("%lld", &x);
		auto& vec = pos[x % k];
		auto j = bisect(vec.begin(), vec.end(), x);
		if (j != vec.end()) {
			cout << (tag[*j] == 2 ? "NO\n" : "YES\n");
		} else {
			cout << "YES\n";
		}
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) solve();
}

