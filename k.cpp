#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MD = 1e9+7;

ll power(ll x, ll y) {
	ll r = 1;
	for (; y; y >>= 1, x = x * x % MD)
		if (y&1) r = r * x % MD;
	return r;
}

ll f(ll m, ll i) {
	ll t = power(m-1, i);
	t = (t + MD - (m-1)*power(MD-1,i-1)%MD) % MD;
	
	return t * power(m, MD-2) % MD;
}

void solve() {
	ll n, k, m;
	cin >> n >> k >> m;
	if (m <= 1) {
		cout << "0\n";
		return;
	}
	ll t = m*m%MD - 3*m + 3;
	t %= MD;
	if (t < 0)
		t += MD;
	ll ano = m * (f(m, k-1)*(m-2)%MD + f(m, k-2)*(m-1)%MD) % MD;
	cout << ano * power(power(t, n-1), k) % MD << "\n";
}

int main() {
	int t;
	cin >> t;
	while (t--)
		solve();
}
