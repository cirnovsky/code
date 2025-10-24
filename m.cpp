
#include <cassert>
#include <iostream>
#include <numeric>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

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
template <typename Tp> void prts(std::vector<Tp> v, char sep=' ', char end='\n') { const int n = v.size(); if (n == 0) { std::cout << end; return; } for (int i = 0; i < n - 1; ++i) std::cout << v[i] << sep; std::cout << v[n - 1] << end; }
template <typename Tp> Tp& cmax(Tp& x, const Tp& y) { return x = std::max(x, y); }
template <typename Tp> Tp& cmin(Tp& x, const Tp& y) { return x = std::min(x, y); } // }}}

using namespace std;

#ifdef LOCAL
#include "t/dbg"
#else
#define dbg(x...)
#endif

ll solve() {
	int n, k;
	cin >> n >> k;
	vll a(n);
	rds(a);
	//median > mean
	sort(a.begin(), a.end());
	//x must be odd
	//guessing the same median is used
	//enumerate median ai and length 2y+1
	//a[0..y)..a[i]..a[i+1,i+y]
	//y*a[i]-a[0..y)+y*a[i]-a[i+1,i+y]
	//2y*a[i]-a[0..y)-a[i+1,i+y]
	//b[y]=a[0..y)+a[i+1,i+y]
	//y<=i
	//i+y+1<=n
	//y<n-i
	//0<=y<=min(i,n-i-1)
	//2y*a[i]-b[y]
	//2a[i]-(b[y]-b[y-1])=2a[i]-(a[y-1]+a[i+y]),y>=1
	vll b(n+1);
	for (int i = 1; i <= n; ++i)
		b[i] = b[i-1] + a[i-1] + a[n-i];
	vll pre(n+1);
	for (int i = 0; i < n; ++i)
		pre[i+1] = pre[i] + a[i];
	ll res = accumulate(all(a), 0ll), base = res;
	for (int i = 0; i < n; ++i) {
		int l = 1, r = min(i, n-i-1), y = r+1;
		//1 1 1 2 2 3
		while (l <= r) {
			int m = (l+r)/2;
			int L = k*(m-1), R = k*m;
			cmin(L, i);
			cmin(R, i);
			debug(i, L, R);
			if (2*a[i] - pre[R] + pre[L] - a[i+m] < 0)
				y = m, r = m-1;
			else
				l = m+1;
		}
		y--;
		dbg(i, y);
		cmax(res, base + 2*y*a[i] - b[y]);
	}
	return res;
}

int main()
{
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(0);
#endif
	int t;
	cin >> t;
	while (t--)
		cout << solve() << "\n";
}
