#include "prog2.h"

int geteuro(void) {
	int ne;
	printf("Immetti numero di euro:\n");
	scanf("%d", &ne);
	return ne;
}

void putlire(int euro, double lire) {
	printf("%d euro valgono %.3f lire\n", euro, lire);
}
