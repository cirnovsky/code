#include <math.h>
#include <stdio.h>

#define N	200000

int main() {
	int t, n;
	long long k;
	int i, j;
	static int aa[N];

	for (scanf("%d", &t); t--;) {
		scanf("%d%lld", &n, &k);
		if ((double) (n - 1) < log2(k))
			puts("-1");
		else {
			int l = 0, r = n;

			for (i = 0, j = n - 2; j >= 0; j--) {
				if (log2(k) > (double) j)
					k -= 1LL << j, aa[--r] = ++i;
				else
					aa[l++] = ++i;
			}
			aa[l++] = n;
			for (i = 0; i < n; ++i)
				printf("%d ", aa[i]);
			puts("");
		}
	}
}
