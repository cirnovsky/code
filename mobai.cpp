
#include <bits/stdc++.h>
#include <utility>

/// {{{ definitions
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

//日你妈又读错了
void solve() {
	int n;
	cin >> n;
	vi a(n);
	rds(a);
	string target;
	cin >> target;

	int mn = 0, mx = 0;
	for (int i=0;i<n;++i) {
		if (a[mn] > a[i])
			mn = i;
		if (a[mx] < a[i])
			mx = i;
	}
	if (target[0] == '1' || target[n-1] == '1' || target[mn] == '1' || target[mx] == '1') {
		cout << "-1\n";
		return;
	}
	cout << "5\n";
	cout << 1 << " " << mn+1 << "\n";
	cout << 1 << " " << mx+1 << "\n";
	cout << mn+1 << " " << n << "\n";
	cout << mx+1 << " " << n << "\n";
	cout << min(mn, mx)+1 << " " << max(mn, mx)+1 << "\n";
}

int main()
{
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(0);
#endif
	int t;
	cin >> t;
	while (t--)
		solve();
}
