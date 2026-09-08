#include "bits/stdc++.h"
using namespace std;
int T;
int n,k;
int p[200010];
int q[200010];
int ps[200010];
int N;
struct node{
    int v;
    int ty;
    //0 1 2
    //1
    //1 2 0
    //2
    //2 0 1
}d[200010];
int V(int ps,node x)
{
    int v=p[ps];
    if(v<x.v) return ((v-1)^1)+1;
    else if(v>x.v+2) return v^1;
    else
    {
        if(x.ty==1)
        {
            if(v==x.v) return x.v+1;
            if(v==x.v+1) return x.v+2;
            if(v==x.v+2) return x.v;
        }
        else
        {
            if(v==x.v) return x.v+2;
            if(v==x.v+1) return x.v;
            return x.v+1;
        }
    }
}
int mp[800010];
void build(int id,int l,int r)
{
    if(l==r) return mp[id]=ps[l],void();
    int mid=l+r>>1;
    build(id<<1,l,mid);
    build(id<<1|1,mid+1,r);
    mp[id]=min(mp[id<<1],mp[id<<1|1]);
}
int mps(int id,int l,int r,int u,int v)
{
    if(l==u && r==v) return mp[id];
    int mid=l+r>>1;
    if(v<=mid) return mps(id<<1,l,mid,u,v);
    else if(u>mid) return mps(id<<1|1,mid+1,r,u,v);
    else return min(mps(id<<1,l,mid,u,mid),mps(id<<1|1,mid+1,r,mid+1,v));
}
bool cmp(node x,node y)
{
    vector<int>sp;
    sp.push_back(ps[x.v]);
    sp.push_back(ps[x.v+1]);
    sp.push_back(ps[x.v+2]);
    sp.push_back(ps[y.v]);
    sp.push_back(ps[y.v+1]);
    sp.push_back(ps[y.v+2]);
    int vl=min(x.v,y.v)+3;
    int vr=max(x.v,y.v)-1;
    if(vl<=vr) sp.push_back(mps(1,1,n,vl,vr));
    sort(sp.begin(),sp.end());
    for(int s:sp)
    {
        if(V(s,x)==V(s,y)) continue;
        if(V(s,x)<V(s,y)) return 1;
        return 0;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>T;
    while(T--)
    {
        cin>>n>>k;
        for(int i=1;i<=n;++i) cin>>p[i];
        for(int i=1;i<=n;++i) ps[p[i]]=i;
        build(1,1,n);
        if(n&1)
        {
            if(k>n-1) cout<<-1<<'\n';
            else
            {
                for(int i=1;i+2<=n;i+=2)
                {
                    d[i]=node{i,1};
                    d[i+1]=node{i,2};
                }
                sort(d+1,d+n,cmp);
                for(int i=1;i<d[k].v;++i)
                    q[ps[i]]=((i-1)^1)+1;
                for(int i=d[k].v+3;i<=n;++i)
                    q[ps[i]]=i^1;
                if(d[k].ty==1)
                {
                    int v=d[k].v;
                    q[ps[v]]=v+1;
                    q[ps[v+1]]=v+2;
                    q[ps[v+2]]=v;
                }
                else
                {
                    int v=d[k].v;
                    q[ps[v]]=v+2;
                    q[ps[v+1]]=v;
                    q[ps[v+2]]=v+1;
                }
                for(int i=1;i<=n;++i) cout<<q[i]<<' ';
                cout<<'\n';
            }
        }
        else
        {
            if(k>1) cout<<-1<<'\n';
            else
            {
                for(int i=1;i<=n;++i) p[i]=((p[i]-1)^1)+1;
                for(int i=1;i<=n;++i) cout<<p[i]<<' ';
                cout<<'\n';
            }
        }
    }
    return 0;
}