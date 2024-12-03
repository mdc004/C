#include "intlist.h"

struct graph {
	int V;
	int E;
	intlist **A;
};
typedef struct graph graph;

/* res >0 se cancellazione avvenuta correttamente */
typedef struct del2out{
	intlist* list;
	int res;  
}del2out;

graph *creategraph(int);


void add_edge( graph *, int , int );


void remove_edge( graph *, int , int );

void readgraph( graph *, FILE *);

void stampalista( graph *, int );

intlist* getAdj( graph *, int );

void destroygraph( graph *);

