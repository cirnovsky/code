static char region[450 << 25];
void * operator new(std::size_t s) {
	static std::size_t i = sizeof region;
	assert(s < i);
	return (void *) &region[i -= s];
}
void operator delete(void *) {}
