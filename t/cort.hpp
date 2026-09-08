
int compare(int i, int j) {
}

void sort(int *ii, int l, int r) {
	while (l < r) {
		int i = l, j = l, k = r, pivot = ii[l + rand_() % (r - l)], tmp;
		while (j < k) {
			int c = compare(ii[j], pivot);

			if (c == 0)
				j++;
			else if (c < 0) {
				tmp = ii[i], ii[i] = ii[j], ii[j] = tmp;
				i++, j++;
			} else {
				--k;
				tmp = ii[k], ii[k] = ii[j], ii[j] = tmp;
			}
		}
		sort(ii, l, i);
		l = k;
	}
}
