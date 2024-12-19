/// {{{
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using db = double;
using ldb = long double;

#define pb push_back
#define eb emplace_back
#define mkp make_pair
#define allu(u) (u).begin(), (u).end()
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define rng(l, r) uniform_int_distribution<ll>(l, r)(rnd)

#define rep1(n) for (int _ = 0; _ < n; ++_)
#define rep2(i, n) for (int i = 0; i < (n); ++i)
#define rep3(i, l, h) for (auto i = (l); i < (h); ++i)
#define rep4(i, l, h, d) for (auto i = (l); i < (h); i += (d))
#define drep1(n) for (int _ = (n)-1; _ >= 0; --_)
#define drep2(i, n) for (int i = (n)-1; i >= 0; --i)
#define drep3(i, h, l) for (auto i = (h)-1; i >= l; --i)
#define drep4(i, h, l, d) for (auto i = (h)-1; i >= l; i -= (d))
#define __overload(a, b, c, d, e, ...) e
#define rep(...) __overload(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define drep(...) __overload(__VA_ARGS__, drep4, drep3, drep2, drep1)(__VA_ARGS__)

using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using bsi = basic_string<int>;
template <typename Tp> using vt = vector<Tp>;
template <typename Tp> using bst = basic_string<Tp>;

template <typename Tp> void rd(Tp& x) { cin >> x; }
template <typename Tp, typename... Args> void rd(Tp& x, Args&... args) { rd(x), rd(args...); }
template <typename Tp> void rds(Tp* v, int n) { for (int i=0;i<n;++i) rd(v[i]); }
template <typename Tp> void rds(vector<Tp>& v) { for (Tp& x : v) rd(x); }
template <typename Tp>
Tp& cmax(Tp& x, const Tp& y) {
    return x = max(x, y);
}
template <typename Tp>
Tp& cmin(Tp& x, const Tp& y) {
    return x = min(x, y);
} // }}}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}
