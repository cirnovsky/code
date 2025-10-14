
#include <assert.h>
#include <string>
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
#define all(u) (u).begin(), (u).end()
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
void rd(Tp& x, Args&... args) {
	rd(x), rd(args...);
}
template <typename Tp>
void rds(Tp* v, int n) {
	for (int i = 0; i < n; ++i)
		rd(v[i]);
}
template <typename Tp>
void rds(std::vector<Tp> &v) {
	for (Tp& x : v)
		rd(x);
}
template <typename Tp>
void prts(std::vector<Tp> &v, char sep=' ', char end='\n') {
	const int n = v.size();

	if (n == 0) {
		std::cout << end;
		return;
	}
	for (int i = 0; i < n - 1; ++i)
		std::cout << v[i] << sep;
	std::cout << v[n - 1] << end;
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

#ifdef LOCAL
const int kv=50;
#else
const int kv = 1e6;
#endif

struct Node {
	int ok, ng;
	Node *ls, *rs;
	int ladd;
	int mn;
	Node() : mn(11451419) {}
	Node(vi &v, int ok, int ng) : ok(ok), ng(ng) {
		if (ok + 1 < ng) {
			int md = ok + (ng - ok) / 2;
			ls = new Node(v, ok, md);
			rs = new Node(v, md, ng);
			pull();
		} else mn = v[ok];
	}
	void pull() { mn = min(ls->mn, rs->mn); }
	void put(Node *node, int x) {
		if (!node) return;
		node->ladd += x;
		node->mn += x;
	}
	void push() {
		if (ladd)
			put(ls, ladd), put(rs, ladd), ladd =0;
	}
	void update(int l, int r, int x) {
		if (ok >= r || ng <= l) return;
		else if (ok >= l && ng <= r) return put(this, x);
		push(), ls->update(l, r, x), rs->update(l, r, x), pull();
	}
	int query() {
		push();
		if (ok + 1  == ng) return ok;
		else if (ls->mn <= 0) return ls->query();
		return rs->query();
	}
	void prt() {
		if (ok+1 == ng) {
			cout<<" "<<mn;
			if (ok == kv)
				cout << endl;
			return;
		}
		push();
		ls->prt(), rs->prt();
	}
};

int main() {
	cin.tie(nullptr)->sync_with_stdio(0);
	int ia, id, n;
	rd(ia, id, n);
	vi a(n), d(n);
	rds(a), rds(d);
	//let df[i] = max(a[i] - ia, 0) + max(d[i] - id, 0)
	//let cnt[k] = #i st df[i] <= k
	//find smallest j st cnt[j] <= j
	//let base[k] = #i st df[i] == k
	vi tmp(kv + 1);
	rep(i,kv+1)
		tmp[i] = -i;
	Node *rt = new Node(tmp, 0, kv + 1);
	rep(i,n) {
		int df = max(a[i] - ia, 0) + max(d[i] - id, 0);
		rt->update(0, df + 1, 1);
	}
	int q; rd(q); while (q--) {
		int i, na, nd;
		rd(i, na, nd);
		i--;
		int df = max(a[i] - ia, 0) + max(d[i] - id, 0);
		a[i] = na;
		d[i] = nd;
		int df_ = max(a[i] - ia, 0) + max(d[i] - id, 0);
		rt->update(0, df + 1, -1);
		rt->update(0, df_ + 1, 1);
	rt->prt();
		cout << rt->query() << "\n";
	}
}
