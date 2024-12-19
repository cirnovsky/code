#include <bits/stdc++.h>
#include <atcoder/all>
#include <cstdio>
#include <iostream>
using namespace std;
using namespace atcoder;
#define ll long long
#define mint static_modint<mod>
#define rep(i,r) for(ll i=0;(int)(i)<(int)(r);i++)
#define rrep(i,n) for(ll (i)=(n)-1;(i)>=0;(i)--)
#define riano_ 

const ll mod = 998244353;

//Unionfind
struct unionfind {
	vector<long long> r;
    vector<int> lp;
	unionfind(long long N) {
		r = vector<long long>(N, -1);
		iota(r.begin(), r.end(), 0);
        lp = vector<int>(N,0);
	}
	long long root(long long x) {
		while (x != r[x])
			x = r[x] = r[r[x]];
		return x;
		/* if (r[x] < 0) return x; */
		/* return r[x] = root(r[x]); */
	}
	void unite(long long x, long long y) {
		x = root(x);
		y = root(y);
		if (x != y)
			r[x] = y;
		else
			lp[x] = 1;
	}
  
    // true if x, y are in same connected component
    bool connected(long long x, long long y) { 
        long long rx = root(x);
        long long ry = root(y);
        return rx == ry;
    }
    // true if the connnected component is not tree
    bool loop(ll x){
        return lp[root(x)];
    }
};

//binomial_coefficient
vector<mint> fact;
vector<mint> invf;
mint binom(ll n,ll k){
    if(n<0||k<0||k>n) return 0;
    else{
        mint a = fact[n]*invf[k];
        a = a*invf[n-k];
        return a;
    }
}

// #(B vertices to b paths)
mint divide_count(ll B,ll b){
    if(B==0&&b==0) return 1;
    return fact[B]*binom(B-1,b-1)*invf[b];
}

const int MD = mod;

int solve(int b, int w, int g)
{
	int res = 0;
	int s, w_, b_;

	for (s = 0; s <= min(b, w); ++s) {
		int s0 = 0, s1 = 0;
		mint bs, ws;
		for (b_ = s; b_ <= b; ++b_) {
			if (g + s - b_ < 0)
				break;
			int tmp = 1;

			if (b || b_)
				tmp = (long long) fact[b].val() * binom(b - 1, b_ - 1).val() % MD * invf[b_].val() % MD;
			tmp = divide_count(b, b_).val();
			s0 += (long long) tmp * binom(b_, s).val() % MD * fact[g].val() % MD * invf[g + s - b_].val() % MD;
		    bs += tmp*binom(b_,s)*fact[g]*invf[g+s-b_]; // select s paths from b paths + connect (b-s) paths to G paths
		}
		for (w_ = s; w_ <= w; ++w_) {
			if (g + s - w_ < 0)
				break;
			int tmp = 1;

			if (w || w_)
				tmp = (long long) fact[w].val() * binom(w - 1, w_ - 1).val() % MD * invf[w_].val() % MD;
			tmp = divide_count(w, w_).val();
			s1 += (long long) tmp * fact[w_].val() % MD * invf[w_ - s].val() % MD * fact[g + s].val() % MD * invf[g + s - w_].val() % MD;
		    ws += tmp*fact[w_]*invf[w_-s]*fact[g+s]*invf[g+s-w_]; // connect s paths to w paths + connect w paths to (G+s) paths
		}
		res += (fact[g]*bs*ws).val();
		res %= MD;
		/* res = (res + (long long) fact[g].val() * s0 % MD * s1 % MD) % MD; */
	}
	return res;
}
/* mint solve(ll B,ll W,ll G){ */
/*     mint res = 0; */
/*     rep(s,min(B,W)+1){ // s:#(b->w) */
/*         mint bs = 0,ws = 0; */
/*         for(ll b=s;b<=B;b++){ */
/*             if(G+s-b<0) break; */
/*             mint p = divide_count(B,b); */
/*             bs += p*binom(b,s)*fact[G]*invf[G+s-b]; // select s paths from b paths + connect (b-s) paths to G paths */
/*         } */
/*         for(ll w=s;w<=W;w++){ */
/*             if(G+s-w<0) break; */
/*             mint p = divide_count(W,w); */
/*             ws += p*fact[w]*invf[w-s]*fact[G+s]*invf[G+s-w]; // connect s paths to w paths + connect w paths to (G+s) paths */
/*         } */
/*         res += fact[G]*bs*ws; */
/*     } */
/*     return res; */
/* } */

int main(){
    riano_; mint ans = 0;
    // pre-calculation for binomial_coefficient
    ll max_val = 6001;
    fact.assign(max_val+1,mint(1));
    invf.assign(max_val+1,mint(1));
    rep(i,max_val) fact[i+1] = fact[i]*mint(i+1);
    invf[max_val] = fact[max_val].inv();
    rrep(i,max_val) invf[i] = invf[i+1]*mint(i+1);

    ll N; cin >> N;
    vector<ll> a(N),b(N);
    rep(i,N) cin >> a[i];
    rep(i,N) cin >> b[i];

    bool ok = true;
    unionfind uf(N);
    vector<bool> use(N+1,false);
    rep(i,N){
        ll x = (a[i]-1)/2;
        if(use[x]) ok = false;
        use[x] = true;
        rep(j,N){
            ll y = (b[j]-1)/2;
            if(x==y) uf.unite(i,j);
        }
    }

    ll B = 0,W = 0,G = 0;
    rep(i,N){
        if(uf.root(i)!=i) continue;
        ll b = 0,w = 0;
        rep(j,N){
            if(uf.connected(i,j)){
                if(a[j]%2==0) b++;
                else w++;
            }
        }

        if(uf.lp[uf.root(i)] && b*w==0){
			ok=false;
        }
		else if (!uf.lp[uf.root(i)])
			if(b==0) W++;
			else if(w==0) B++;
			else G++;
    }

    if(!ok){
        cout << 0 << endl; return 0;
    }

	cout<<solve(B, W, G);
    /* cout << solve(B,W,G).val() << endl; */
}
