
int pq[ + 1], cnt;

int lt(int i, int j) { return i <= j; }

int p2(int i) {
	return (i *= 2) > cnt ? 0 : (i < cnt && lt(pq[i + 1], pq[i]) ? i + 1 : i);
}

void swap(int *x, int *y) {
	int tmp;

	tmp = *y, *y = *x, *x = tmp;
}

void pq_up(int i) {
	for (; i && !lt(pq[i / 2], pq[i]); i /= 2)
		swap(pq + i / 2, pq + i);
}

void pq_dn(int i) {
	while ((i = p2(i)) && !lt(pq[i / 2], pq[i]))
		swap(pq + i / 2, pq + i);
}

void pq_add(int x) {
	pq[++cnt] = x, pq_up(cnt);
}

void pq_pop() {
	pq[1] = pq[cnt--], pq_dn(1);
}

int pq_first() { return pq[1]; }
