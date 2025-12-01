
#include <bits/stdc++.h>

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

vi cnm;
int mex(int l, int r) {
	auto tmp = slice(cnm, l, r);
	sort(all(tmp));
	if (tmp[0])
		return 0;
	for (int i=0;i+1<r-l;++i) {
		if (tmp[i+1] != tmp[i]+1)
			return tmp[i]+1;
	}
	return tmp.back() + 1;
}

using P = pair<int, int> ;
int main() {
	cin.tie(nullptr)->sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		int n, q;
		cin >> n >> q;
		vector<P> qs(q);
		for (auto &[l, r] : qs)
			cin >> l >> r, l--;
		cnm = vi(n); rds(cnm);
		int ans = 0;
		for (auto [l, r] : qs) {
			debug(l, r,mex(l, r));
			cmax(ans, mex(l, r));
		}
		cout << ans << "\n";
	}
}
