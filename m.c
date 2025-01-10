#include <Judy.h>
#include <stdio.h>

int main() {
	Pvoid_t judy = NULL;
	Word_t idx = 42, *PValue;
	int Rc;

	PValue = (Word_t *) JudyLIns(&judy, idx, PJE0);
	*PValue = 123;

	PValue = (Word_t *) JudyLGet(judy, idx, PJE0);
	printf("Value: %d\n", *PValue);
	return 0;
}
