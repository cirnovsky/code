#include <stdio.h>

#define N	100000
#define N_	(1 << 17) 	/* N_ = pow2(ceil(log(N + 1))) */

int sz[N_ * 2], lz[N_], h_, n_;
long long sum[N_ * 2];

void put(int i, int x)
{
	sum[i] += (long long) x * sz[i];
	if (i < n_)
		lz[i] += x;
}

void pus(int i)
{
	if (lz[i])
		put(i << 1, lz[i]), put(i << 1 | 1, lz[i]), lz[i] = 0;
}

void pul(int i)
{
    if (!lz[i])
		sum[i] = sum[i << 1] + sum[i << 1 | 1];
}

void push(int i)
{
	int h;

	for (h = h_; --h;)
		pus(i >> h);
}

void pull(int i)
{
	while (i > 1)
		pul(i >>= 1);
}

void build(int* aa, int n)
{
	int i;

	h_ = 0;
	while ((1 << h_) <= n)
		h_++;
	n_ = 1 << h_;
	for (i = 0; i < n; ++i)
		sum[i + n_] = aa[i], sz[i + n_] = 1;
	for (i = n_ - 1; --i;)
		pul(i), sz[i] = sz[i << 1] + sz[i << 1 | 1];
}

void update(int l, int r, int x)
{
	int l_ = l += n_, r_ = r += n_;

	push(l_), push(r_);
	for (; l < r; l >>= 1, r >>= 1) {
		if (l & 1)
			put(l++, x);
		if (r & 1)
			put(--r, x);
	}
	pull(l_), pull(r_);
}

long long query(int l, int r)
{
	long long x = 0;

	push(l += n_), push(r += n_);
	for (; l < r; l >>= 1, r >>= 1) {
		if (l & 1)
			x += sum[l++];
		if (r & 1)
			x += sum[--r];
	}
	return x;
}

int main()
{
	int n, m;
	int i;
	static int aa[N];
	
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; ++i)
		scanf("%d", aa + i);
	build(aa, n);
	while (m--) {
		int t, l, r, x;

		scanf("%d%d%d", &t, &l, &r);
		l--;
		if (t == 1)
			scanf("%d", &x), update(l, r, x);
		else
			printf("%lld\n", query(l, r));
	}
}
