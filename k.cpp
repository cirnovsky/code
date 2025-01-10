#include<bits/stdc++.h>
 
using namespace std;
 
vector<vector<int>> g;
int color[2001];

bool dfs(int v)
{
	color[v] = 2;
	bool res = false;
	for(auto y : g[v])
	{
	    if(color[y] == 0)
		res |= dfs(y);
	    else if (color[y] == 2) res = true;
	}
	color[v] = 1;
	return res;
}

void add_edge(int x, int y)
{
	g[x].push_back(y);
}
 
int get_bit(int x, int y)
{
    return (x >> y) & 1;
}
 
bool check(const vector<vector<int>>& a, const vector<vector<int>>& b, int k)
{
    int n = a.size();
    int m = a[0].size();
    vector<bool> must_row(n);
    vector<bool> must_col(m);
    vector<vector<int>>(n + m).swap(g);
    for (int i = 0; i < n + m; ++i)
	    color[i] = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            if(get_bit(a[i][j], k) != get_bit(b[i][j], k))
            {
                if(get_bit(b[i][j], k) == 0) must_row[i] = true;
                else must_col[j] = true;
            }
            if(get_bit(b[i][j], k) == 0) add_edge(j + n, i);
            else add_edge(i, j + n);
        }                 
    for(int i = 0; i < n; i++)
        if(must_row[i] && !color[i] && dfs(i))
            return false;
    for(int j = 0; j < m; j++)
        if(must_col[j] && !color[j + n] && dfs(j + n))
            return false;
    return true;
}
 
void solve()
{
    int n, m;
    scanf("%d %d", &n, &m);
    vector<vector<int>> a(n, vector<int>(m));
    auto b = a;
    int h = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &a[i][j]), h = max(h, a[i][j]);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &b[i][j]), h = max(h, b[i][j]);
    for(int i = 0; (1 << i) <= h; i++)
    {
        if(!check(a, b, i))
        {
            puts("No");
            return;
        }
    }
    puts("Yes");
}
 
int main()
{                             
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++) solve();
}
