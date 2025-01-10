#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <random>
#include <chrono>
#include <cstring>

/// {{{ definations
using ll = long long;
using ull = unsigned long long;
using db = double;
using ldb = long double;

#define pb push_back
#define eb emplace_back
#define mkp std::make_pair
#define allu(u) (u).begin(), (u).end()
std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
#define rng(l, r) std::uniform_int_distribution<ll>(l, r - 1)(rnd)

#define rep1(n) for (int _ = 0; _ < n; ++_)
#define rep2(i, n) for (int i = 0; i < (n); ++i)
#define rep3(i, l, h) for (auto i = (l); i < (h); ++i)
#define rep4(i, l, h, d) for (auto i = (l); i < (h); i += (d))
#define drep1(n) for (int _ = (n) - 1; _ >= 0; --_)
#define drep2(i, n) for (int i = (n) - 1; i >= 0; --i)
#define drep3(i, h, l) for (auto i = (h) - 1; i >= l; --i)
#define drep4(i, h, l, d) for (auto i = (h) - 1; i >= l; i -= (d))
#define __overload(a, b, c, d, e, ...) e
#define rep(...) __overload(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define drep(...) __overload(__VA_ARGS__, drep4, drep3, drep2, drep1)(__VA_ARGS__)

using vi = std::vector<int>;
using vvi = std::vector<vi>;
using vll = std::vector<ll>;
using vvll = std::vector<vll>;
using bsi = std::basic_string<int>;
template <typename Tp>
using vt = std::vector<Tp>;
template <typename Tp>
using bst = std::basic_string<Tp>;

template <typename Tp> void rd(Tp& x) { std::cin >> x; }
template <typename Tp, typename... Args>
void rd(Tp& x, Args&... args) {
	rd(x), rd(args...);
}
template <typename Tp>
void rds(Tp* v, int n) {
	for (int i = 0; i < n; ++i)
		rd(v[i]);
}
template <typename Tp>
void rds(std::vector<Tp>& v) {
	for (Tp& x : v)
		rd(x);
}
template <typename Tp>
Tp& cmax(Tp& x, const Tp& y) {
	return x = std::max(x, y);
}
template <typename Tp>
Tp& cmin(Tp& x, const Tp& y) {
	return x = std::min(x, y);
} // }}}

const int N = 1e3;

vvi adj;
int kk[N * 2];

int dfs(int i) {
	kk[i] = 2;

	int res = 0;
	for (int j : adj[i])
		if (kk[j] == 0)
			res |= dfs(j);
		else if (kk[j] == 2)
			res = 1;
		
	kk[i] = 1;
	return res;
}

int main() {
	std::cin.tie(nullptr)->sync_with_stdio(0);

	int t; rd(t); while (t--) {
		int n, m;
		rd(n, m);

		vvi aa(n, vi(m)), bb(n, vi(m));
		int h = 0, ans = 1;
		rep(n)
			rds(aa[_]), cmax(h, *std::max_element(allu(aa[_])));
		rep(n)
			rds(bb[_]), cmax(h, *std::max_element(allu(bb[_])));

		auto solve = [&](int bit) -> int {
			vvi(n + m).swap(adj);
			memset(kk, 0, (n + m) * sizeof *kk);
			vi row(n), col(m);
		

			rep(i, n)
				rep(j, m)
					if ((aa[i][j] >> bit & 1) != (bb[i][j] >> bit & 1)) {
						if (aa[i][j] >> bit & 1)
							row[i] = 1;
						else
							col[j] = 1;
					}

			rep(i, n)
				rep(j, m)
					if ((bb[i][j] >> bit & 1) == 0)
						adj[j + n].pb(i);
					else
						adj[i].pb(j + n);

			rep(i, n)
				if (row[i] && !kk[i] && dfs(i))
					return false;
			rep(j, m)
				if (col[j] && !kk[j + n] && dfs(j + n))
					return false;
			return true;

		};

		for (int k = 0; (1 << k) <= h; ++k)
			ans &= solve(k);
		std::cout << (ans ? "YES" : "NO") << '\n';
	}

	return 0;
}
