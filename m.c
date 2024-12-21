#include <stdio.h>

#define N	50

int main() {
	freopen("in", "r", stdin);
	int t;

	scanf("%d", &t);
	while (t--) {
		int n;
		int i, j, k;
		int one = 1, zero = 1;
		static int aa[N];

		scanf("%d", &n);
		for (i = 0; i < n; ++i)
			scanf("%d", aa + i);
		for (i = 0; i < n; ++i)
			if (aa[i])
				zero = 0;
		for (i = 0; i < n; ++i)
			if (aa[i])
				break;
		for (j = n; j--;)
			if (aa[j])
				break;

		for (k = i; k <= j; ++k)
			if (!aa[k])
				one = 0;
		if (zero)
			puts("0");
		else if (one)
			puts("1");
		else
			puts("2");
	}
	return 0;
}
