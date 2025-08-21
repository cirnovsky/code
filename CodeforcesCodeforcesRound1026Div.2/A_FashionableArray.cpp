// time-limit: 1000
// problem-url: https://codeforces.com/contest/2110/problem/A
#include <bits/stdc++.h>
using namespace std;

const int N = 50;
int a[N];

int solve() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	sort(a, a + n);
	int odd_pref = 0, even_pref = 0, odd_suf = n, even_suf = n;
	for (; odd_pref < n; ++odd_pref) {
		if (a[odd_pref] % 2 == 0) break;
	}
	for (; even_pref < n; ++even_pref) {
		if (a[even_pref] % 2 == 1) break;
	}
	for (; odd_suf-- >= 0;) {
		if (a[odd_suf] % 2 == 0) {
			odd_suf++;
			break;
		}
	}
	for (; even_suf-- >= 0;) {
		if (a[even_suf] % 2 == 1) {
			even_suf++;
			break;
		}
	}
	// odd+odd
	int res = even_pref + n - even_suf;
	// even+even
	res = min(res, odd_pref + n - odd_suf);
	return res;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) printf("%d\n", solve());
}
