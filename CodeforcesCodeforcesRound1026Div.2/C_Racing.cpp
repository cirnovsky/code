// time-limit: 2000
// problem-url: https://codeforces.com/contest/2110/problem/C
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;
int l[N], r[N], d[N], suf[N], zero[N + 1];

void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &d[i]);
	for (int i = 0; i < n; ++i) scanf("%d%d", &l[i], &r[i]);
	for (int i = 0; i < n; ++i) {
		zero[i + 1] = zero[i] + (d[i] == 0);
	}
	const int INF = 0x3f3f3f3f;
	for (int i = n; i-- > 0;) {
		suf[i] = max(i + 1 == n ? -INF : suf[i + 1], l[i] - i + zero[i + 1]);
	}
	int cur = 0;
	for (int i = 0; i < n; ++i) {
		if (d[i] != -1) {
			cur += d[i];
		} else if (suf[i] >= cur - zero[i] - i + 1) {
			cur++;
			d[i] = 1;
		} else {
			d[i] = 0;
		}
		if (!(l[i] <= cur && cur <= r[i])) {
			puts("-1");
			return;
		}
	}
	for (int i = 0; i < n; ++i) printf("%d%c", d[i], " \n"[i == n - 1]);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) solve();
}
