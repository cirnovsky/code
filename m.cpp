// X1(a) X2(b)
// Y1(c) Y2(d)
// X1*Y1 -> X2*Y2
// X1*Y2 -> X2*Y1

#include <bits/stdc++.h>

using namespace std;

const int N = 2e5;
int xx[N], yy[N], tmp[N], tmp2[N], rev[N], rev2[N];

void solve()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d", &xx[i], &yy[i]);
	}
	iota(tmp, tmp + n, 0);
	iota(tmp2, tmp2 + n, 0);
	sort(tmp, tmp + n, [&](int i, int j)
			{
			return xx[i] < xx[j];
			});
	sort(tmp2, tmp2 + n, [&](int i, int j)
			{
			return yy[i] < yy[j];
			});
	for (int i = 0; i < n; ++i)
	{
		rev[tmp[i]] = i;
		rev2[tmp2[i]] = i;
	}
	vector<int> cat[4];
	for (int i = 0; i < n; ++i)
	{
		cat[(rev[i] < n / 2) << 1 | (rev2[i] < n / 2)].push_back(i);
	}
	for (int i = 0; i < (int) cat[2].size(); ++i)
	{
		printf("%d %d\n", cat[2][i] + 1, cat[1][i] + 1);
	}
	for (int i = 0; i < (int) cat[3].size(); ++i)
	{
		printf("%d %d\n", cat[3][i] + 1, cat[0][i] + 1);
	}
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
