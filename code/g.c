#include <bits/types/struct_timeval.h>
#include <stdio.h>
#include "sys/time.h"

#define N	1000

unsigned int Z;

int rand_()
{
	return (Z *= 3) >> 1;
}

void srand_()
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	Z = tv.tv_sec ^ tv.tv_usec | 1;
}

void swap(int* a, int* b, int width)
{
	int i, t;

	for (i = 0; i < width; ++i) {
		t = a[i];
		a[i] = b[i];
		b[i] = t;
	}
}

int main()
{
	srand_();
	printf("%d\n", rand_() & 1);
}
