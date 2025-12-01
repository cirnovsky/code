
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

void solve() {
	ll n, q;
	cin >> n >> q;
	vll a(n);
	rds(a);
	sort(all(a));
	reverse(all(a));
	while (q--) {
		ll c; cin >> c;
		if (c == 0) {
			cout << "0\n";
			continue;
		}
		ll pcnt = __builtin_popcount(c);
		vll bins(part(a, 0, min(n, pcnt))), sums(len(bins));
		using P = pair<ll, ll>;
		priority_queue<P> pq;
		for (ll i = 0; i < len(bins); ++i)
			pq.emplace(bins[i], i);
		ll res = 0;
		for (ll k = log2(c); k >= 0; --k) {
			if (~c & (1 << k))
				continue;
			auto [bin, idx] = pq.top();
			pq.pop();
			ll ovf = max(0ll, -bin);
			sums[idx] |= 1<<k;
			ll nw = -bins[idx] + sums[idx];
			cmax(nw, 0ll);
			res += nw - ovf;
			pq.emplace(bins[idx] - sums[idx], idx);
		}
		cout << res << "\n";
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(0);
	ll t;
	cin >> t;
	while (t--)
		solve();
}
