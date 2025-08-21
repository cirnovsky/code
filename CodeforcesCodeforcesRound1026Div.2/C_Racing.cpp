// time-limit: 2000
// problem-url: https://codeforces.com/contest/2110/problem/C
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;
int l[N], r[N], d[N];

void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &d[i]);
	for (int i = 0; i < n; ++i) scanf("%d%d", &l[i], &r[i]);
	int cur = 0;
	vector<int> prev;
	for (int i = 0; i < n; ++i) {
		if (d[i] == -1) prev.push_back(i);
		else cur += d[i];
		while (cur < l[i]) {
			if (prev.empty()) {
				puts("-1");
				return;
			}
			cur++;
			d[prev.back()] = 1;
			prev.pop_back();
		}
		while (cur + (int) prev.size() > r[i]) {
			if (prev.empty()) {
				puts("-1");
				return;
			}
			d[prev.back()] = 0;
			prev.pop_back();
		}
	}
	for (int i = 0; i < n; ++i)
		printf("%d%c", max(0, d[i]), " \n"[i == n - 1]);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) solve();
}
