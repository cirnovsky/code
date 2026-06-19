#include "bits/stdc++.h"
#include <functional>

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

bool match_bits(vi v){
  int n=v.size();
  vi buck(50);
  for(auto x:v)buck[x]++;
  for(int i=1;i<=n;++i){
    int p=__builtin_popcount(i);
    buck[p]--;
  }
  for(int i:buck){
    if(i)return 0;
  }
  return 1;
}
bool has_dup(vi v){
  sort(v.begin(),v.end());
  int n=v.size();
  for(int i=1;i<n;++i){
    if(v[i]==v[i-1])return 1;
  }
  return 0;
}
ll solve(){
  int n;
  cin>>n;
  int m=0;
  while((1<<m)<=n)m++;
  vector<int>cnts(n),nums(n);
  for(int i=0;i<m;++i){
    string s;
    cin>>s;
    for(int j=0;j<n;++j){
      if(s[j]=='1'){
        cnts[j]++;
        nums[j]^=(1<<i);
      }
    }
  }
  if(has_dup(nums)||!match_bits(cnts))return 0;
  sort(cnts.begin(),cnts.end(),greater<int>());
  int pcount_of_n = __builtin_popcount(n);
  ll res=1;
  for(int i=1;i<=pcount_of_n;++i)res*=i;
  for(int i=1;i<=m-pcount_of_n;++i)res*=i;
  int j=0;
  while(j<n&&cnts[j]==cnts[0])j++;
  return res*j;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int t;
  cin>>t;
  while(t--)cout<<solve()<<"\n";
}
