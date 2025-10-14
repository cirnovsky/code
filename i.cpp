#include <set>
#include <map>
#include <queue>
#include <numeric>
#include <limits.h>
#include <assert.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
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
#define all(u) (u).begin(), (u).end()
#define part(u, l, r) (u).begin() + (l), (u).begin() + (r)
#define slice(u, l, r) vi(part(u, l, r))
#define len(u) ((int) (u).size())
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
void rd(Tp& x, Args&... args) { rd(x), rd(args...); }
template <typename Tp>
void rds(Tp* v, int n) { for (int i = 0; i < n; ++i) rd(v[i]); }
template <typename Tp>
void rds(std::vector<Tp> &v) { for (Tp& x : v) rd(x); }
template <typename Tp>
void prts(std::vector<Tp> &v, char sep=' ', char end='\n') {
	const int n = v.size();
	if (n == 0) { std::cout << end; return; }
	for (int i = 0; i < n - 1; ++i) std::cout << v[i] << sep;
	std::cout << v[n - 1] << end;
}
template <typename Tp>
Tp& cmax(Tp& x, const Tp& y) { return x = std::max(x, y); }
template <typename Tp>
Tp& cmin(Tp& x, const Tp& y) { return x = std::min(x, y); } // }}}

using namespace std;

int query(set<int> & st) {
	cout << "? " << len(st);
	for (int i : st)
		cout << " " << i + 1;
	cout << endl;
	int r;
	cin >> r;
	return r;
}

void solve() {
	int n;
	cin >> n;
	set<int> st;
	vi ans(2 * n, -1);
	rep(i,2*n) {
		st.insert(i);
		int res = query(st);
		if (res > 0) {
			ans[i] = res;
			st.erase(i);
		}
	}
	set<int>().swap(st);
	rep(i,2*n) {
		if (ans[i] >= 0)
			st.insert(i);
	}
	rep(i,2*n) {
		if (ans[i] == -1) {
			st.insert(i);
			ans[i] = query(st);
			st.erase(i);
		}
	}
	cout << "!";
	for (int x : ans)
		cout << " " << x;
	cout << endl;
}

int main() {
#ifdef ONLINE_JUDGE
	cin.tie(nullptr)->sync_with_stdio(0);
#endif
	int t;
	cin >> t;
	while (t--)
		solve();
}
