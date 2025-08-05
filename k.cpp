#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <functional>

using namespace std;

const int MOD = 1'000'000'007;

long long binpow(long long a, long long p) {
	return p?binpow(a*a%MOD, p>>1)*(p&1?a:1)%MOD:1;
}

long long bininv(long long a) {
	return binpow(a, MOD-2);
}

void solve(int test_ind){
	int n;
	cin >> n;
	vector<long long> a(n);
	for (auto &i: a) cin >> i;
	long long ans = -1;
	for (long long dd=0;dd<3;++dd) {
		long long sm = 0;
		for (auto i: a) sm += i;
		if (sm % 3 != dd * n % 3) continue;
		// cx + d
		long long c = 1, d = 0;
		for (int i=1;i<n;++i) {
			// a[i] - (cx+d) * 2 - dd
			// a[i] - dd -2cx - 2d
			// -2cx, a[i] - dd - 2d
			c = c * (MOD - 2ll) % MOD;
			d = (a[i] + MOD - dd - 2ll * d % MOD + MOD) % MOD;
		}
		// a[0] = dd+(2c+1)x+2d
		for (long long delta=0;delta<1;++delta) {
			long long x = ((a[0] + MOD - dd) % MOD - 2ll * d % MOD + MOD + MOD) % MOD * bininv((2ll * c + 1))%MOD;
			x += delta * MOD;

			// cerr << dd << " " << x << endl;
			long long a0 = a[0] - x;
			long long mn = x;
			sm = x;
			for (int i=1;i<n;++i) {
				x = a[i] - dd - 2 * x;
				// cerr << i << ": " << x << endl;
				mn = min(mn, x);
				sm += x;
				if (abs(x) > 100ll * MOD) break;
				if (i == n-1) {
					a0 -= 2 * x;
				}
			}
			if (a0 == dd && mn >= 0) {
				long long val = sm - mn * n;
				if (ans == -1 || ans > val) ans = val;
			}
		}
	}
	if (ans == -1) {
	    cout << 0 << endl;
	} else {
        long long original_sum = 0;
        for (auto& x : a) {
            original_sum += x;
        }
        cout << (original_sum - 3 * ans) / n << endl;
	}
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}
