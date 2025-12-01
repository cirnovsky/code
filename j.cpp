

#include <bits/stdc++.h>

// {{{ definitions
using ll = long long; using ull = unsigned long long; using db = double; using ldb = long double;

#define all(u) (u).begin(), (u).end()
#define part(u, l, r) (u).begin() + (l), (u).begin() + (r)
#define slice(u, l, r) vi(part(u, l, r))
#define len(u) ((int) (u).size())
std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
#define rng(l, r) std::uniform_int_distribution<ll>(l, r - 1)(rnd)

using vi = std::vector<int>; using vvi = std::vector<vi>; using vll = std::vector<ll>; using vvll = std::vector<vll>; using bsi = std::basic_string<int>; template <typename Tp> using vt = std::vector<Tp>; template <typename Tp> using bst = std::basic_string<Tp>;

template <typename Tp> void rd(Tp& x) { std::cin >> x; }
template <typename Tp, typename... Args> void rd(Tp& x, Args&... args) { rd(x), rd(args...); }
template <typename Tp> void rds(Tp* v, int n) { for (int i = 0; i < n; ++i) rd(v[i]); }
template <typename Tp> void rds(std::vector<Tp> &v) { for (Tp& x : v) rd(x); }
template <typename Tp> Tp& cmax(Tp& x, const Tp& y) { return x = std::max(x, y); }
template <typename Tp> Tp& cmin(Tp& x, const Tp& y) { return x = std::min(x, y); } // }}}

using namespace std;

#ifdef LOCAL
#include "t/dbg"
#else
#define debug(x...)
#endif
void solve() {
	// most shitty problem
	int n, q;
	rd(n, q);
	string s;
	cin >> s;
	int base = 0;
	for (int i = 0; i < n; ++i) {
		char cur = s[i], nxt = i + 1 < n ? s[i + 1] : '.';
		if (cur == 'X')
			base += 10;
		else if (cur == 'V')
			base += 5;
		else if (cur == 'I')
			cur += nxt == 'X' || nxt == 'V' ? -1 : 1;
	}

	int i_xv = 0, i_ = 0, _xv = 0, __ = 0, _ = 0;
	for (int i = 0; i < n; ++i) {
		int lc = i > 0 ? s[i - 1] : '.', rc = i + 1 < n ? s[i + 1] : '.';
		if (s[i] == '?') {
			if (lc == 'I' && (rc == 'X' || rc == 'V'))
				i_xv++, s[i] = '.';
			else if (lc == 'I')
				i_++, s[i] = '.';
			else if (rc == 'X' || rc == 'V')
				_xv++, s[i] = '.';
		}
	}
	for (int i = 0; i < n; ++i) {
		if (s[i] == '?' && i + 1 < n && s[i + 1] == '?')
			__++;
	}
	_ = count(all(s), '?');

	int total = i_xv + i_ + _xv + 2 * __ + _;

	while (q--) {
		int __i_xv = i_xv, __i_ = i_, ___xv = _xv, ____ = __, ___ = _;

		int cx, cv, vi;
		rd(cx, cv, ci);

		int cxv = cx + cv;
		int ui = min(total, vi), uxv = total - ui;

		int delta = 5 * min(uxv, cv) + 10 * max(uxv - cv, 0);

		assert(uxv <= cxv);
		// ui = #I used
		// uxv = #X/V used
		// prepend I to existing X/V
		// append X/V to existing I
		// fill a pair of adjacent vacancies with I(X/V)

		int Ii_xv = min(ui, i_xv);
		ui -= Ii_xv, i_xv -= Ii_xv;

		int XVi_xv = min(uxv, i_xv);
		uxv -= XVi_xv, i_xv -= XVi_xv;

		assert(i_xv == 0);


		i_xv = __i_xv, i_ = __i_, _xv = ___xv, __ = ____, _ = ___;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--)
		solve();
}
