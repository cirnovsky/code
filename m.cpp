/**
 * x = d(lca, u), y = d(lca, v), 2 * y - 1
 * min(d(lca, u), d(lca, v)) * 2 - 1 = (min(d(u), d(v)) - d(lca)) * 2 - 1 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <random>
#include <chrono>

/// {{{ definitions
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

using namespace std;

int n, d, mod;

int exgcd(int a, int b, int &x, int &y) {
	if (!b) {
		x = 1, y = 0;
		return a;
	}
	int g = exgcd(b, a % b, y, x);
	y -= a / b * x;
	return g;
}

int inverse(int a) {
	int x, y;
	exgcd(a, mod, x, y);
	return (x % mod + mod) % mod;
}

// = n!/(k!(n-k)!) = n*(n-1)*...*(k+1)/(n-k)!
long long choose(int n, int k) {
	long long up = 1, dn = 1;
	rep(i, k)
		up *= n - i, dn *= i + 1;
	return up / dn;
}

vi

void dfs(int i) {
	
}

int main() {
	std::cin.tie(nullptr)->sync_with_stdio(0);

	return 0;
}
