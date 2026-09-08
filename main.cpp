#include<bits/stdc++.h>
using namespace std;
vector<int>adj[10];
int f[1<<10], K;
//min (f[subset] - sum c[i in subset])
//subset != empty!!!!!
vector<pair<int,int>> nx_cond(vector<pair<int,int>> cond,int c) {
  for(auto &[i,v]:cond) {
    if(i>>c&1 && (v-- == 0))return {{1023, -1}};
  }
  return cond;
}
void dfs(int first, int rem,vector<pair<int,int>>cond,string &s) {
  erase_if(cond, [&](pair<int, int> x) {return x.second >= rem;});
	if(cond.empty())return;
	if(rem==0){
	  cout<<s<<" \n"[--K == 0];
	  if(K==0) exit(0);
	} else {
		int mask=0;
		if(ranges::min(cond | views::values)==rem-1) {
		  for(auto [i,v]:cond){
		    if(v==rem-1)
          mask |= i;
      }
		} else {
			mask=1023;
		}
		for(int d=first;d<10;++d) {
			if(~mask>>d&1)continue;
			s += d+'0';
      dfs(0, rem-1,nx_cond(cond,d),s);
			s.pop_back();
		}
	}
}
int main() {
	cin.tie(nullptr)->sync_with_stdio(0);
	int N;cin>>N>>K;
	for(int i=0;i<N;++i) {
	  int mask=0;
	  for(int j=0,c;j<6;++j) {
	    cin>>c;
	    mask|=(1<<c);
    }
    for(int j=0;j<(1<<10);++j)f[j]+=bool(j&mask);
  }
	string empty="";
	for(int n=1;;++n) {
	  vector<pair<int,int>> cond;
	  for(int j=1;j<(1<<10);++j)cond.emplace_back(j,f[j]);
		dfs(1,n,cond,empty);
  }
}
