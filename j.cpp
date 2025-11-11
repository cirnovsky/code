
#include <bits/stdc++.h>
#include <cassert>
#include <set>
using namespace std;

#define len(u) ((int) (u).size())

vector<array<int, 4>> ans;

bool valid(string const &s, int m) {
	vector<pair<int, int>> a, b;

	int n = len(s);
	vector<char> used(n);

	for (int i = 0, j = 0; i < n; ++i) {
		if (len(a) == m)
			break;
		if (s[i] == 'I') {
			while (j <= i)
				j++;
			while (j < n && s[j] != 'C')
				j++;
			if (j < n) {
				a.emplace_back(i, j);
				used[i] = used[j] = 1;
			}
		}
	}
	if (len(a) < m)
		return 0;
	for (int i = n, j = n; i-- > 0; ) {
		if (len(b) == m)
			break;
		if (!used[i] && s[i] == 'C') {
			while (j >= i)
				j--;
			while (j >= 0 && (s[j] != 'P' || used[j]))
				j--;
			if (j >= 0) {
				b.emplace_back(j, i);
				used[j] = used[i] = 1;
			}
		}
	}
	if (len(b) < m)
		return 0;
	int i = m, j = 0;
	while (i > 0) {
		auto [p, q] = a[i-1];
		auto [u, v] = b[j];
		if (q > u)
			return 0;
		i--, j++;
	}
	for (int i = 0; i < m; ++i)
		ans.push_back({a[i].first, a[i].second, b[m-i-1].first, b[m-i-1].second});
	return 1;
}

void solve() {
	string s;
	cin >> s;
	//bs on ans
	//use first m number of Is
	int n = len(s);
	int ok = 0, ng = n/4+1;
	while (ok+1 < ng) {
		int m = ok+(ng-ok)/2;
		ans.clear();
		ans.shrink_to_fit();
		if (valid(s, m))
			ok = m;
		else
			ng = m;
	}
	ans.clear();
	ans.shrink_to_fit();
	valid(s, ok);
	set<int> tmp;
	cout << ok << "\n";
	for (auto &p : ans)
		tmp.insert(p[0]), tmp.insert(p[1]), tmp.insert(p[2]), tmp.insert(p[3]),
		cout << p[0]+1 << " " << p[1]+1 << " " << p[2]+1 << " " << p[3]+1 << "\n";
	assert(len(tmp) == 4*ok);
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--)
		solve();
}
