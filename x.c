#include "stdio.h"
#include <stdlib.h>

int main()
{
	while (1) {
		system("./g && ./m");
	}
	while (1) {
		system("./g && ./k && ./m");
		if (system("diff -Z ./k.out ./m.out")) {
			system("cat ./k.out ./m.out ./in.txt");
			puts("WA");
			break;
		}
		puts("AC");
	}
}
