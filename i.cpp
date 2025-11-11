
#include <algorithm>
#include <array>
#include <bits/stdc++.h>
#include <vector>

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
	string s;
	cin >> s;
	int n = len(s);
	int l = 0, r = n/4, ans = 0;
	vector<array<int, 4>> pos;
	auto check = [&](int k) {
		vector<int> fst, snd, p, q, tag(n);
		for (int i=0,j=0;i<n&&len(fst)<k;++i) {
			if (s[i] == 'I') {
				while (j < n && (j <= i || s[j] != 'C'))
					j++;
				if (j < n) {
					tag[j] = 1;
					fst.push_back(j++), p.push_back(i);
				}
			}
		}
		for (int i=n,j=n;i-->0&&len(snd)<k;) {
			if (s[i] == 'C' && !tag[i]) {
				while (j >= 0 && (j >= i || s[j] != 'P'))
					j--;
				if (j >= 0)
					snd.push_back(j--), q.push_back(i);
			}
		}
		if (len(fst) < k || len(snd) < k)
			return false;
		pos.clear();
		for (int i=0;i<k;++i) {
			if (fst[i] >= snd[k-i-1])
				return false;
			pos.push_back({p[i], fst[i], snd[k-i-1], q[k-i-1]});
		}
		return true;
	};
	while (l <= r) {
		int mid = (l+r)/2;
		if (check(mid)) l = mid+1, ans = mid;
		else r = mid-1;
	}
	check(ans);
	cout << ans << "\n";
	set<int> tmp;
	for (auto &&p : pos) {
		for (int i : p)
			cout << i+1 << " ";
		cout << "\n";
		
		tmp.insert(p[3]);
		tmp.insert(p[1]);
	}
	assert(len(tmp) == ans*2);
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
