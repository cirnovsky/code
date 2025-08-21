// time-limit: 1000
// problem-url: https://codeforces.com/contest/2110/problem/B
#include <bits/stdc++.h>
using namespace std;

const int N= 2e5;
char str[N];
int sum[N + 1];

bool solve() {
	scanf("%s", str);
	int n = strlen(str);
	for (int i = 0; i < n; ++i) {
		sum[i + 1] = sum[i] + (str[i] == '(' ? 1 : -1);
	}
	return count(sum + 1, sum + n, 0);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) puts(solve() ? "YES" : "NO");
}
