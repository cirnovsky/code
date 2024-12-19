
void sort(int *aa, int l, int r) {
	while (l < r) {
		int i = l, j = l, k = r, pivot = aa[l + rand_() % (r - l)], tmp;
		while (j < k) {
			if (aa[j] == pivot)
				j++;
			else if (aa[j] < pivot) {
				tmp = aa[i], aa[i] = aa[j], aa[j] = tmp;
				i++, j++;
			} else {
				--k;
				tmp = aa[k], aa[k] = aa[j], aa[j] = tmp;
			}
		}
		sort(aa, l, i);
		l = k;
	}
}
