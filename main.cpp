#include "bits/stdc++.h"

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

void compress(vi& a){
  vi b=a;
  sort(all(b));
  b.erase(unique(all(b)), b.end());
  for(auto&x:a){
    x=lower_bound(all(b),x)-b.begin();
  }
}

using pii=pair<int,int>;
bool solve(){
  int n;
  cin>>n;
  vi a(n);
  for(int i=0;i<n;++i)cin>>a[i];
  compress(a);
  vector<vector<pii>> inters(n);
  for(int i=0,j=0;i<n;i=j){
    while(j<n&&a[i]==a[j])j++;
    inters[a[i]].emplace_back(i,j);
  }

  auto move_n_check=[&](int from,int to){
    if(0>to||n<=to)return false;
    vi b=a;
    swap(b[from],b[to]);
    vi used(n);
    for(int i=0,j=0;i<n;i=j){
      if(used[b[i]])return false;
      while(j<n&&b[i]==b[j])j++;
      used[b[i]]=true;
    }
    return true;
  };

  int count=0;
  for(auto &&arr:inters){
    if(len(arr)<=1)continue;
    if(len(arr)>3)return false;
    count++;
    if(count>2)return false;
    if(len(arr)==2){
      int i,l,r;
      if(arr[0].second-arr[0].first==1){
        i=arr[0].first;
        tie(l,r)=arr[1];
        if(move_n_check(i,l-1) || move_n_check(i,r))return true;
      }
      if(arr[1].second-arr[1].first==1){
        i=arr[1].first;
        tie(l,r)=arr[0];
        if(move_n_check(i,l-1) || move_n_check(i,r))return true;
      }
      return false;
    }else{
      int i,to;
      if(arr[0].second-arr[0].first==1){
        i=arr[0].first;
        to=arr[1].second;
        if(move_n_check(i, to))return true;
      }
      if(arr[2].second-arr[2].first==1){
        i=arr[2].first;
        to=arr[0].second;
        if(move_n_check(i, to))return true;
      }
      return false;
    }
    break;
  }
  return true;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(0);
  int t;
  cin>>t;
  while(t--)cout<<(solve()?"yes":"no")<<"\n";
}
