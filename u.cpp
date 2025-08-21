#include <bits/stdc++.h>
using namespace std;

const int N = 5e5;
int a[N + 1];

void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	int j = 0;
	int rounds = 0;
	a[n] = a[n - 1];
	for (int i = 1; i <= n; ++i) {
		if (a[i] == a[i - 1]) {
			if (j + 1 < i) {
				rounds = max(rounds, (i - j - 1 - (a[i] ^ a[j])) / 2);
				if (a[i - 1] == a[j]) {
					for (int k = j; k < i; ++k) a[k] = a[j];
				} else {
					for (int k = j; k < j + (i - j) / 2; ++k)
						a[k] = a[j];
					for (int k = j + (i - j) / 2; k < i; ++k)
						a[k] = a[i];
				}
			}
			j = i;
		}
	}
	printf("%d\n", rounds);
	for (int i = 0; i < n; ++i)
		printf("%d ", a[i]);
	puts("");
}

int main() {
	int t = 1;
	while (t--) solve();
}
