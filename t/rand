
unsigned int Z;

int rand_() {
	return (Z *= 3) >> 1;
}

void srand_() {
	struct timeval tv;

	gettimeofday(&tv, NULL);
	Z = tv.tv_sec ^ tv.tv_usec | 1;
}
