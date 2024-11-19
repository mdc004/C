#include "item.h"

struct codap {
	int hs; /*heapsize*/
	int vetsize;
	item *Q; /* Q, da allocare, verrà gestito come un heap minimo*/ 
};

typedef struct codap codap; 

codap *createCodap();


int Minimum(codap * , item *);

int ExtractMin(codap *, item*); 

void DecreaseKey(codap *, int , key );



int Insert(codap *, item);


