#include <stdio.h>
#include <stdlib.h>

#define N	1000

int *ej[2 * N], eo[2 * N];

void append(int i, int j) {
	int o = eo[i]++;

	if (o >= 2 && (o & o - 1) == 0)
		ej[i] = (int *) realloc(ej[i], o * 2 * sizeof *ej[i]);
	ej[i][o] = j;
}

int max(int i, int j) { return i > j ? i : j; }

int *aa[N], *bb[N];

int solve(int n, int m, int bit) {
	int i, j, k;
	static int row[N], col[N];

	for (i = 0; i < n + m; ++i)
		ej[i] = (int *) malloc(2 * sizeof *ej[i]), eo[i] = 0;
	for (i = 0; i < n; ++i)
		for (j = 0; j < m; ++j)
	for (i = 0; i < n; ++i)
		row[i] = 0;
	for (i = 0; i < m; ++i)
		col[i] = 0;
	for (i = 0; i < n + m; ++i)
		free(ej[i]);
}

int main() {
	int t;

	scanf("%d", &t);
	while (t--) {
		int n, m;
		int i, j;
		int h = 0, ans = 1;

		scanf("%d%d", &n, &m);
		for (i = 0; i < n; ++i) {
			aa[i] = (int *) malloc(m * sizeof *aa[i]);
			bb[i] = (int *) malloc(m * sizeof *bb[i]);
		}
		for (i = 0; i < n; ++i)
			for (j = 0; j < m; ++j)
				scanf("%d", &aa[i][j]), h = max(h, aa[i][j]);
		for (i = 0; (1 << i) <= h; ++i)
			ans &= solve(n, m, 1 << i);
		puts(ans ? "YES" : "NO");
		for (i = 0; i < n; ++i)
			free(aa[i]), free(bb[i]);
	}
	return 0;
}
