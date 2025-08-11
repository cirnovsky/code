// dp[i][s] + t + 1 -> dp[son[i][(s + t) % deg[i]]][s + t + 1]

#include <bits/stdc++.h>

using namespace std;

const int N = 5e3;
vector<int> adj[N];
int f0[N], f1[N];

void solve()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0, u, v; i < m; ++i)
	{
		scanf("%d%d", &u, &v);
		u--;
		v--;
		adj[u].push_back(v);
	}
	const int INF = 0x3f3f3f3f;
	memset(f0, 0x3f, n * sizeof *f0);
	f0[0] = 0;
	int t;
	for (t = 0; t <= n; ++t)
	{
		for (int i = 0; i < n; ++i)
		{
			f1[i] = min(f1[i], f0[i] + 1);
			f1[adj[i][t % adj[i].size()]] = min(f1[adj[i][t % adj[i].size()]], f0[i]);
		}
		if (f1[n - 1] != INF)
		{
			break;
		}
		for (int i = 0; i < n; ++i)
		{
			swap(f0[i], f1[i]);
			f1[i] = INF;
		}
	}
	cout << t << " " << f1[n - 1] << "\n";
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		solve();
	}
}
