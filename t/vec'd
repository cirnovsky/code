
struct vector {
	size_t nmemb;
	size_t size;
	void *data;
};

void crect(struct vector *base, size_t n, size_t size) {
	int m = 0;

	while ((1 << m) <= n)
		m++;
	base->nmemb = n;
	base->size = size;
	base->data = malloc(m * base->size);
}

void appect_raw(struct vector *base, void *value) {
	int o = base->nmemb;

	if (o >= 2 && (o & (o - 1)) == 0)
		base->data = realloc(base->data, o * 2 * base->size);
	void *dest = (char *) base->data + o * base->size;
	memcpy(dest, value, base->size);
	base->nmemb++;
}

#define appect(base, value) do {		\
	__typeof__(value) tmp = value;		\
	appect_raw(base, &tmp);			\
} while (0);
