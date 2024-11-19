#include "../intlist/intlist.h"


struct intqueue {
	intlist *head, *tail;
	int size;
};

typedef struct intqueue intqueue;

int Empty(intqueue *);
void enqueue(intqueue *);
intqueue *createqueue(void);
void destroyqueue(intqueue *);
int dequeue(intqueue *, item *);
int Head(intqueue * , item*);
int Tail(intqueue *, item *);
int size(intqueue * ); 

