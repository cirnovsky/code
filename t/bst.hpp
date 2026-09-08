
int ll[N + 1], rr[N + 1], zz[N + 1], xx[N + 1], size[N + 1], _;

int node(int x) {
	zz[_] = rand_(), ll[_] = rr[_] = 0;
	xx[_] = x, size[_] = 1;
	return _++;
}

int pul(int i) {
	if (i)
		size[i] = size[ll[i]] + size[rr[i]] + 1;
}

void split(int i, int x, int *p, int *q) {
	if (i == 0)
		*p = *q = 0;
	else if (xx[i] <= x)
		*p = i, split(rr[i], x, rr + *p, q);
	else
		*q = i, split(ll[i], x, p, ll + *q);
	pul(i);
}

int merge(int i, int j) {
	if (i == 0 || j == 0)
		return i + j;
	else if (zz[i] > zz[j])
		return rr[i] = merge(rr[i], j), pul(i), i;
	else
		return ll[j] = merge(i, ll[j]), pul(j), j;
}

int rt;

void insert(int x) {
	int i, j;
	
	split(rt, x, &i, &j);
	rt = merge(i, merge(node(x), j));
}

void remov(int x) {
	int i, j, k;
	
	split(rt, x, &i, &j);
	split(i, x - 1, &i, &k);
	rt = merge(i, merge(merge(ll[k], rr[k]), j));
}

int rank(int x) {
	int i, j, result;
	
	split(rt, x - 1, &i, &j);
	result = size[i] + 1;
	rt = merge(i, j);
	return result;
}

int at(int k) {
	int i = rt;
	
	while (1) {
		if (size[ll[i]] + 1 < k)
			k -= size[ll[i]] + 1, i = rr[i];
		else if (size[ll[i]] + 1 == k)
			return xx[i];
		else
			i = ll[i];
	}
	return ~(1 << 31);
}

int prev(int x) {
	int i, j, k;
	
	split(rt, x - 1, &i, &j);
	if (i == 0)
		return -~(1 << 31);
	for (k = i; rr[k];)
		k = rr[k];
	rt = merge(i, j);
	return xx[k];
}

int next(int x) {
	int i, j, k;
	
	split(rt, x, &i, &j);
	if (j == 0)
		return ~(1 << 31);
	for (k = j; ll[k];)
		k = ll[k];
	rt = merge(i, j);
	return xx[k];
}
