#include "bits/stdc++.h"
using namespace std;
pair<vector<int>,vector<int>>SA(string s, int lim=256) {
  vector<int> sa,lcp;
  s.push_back(0); int n=s.size(),k=0,a,b;
  vector<int> x(s.begin(), s.end()),y(n),ws(max(n,lim));
  sa = lcp = y, iota(sa.begin(), sa.end(), 0);
  for(int j=0,p=0;p<n;j=max(1,j*2),lim=p) {
    p = j, iota(y.begin(), y.end(), n - j);
    for(int i=0;i<n;++i) if(sa[i]>=j)y[p++] = sa[i]-j;
    fill(ws.begin(), ws.end(), 0);
    for(int i=0;i<n;++i) ws[x[i]]++;
    for(int i=1;i<lim;++i) ws[i]+=ws[i-1];
    for(int i=n;i--;) sa[--ws[x[y[i]]]] = y[i];
    x.swap(y), p = 1, x[sa[0]] = 0;
    for(int i=1;i<n;++i) a = sa[i-1], b = sa[i], x[b] =
      (y[a] == y[b] && y[a + j] == y[b+j]) ? p-1 : p++;
  }
  for(int i=0,j;i<n-1;lcp[x[i++]]=k)
    for(k&&k--,j=sa[x[i]-1];
        s[i+k]==s[j+k];k++);
  return make_pair(sa,lcp);
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int N;cin>>N;
  string s,t;
  for(int i=0;i<n;++i) {
    if(i)s+='#';
    cin>>t;
    s+=t;
  }
  auto [sa,hh] = SA(s);
  for(int i=0;i<s.size();++i){
    cout<<s.substr(sa[i])<<"\n";
}
