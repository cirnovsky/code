#include <stdio.h>
#include <sys/time.h>

unsigned int Z;

int rand_() {
	return (Z *= 3) >> 1;
}

void srand_() {
	struct timeval tv;

	gettimeofday(&tv, NULL);
	Z = tv.tv_sec ^ tv.tv_usec | 1;
}

struct Node {
	int key, priority, size;
	struct Node *l, *r;
};

Node *null;

Node *node(int key) {
	Node *x = (Node *) malloc(sizeof(node));

	x->size = 1, x->key = key, x->priority = rand();
	x->l = x->r = null;
	return x;
}

void pul(Node *i) {
	if (i != null)
		i->size = i->l->size + i->r->size + 1;
}

void split(Node *i, int key, Node **let, Node **gt) {
	if (i == null)
		*let = *gt = null;
	else if (i->key <= key) {
		*let = i;
		split(i->r, key, *let->r, *gt->)
	}
}

int main() {
	srand_();
	return 0;
}
