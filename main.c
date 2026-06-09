#include "stdio.h"

int main() {
	printf("%p\n", p);
	func(&p);
	printf("%p\n", p);
}
